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
    //�f�o�b�O�p
    debug::setString("score_state:%d", score_state);
    debug::setString("score_timer:%d", score_timer);

    switch (score_state)
    {
    case 0:
        //////// �����ݒ� ////////
        score_state++;

        /*fallthrough*/

    case 1:
        //////// �p�����[�^�̐ݒ� ////////
        GameLib::setBlendMode(Blender::BS_ALPHA);
        music::play(0, FALSE);


        score_state++;
        /*fallthrough*/

    case 2:
        //////// �ʏ펞 ////////

        //���͂̌��m
        if (TRG(0) & PAD_START)   isend = true;
        //�����x��������
        if (isend)    score_alpha += 0.02;
        //�����x�ɉ����Ď��̃V�[����
        if (score_alpha > 1.5f)     nextScene = SCENE_TITLE;

        break;
    }
    score_timer++;
}

void score_render() 
{
    //GameLib::clear(0.2f, 0.7f, 0.0f);
    //�w�i
    sprite_render(
        score_background_sprite,
        0, 0,
        1, 1,
        0, 0,
        SCREEN_W, SCREEN_H,
        0, 0,
        0
    );
    //����
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

//�����L���O�̕\���p�i�Q�l�j
#if 0
//�e�L�X�g��\��
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
        //���̃A���t�@�x�b�g��ݒ�
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

        //�����L���O��\��
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
