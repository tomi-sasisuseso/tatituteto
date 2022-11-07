#include "all.h"

int title_state;
int title_timer;

int control = 0;

const float STAGE_SPEED = 0.03f;
const float MAX_SPEED = 1.0f;
const float FRICTION = 0.95f;
const float GRAVITY = 9.8f;

OBJ2D stage;
Sprite* stage_sprite;

OBJ2D ball1;
Sprite* ball1_sprite;

void title_init()
{
    title_state = 0;
    title_timer = 0;

    stage_sprite = sprite_load(L"./Data/Images/棒.png");
    ball1_sprite = sprite_load(L"./Data/Images/ボール.png");
}

void title_deinit()
{
    music::stop(0);
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

        stage.pos = { SCREEN_W / 2, SCREEN_H / 2 + 100 };
        stage.scale = { 1, 1 };
        stage.angle = 0;
        stage.velocity = { 0,0 };
        stage.texSize = { 450, 30 };
        ball1.pos = { SCREEN_W / 2, SCREEN_H / 2 - 100 };
        ball1.scale = { 0.5, 0.5 };
        ball1.texSize = { 150, 150 };
        ball1.angle = 0;

        title_state++;
        /*fallthrough*/

    case 2:
        //////// 通常時 ////////
        //デバッグ用
        debug::setString("title_state:%d", title_state);
        debug::setString("title_timer:%d", title_timer);
        debug::setString("velocity: %f", stage.velocity);

        if (TRG(0) & PAD_START)
        {
            nextScene = SCENE_GAME;
            break;
        }

        stage_move();
        ball_move();
        break;
    }


    title_timer++;
}

void title_render()
{
    // 画面を青で塗りつぶす
    GameLib::clear(0.3f, 0.5f, 1.0f);

    //ステージの描画
    sprite_render(
        stage_sprite,
        stage.pos.x, stage.pos.y,
        stage.scale.x, stage.scale.y,
        0, 0,
        stage.texSize.x, stage.texSize.y,
        450 / 2, 30 / 2,
        stage.angle
    );
    //ボールの描画
    sprite_render(
        ball1_sprite,
        ball1.pos.x, ball1.pos.y,
        ball1.scale.x, ball1.scale.y,
        0, 0,
        ball1.texSize.x, ball1.texSize.y,
        75, 75,
        ball1.angle
    );
}

void stage_move()
{
    //入力
    if (STATE(0) & PAD_LEFT)     control = -1;
    else if (STATE(0) & PAD_RIGHT)     control = 1;
    else    control = 0;

    stage.velocity.x += control * STAGE_SPEED;

    //速度の制限など
    if(control == 0)    stage.velocity.x *= FRICTION;
    stage.velocity.x = std::clamp(stage.velocity.x, -MAX_SPEED, MAX_SPEED);

    stage.angle += ToRadian(stage.velocity.x);
}

void ball_move()
{
    ball1.pos = stage.pos;
    ball1.pos.y -= ball1.texSize.y / 2;
}