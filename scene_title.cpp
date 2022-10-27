#include "all.h"

int title_state;
int title_timer;

int ease_timer;

Sprite* Easing_test;
VECTOR2 Easing_test_pos;

void title_init()
{
    title_state = 0;
    title_timer = 0;
    ease_timer = INT_MAX;
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
        Easing_test = sprite_load(L"./Data/Images/Easing_test.png");

        /*fallthrough*/
    case 1:
        //////// パラメータの設定 ////////
        GameLib::setBlendMode(Blender::BS_ALPHA);
        music::play(0, FALSE);

        Easing_test_pos = { 100, 100 };

        title_state++;
        /*fallthrough*/

    case 2:
        //////// 通常時 ////////

        if (TRG(0) & PAD_START)
        {
            nextScene = SCENE_GAME;
            break;
        }
        //イージング関数のサンプル
        const int easing_time = 60;    //ここで移動が完了するまでの時間を設定
        //タイマーを０にすることで開始
        if (TRG(0) & PAD_TRG1)   ease_timer = 0;

        if (ease_timer < easing_time)
        {
            ease_timer++;
            float t = (float)ease_timer / easing_time;
            //変化させる値　＝　初期値　＋　終了値　＊　使うイージング関数
            Easing_test_pos.x = 100 + 800 * Easing::elastic_out(t);
        }
        break;
    }

    debug::setString("title_state:%d", title_state);
    debug::setString("title_timer:%d", title_timer);

    debug::setString("Easing_pos_x: % f", Easing_test_pos.x);
    debug::setString("ease_timer: %d", ease_timer);

    title_timer++;
}

void title_render()
{
    // 画面を青で塗りつぶす
    GameLib::clear(0.3f, 0.5f, 1.0f);

    sprite_render(
        Easing_test,
        Easing_test_pos.x, Easing_test_pos.y,
        1, 1,
        0, 0,
        256, 256,
        0, 0,
        0
    );
}
