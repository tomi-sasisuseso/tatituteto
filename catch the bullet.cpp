#include "all.h"

int title_state;
int title_timer;

//パラメータ
//SAFE_ANGLEについて　-1から1の間で調整　値が大きくなるほどセーフの判定が厳しくなる
const float CIRCLE_MOVESPEED = 0.15f;
const float CIRCLE_MAXSPEED = 3.0f;
const float CIRCLE_DECELERATION = 0.8f;
const float SAFE_ANGLE = 0.82f;
int bullet_speed = 5;
int spawn_interval = 30;

Sprite* circle_sprite;
Sprite* bullet_sprite;
OBJ2D circle;
OBJ2D bullet;

float product = 0;
int spawn_counter = 0;

void title_init()
{
    title_state = 0;
    title_timer = 0;

    circle_sprite = sprite_load(L"./Data/Images/ゲーム4_円.png");
    bullet_sprite = sprite_load(L"./Data/Images/ゲーム4_弾.png");
}

void title_deinit()
{
    music::stop(0);
    safe_delete(circle_sprite);
    safe_delete(bullet_sprite);
}

void title_update()
{
    switch (title_state)
    {
    case 0:
        //////// 初期設定 ////////
        title_state++;
        bullet_init();

        /*fallthrough*/
    case 1:
        //////// パラメータの設定 ////////
        GameLib::setBlendMode(Blender::BS_ALPHA);
        music::play(0, FALSE);
        //中心の円
        circle.pos = CENTER;
        circle.scale = { 1, 1 };
        circle.texPos = { 0,0 };
        circle.texSize = { 300,300 };
        circle.pivot = circle.texSize / 2;
        circle.Dradius = 150;
        circle.angle = 0;
        //弾
        bullet.pos = { -100, -600 };
        bullet.scale = { 1, 1 };
        bullet.texPos = { 0,0 };
        bullet.texSize = { 70, 70 };
        bullet.pivot = bullet.texSize / 2;
        bullet.Dradius = 24;
        bullet.angle = 0;

        title_state++;
        /*fallthrough*/

    case 2:
        //////// 通常時 ////////
        //デバッグ用
        debug::setString("title_state:%d", title_state);
        debug::setString("title_timer:%d", title_timer);
        debug::setString("Bullet Angle: %f", bullet.angle);
        debug::setString("Bullet Vector: %f %f", bullet.vector_normal.x, bullet.vector_normal.y);
        debug::setString("Circle Angle: %f", circle.angle);
        debug::setString("Circle Vector: %f %f", circle.vector_normal.x, circle.vector_normal.y);
        debug::setString("Inner Product: %f", product);
        debug::setString("Spawn Counter: %i", spawn_counter);

        if (TRG(0) & PAD_START)
        {
            nextScene = SCENE_GAME;
            break;
        }
        circle_move();
        bullet_move();
        is_safe();
    }
    title_timer++;
}

void title_render()
{
    // 画面を青で塗りつぶす
    GameLib::clear(0.3f, 0.5f, 1.0f);
    //円
    sprite_render(
        circle_sprite,
        circle.pos.x, circle.pos.y,
        circle.scale.x, circle.scale.y,
        circle.texPos.x, circle.texPos.y,
        circle.texSize.x, circle.texSize.y,
        circle.pivot.x, circle.pivot.y,
        circle.angle,
        1.0f, 1.0f, 1.0f, 1.0f
    );
    sprite_render(
        bullet_sprite,
        bullet.pos.x, bullet.pos.y,
        bullet.scale.x, bullet.scale.y,
        bullet.texPos.x, bullet.texPos.y,
        bullet.texSize.x, bullet.texSize.y,
        bullet.pivot.x, bullet.pivot.y,
        bullet.angle,
        1.0f, 1.0f, 1.0f, 1.0f
    );
#if 0
    //当たり判定
    //円
    primitive::circle(
        circle.pos,
        circle.Dradius,
        { 1, 1 },
        circle.angle,
        { 1.0f, 0.0f, 0.0f, 0.4f }
    );
    //弾
    primitive::circle(
        bullet.pos,
        bullet.Dradius,
        { 1, 1 },
        bullet.angle,
        { 1.0f, 0.0f, 0.0f, 0.4f }
    );
    //ベクトル
    primitive::line(
        circle.pos,
        circle.pos + circle.vector_normal * -300,
        { 1.0f, 0.0f, 0.0f, 1.0f },
        3.0f
    );
    primitive::line(
        bullet.pos,
        bullet.pos + bullet.vector_normal * 100,
        { 0.0f, 1.0f, 0.0f, 1.0f },
        3.0f
    );
#endif
}

//円の移動
void circle_move()
{
    //ベクトル、内積
    circle.vector_normal = { cosf(circle.angle), sinf(circle.angle) };
    product = inner_product(circle.vector_normal, bullet.vector_normal);
    //入力
    switch (STATE(0) & (PAD_LEFT | PAD_RIGHT))
    {
    case PAD_LEFT:
        circle.velocity.x += -CIRCLE_MOVESPEED;
        break;
    case PAD_RIGHT:
        circle.velocity.x += CIRCLE_MOVESPEED;
        break;
    default:
        circle.velocity.x *= CIRCLE_DECELERATION;
        break;
    }
    //速度の制限
    circle.velocity.x = std::clamp(circle.velocity.x, -CIRCLE_MAXSPEED, CIRCLE_MAXSPEED);
    //速度を位置に代入
    circle.angle += ToRadian(circle.velocity.x);
}

//弾を初期化
void bullet_init()
{
    //位置を設定
    float angle = rand() % 360;
    float x = (SCREEN_W / 2) + cosf(angle) * SCREEN_W;
    float y = (SCREEN_H / 2) + sinf(angle) * SCREEN_H;
    bullet.pos = { x, y };
    //カウンターをリセット
    spawn_counter = 0;
}

//弾の処理
void bullet_move()
{
    //キャッチ後のインターバル
    spawn_counter++;
    if (spawn_counter < spawn_interval)  return;
    debug::setString("Bullet Activated!");
    //中心に移動
    bullet.angle = p_to_p_angle(CENTER, bullet.pos);
    bullet.vector_normal = { cosf(bullet.angle), sinf(bullet.angle) };
    bullet.velocity = bullet.vector_normal * bullet_speed;
    //速度を位置に代入
    bullet.pos += bullet.velocity;
}

//当たり判定
void is_safe()
{
    //くぐり抜けた場合
    if (circle_collision(CENTER, bullet.pos, 1, 1))
    {
        bullet_init();
    }
    //ミスをした場合
    if (circle_collision(circle.pos, bullet.pos, circle.Dradius, bullet.Dradius) && product < SAFE_ANGLE)
    {
        bullet_init();
    }
}
