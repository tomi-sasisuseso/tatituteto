#include "catch the bullet.h"
Sprite* circle_sprite;
Sprite* bullet_sprite;

extern OBJ2D back[MAX_GAMES];

void Game3_Manager::Game3_Manager_init()
{
    //////// パラメータの設定 ////////
    GameLib::setBlendMode(Blender::BS_ALPHA);
    music::play(0, FALSE);
    //中心の円
    circle.pos = { back[2].pos.x + back[2].texSize.x/2,back[2].pos.y + back[2].texSize.y/2 };
    circle.scale = { 1, 1 };
    circle.texPos = { 0,0 };
    circle.texSize = { 300,300 };
    circle.pivot = circle.texSize / 2;
    circle.Dradius = 150;
    circle.angle = 0;

    bullet_init();

    circle_sprite = sprite_load(L"./Data/Images/ゲーム4_円.png");
    bullet_sprite = sprite_load(L"./Data/Images/ゲーム4_弾.png");
}

void Game3_Manager::Game3_Manager_deinit()
{
    music::stop(0);
    safe_delete(circle_sprite);
    safe_delete(bullet_sprite);
}

void Game3_Manager::Game3_Manager_update()
{
    circle_move();
    bullet_move();
    is_safe();
}

void Game3_Manager::Game3_Manager_render()
{

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
void Game3_Manager::circle_move()
{
    //ベクトル、内積
    circle.pos = { back[2].pos.x + back[2].texSize.x/2,
                   back[2].pos.y + back[2].texSize.y/2 };

    circle.vector_normal = { cosf(circle.angle), sinf(circle.angle) };
    product = inner_product(circle.vector_normal, bullet.vector_normal);
    //入力
    switch (STATE(0) & (PAD_TRG3 | PAD_TRG4))
    {
    case PAD_TRG3:
        circle.velocity.x += -CIRCLE_MOVESPEED;
        break;
    case PAD_TRG4:
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
void Game3_Manager::bullet_init()
{
    //弾
    bullet.pos = { -100, -600 };
    bullet.scale = { 1, 1 };
    bullet.texPos = { 0,0 };
    bullet.texSize = { 70, 70 };
    bullet.pivot = bullet.texSize / 2;
    bullet.Dradius = 24;
    bullet.angle = 0;

    //位置を設定
    float angle = rand() % 360;
    float x = (circle.pos.x) + cosf(angle) * SCREEN_W;
    float y = (circle.pos.y) + sinf(angle) * SCREEN_H;
    bullet.pos = { x, y };

    //カウンターをリセット
    spawn_counter = 0;
}

//弾の処理
void Game3_Manager::bullet_move()
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
void Game3_Manager::is_safe()
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
