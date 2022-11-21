#include "all.h"

int score_state;
int score_timer;

float score_alpha;
bool isend;

Sprite* score_background_sprite;
Sprite* score_number_sprite;

void score_init() {
    score_state = 0;
    score_timer = 0;

    score_alpha = 0.0f;
    isend = false;

    score_background_sprite = sprite_load(L"./Data/Images/GAMEOVER.png");
    score_number_sprite = sprite_load(L"./Data/Images/number.png");
}

void score_deinit() {
    score_state = 0;
    score_timer = 0;
}

void score_update() {
    //デバッグ用
    debug::setString("score_state:%d", score_state);
    debug::setString("score_timer:%d", score_timer);

    switch (score_state)
    {
    case 0:
        //////// 初期設定 ////////
        score_state++;

        /*fallthrough*/

    case 1:
        //////// パラメータの設定 ////////
        GameLib::setBlendMode(Blender::BS_ALPHA);
        music::play(0, FALSE);


        score_state++;
        /*fallthrough*/

    case 2:
        //////// 通常時 ////////

        //入力の検知
        if (TRG(0) & PAD_START)   isend = true;
        //透明度を下げる
        if (isend)    score_alpha += 0.02;
        //透明度に応じて次のシーンに
        if (score_alpha > 1.5f)     nextScene = SCENE_TITLE;

        break;
    }
    score_timer++;
}

void score_render() 
{
    //GameLib::clear(0.2f, 0.7f, 0.0f);
    //背景
    sprite_render(
        score_background_sprite,
        0, 0,
        1, 1,
        0, 0,
        SCREEN_W, SCREEN_H,
        0, 0,
        0
    );
    //文字
    for (int i = 0; i < 6; i++)
    {
        sprite_render(
            score_number_sprite,
            SCREEN_W / 2 + (i * 100), 100,
            1, 1,
            40, 0,
            40, 61,
            0, 0,
            0
        );
    }

    primitive::rect(
        { 0, 0 },
        { SCREEN_W, SCREEN_H },
        { 0, 0 },
        0,
        { 0.0f, 0.0f, 0.0f, score_alpha }
    );
}

//ランキングの表示用（参考）
#if 0
//テキストを表示
void text_render()
{
    const VECTOR2 base_pos = { SCREEN_W / 2 - 230, SCREEN_H / 2 - 150 };
    const float betweenLines = 95;
    const float show_duration = 30;

    if (text_easeTimer < show_duration)
    {
        text_easeTimer++;
        float t = (float)text_easeTimer / show_duration;
        text_alpha = Easing::step(eType::LINEAR, 0, 1, t);
    }

    for (int i = 0; i < 5; i++)
    {
        std::string r;
        //後ろのアルファベットを設定
        switch (i)
        {
        case 0:
            r = "st";
            break;
        case 1:
            r = "nd";
            break;
        case 2:
            r = "rd";
            break;
        case 3:
            r = "th";
            break;
        case 4:
            r = "th";
            break;
        }

        //ランキングを表示
        font::textOut(
            3,
            std::to_string(i + 1) + r,
            { base_pos.x, base_pos.y + (i * betweenLines) },
            { 3, 3 },
            { 1, 1, 1, text_alpha },
            TEXT_ALIGN::UPPER_LEFT,
            false
        );
    }
<<<<<<< HEAD
}
#endif
=======

}

>>>>>>> tomy
