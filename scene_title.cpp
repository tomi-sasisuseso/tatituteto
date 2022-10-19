#include "all.h"

int title_state;
int title_timer;

Sprite* sprCar;

void title_init()
{
    title_state = 0;
    title_timer = 0;
}

void title_deinit()
{
#if 4
//******************************************************************************
// TODO:04 タイトル終了で音楽を停止させる
//------------------------------------------------------------------------------
/*
課題）
    □ タイトル終了時に音楽を停止させましょう。
        0番の曲を停止してください。

解説）
        使用関数）
            music::stop

        引数）
            音楽のインデックス
*/
//******************************************************************************
#endif
    //TODO_04
    music::stop(0);

    safe_delete(sprCar);
}

void title_update()
{
    switch (title_state)
    {
    case 0:
        //////// 初期設定 ////////
        sprCar = sprite_load(L"./Data/Images/right.png");
        title_state++;
        /*fallthrough*/

    case 1:
        //////// パラメータの設定 ////////
        GameLib::setBlendMode(Blender::BS_ALPHA);
#if 3
//******************************************************************************
// TODO:03 タイトルで音楽を再生する
//------------------------------------------------------------------------------
/*
課題）
    □ タイトルで音楽を再生しましょう。
      0番の曲を再生してください。（今回はループ無しで。）

解説）
      使用関数）
          music::play

      引数）
          音楽のインデックス
          ループフラグ（ループする:true、ループしない:false）
*/
//******************************************************************************
#endif
        //TODO_03
        music::play(0, FALSE);

        title_state++;
        /*fallthrough*/

    case 2:
        //////// 通常時 ////////

        if (TRG(0) & PAD_START)
        {
            nextScene = SCENE_GAME;
            break;
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

    // タイトルの文字
    font::textOut(4, "ECC COMP", VECTOR2(100, 80), VECTOR2(2.4f, 2.4f), VECTOR4(1, 0.8f, 0, 1));
    font::textOut(4, "Game Programming I", VECTOR2(80, 180), VECTOR2(2.0f, 2.0f), VECTOR4(0, 1, 0.6f, 1));

    // "Push Enter Key" 点滅
    for (int i=0; i<18; i++) debug::setString("");
    debug::setString("title_timer / 32       :%d", title_timer / 32);
    debug::setString("title_timer / 32 %% 2   :%d", title_timer / 32 % 2);
    debug::setString("title_timer >> 5       :%d", title_timer >> 5);
    debug::setString("title_timer >> 5 & 0x01:%d", title_timer >> 5 & 0x01);
    debug::setString("title_timer & 0x20     :%d", title_timer & 0x20);
    if (title_timer >> 5 & 0x01)
    {
        font::textOut(4, "Push Enter Key", VECTOR2(120, 560), VECTOR2(1.4f, 1.4f));
    }

    sprite_render(sprCar, 200, 200);
}
