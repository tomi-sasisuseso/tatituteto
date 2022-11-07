#include "all.h"

int score_state;
int score_timer;

bool showRanking;
int scorePanel_easeTimer = 100;

OBJ2D scorePanel;

int text_easeTimer;
float text_alpha;

void score_init() {
    score_state = 0;
    score_timer = 0;

    showRanking = false;
    scorePanel_easeTimer = INT_MAX;
    text_easeTimer = INT_MAX;
    text_alpha = 0;

    texture::load(TEXTURE_SCOREPANEL, L"./Data/Images/score_panel.png");
}

void score_deinit() {
    score_state = 0;
    score_timer = 0;
}

void score_update() {
    //デバッグ用
    debug::setString("score_state:%d", score_state);
    debug::setString("score_timer:%d", score_timer);
    debug::setString("panel.pos.x: %f", scorePanel.pos.x);

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

        scorePanel.pos = { -600, SCREEN_H / 2 };
        scorePanel.scale = { 1, 1 };
        scorePanel.texSize = { 600, 720 };

        score_state++;
        /*fallthrough*/

    case 2:
        //////// 通常時 ////////

        if (TRG(0) & PAD_START)
        {
            nextScene = SCENE_TITLE;
            break;
        }

        //スコアの背景を移動
        if (score_timer == 10 || TRG(0) & PAD_TRG1)      scorePanel_easeTimer = 0;
        const float duration = 40;
        if (scorePanel_easeTimer < duration)
        {
            scorePanel_easeTimer++;
            float t = (float)scorePanel_easeTimer / duration;
            scorePanel.pos.x = Easing::step(eType::ELASTIC_INOUT, 1920, SCREEN_W / 2, t);
            //scorePanel.pos.x = SCREEN_W - SCREEN_W / 2 * Easing::linear(t);
        }

        //ランキングを表示（仮）
        if (score_timer == 60)
        {
            text_easeTimer = 0;
            showRanking = !showRanking;
        }

        break;
    }
    score_timer++;
}

void score_render() 
{
    GameLib::clear(0.2f, 0.7f, 0.0f);

    texture::begin(TEXTURE_SCOREPANEL);
    texture::draw(
        TEXTURE_SCOREPANEL,
        scorePanel.pos,
        scorePanel.scale,
        { 0, 0 },
        scorePanel.texSize,
        scorePanel.texSize / 2,
        0
    );
    texture::end(TEXTURE_SCOREPANEL);

    if (showRanking)
    {
        text_render();
    }
}

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
}