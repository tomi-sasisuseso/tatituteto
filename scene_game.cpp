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
#define GAME2_CENTER buck[1].pos.x+buck[4].pos.x/2

//------< �ϐ� >----------------------------------------------------------------
int game_state;
int game_timer;
int score;

const int scroll_time[MAX_GAMES - 1] = {
    100, 200, 300, 400, 500
};

int tutrial_easeTimer = INT_MAX;
const float TUTRIAL_EASEDURATION = 20;
VECTOR2 tutrial_pos_start;
VECTOR2 tutrial_pos_end;
VECTOR2 tutrial_pos;
int tutrial_counter;

bool isPaused;
bool tutorial;
bool missed_game[6];

bool scroll_Frag[6];

const float duration = 60;
int scroll_timer[MAX_GAMES];
int timer[MAX_GAMES];
int number_of_games;
float game2_center;
float game_volume;

float back_slide;

int finish_timer = 0;

Sprite* Back[MAX_GAMES];
Sprite* GameOver[5];
Sprite* Between[5];
Sprite* tutrial_sprite[6];

Sprite* Ball;
Sprite* Square;
Sprite* Frame;


Sprite* Game4_beruto;
Sprite* Game4_box;
Sprite* Game4_hole;

OBJ2D back[MAX_GAMES];
OBJ2D between[MAX_GAMES];

//OBJ2D ball;

Squares square(SCREEN_W + 50, SCREEN_H / 2 );
SHOOTER shot;
extern const VECTOR2 square_offsets[4];

Game1_Manager game1_manager;
Game3_Manager game3_manager;
Game4_Manager game4_manager;
Game5_Manager game5_manager;
Game6_Manager game6_manager;

/*
* ��{scene_game.cpp�ł̃N���X�̌Ăяo���̓����o�֐��̂�
* ���̏ꍇ SHOOTER�N���X �� shot �̂悤�ȑg�ݕ��B
* Squares�N���X�� square �͂��܂肫�ꂢ�Ȍ`�ł͂Ȃ��B(�r���ŃN���X�̑g�ݕ��ɕύX��������);
*/

#define ball_error  0//ball.texSize.x/(2.0f/ball.scale.x)
//--------------------------------------
//  �����ݒ�
//--------------------------------------
void game_init()
{
    game_state = 0;
    game_timer = 0;
    number_of_games = 1;
    finish_timer = 0;
    game_volume = 1.0f;
    back_slide = 0;
    scroll_timer[0] = 50000;
    scroll_timer[1] = 50000;
    scroll_timer[2] = 50000;
    scroll_timer[3] = 50000;
    scroll_timer[4] = 50000;
    scroll_timer[5] = 50000;
    game2_center = 0;
    square.square_init();
    square.frame_init();
    shot.bullet_init();

    game1_manager.Game1_Manager_init();
    game4_manager.Game4_Manager_init();
    game5_manager.Game5_Manager_init();
    game6_manager.Game6_Manager_init();

    isPaused = false;


}

//--------------------------------------
//  �I������
//--------------------------------------
void game_deinit()
{
    music::stop(1);

    game1_manager.Game1_Manager_deinit();
    game3_manager.Game3_Manager_deinit();
    game5_manager.Game5_Manager_deinit();
    game6_manager.Game6_Manager_deinit();
}

//--------------------------------------
//  �X�V����
//--------------------------------------
void game_update()
{
    //�Q�[�����|�[�Y
    if (TRG(0) & PAD_START&& !tutorial)
        isPaused = !isPaused;       // 0�R���̃X�^�[�g�{�^���������ꂽ��|�[�Y��Ԃ����]
    if (tutorial && TRG(0) & PAD_START)
    {
        tutorial = false;
        tutrial_pos = tutrial_pos_start;
    }
    if (isPaused||tutorial) 
        return;           // ���̎��_�Ń|�[�Y���Ȃ烊�^�[��

    switch (game_state)
    {
    case 0:
        //////// �����ݒ� ////////

        /*Back[0] = sprite_load(L"./Data/Images/�w�i2.png");
        Back[1] = sprite_load(L"./Data/Images/��1.png");
        Back[2] = sprite_load(L"./Data/Images/�Q�[��4_�w�i.png");
        Back[3] = sprite_load(L"Data/Images/�Q�[��5_�w�i.png");
        Back[4] = sprite_load(L"Data/Images/��8.png");
        Back[5] = sprite_load(L"Data/Images/��10.png");

        Square = sprite_load(L"./Data/images/�Q�[��2_�l�p.png");
        Frame = sprite_load(L"./Data/images/�Q�[��2_�g.png");
        Ball = sprite_load(L"./Data/Images/�{�[��_�E.png");
        texture::load(1, L"Data/images/�Q�[��2_�e.png", SHOT_MAX);

        Game4_box = sprite_load(L"./Data/Images/�Q�[��5_�l�p.png");
        Game4_hole = sprite_load(L"./Data/Images/�Q�[��5_��.png");
        Game4_beruto = sprite_load(L"Data/Images/�Q�[��5_�x���g�R���x�A.png");*/

        Back[0] = sprite_load(L"./Data/Images/�Q�[��1_�w�i.png");
        Back[1] = sprite_load(L"./Data/Images/�Q�[��2_�w�i.png");
        Back[2] = sprite_load(L"./Data/Images/�Q�[��4_�w�i.png");
        Back[3] = sprite_load(L"Data/Images/�Q�[��5_�w�i.png");
        Back[4] = sprite_load(L"Data/Images/�Q�[��3_�w�i.png");
        Back[5] = sprite_load(L"Data/Images/�Q�[��6_�w�i.png");

        GameOver[0] = sprite_load(L"./Data/Images/1.png");
        GameOver[1] = sprite_load(L"./Data/Images/2.png");
        GameOver[2] = sprite_load(L"./Data/Images/3.png");
        GameOver[3] = sprite_load(L"./Data/Images/4.png");
        GameOver[4] = sprite_load(L"./Data/Images/5.png");

        Between[0] = sprite_load(L"./Data/Images/��1.png");
        Between[1] = sprite_load(L"./Data/Images/��2.png");
        Between[2] = sprite_load(L"./Data/Images/��3.png");
        Between[3] = sprite_load(L"./Data/Images/��4.png");
        Between[4] = sprite_load(L"./Data/Images/��5.png");
        Between[5] = sprite_load(L"./Data/Images/��6.png");

        tutrial_sprite[0] = sprite_load(L"./Data/Images/�`���[�g���A��_1.png");
        tutrial_sprite[1] = sprite_load(L"./Data/Images/�`���[�g���A��_2.png");
        tutrial_sprite[2] = sprite_load(L"./Data/Images/�`���[�g���A��_3.png");
        tutrial_sprite[3] = sprite_load(L"./Data/Images/�`���[�g���A��_4.png");
        tutrial_sprite[4] = sprite_load(L"./Data/Images/�`���[�g���A��_5.png");
        tutrial_sprite[5] = sprite_load(L"./Data/Images/�`���[�g���A��_6.png");

        Ball = sprite_load(L"./Data/Images/�Q�[��1_�{�[��.png");

        Square = sprite_load(L"./Data/Images/�Q�[��2_�l�p.png");
        Frame = sprite_load(L"./Data/Images/�Q�[��2_�g.png");
        texture::load(1, L"Data/Images/�Q�[��2_�e.png", SHOT_MAX);

        Game4_box = sprite_load(L"./Data/Images/�Q�[��5_�l�p.png");
        Game4_hole = sprite_load(L"./Data/Images/�Q�[��5_��.png");
        Game4_beruto = sprite_load(L"Data/Images/�Q�[��5_�x���g�R���x�A.png");

        game_state++;
        /*fallthrough*/

    case 1:
        //////// �p�����[�^�̐ݒ� ////////

        GameLib::setBlendMode(Blender::BS_ALPHA);
        music::play(1, true);

        back[0].texSize = { 1980, 1080 };//{ 1280,540 };
        back[0].pivot = { 0,0 };
        back[0].pos = { 0,0 };
        back[0].scale = { 2, 2 };

        back[1].pos = { SCREEN_W,0 };
        back[1].scale = { 1,1 };
        back[1].pivot = { 0,0 };
        back[1].texSize = { 1920, 1080 };

        /*between[1].pos = { SCREEN_W,0 };
        between[1].scale = { 1,1 };
        between[1].pivot = { 0,0 };
        between[1].texSize = { 1920, 1080 };*/

        //back[1].pivot = { 960 / 2, 1080 / 2 };
        //back[1].pos = { 1920 + back[1].pivot.x, 1080 / 2 };

        back[1].scale = { 1,1 };
        back[1].pivot = { 0,0 };
        back[1].texSize = { 1920, 1080 };
        
        back[2].texSize = { 1920, 1080 };
        back[2].pivot = { 1920 / 2, 1080 / 2 };
        back[2].pos = { 1920 / 2, 1080+back[2].pivot.y  };
        

        back[2].texSize = { 2000, 560 };
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

        


        /*Squares square(SCREEN_W + 50, SCREEN_H / 2 - 150);
          �Q�[�����[�v�̒��ŃN���X�̎��Ԑ錾�͂ł��Ȃ��H
          */

        square.square_init();
        square.frame_init();
        shot.bullet_init();

        game1_manager.Game1_Manager_init();
        game3_manager.Game3_Manager_init();
        game4_manager.Game4_Manager_init();
        game5_manager.Game5_Manager_init();
        game6_manager.Game6_Manager_init();

        tutrial_pos_start = { SCREEN_W / 2, -400 };
        tutrial_pos_end = CENTER;
        tutrial_pos = tutrial_pos_start;
        tutrial_counter = -1;
        //�~�X����̃��Z�b�g
        for (int i = 0; i < MAX_GAMES; i++)
        {
            missed_game[i] = false;
            scroll_Frag[i] = false;
        }

        game_state++;
        /*fallthrough*/

    case 2:
        //////// �ʏ펞 ////////
        //�f�o�b�O�p
#if 1
        debug::setString("game_state:%d", game_state);
        debug::setString("game_timer:%d", game_timer);
        debug::setString("");
        debug::setString("ENTER:PAUSE");
        //debug::setString("ball.scale:%f", ball.scale.x);
        debug::setString("back[0].pos.x:%f", back[0].pos.x);
        debug::setString("back[0].pos.y:%f", back[0].pos.y);
        debug::setString("back[2].pos.y:%f", back[2].pos.y);
        debug::setString("back[3].pos.x:%f", back[3].pos.x);

        debug::setString("bullet_timer:%d", shot.bullet_timer);
        debug::setString("shot.spwaonFlag:%d", shot.spawnFlag);
        debug::setString("game2_center:%f", game2_center);
        debug::setString("frame_Pos():%f", square.frame_getPos());
        debug::setString("frame_Scale():%f", square.frame_getScale());
        debug::setString("square.a.texSize.y :%f", square.square.texSize.y);
        debug::setString("square.a.scale.y :%f", square.square.scale.y);
        debug::setString("game4_manager.box_timer :%d", game4_manager.box_timer);
        debug::setString("game4_manager.spwanFlag :%d", game4_manager.spwanFlag);
        debug::setString("game4_manager.box.speed.y :%f", game4_manager.box.speed.y);
        debug::setString("game4_manager.box.pos.y :%f", game4_manager.box.pos.y);
        debug::setString("game4_manager.box.isLiving :%d", game4_manager.box.isLiving);
        debug::setString("game4_manager.fallCheck :%d", game4_manager.fallCheck);
        debug::setString("game5_manager.background.scale.x :%f", game5_manager.background.scale.x);
        debug::setString("game5_manager.ball3.pos.x :%f", game5_manager.ball3.pos.x);
        debug::setString("game5_manager.ball3.pos.y :%f", game5_manager.ball3.pos.y);
        debug::setString("back[1].pos.x :%f", back[1].pos.x);
        debug::setString("back[1].scale.x :%f", back[1].scale.x);
        debug::setString("game5_manager.background.texSize.y:%f", game5_manager.background.texSize.y);
        debug::setString("game5_manager.hole.pos.x:%f", game5_manager.hole.pos.x);
        debug::setString("game3_manager.bullet.pos.x:%f", game3_manager.bullet.pos.x);
        debug::setString("game3_manager.bullet.pos.y:%f", game3_manager.bullet.pos.y);
        debug::setString("game6_manager.triangle.pos.x:%f", game6_manager.triangle.pos.x);
        debug::setString("game6_manager.triangle.pos.y:%f", game6_manager.triangle.pos.y);


        debug::setString("back[5].pos.x:%f", back[5].pos.x);
        debug::setString("back[3].texSize.x:%f", back[3].texSize.x);
        debug::setString("back[3].texPos.x:%f", back[3].texPos.x);

        debug::setString("timer[0] %d", timer[0]);
#endif

        back_update();


        //�~�X�̔���
        //for (int i = 0; i < MAX_GAMES; i++)
        //{
        //    if (missed_game[i])
        //    {
        //        //���y�̃{�����[��
        //        game_volume -= 0.04;
        //        game_volume = std::clamp(game_volume, 0.0f, 1.0f);
        //        music::setVolume(1, game_volume);
        //        //�����҂�
        //        finish_timer++;
        //        if (finish_timer < 90) break;

        //        nextScene = SCENE_SCORE;
        //        score = game_timer;
        //        break;
        //    }
        //}
        ////�Q�[���I�[�o�[�ɂȂ����瓮����I��
        //for (int i = 0; i < MAX_GAMES; i++)
        //{
        //    if (missed_game[i])  return;
        //}


        if (TRG(0) & PAD_SELECT)
        {
            nextScene = SCENE_SCORE;
            score = game_timer;
            break;
        }


        /////// Game2__Manager_updata ///////
#if 1
        VECTOR2 shot_pos[2] = { { back[1].pos.x , 0 },{back[4].pos.x,0} };
        float height = square.frame_getPos()-((square.frame_getTexS()/2) * square.frame_getScale()); // tex_size.y * scale
        game2_center = (back[1].pos.x + back[4].pos.x) / 2;

        shot.Update(square.square);
        shot.Shot(shot_pos[rand() % 2], height, (square.square.texSize.y*square.square.scale.y) * (rand() % 4+1));// �o���ʒu�����߂Ă��̂܂ܔ��˂��Ă�

        square.update();
#endif
        game1_manager.Game1_Manager_update();
        game3_manager.Game3_Manager_update();
        game4_manager.Game4_Manager_update();
        game5_manager.Game5_Manager_update();
        game6_manager.Game6_Manager_update();

        game_tutorial();

        break;
    }

    game_timer++;
    shot.bullet_timer++;
}

void back_update() {


    /////// 1��ڂ̃X���C�h���� ///////
    if (game_timer == scroll_time[0])
    {
        scroll_timer[0] = 0;
        number_of_games = 2;
    }
    if (scroll_timer[0] < duration)
    {
        scroll_Frag[1] = true;
        scroll_timer[0]++;
        float t = (float)scroll_timer[0] / duration;
        back[0].pos.x = Easing::step(eType::SMOOTHER_STEP_OUT, 0, -SCREEN_W / 3, t);
        back[1].pos.x = Easing::step(eType::SMOOTHER_STEP_OUT, SCREEN_W, SCREEN_W / 2, t);

        game1_manager.Game1_Manager_slideX(SCREEN_W / 4);

        square.square_slideX(SCREEN_W - SCREEN_W / 4);
        shot.bullet_init();
    }
    else scroll_Frag[1] = false;

    /////// 2��ڂ̃X���C�h���� ///////
    if (game_timer == scroll_time[1])
    {
        scroll_timer[1] = 0;
        number_of_games = 3;
    }
    if (back[0].scale.x >= 1) {
        if (game_timer > scroll_time[1]) {
            scroll_Frag[2] = true;

            back[0].scale.x *= 0.99;
            back[0].scale.y *= 0.99;
            //back[1].scale.x *= 0.99;
            //back[1].scale.y *= 0.99;

            /*ball.scale.x *= 0.99;
            ball.scale.y *= 0.99;
            if (ball.pos.y > SCREEN_H / 4) ball.pos.y -= 4;
            else ball.pos.y = SCREEN_H / 4;*/


            //game1_manager.Game1_Manager_shrink();
            game1_manager.Game1_Manager_slideY(SCREEN_H / 3 );

            square.square_slideY(SCREEN_H / 4);
            //shot.game2_shrink();
            //square.square_shrink();

            if (scroll_timer[1] < duration)
            {
                scroll_timer[1]++;
                float t = (float)scroll_timer[1] / duration;
                back[0].pos.x = Easing::step(eType::SMOOTHER_STEP_OUT, -SCREEN_W/3, 0, t);
                back[1].pos.y = Easing::step(eType::SMOOTHER_STEP_OUT, 0, -SCREEN_H/4, t);
                back[2].pos.y = Easing::step(eType::SMOOTHER_STEP_OUT, SCREEN_H, SCREEN_H/2, t);
                game3_manager.Game3_Manager_init();

            }
            
            //back[2].pos = { 0,back[0].texSize.y * back[0].scale.y };
        }
        else scroll_Frag[2] = false;

    }

    /////// 3��ڂ̃X���C�h���� ///////
    if (game_timer == scroll_time[2])
    {
        scroll_timer[2] = 0;
        number_of_games = 4;
    }
    if (scroll_timer[2] < duration) {
        scroll_Frag[3] = true;

        scroll_timer[2]++;
        float t = (float)scroll_timer[2] / duration;
        back[2].pos.x = Easing::step(eType::SMOOTHER_STEP_OUT, 0, -SCREEN_W/2, t);
        back[3].pos.x = Easing::step(eType::SMOOTHER_STEP_OUT, SCREEN_W, SCREEN_W / 2, t);
        game3_manager.Game3_Manager_slide(SCREEN_W / 4);
        game3_manager.Game3_Manager_shrink();
        game4_manager.Game4_Manager_init();
    }
    else scroll_Frag[3] = false;


    /////// 4��ڂ̃X���C�h���� ///////
    if (game_timer == scroll_time[3])
    {
        scroll_timer[3] = 0;
        number_of_games = 5;
    }
    if (scroll_timer[3] < duration) {
        scroll_Frag[4] = true;

        scroll_timer[3]++;
        float t = (float)scroll_timer[3] / duration;
        back[0].pos.x = Easing::step(eType::SMOOTHER_STEP_OUT, 0, -SCREEN_W / 2, t);
        back[1].pos.x = Easing::step(eType::SMOOTHER_STEP_OUT, SCREEN_W/2, SCREEN_W / 2-SCREEN_W/6, t);
        back[1].pos.y = Easing::step(eType::SMOOTHER_STEP_OUT, -SCREEN_H / 4, -SCREEN_H/12 , t);
        back[4].pos.x = Easing::step(eType::SMOOTHER_STEP_OUT, SCREEN_W, SCREEN_W - SCREEN_W / 3, t);

        game1_manager.Game1_Manager_slideX(SCREEN_W / 6);
        square.square_slideX(SCREEN_W/2);
        
        shot.game2_shrink();
        square.square_shrink();

        /*if (ball.pos.x > SCREEN_W / 6 ) ball.pos.x -= 8;
        else ball.pos.x = SCREEN_W / 6 ;*/

    }
    else scroll_Frag[4] = false;


    /////// 5��ڂ̃X���C�h���� ///////
    if (game_timer == scroll_time[4])
    {
        game6_manager.barrier_init();
        scroll_timer[4] = 0;
        number_of_games = 6;
    }
    if (scroll_timer[4] < duration) {
        scroll_Frag[5] = true;
        scroll_timer[4]++;
        float t = (float)scroll_timer[4] / duration;

        back[3].texSize.x -= 5.333333f;
        back[3].texPos.x += 2.666667f;
        back_slide += 2.666667f;

        back[2].pos.x = Easing::step(eType::SMOOTHER_STEP_OUT, -SCREEN_W/2, SCREEN_W/3-SCREEN_W  , t);
        back[3].pos.x = Easing::step(eType::SMOOTHER_STEP_OUT, SCREEN_W / 2, SCREEN_W / 2 - back[3].texSize.x / 2, t);
        back[5].pos.x = Easing::step(eType::SMOOTHER_STEP_OUT, SCREEN_W, SCREEN_W - SCREEN_W / 3, t);
        game3_manager.Game3_Manager_slide(SCREEN_W / 6);
    }
    else scroll_Frag[5] = false;

}

//--------------------------------------
//  �`�揈��
//--------------------------------------

void game_render()
{
    GameLib::clear(1,1,1);
    
    
    /////// �X�N���[�����邽�߂ɉ��ɕ`�� ///////
    sprite_render(Back[4],
        back[4].pos.x, back[4].pos.y,
        back[4].scale.x, back[4].scale.y,
        0, 0,
        back[4].texSize.x, back[4].texSize.y,
        back[4].pivot.x, back[4].pivot.y);
    

    

    /////// �X�N���[�����邽�߂ɉ��ɕ`�� ///////
    sprite_render(Back[5],
        back[5].pos.x, back[5].pos.y,
        back[5].scale.x, back[5].scale.y,
        0, 0,
        back[5].texSize.x, back[5].texSize.y,
        back[5].pivot.x, back[5].pivot.y);

    game6_manager.Game6_Manager_render();
    game5_manager.Game5_Manager_render();
    

    sprite_render(Back[0],
        back[0].pos.x, back[0].pos.y,
        back[0].scale.x,back[0].scale.y,
        0, 0,
        back[0].texSize.x, back[0].texSize.y,
        back[0].pivot.x, back[0].pivot.y);
    sprite_render(Between[0],
        back[0].pos.x, back[0].pos.y,
        back[0].scale.x, back[0].scale.y,
        0, 0,
        back[0].texSize.x, back[0].texSize.y,
        back[0].pivot.x, back[0].pivot.y);

    game1_manager.Game1_render();


    sprite_render(Back[1],
        back[1].pos.x, back[1].pos.y,
        back[1].scale.x, back[1].scale.y,
        0, 0,
        back[1].texSize.x, back[1].texSize.y,
        back[1].pivot.x, back[1].pivot.y);
    sprite_render(Between[0],
        back[1].pos.x, back[1].pos.y,
        back[1].scale.x, back[1].scale.y,
        0, 0,
        back[1].texSize.x, back[1].texSize.y,
        back[1].pivot.x, back[1].pivot.y);

    square.square_render();
    shot.shot_render();


    /////// �e���ʂ̃Q�[���̏�ɕ`�悳��邩�� ///////
    sprite_render(Back[2],
        back[2].pos.x, back[2].pos.y,
        back[2].scale.x, back[2].scale.y,
        0, 0,
        back[2].texSize.x, back[2].texSize.y,
        back[2].pivot.x, back[2].pivot.y);
    sprite_render(Between[0],
        back[2].pos.x, back[2].pos.y,
        back[2].scale.x, back[2].scale.y,
        0, 0,
        back[2].texSize.x, back[2].texSize.y,
        back[2].pivot.x, back[2].pivot.y);

    game3_manager.Game3_Manager_render();
    

    sprite_render(Back[3],
        back[3].pos.x, back[3].pos.y,
        back[3].scale.x, back[3].scale.y,
        back[3].texPos.x,back[3].texPos.y,
        back[3].texSize.x, back[3].texSize.y,
        back[3].pivot.x, back[3].pivot.y);
    sprite_render(Between[0],
        back[3].pos.x, back[3].pos.y,
        back[3].scale.x, back[3].scale.y,
        0, 0,
        back[3].texSize.x, back[3].texSize.y,
        back[3].pivot.x, back[3].pivot.y);

    game4_manager.Game4_render();

    sprite_render(Between[0],
        back[4].pos.x, back[4].pos.y,
        back[4].scale.x, back[4].scale.y,
        0, 0,
        back[4].texSize.x, back[4].texSize.y,
        back[4].pivot.x, back[4].pivot.y);


    //sprite_render(Back[5],
    //    back[5].pos.x, back[5].pos.y,
    //    back[5].scale.x, back[5].scale.y,
    //    0, 0,
    //    back[5].texSize.x, back[5].texSize.y,
    //    back[5].pivot.x, back[5].pivot.y);
    sprite_render(Between[0],
        back[5].pos.x, back[5].pos.y,
        back[5].scale.x, back[5].scale.y,
        0, 0,
        back[5].texSize.x, back[5].texSize.y,
        back[5].pivot.x, back[5].pivot.y);

    gameover_render();
    tutrial_render();

    //�|�[�Y��
    if (isPaused)    font::textOut(
        3,
        "PAUSE",
        CENTER,
        { 3,3 },
        { 0,0,0,1 },
        TEXT_ALIGN::MIDDLE
    );

}

void gameover_render()
{
    //1�Ԗ�
    if (missed_game[0])
    {
        Sprite* s = nullptr;
        VECTOR2 texsize = { 0, 0 };

        switch (number_of_games)
        {
        case 1:
            s = GameOver[0];
            texsize = { 1980, 1080 };
            break;
        case 2:
            s = GameOver[1];
            texsize = { 960, 1080 };
            break;
        case 3:
        case 4:
            s = GameOver[3];
            texsize = { 960, 540 };
            break;
        case 5:
        case 6:
            s = GameOver[4];
            texsize = { 650, 540 };
        default:
            break;
        }

        sprite_render(
            s,
            0, 0,
            1, 1,
            0, 0,
            texsize.x, texsize.y,
            0, 0,
            0
        );
    }
    //2�Ԗ�
    if (missed_game[1])
    {
        Sprite* s = nullptr;
        VECTOR2 pos = { 0, 0 };
        VECTOR2 texsize = { 0, 0 };

        switch (number_of_games)
        {
        case 2:
            s = GameOver[1];
            texsize = { 960, 1080 };
            pos = { SCREEN_W / 2, 0 };
            break;
        case 3:
        case 4:
            s = GameOver[3];
            texsize = { 960, 540 };
            pos = { SCREEN_W / 2, 0 };
            break;
        case 5:
        case 6:
            s = GameOver[4];
            texsize = { 650, 540 };
            pos = { SCREEN_W / 3, 0 };
        default:
            break;
        }

        sprite_render(
            s,
            pos.x, pos.y,
            1, 1,
            0, 0,
            texsize.x, texsize.y,
            0, 0,
            0
        );
    }
    //3�Ԗ�
    if (missed_game[2])
    {
        Sprite* s = nullptr;
        VECTOR2 texsize = { 0, 0 };
        switch (number_of_games)
        {
        case 3:
            s = GameOver[2];
            texsize = { 1920, 540 };
            break;
        case 4:
        case 5:
            s = GameOver[3];
            texsize = { 960, 540 };
        case 6:
            s = GameOver[4];
            texsize = { 640, 540 };
            break;
        }
        
        sprite_render(
            s,
            0, SCREEN_H / 2,
            1, 1,
            0, 0,
            texsize.x, texsize.y,
            0, 0,
            0
        );
    }
    //4�Ԗ�
    if (missed_game[3])
    {
        Sprite* s = nullptr;
        VECTOR2 texsize = { 0, 0 };
        VECTOR2 pos = { 0, 0 };
        switch (number_of_games)
        {
        case 4:
            s = GameOver[3];
            texsize = { 960, 540 };
            pos = CENTER;
            break;
        case 5:
        case 6:
            s = GameOver[4];
            texsize = { 650, 540 };
            pos = { SCREEN_W / 3, SCREEN_H / 2 };
            break;
        }
        sprite_render(
            s,
            pos.x, pos.y,
            1, 1,
            0, 0,
            texsize.x, texsize.y,
            0, 0,
            0
        );
    }
    //5�Ԗ�
    if (missed_game[4])
    {
        sprite_render(
            GameOver[4],
            SCREEN_W / 3 * 2.0f, 0,
            1, 1,
            0, 0,
            650, 540,
            0, 0,
            0
        );
    }
    //6�Ԗ�
    if (missed_game[5])
    {
        sprite_render(
            GameOver[4],
            SCREEN_W / 3 * 2.0f, SCREEN_H / 2,
            1, 1,
            0, 0,
            650, 540,
            0, 0,
            0
        );
    }
}

void game_tutorial() {
    for (int i = 0; i < MAX_GAMES; i++) {
        timer[i] = scroll_time[i] + duration;
    }

    if (game_timer == 0)
    {
        tutorial = true;
        tutrial_init();
    }

    if (game_timer == timer[0])
    {
        tutorial = true;
        tutrial_init();
    }
    else if (game_timer == timer[1])
    {
        tutorial = true;
        tutrial_init();
    }
    else if (game_timer == timer[2])
    {
        tutorial = true;
        tutrial_init();
    }
    else if (game_timer == timer[3])
    {
        tutorial = true;
        tutrial_init();
    }
    else if (game_timer == timer[4])
    {
        tutorial = true;
        tutrial_init();
    }
}

void tutrial_init()
{
    tutrial_easeTimer = 0;
    tutrial_pos = tutrial_pos_start;
    tutrial_counter++;
}

void tutrial_render()
{
    if (tutrial_easeTimer < TUTRIAL_EASEDURATION)
    {
        tutrial_easeTimer++;
        float t = (float)tutrial_easeTimer / TUTRIAL_EASEDURATION;
        tutrial_pos.y = Easing::step(eType::EXPO_OUT, tutrial_pos_start.y, tutrial_pos_end.y, t);
    }
    Sprite* s = nullptr;
    s = tutrial_sprite[tutrial_counter % 6];

    sprite_render(
        s,
        tutrial_pos.x, tutrial_pos.y,
        1, 1,
        0, 0,
        1000, 450,
        500, 225,
        0
    );
}