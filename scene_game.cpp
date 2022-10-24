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

        game_state++;
        /*fallthrough*/

    case 1:
        //////// �p�����[�^�̐ݒ� ////////

        GameLib::setBlendMode(Blender::BS_ALPHA);

        bgmNo = 0;

        game_state++;
        /*fallthrough*/

    case 2:
        //////// �ʏ펞 ////////
        //�f�o�b�O
        debug::setString("game_timer: %d", game_timer);

        if (TRG(0) & PAD_SELECT)

        //�f�o�b�O
        debug::setString("game_timer: %d", game_timer);


        if (TRG(0) & PAD_START)
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
}
