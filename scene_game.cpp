//******************************************************************************
//
//
//      scene_game
//
//
//******************************************************************************

//----< �C���N���[�h >-----------------------------------------------------------
#include "all.h"

//------< �萔 >----------------------------------------------------------------


//------< �ϐ� >----------------------------------------------------------------
int game_state;
int game_timer;

bool isPaused;

int bgmNo;

Sprite* Buck[MAX_GAMES];


//--------------------------------------
//  �����ݒ�
//--------------------------------------
void game_init()
{
    game_state = 0;
    game_timer = 0;

    isPaused = false;
}

//--------------------------------------
//  �I������
//--------------------------------------
void game_deinit()
{
    
}

//--------------------------------------
//  �X�V����
//--------------------------------------
void game_update()
{

    debug::setString("game_state:%d", game_state);
    debug::setString("game_timer:%d", game_timer);

    switch (game_state)
    {
    case 0:
        //////// �����ݒ� ////////
        Buck[0] = sprite_load(L"Data/images/��1.png");
        Buck[1] = sprite_load(L"Data/images/��2.png");
        Buck[2] = sprite_load(L"Data/images/���R.png");
        Buck[3] = sprite_load(L"Data/images/��4.png");
        game_state++;
        /*fallthrough*/

    case 1:
        //////// �p�����[�^�̐ݒ� ////////

        GameLib::setBlendMode(Blender::BS_ALPHA);

        





        game_state++;
        /*fallthrough*/

    case 2:
        //////// �ʏ펞 ////////

        //�f�o�b�O
        debug::setString("game_timer: %d", game_timer);


        if (TRG(0) & PAD_SELECT)
        {
            nextScene = SCENE_SCORE;
            break;
        }
        //�|�[�Y���Ȃ炱���Ń��^�[��
        if (isPaused)    return;
        

        break;
    }

    game_timer++;
}

//--------------------------------------
//  �`�揈��
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

}
