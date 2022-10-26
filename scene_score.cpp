#include "all.h"

int score_state;
int score_timer;

void score_init() {
    score_state = 0;
    score_timer = 0;
}

void score_deinit() {
    score_state = 0;
    score_timer = 0;
}

void score_update() {
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

        if (TRG(0) & PAD_START)
        {
            nextScene = SCENE_TITLE;
            break;
        }

        break;
    }
}

void score_render() {
    GameLib::clear(0.2f, 0.7f, 0.0f);
}