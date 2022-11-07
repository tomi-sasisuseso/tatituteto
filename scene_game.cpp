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


int scroll_timer;
int bgmNo;

Sprite* Back[MAX_GAMES];
Sprite* Ball;
OBJ2D back[MAX_GAMES];
OBJ2D ball;

//--------------------------------------
//  初期設定
//--------------------------------------
void game_init()
{
    game_state = 0;
    game_timer = 0;
    scroll_timer = 100;
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
<<<<<<< HEAD
        Back[0] = sprite_load(L"./Data/Images/背景2.png");
        Back[1] = sprite_load(L"./Data/Images/仮1.png");
        Back[2] = sprite_load(L"./Data/Images/仮3.png");
        //Back[3] = sprite_load(L"Data/Images/背景1.png");
        Ball = sprite_load(L"./Data/Images/ボール_右.png");
=======

        Back[0] = sprite_load(L"Data/Images/背景2.png");
        Back[1] = sprite_load(L"Data/Images/仮1.png");
        Back[2] = sprite_load(L"Data/Images/仮3.png");
        //Back[3] = sprite_load(L"Data/images/背景1.png");
        Ball = sprite_load(L"Data/images/ボール_右.png");
>>>>>>> 648788432114e43e25373147bd9ea4406e5cc164

        game_state++;
        /*fallthrough*/

    case 1:
        //////// パラメータの設定 ////////

        GameLib::setBlendMode(Blender::BS_ALPHA);

        back[0].texSize = { 1280,540 };
        back[0].pivot = { 0,0 };
        back[0].pos = { 0,0};
        back[0].scale = { 2, 2 };

        //back[0].pos = { 1920 / 2, 1080 / 2 };
        //back[0].pivot = { 640/2,460/2 };

        back[1].texSize = { 1920, 1080 };
        back[1].pivot = { 0,0 };
        back[1].pos = { SCREEN_W,0 };
<<<<<<< HEAD
=======
        back[1].scale = { 1,1 };
        
        //back[1].pivot = { 960 / 2, 1080 / 2 };
        //back[1].pos = { 1920 + back[1].pivot.x, 1080 / 2 };
>>>>>>> 648788432114e43e25373147bd9ea4406e5cc164
        
        back[2].texSize = { 1920, 1080 };
        back[2].pivot = { 1920 / 2, 1080 / 2 };
        back[2].pos = { 1920 / 2, 1080+back[2].pivot.y  };
        

        back[3].texSize = { 1920, 1080 };
        back[3].pivot = { 1920 / 2, 1080 / 2 };
        back[3].pos = { 1920 / 2, 1080 / 2 };

        ball.pos = { SCREEN_W / 3,SCREEN_H - 310 };
        ball.texPos = { 0,0 };
        ball.texSize = { 150,150 };


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


        back_update();
        break;
    }

    game_timer++;
}

void back_update() {
    //back[0].pos.x -= 2;
    //if (back[1].pos.x >= SCREEN_W / 2) {
    //    if (game_timer > 200) {
    //        //back[0].pos.x -= 5;
    //        back[1].pos.x -= 5;
    //    }

    //}


    if (game_timer == 200) scroll_timer = 0;

    const float duration = 60;
    if (scroll_timer < duration)
    {
        scroll_timer++;
        float t = (float)scroll_timer / duration;
        back[1].pos.x = Easing::step(eType::BACK_OUT, SCREEN_W, SCREEN_W / 2, t);
    }

    if (back[0].scale.x >= 1) {
        if (game_timer > 500) {
            back[0].scale.x *= 0.99;
            back[0].scale.y *= 0.99;
            back[1].scale.x *= 0.99;
            back[1].scale.y *= 0.99;
        }
    }
}

//--------------------------------------
//  描画処理
//--------------------------------------

void game_render()
{
<<<<<<< HEAD
    GameLib::clear(1,1,1);
=======

    GameLib::clear(0.2f, 0.2f, 0.4f);
>>>>>>> 648788432114e43e25373147bd9ea4406e5cc164
   
    sprite_render(Back[0],
        back[0].pos.x, back[0].pos.y,
        back[0].scale.x,back[0].scale.y,
        0, 0,
        back[0].texSize.x, back[0].texSize.y,
        back[0].pivot.x, back[0].pivot.y);

    sprite_render(Back[1],
        back[1].pos.x, back[1].pos.y,
        back[1].scale.x, back[1].scale.y,
        0, 0,
        back[1].texSize.x, back[1].texSize.y,
        back[1].pivot.x, back[1].pivot.y);

<<<<<<< HEAD
    ball_render();
=======
    /*sprite_render(Back[0],
        back[2].pos.x, back[2].pos.y,
        1, 1,
        0, 0,
        back[2].texSize.x, back[2].texSize.y,
        back[2].pivot.x, back[2].pivot.y);
    
    sprite_render(Back[2],
        back[3].pos.x, back[3].pos.y,
        1, 1,
        0, 0,
        back[3].texSize.x, back[3].texSize.y,
        back[3].pivot.x, back[3].pivot.y);*/

    //ball_render();
>>>>>>> 648788432114e43e25373147bd9ea4406e5cc164

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

void ball_render() {
    sprite_render(Ball, ball.pos.x, ball.pos.y,
        1, 1,
        ball.texPos.x, ball.texPos.x,
        ball.texSize.x, ball.texSize.y,
        0, 0);
}