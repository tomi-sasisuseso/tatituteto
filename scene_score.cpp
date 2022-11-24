#include "all.h"

int score_state;
int score_timer;

const float EASE_DURATION = 8;

extern int score;
int number_of_digits;
int digits[] = {0, 0, 0, 0, 0, 0};

float score_numalpha = 0.0f;
float score_alpha_overall;
bool isend = false;
int score_select = true;
VECTOR2 continue_pos_def;
VECTOR2 continue_pos;
VECTOR2 giveup_pos_def;
VECTOR2 giveup_pos;
VECTOR2 continue_scale;
VECTOR2 giveup_scale;
int easeTimer = INT_MAX;

Sprite* score_background_sprite;
Sprite* score_str_sprite;
Sprite* score_number_sprite;
Sprite* score_continue_1;
Sprite* score_continue_2;
Sprite* score_giveup_1;
Sprite* score_giveup_2;

void score_init() {
    score_state = 0;
    score_timer = 0;
    //画面のフェードアウトをリセット
    score_alpha_overall = 0.0f;
    isend = false;
    //桁数を計算
    number_of_digits = countDigits(score);
    //桁数のそれぞれの数字を取得
    for (int i = 0; i < number_of_digits; i++)
    {
        digits[i] = getDigits(score, number_of_digits - (i + 1), number_of_digits - (i + 1));
    }
    //スプライトをロード
    score_background_sprite = sprite_load(L"./Data/Images/GAMEOVER.png");
    score_str_sprite = sprite_load(L"./Data/Images/SCORE.png");
    score_number_sprite = sprite_load(L"./Data/Images/number.png");
    score_continue_1 = sprite_load(L"./Data/Images/CONTINUE_1.png");
    score_continue_2 = sprite_load(L"./Data/Images/CONTINUE_2.png");
    score_giveup_1 = sprite_load(L"./Data/Images/GIVEUP_1.png");
    score_giveup_2 = sprite_load(L"./Data/Images/GIVEUP_2.png");
}

void score_deinit() {
    score_state = 0;
    score_timer = 0;
    //スプライトのメモリ開放
    safe_delete(score_background_sprite);
    safe_delete(score_str_sprite);
    safe_delete(score_number_sprite);
    safe_delete(score_continue_1);
    safe_delete(score_continue_2);
    safe_delete(score_giveup_1);
    safe_delete(score_giveup_2);
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
        continue_pos_def = continue_pos = { 600, 800 };
        giveup_pos_def = giveup_pos = { 1350, 800 };
        continue_scale = { 1, 1 };
        giveup_scale = { 1, 1 };

        score_state++;
        /*fallthrough*/

    case 2:
        //////// 通常時 ////////

        //入力の検知
        if (TRG(0) & PAD_START)   isend = true;
        //透明度を下げる
        if (isend)    score_alpha_overall += 0.02;
        //数字の透明度
        score_numalpha = abs(cosf(score_timer * 0.1f));
        //選択の切り替え
        if (TRG(0) & PAD_LEFT)
        {
            score_select = true;
            easeTimer = 0;
        }
        if (TRG(0) & PAD_RIGHT)
        {
            score_select = false;
            easeTimer = 0;
        }
        //コンティニュー
        if (score_select && score_alpha_overall > 1.5f)     nextScene = SCENE_GAME;
        //ギブアップ
        if (!score_select && score_alpha_overall > 1.5f)    nextScene = SCENE_TITLE;

        //文字をバウンドさせる
        if (easeTimer < EASE_DURATION)
        {
            easeTimer++;
            float t = (float)easeTimer / EASE_DURATION;
            if (score_select)
            {
                continue_pos.y = Easing::step(eType::SMOOTHER_STEP_INOUT, continue_pos_def.y - 20, continue_pos_def.y, t);
                continue_scale.x = Easing::step(eType::SMOOTHER_STEP_INOUT, 1.3f, 1.0f, t);
                continue_scale.y = Easing::step(eType::SMOOTHER_STEP_INOUT, 1.1f, 1.0f, t);
            }
            else
            {
                giveup_pos.y = Easing::step(eType::SMOOTHER_STEP_INOUT, giveup_pos_def.y - 20, giveup_pos_def.y, t);
                giveup_scale.x = Easing::step(eType::SMOOTHER_STEP_INOUT, 1.3f, 1.0f, t);
                giveup_scale.y = Easing::step(eType::SMOOTHER_STEP_INOUT, 1.1f, 1.0f, t);
            }
        }

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
        SCREEN_W / 2, SCREEN_H / 2,
        1, 1,
        0, 0,
        1500, 900,
        750, 450,
        0
    );
    //スコア
    sprite_render(
        score_str_sprite,
        800, 650,
        1, 1,
        0, 0,
        244, 63,
        122, 31.5f,
        0
    );
    //数字
    for (int i = 0; i < number_of_digits; i++)
    {
        sprite_render(
            score_number_sprite,
            1100 + (i * 50), 620,
            1, 1,
            digits[i] * 40, 0,
            40, 61,
            0, 0,
            0,
            1, 1, 1, score_numalpha
        );
    }
    //リトライ、ギブアップの背景
    sprite_render(
        score_continue_2,
        continue_pos.x, continue_pos.y,
        continue_scale.x, continue_scale.y,
        0, 0,
        309, 49,
        309 * 0.5f, 49 * 0.5f,
        0
    );
    sprite_render(
        score_giveup_2,
        giveup_pos.x, giveup_pos.y,
        giveup_scale.x, giveup_scale.y,
        0, 0,
        309, 49,
        309 * 0.5f, 49 * 0.5f,
        0
    );
    if (score_select)
    {
        sprite_render(
            score_continue_1,
            continue_pos.x - 5, continue_pos.y - 5,
            continue_scale.x, continue_scale.y,
            0, 0,
            309, 49,
            309 * 0.5f, 49 * 0.5f,
            0
        );
    }
    else
    {
        sprite_render(
            score_giveup_1,
            giveup_pos.x - 5, giveup_pos.y - 5,
            giveup_scale.x, giveup_scale.y,
            0, 0,
            309, 49,
            309 * 0.5f, 49 * 0.5f,
            0
        );
    }
    //画面を暗転
    primitive::rect(
        { 0, 0 },
        { SCREEN_W, SCREEN_H },
        { 0, 0 },
        0,
        { 0.0f, 0.0f, 0.0f, score_alpha_overall }
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

