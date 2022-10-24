//******************************************************************************
//
//
//      scene_game
//
//
//******************************************************************************

//----< インクルード >-----------------------------------------------------------
#include "all.h"

//------< 定数 >----------------------------------------------------------------


//------< 変数 >----------------------------------------------------------------
int game_state;
int game_timer;


Sprite* sprBack;

int bgmNo;

//--------------------------------------
//  初期設定
//--------------------------------------
void game_init()
{
    game_state = 0;
    game_timer = 0;
}

//--------------------------------------
//  終了処理
//--------------------------------------
void game_deinit()
{
    safe_delete(sprBack);
}

//--------------------------------------
//  更新処理
//--------------------------------------
void game_update()
{
    switch (game_state)
    {
    case 0:
        //////// 初期設定 ////////

        sprBack = sprite_load(L"./Data/Images/DJ-booth.jpg");

        game_state++;
        /*fallthrough*/

    case 1:
        //////// パラメータの設定 ////////

        GameLib::setBlendMode(Blender::BS_ALPHA);

        bgmNo = 0;

        game_state++;
        /*fallthrough*/

    case 2:
        //////// 通常時 ////////
        if (TRG(0) & PAD_SELECT)
        {
            nextScene = SCENE_TITLE;
            break;
        }

        if (STATE(0) & PAD_TRG1)
        {

        }

        break;
    }

    game_timer++;
}

//--------------------------------------
//  描画処理
//--------------------------------------
void game_render()
{
    GameLib::clear(0.2f, 0.2f, 0.4f);

    //sprite_render(sprBack, 0, 0);

    //primitive::rect(
    //    0, 32, 320, 650, 
    //    0, 0, ToRadian(0), 
    //    0, 0, 0, 0.7f
    //);
}
