#include "ball_balancing.h"

//ステージ、ボールのパラメーター
const float STAGE_SPEED = 0.02f;
const float STAGE_MAX_SPEED = 1.0f;
const float BALL_SPEED = 0.2f;
const float BALL_MAX_SPEED = 2.0f;
const float BALL_ADJUST = 0.1f;
const float FRICTION = 0.95f;
const float GRAVITY = 0.7f;

extern OBJ2D back[MAX_GAMES];

Sprite* stage_sprite;
Sprite* ball1_sprite;

void Game1_Manager::Game1_Manager_init()
{
    GameLib::setBlendMode(Blender::BS_ALPHA);

    //ステージ
    stage.pos = { SCREEN_W / 2, SCREEN_H / 2 + 100 };
    stage.scale = { 1, 1 };
    stage.angle = 0;
    stage.velocity = { 0.2f ,0 };
    stage.texSize = { 450, 30 };
    stage.pivot = stage.texSize / 2;

    ball_init();

    //スプライトを読み込み
    stage_sprite = sprite_load(L"./Data/Images/ゲーム1_棒.png");
    ball1_sprite = sprite_load(L"./Data/Images/ゲーム1_ボール.png");
}

void Game1_Manager::Game1_Manager_deinit()
{
    music::stop(0);
    //スプライトのメモリ開放
    safe_delete(stage_sprite);
    safe_delete(ball1_sprite);
}

void Game1_Manager::Game1_Manager_update()
{
    stage_move();
    ball_move();
    Game1_judge();
}

void Game1_Manager::Game1_render()
{
    //ステージの描画
    sprite_render(
        stage_sprite,
        stage.pos.x, stage.pos.y,
        stage.scale.x, stage.scale.y,
        0, 0,
        stage.texSize.x, stage.texSize.y,
        stage.pivot.x, stage.pivot.y,
        stage.angle
    );
    //ボールの描画
    sprite_render(
        ball1_sprite,
        ball.pos.x, ball.pos.y,
        ball.scale.x, ball.scale.y,
        0, 0,
        ball.texSize.x, ball.texSize.y,
        ball.pivot.x, ball.pivot.y,
        ball.angle
    );

#if 0
    //当たり判定
    primitive::rect(
        stage.pos,
        stage.texSize,
        stage.pivot,
        stage.angle,
        VECTOR4(1.0f, 0.0f, 0.0f, 0.5f)
    );
    primitive::circle(
        ball.pos,
        ball.Dradius,
        VECTOR2(1,1),
        0,
        VECTOR4(1.0f, 0.0f, 0.0f, 0.5f)
    );
#endif
}

void Game1_Manager::stage_move()
{
    //入力
    if (GetAsyncKeyState('A'))     control = -1;
    else if (GetAsyncKeyState('D'))     control = 1;
    else    control = 0;
    //回転
    stage.velocity.x += control * STAGE_SPEED;
    //速度の制限など
    if(control == 0)    stage.velocity.x *= FRICTION;
    stage.velocity.x = std::clamp(stage.velocity.x, -STAGE_MAX_SPEED, STAGE_MAX_SPEED);
    //角度
    stage.angle += ToRadian(stage.velocity.x);
}


void Game1_Manager::ball_init()
{
    //ボールの初期位置を設定
    //ボール
    ball.pos = { SCREEN_W / 2, SCREEN_H / 2 - 100 };
    ball.scale = { 0.5, 0.5 };
    ball.texSize = { 150, 150 };
    ball.pivot = ball.texSize / 2;
    ball.angle = 0;
    ball.Dradius = 40.0f;
    ball.velocity = { 0, 0 };

    ball.pos = stage.pos;
    ball.pos.y -= ball.texSize.y / 2;
}

void Game1_Manager::ball_move()
{
    //ボールのx方向の計算（ステージの角度に応じて速度を設定）
    ball.velocity.y += GRAVITY;
    ball.velocity.x += stage.angle * BALL_SPEED;
    ball.velocity.x = std::clamp(ball.velocity.x, -BALL_MAX_SPEED, BALL_MAX_SPEED);
    //ボールの角度を設定
    ball.angle += ToRadian(ball.velocity.x);
    //y方向（重力）
    if (CircleWithRotatedRectanglecollide(stage.pos, stage.pivot, -stage.angle, stage.texSize, ball.pos, ball.Dradius))
    {
        ball.velocity.y = 0;

        while (CircleWithRotatedRectanglecollide(stage.pos, stage.pivot, -stage.angle, stage.texSize, ball.pos, ball.Dradius))
        {
            ball.pos.y -= BALL_ADJUST;
        }
    }
    //最終的な速度を位置に代入
    ball.pos += ball.velocity;
}

void Game1_Manager::Game1_Manager_slideX(float x)
{
    if (stage.pos.x > x) {
        stage.pos.x -= 16;
        ball.pos.x -= 16;
    }
    else stage.pos.x = x;
    
    //if (stage.pos.x > x) stage.pos.x -= 16;
    //else stage.pos.x = x;
    //if (ball.pos.x > x) ball.pos.x -= 16;
    //else ball.pos.x = x;
}

void Game1_Manager::Game1_Manager_slideY(float y)
{
    if (stage.pos.y > y) {
        stage.pos.y -= 16;
        ball.pos.y -= 16;
    }
    else stage.pos.y = y;
}

void Game1_Manager::Game1_Manager_shrink()
{
    stage.scale *= 0.99;
    ball.scale *= 0.99;
    stage.Dradius *= 0.99;
    ball.Dradius *= 0.99;
    if (stage.pos.y > SCREEN_H / 4) stage.pos.y -= 4;
    else stage.pos.y = SCREEN_H / 4;
    if (ball.pos.y > SCREEN_H / 4) ball.pos.y -= 4;
    else ball.pos.y = SCREEN_H / 4;
}

void Game1_Manager::Game1_judge()
{
    if (ball.pos.y > SCREEN_H)  missed_game[0] = true;
}

