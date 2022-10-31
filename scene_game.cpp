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

Sprite* Buck[MAX_GAMES];


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
    //ゲームをポーズ
    if (TRG(0) & PAD_START)
        isPaused = !isPaused;       // 0コンのスタートボタンが押されたらポーズ状態が反転
    if (isPaused) return;           // この時点でポーズ中ならリターン

    switch (game_state)
    {
    case 0:
        //////// 初期設定 ////////
        Buck[0] = sprite_load(L"./Data/images/仮1.png");
        Buck[1] = sprite_load(L"./Data/images/仮2.png");
        Buck[2] = sprite_load(L"./Data/images/仮3.png");
        Buck[3] = sprite_load(L"./Data/images/仮4.png");
        game_state++;
        /*fallthrough*/

    case 1:
        //////// パラメータの設定 ////////

        GameLib::setBlendMode(Blender::BS_ALPHA);

        





        game_state++;
        /*fallthrough*/

    case 2:
        //////// 通常時 ////////
        //デバッグ用
        debug::setString("game_state:%d", game_state);
        debug::setString("game_timer:%d", game_timer);
        debug::setString("");
        debug::setString("ENTER:PAUSE");

        if (TRG(0) & PAD_SELECT)
        {
            nextScene = SCENE_SCORE;
            break;
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

   
    sprite_render(Buck[0],
        1920/2, 1080/2,
        1, 1,
        0, 0,
        1920, 1080,
        1920 / 2, 1080 / 2);

    sprite_render(Buck[1],
        1920/2, 1080/2,
        1, 1,
        0, 0,
        1920, 1080,
        1920 / 2, 1080 / 2);

    sprite_render(Buck[2],
        1920/2, 1080/2,
        1, 1,
        0, 0,
        1920, 1080,
        1920 / 2, 1080 / 2);
    
    sprite_render(Buck[3],
        1920/2, 1080/2,
        1, 1,
        0, 0,
        1920, 1080,
        1920 / 2, 1080 / 2);

    //ポーズ中
    if (isPaused)    font::textOut(
        3,
        "PAUSE",
        CENTER,
        { 3,3 },
        { 0,0,0,1 },
        TEXT_ALIGN::MIDDLE
    );

}
