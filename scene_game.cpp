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

bool isPaused;

int bgmNo;

//--------------------------------------
//  初期設定
//--------------------------------------
void game_init()
{
    game_state = 0;
    game_timer = 0;

    isPaused = false;
}

//--------------------------------------
//  終了処理
//--------------------------------------
void game_deinit()
{
    
}

//--------------------------------------
//  更新処理
//--------------------------------------
void game_update()
{

    debug::setString("game_state:%d", game_state);
    debug::setString("game_timer:%d", game_timer);

    switch (game_state)
    {
    case 0:
        //////// 初期設定 ////////

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
        //デバッグ
        debug::setString("game_timer: %d", game_timer);

        if (TRG(0) & PAD_SELECT)

        //デバッグ
        debug::setString("game_timer: %d", game_timer);


        if (TRG(0) & PAD_START)
        {
            nextScene = SCENE_SCORE;
            break;
        }
        //ポーズ中ならここでリターン
        if (isPaused)    return;
        

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
}
