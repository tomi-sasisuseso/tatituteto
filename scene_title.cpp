#include "all.h"

int title_state;
int title_timer;

const int FLASHING_SPEED = 40;
const float TITLE_EASE_DURATION = 50;

VECTOR2 title_str_pos;
VECTOR2 title_str_pos_start = { -300, 780 };
VECTOR2 title_str_pos_end = { 680, 780 };
float title_alpha;
bool isbegin;
int title_easeTimer = INT_MAX;
float title_volume;


Sprite* title_background_sprite;
Sprite* title_str_sprite;
Sprite* title_str_load1;
Sprite* title_str_load2;

void Game6_Manager_init()
{
    title_state = 0;
    title_timer = 0;

    title_str_pos = title_str_pos_start;
    title_alpha = 0.0f;
    title_volume = 1.0f;
    isbegin = false;

    title_background_sprite = sprite_load(L"./Data/Images/タイトル.png");
    title_str_load1 = sprite_load(L"./Data/Images/PRESS_1.png");
    title_str_load2 = sprite_load(L"./Data/Images/PRESS_2.png");
}

void Game6_Manager_deinit()
{
    music::stop(0);
}

void Game6_Manager_update()
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
        music::play(0, false);

        title_state++;
    case 2:
        //////// 通常時 ////////
        //デバッグ用
        debug::setString("title_state:%d", title_state);
        debug::setString("title_timer:%d", title_timer);

        //文字のスライド
        if (title_timer == 30)   title_easeTimer = 0;
        if (title_easeTimer < TITLE_EASE_DURATION)
        {
            title_easeTimer++;
            float t = (float)title_easeTimer / TITLE_EASE_DURATION;
            title_str_pos.x = Easing::step(eType::BACK_OUT, title_str_pos_start.x, title_str_pos_end.y, t);
        }

        //文字のスプライトの切り替え
        if (title_timer % FLASHING_SPEED < FLASHING_SPEED / 2)  title_str_sprite = title_str_load1;
        else    title_str_sprite = title_str_load2;
        //入力の検知
        if (TRG(0) & PAD_START && !isbegin)
        {
            isbegin = true;
            //sound::play(XWB_MAIN, XWB_MAIN_ENTER);
        }
        //透明度を下げる
        if (isbegin)
        {
            title_alpha += 0.02;
            title_volume -= 0.05;
            title_volume = std::clamp(title_volume, 0.0f, 1.0f);
            music::setVolume(0, title_volume);
        }
        //透明度に応じて次のシーンに
        if (title_alpha > 1.5f) nextScene = SCENE_GAME;

        break;
    }
    title_timer++;
}

void Game6_Manager_render()
{
    // 画面を青で塗りつぶす
    GameLib::clear(0.3f, 0.5f, 1.0f);
    //背景
    sprite_render(
        title_background_sprite,
        0, 0,
        1, 1,
        0, 0,
        SCREEN_W, SCREEN_H,
        0, 0,
        0
    );
    //文字(点滅)

    sprite_render(
        title_str_sprite,
        title_str_pos.x, title_str_pos.y,
        1, 1,
        0, 0,
        587, 55,
        587 * 0.5f, 55 * 0.5f,
        0
    );

    //塗りつぶし
    primitive::rect(
        { 0, 0 },
        { SCREEN_W, SCREEN_H },
        { 0, 0 },
        0,
        { 0.0f, 0.0f, 0.0f, title_alpha }
    );
}

