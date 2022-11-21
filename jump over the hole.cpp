#include "all.h"

int title_state;
int title_timer;

//パラメータ
const float GRAVITY = 0.5f;
const float MOVE_SPEED = 5.0f;
const float ROTATE_SPEED = MOVE_SPEED * 0.6f;
const float JUMP_POWER = 20.0f;
const float SPAWN_POS_X = SCREEN_W + 100;
const float DESPAWN_POS_X = -100;
const float BORDER_TO_FALL = 780.0f;
//最大から最少までの間からランダムに待機時間を設定
const int MAX_WAIT_TIME = 1000;
const int MIN_WAIT_TIME = 100;

OBJ2D background;
OBJ2D ball3;
OBJ2D hole;

Sprite* ball_sprite;
Sprite* hole_sprite;

float wait_time = 0;
float floor_height = 0;
bool is_on_floor = false;

void title_init()
{
    title_state = 0;
    title_timer = 0;

    texture::load(TEXNO::GAME3_BG, L"./Data/Images/ゲーム3_背景.png", 5000);
    ball_sprite = sprite_load(L"./Data/Images/ゲーム3_ボール.png");
    hole_sprite = sprite_load(L"./Data/Images/ゲーム3_穴.png");
}

void title_deinit()
{
    music::stop(0);
    safe_delete(ball_sprite);
    safe_delete(hole_sprite);
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
        //背景
        background.pos = CENTER;
        background.scale = { 1, 1 };
        background.texPos = { 0,0 };
        background.texSize = { 1280, 540 };
        background.pivot = background.texSize / 2;
        background.angle = 0;
        //四角
        ball3.pos = CENTER;
        ball3.scale = { 0.5f, 0.5f };
        ball3.texPos = { 0,0 };
        ball3.texSize = { 150, 150 };
        ball3.pivot = ball3.texSize / 2;
        ball3.angle = 0;
        ball3.Dradius = 32.0f;
        //穴
        hole.scale = { 1, 1 };
        hole.texPos = { 0,0 };
        hole.texSize = { 150, 150 };
        hole.pivot = hole.texSize / 2;
        hole.angle = 0;
        hole.Dradius = 32.0f;
        //ボールの初期位置
        ball3.pos.x += -400.0f;
        ball3.pos.y += background.texSize.y * 0.5f - ball3.pivot.y * 1.5f;
        floor_height = ball3.pos.y;

        hole_init();
        title_state++;
    case 2:
        //////// 通常時 ////////
        //デバッグ用
        debug::setString("title_state:%d", title_state);
        debug::setString("title_timer:%d", title_timer);
        debug::setString("Ball Position: %f %f", ball3.pos.x, ball3.pos.y);
        debug::setString("Hole Position: %f %f", hole.pos.x, hole.pos.y);
        debug::setString("Hole Waittime: %f", wait_time);

        ball_move();
        hole_move();
        break;
    }
    title_timer++;
}

void title_render()
{
    // 画面を青で塗りつぶす
    GameLib::clear(0.3f, 0.5f, 1.0f);
    //背景
    texture::begin(TEXNO::GAME3_BG);
    for (int i = 0; i < 3000; i++)
    {
        texture::draw(
            TEXNO::GAME3_BG,
            { background.pos.x * i - (title_timer * MOVE_SPEED), background.pos.y },
            background.scale,
            background.texPos,
            background.texSize,
            background.pivot,
            background.angle
        );
    }
    texture::end(TEXNO::GAME3_BG);
    //穴
    sprite_render(
        hole_sprite,
        hole.pos.x, hole.pos.y,
        hole.scale.x, hole.scale.y,
        hole.texPos.x, hole.texPos.y,
        hole.texSize.x, hole.texSize.y,
        hole.pivot.x, hole.pivot.y,
        hole.angle
    );
    //ボール
    sprite_render(
        ball_sprite,
        ball3.pos.x, ball3.pos.y,
        ball3.scale.x, ball3.scale.y,
        ball3.texPos.x, ball3.texPos.y,
        ball3.texSize.x, ball3.texSize.y,
        ball3.pivot.x, ball3.pivot.y,
        ball3.angle
    );
    //デバッグ用
#if 1

#endif
}

void ball_move()
{
    //重力
    ball3.velocity.y += GRAVITY;
    //回転
    ball3.angle += ToRadian(ROTATE_SPEED);
    //ジャンプ
    if (TRG(0) & PAD_TRG1 && is_on_floor)
    {
        ball3.velocity.y = -JUMP_POWER;
    }
    //速度を位置に代入
    ball3.pos += ball3.velocity;
    //穴の左右の位置
    float left = hole.pos.x - hole.pivot.x;
    float right = hole.pos.x + hole.pivot.x;
    //地面にいる場合
    if (ball3.pos.y > floor_height && !(left < ball3.pos.x && ball3.pos.x < right))
    {
        debug::setString("onground");
        ball3.velocity.y = 0;
        ball3.pos.y = floor_height;
        is_on_floor = true;
    }
    //空中
    else
    {
        is_on_floor = false;
    }
    //落下の判定
    if (ball3.pos.y > BORDER_TO_FALL)   title_init();
}

void hole_init()
{
    //位置
    hole.pos = CENTER;
    hole.pos.y += background.pivot.y - 5;
    hole.pos.x = SPAWN_POS_X;
    //次に出現するまでの時間をランダムに生成
    wait_time = MIN_WAIT_TIME + rand() % MAX_WAIT_TIME;
}

void hole_move()
{
    //左方向に移動
    hole.velocity.x = -MOVE_SPEED;
    //位置をリセット
    if (hole.pos.x < DESPAWN_POS_X - wait_time)
    {
        hole_init();
    }
    //速度を位置に代入
    hole.pos += hole.velocity;
}