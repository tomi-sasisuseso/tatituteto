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
#define GAME2_CENTER buck[1].pos.x+buck[4].pos.x/2

//------< 変数 >----------------------------------------------------------------
int game_state;
int game_timer;

bool isPaused;

const float duration = 60;
int scroll_timer[MAX_GAMES];
float game2_center;

int bgmNo;

Sprite* Back[MAX_GAMES];
Sprite* Ball;
Sprite* Square;

OBJ2D back[MAX_GAMES];
OBJ2D ball;
Squares square[4];

SHOOTER shot;

extern const VECTOR2 square_offsets[4];

#define ball_error  0//ball.texSize.x/(2.0f/ball.scale.x)
//--------------------------------------
//  初期設定
//--------------------------------------
void game_init()
{
    game_state = 0;
    game_timer = 0;
    scroll_timer[0] = 50000;
    scroll_timer[1] = 50000;
    scroll_timer[2] = 50000;
    scroll_timer[3] = 50000;
    scroll_timer[4] = 50000;
    scroll_timer[5] = 50000;
    game2_center = 0;

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
        Back[0] = sprite_load(L"./Data/Images/背景2.png");
        Back[1] = sprite_load(L"./Data/Images/仮1.png");
        Back[2] = sprite_load(L"./Data/Images/仮14.png");
        Back[3] = sprite_load(L"Data/Images/仮4.png");
        Back[4] = sprite_load(L"Data/Images/仮8.png");
        Back[5] = sprite_load(L"Data/Images/仮10.png");

        Ball = sprite_load(L"./Data/Images/ボール_右.png");
        texture::load(0, L"Data/images/ゲーム2_四角.png", 4U);
        texture::load(1, L"Data/images/ゲーム2_弾.png", SHOT_MAX);

        game_state++;
        /*fallthrough*/

    case 1:
        //////// パラメータの設定 ////////

        GameLib::setBlendMode(Blender::BS_ALPHA);

        back[0].texSize = { 1280,540 };
        back[0].pivot = { 0,0 };
        back[0].pos = { 0,0 };
        back[0].scale = { 2, 2 };


        //back[0].pos = { 1920 / 2, 1080 / 2 };
        //back[0].pivot = { 640/2,460/2 };

        back[1].texSize = { 1920, 1080 };
        back[1].pivot = { 0,0 };
        back[1].pos = { SCREEN_W,0 };
        back[1].scale = { 1,1 };


        //back[1].pivot = { 960 / 2, 1080 / 2 };
        //back[1].pos = { 1920 + back[1].pivot.x, 1080 / 2 };

        back[2].texSize = { 1920, 540 };
        back[2].pivot = { 0,0 };
        back[2].pos = { 0,SCREEN_H };
        back[2].scale = { 1,1 };


        back[3].texSize = { 960, 540 };
        back[3].pivot = { 0,0 };
        back[3].pos = { SCREEN_W,SCREEN_H / 2 };
        back[3].scale = { 1,1 };


        back[4].texSize = { 640, 540 };
        back[4].pivot = { 0,0 };
        back[4].pos = { SCREEN_W,0 };
        back[4].scale = { 1,1 };


        back[5].texSize = { 640, 540 };
        back[5].pivot = { 0,0 };
        back[5].pos = { SCREEN_W,SCREEN_H / 2 };
        back[5].scale = { 1,1 };


        ball.texPos = { 0,0 };
        ball.texSize = { 150,150 };
        ball.pos = { SCREEN_W / 2 ,SCREEN_H / 2 };
        ball.pivot = { 150 / 2,150 / 2 };
        ball.scale = { 1,1 };

        square[0].pos_Init(SCREEN_W + 50, SCREEN_H / 2 - 150);
        square[1].pos_Init(SCREEN_W + 50, SCREEN_H / 2 - 50);
        square[2].pos_Init(SCREEN_W + 50, SCREEN_H / 2 + 50);
        square[3].pos_Init(SCREEN_W + 50, SCREEN_H / 2 + 150);

        square[0].scale_Init(1, 1);
        square[0].texP_Init(0, 0);
        square[0].texS_Init(100, 100);
        square[0].pivot_Init(100 / 2, 100 / 2);


        game_state++;
        /*fallthrough*/

    case 2:
        //////// 通常時 ////////
        //デバッグ用
        debug::setString("game_state:%d", game_state);
        debug::setString("game_timer:%d", game_timer);
        debug::setString("");
        debug::setString("ENTER:PAUSE");
        debug::setString("ball.scale:%f", ball.scale.x);
        debug::setString("back[0].pos.x:%f", back[0].pos.x);
        debug::setString("back[0].pos.y:%f", back[0].pos.y);
        debug::setString("back[2].pos.y:%f", back[2].pos.y);
        debug::setString("back[3].pos.x:%f", back[3].pos.x);

        debug::setString("bullet_timer:%d", shot.bullet_timer);
        debug::setString("shot.spwaonFlag:%d", shot.spwaonFlag);
        debug::setString("game2_center:%f", game2_center);

        if (TRG(0) & PAD_SELECT)
        {
            nextScene = SCENE_SCORE;
            break;
        }

        VECTOR2 shot_pos[2] = { back[1].pos , back[4].pos };
        float height = back[1].texSize.y * back[1].scale.y; // tex_size.y * scale
        game2_center = (back[1].pos.x + back[4].pos.x) / 2;

        shot.Update();
        shot.Shot(shot_pos[rand() % 2], height, rand() % 3);// 出現位置を決めてそのまま発射してる
        

        back_update();
        break;
    }

    game_timer++;
    shot.bullet_timer++;
}

void back_update() {
    //back[0].pos.x -= 2;
    //if (back[1].pos.x >= SCREEN_W / 2) {
    //    if (game_timer > 200) {
    //        //back[0].pos.x -= 5;
    //        back[1].pos.x -= 5;
    //    }

    //}


    /////// 1回目のスライド処理 ///////
    if (game_timer == 200) scroll_timer[0] = 0;
    if (scroll_timer[0] < duration)
    {
        scroll_timer[0]++;
        float t = (float)scroll_timer[0] / duration;
        back[0].pos.x = Easing::step(eType::SMOOTHER_STEP_OUT, 0, -SCREEN_W / 3, t);
        back[1].pos.x = Easing::step(eType::SMOOTHER_STEP_OUT, SCREEN_W, SCREEN_W / 2, t);

        if (ball.pos.x > SCREEN_W / 4) ball.pos.x -= 16;
        else ball.pos.x = SCREEN_W / 4;
        if (square[0].a.pos.x > SCREEN_W - SCREEN_W / 4) {
            square[0].a.pos.x -= 16;
            square[1].a.pos.x -= 16;
            square[2].a.pos.x -= 16;
            square[3].a.pos.x -= 16;
        }
        else {
            square[0].a.pos.x = SCREEN_W - SCREEN_W / 4;
            square[1].a.pos.x = SCREEN_W - SCREEN_W / 4;
            square[2].a.pos.x = SCREEN_W - SCREEN_W / 4;
            square[3].a.pos.x = SCREEN_W - SCREEN_W / 4;
        }
    }

    /////// 2回目のスライド処理 ///////
    if (game_timer == 400) scroll_timer[1] = 0;
    if (back[0].scale.x >= 1) {
        if (game_timer > 400) {
            back[0].scale.x *= 0.99;
            back[0].scale.y *= 0.99;
            back[1].scale.x *= 0.99;
            back[1].scale.y *= 0.99;

            ball.scale.x *= 0.99;
            ball.scale.y *= 0.99;
            ball.pos.y -= 4;

            shot.game2_shrink();

            if (scroll_timer[1] < duration)
            {
                scroll_timer[1]++;
                float t = (float)scroll_timer[1] / duration;
                back[0].pos.x = Easing::step(eType::SMOOTHER_STEP_OUT, -SCREEN_W/3, 0, t);
                back[2].pos.y = Easing::step(eType::SMOOTHER_STEP_OUT, SCREEN_H, SCREEN_H/2, t);
            }

            //back[2].pos = { 0,back[0].texSize.y * back[0].scale.y };
        }
    }

    /////// 3回目のスライド処理 ///////
    if (game_timer == 600) scroll_timer[2] = 0;
    if (scroll_timer[2] < duration) {
        scroll_timer[2]++;
        float t = (float)scroll_timer[2] / duration;
        back[3].pos.x = Easing::step(eType::SMOOTHER_STEP_OUT, SCREEN_W, SCREEN_W / 2, t);
    }

    /////// 4回目のスライド処理 ///////
    if (game_timer == 800)scroll_timer[3] = 0;
    if (scroll_timer[3] < duration) {
        scroll_timer[3]++;
        float t = (float)scroll_timer[3] / duration;
        back[0].pos.x = Easing::step(eType::SMOOTHER_STEP_OUT, 0, -SCREEN_W / 6, t);
        back[1].pos.x = Easing::step(eType::SMOOTHER_STEP_OUT, SCREEN_W/2, SCREEN_W / 2-SCREEN_W/6, t);
        back[4].pos.x = Easing::step(eType::SMOOTHER_STEP_OUT, SCREEN_W, SCREEN_W - SCREEN_W / 3, t);

        if (ball.pos.x > SCREEN_W / 6 ) ball.pos.x -= 8;
        else ball.pos.x = SCREEN_W / 6 ;

    }

    /////// 5回目のスライド処理 ///////
    if (game_timer == 1000)scroll_timer[4] = 0;
    if (scroll_timer[4] < duration) {
        scroll_timer[4]++;
        float t = (float)scroll_timer[4] / duration;
        back[2].pos.x = Easing::step(eType::SMOOTHER_STEP_OUT, 0, -SCREEN_W / 6, t);
        back[3].pos.x = Easing::step(eType::SMOOTHER_STEP_OUT, SCREEN_W/2, SCREEN_W / 2 - SCREEN_W / 6, t);
        back[5].pos.x = Easing::step(eType::SMOOTHER_STEP_OUT, SCREEN_W, SCREEN_W - SCREEN_W / 3, t);

    }
}

//--------------------------------------
//  描画処理
//--------------------------------------

void game_render()
{

    GameLib::clear(1,1,1);


    GameLib::clear(0.2f, 0.2f, 0.4f);

    sprite_render(Back[0],
        back[0].pos.x, back[0].pos.y,
        back[0].scale.x,back[0].scale.y,
        0, 0,
        back[0].texSize.x, back[0].texSize.y,
        back[0].pivot.x, back[0].pivot.y);

    ball_render();


    sprite_render(Back[1],
        back[1].pos.x, back[1].pos.y,
        back[1].scale.x, back[1].scale.y,
        0, 0,
        back[1].texSize.x, back[1].texSize.y,
        back[1].pivot.x, back[1].pivot.y);

    square_render();

    shot.shot_render();

    sprite_render(Back[2],
        back[2].pos.x, back[2].pos.y,
        back[2].scale.x, back[2].scale.y,
        0, 0,
        back[2].texSize.x, back[2].texSize.y,
        back[2].pivot.x, back[2].pivot.y);
    

    sprite_render(Back[3],
        back[3].pos.x, back[3].pos.y,
        back[3].scale.x, back[3].scale.y,
        0, 0,
        back[3].texSize.x, back[3].texSize.y,
        back[3].pivot.x, back[3].pivot.y);
    
    
    sprite_render(Back[4],
        back[4].pos.x, back[4].pos.y,
        back[4].scale.x, back[4].scale.y,
        0, 0,
        back[4].texSize.x, back[4].texSize.y,
        back[4].pivot.x, back[4].pivot.y);
    
    
    sprite_render(Back[5],
        back[5].pos.x, back[5].pos.y,
        back[5].scale.x, back[5].scale.y,
        0, 0,
        back[5].texSize.x, back[5].texSize.y,
        back[5].pivot.x, back[5].pivot.y);


    //ball_render();

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
        ball.scale.x, ball.scale.y,
        ball.texPos.x, ball.texPos.x,
        ball.texSize.x, ball.texSize.y,
        ball.pivot.x, ball.pivot.y);
}

void square_render() {
    texture::begin(0);
    texture::draw(0,
        square[0].getPos(),
        square[0].getScale(),
        square[0].getTexP(),
        square[0].getTexS(),
        square[0].getPivot()
    ); 
    texture::draw(0,
        square[1].getPos(),
        square[0].getScale(),
        square[0].getTexP(),
        square[0].getTexS(),
        square[0].getPivot()
    ); 
    texture::draw(0,
        square[2].getPos(),
        square[0].getScale(),
        square[0].getTexP(),
        square[0].getTexS(),
        square[0].getPivot()
    );
    texture::draw(0,
        square[3].getPos(),
        square[0].getScale(),
        square[0].getTexP(),
        square[0].getTexS(),
        square[0].getPivot()
    );
    texture::end(0);
}
