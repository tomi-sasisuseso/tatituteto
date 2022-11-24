#include "all.h"

int title_state;
int title_timer;

//パラメータ
const float DURATION = 60;
const float MOVE_SPEED = 5.0f;
const float SPAWN_POS_X = SCREEN_W + 200.0f;
const float DESPAWN_POS_X = -100.0f;
const float COYOTE_TIME = 20.0f;

OBJ2D triangle;
OBJ2D background;
OBJ2D barrier;

int triangle_easetimer = INT_MAX;
VECTOR2 upperpos = CENTER, downerpos = CENTER;

Sprite* background_sprite;
Sprite* triangle_sprite;
Sprite* barrier_sprite;

bool reverse = true;
float interval = 150.0f;

void title_init()
{
    title_state = 0;
    title_timer = 0;
    srand(unsigned int(time(NULL)));

    background_sprite = sprite_load(L"./Data/Images/ゲーム6_背景.png");
    triangle_sprite = sprite_load(L"./Data/Images/ゲーム6_三角.png");
    barrier_sprite = sprite_load(L"./Data/Images/ゲーム6_障害物.png");
}

void title_deinit()
{
    music::stop(0);

    safe_delete(background_sprite);
    safe_delete(triangle_sprite);
    safe_delete(barrier_sprite);
}

void title_update()
{
    switch (title_state)
    {
    case 0:
        //////// 初期設定 ////////
        title_state++;

        /*fallthrough*/
    case 1:
        //////// パラメータの設定 ////////
        GameLib::setBlendMode(Blender::BS_ALPHA);
        music::play(0, FALSE);
        //四角
        triangle.scale = { 0.5f, 0.5f };
        triangle.texPos = { 0,0 };
        triangle.texSize = { 200, 160 };
        triangle.pivot = triangle.texSize / 2;
        triangle.angle = 0;
        triangle.Dradius = 32.0f;
        //背景
        background.pos = CENTER;
        background.scale = { 1, 1 };
        background.texPos = { 0,0 };
        background.texSize = { 1280, 540 };
        background.pivot = background.texSize / 2;
        background.angle = 0;
        //障害物
        barrier.pos = CENTER;
        barrier.scale = { 1, 1 };
        barrier.texPos = { 0,0 };
        barrier.texSize = { 60, 160 };
        barrier.pivot = barrier.texSize / 2;
        barrier.angle = 0;
        barrier.Dradius = 32;
        /*fallthrough*/
        //初期位置
        upperpos += {0, -background.texSize.y * 0.5f + triangle.pivot.y};
        downerpos += {0, background.texSize.y * 0.5f - triangle.pivot.y};
        triangle.pos = downerpos;
        triangle.pos.x -= 500.0f;
        barrier_init();

        title_state++;
    case 2:
        //////// 通常時 ////////
        //デバッグ用
        debug::setString("title_state:%d", title_state);
        debug::setString("title_timer:%d", title_timer);
        debug::setString("Triangle Velocity: %f %f", triangle.velocity.x, triangle.velocity.y);
        debug::setString("Triangle Position: %f %f", upperpos.y, downerpos.y);
        debug::setString("Barrier Position: %f %f", barrier.pos.x, barrier.pos.y);

        if (TRG(0) & PAD_START)
        {
            nextScene = SCENE_GAME;
            break;
        }

        triangle_move();
        barrier_move();
        break;
    }


    title_timer++;
}

void title_render()
{
    // 画面を青で塗りつぶす
    GameLib::clear(0.3f, 0.5f, 1.0f);
    //背景
    for (int i = 0; i < 5000; i++)
    {
        sprite_render(
            background_sprite,
            background.pos.x * i - (title_timer * MOVE_SPEED), background.pos.y,
            background.scale.x, background.scale.y,
            background.texPos.x, background.texPos.y,
            background.texSize.x, background.texSize.y,
            background.pivot.x, background.pivot.y,
            background.angle
        );
    }
    //三角
    sprite_render(
        triangle_sprite,
        triangle.pos.x, triangle.pos.y,
        triangle.scale.x, triangle.scale.y,
        triangle.texPos.x, triangle.texPos.y,
        triangle.texSize.x, triangle.texSize.y,
        triangle.pivot.x, triangle.pivot.y,
        triangle.angle
    );
    //障害物
    sprite_render(
        barrier_sprite,
        barrier.pos.x, barrier.pos.y,
        barrier.scale.x, barrier.scale.y,
        barrier.texPos.x, barrier.texPos.y,
        barrier.texSize.x, barrier.texSize.y,
        barrier.pivot.x, barrier.pivot.y,
        barrier.angle
    );
    //デバッグ用
#if 1
    //障害物
    primitive::circle(
        barrier.pos,
        32,
        { 1, 1 },
        0,
        { 1.0f, 0.0f, 0.0f, 0.5f }
    );
    //△
    primitive::circle(
        triangle.pos,
        triangle.Dradius,
        { 1, 1 },
        0,
        { 1.0f, 0.0f, 0.0f, 0.5f }
    );
#endif
}

void triangle_move()
{
    //左右に反転
    if (TRG(0) & PAD_TRG1 && !(0 < triangle_easetimer && triangle_easetimer < DURATION - COYOTE_TIME))
    {
        reverse = !reverse;
        triangle_easetimer = 0;
    }
    //移動
    if (triangle_easetimer < DURATION)
    {
        triangle_easetimer++;
        float t = (float)triangle_easetimer / DURATION;
        if (reverse)
        {
            triangle.pos.y = Easing::step(eType::BOUNCE_OUT, upperpos.y, downerpos.y, t);
            triangle.angle = Easing::step(eType::EXPO_OUT, PI, TAU, t * 1.3f);
        }
        else
        {
            triangle.pos.y = Easing::step(eType::BOUNCE_OUT, downerpos.y, upperpos.y, t);
            triangle.angle = Easing::step(eType::EXPO_OUT, TAU, PI, t * 1.3f);
        }        
    }
}

void barrier_init()
{
    //上下どちらか設定
    int choise = rand() % 2;
    //下
    if (choise == 0)
    {
        barrier.pos.y = SCREEN_H / 2 - interval;
    }
    //上
    else
    {
        barrier.pos.y = SCREEN_H / 2 + interval;
    }
    //x方向
    barrier.pos.x = SPAWN_POS_X;
}

void barrier_move()
{
    //画面外に出たらリスポーン
    if (barrier.pos.x < DESPAWN_POS_X)
    {
        barrier_init();
    }
    //障害物にヒット
    if (circle_collision(triangle.pos, barrier.pos, triangle.Dradius, barrier.Dradius))
    {
        barrier_init();
    }

    barrier.velocity.x = -MOVE_SPEED;
    barrier.pos += barrier.velocity;
}