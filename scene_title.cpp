#include "all.h"

int title_state;
int title_timer;

Sprite* Easing_test;
VECTOR2 Easing_test_pos;

void title_init()
{
    title_state = 0;
    title_timer = 0;

    Easing_test = sprite_load(L"./Data/Images/Easing_test.png");
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
        if (TRG(0) & PAD_TRG1)
        {
            Easing_test_pos = Easing::linear()
        }

        break;
    }

    debug::setString("title_state:%d", title_state);
    debug::setString("title_timer:%d", title_timer);

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
