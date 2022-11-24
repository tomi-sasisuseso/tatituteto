#include "jump over the hole.h"

Sprite* ball_sprite;
Sprite* hole_sprite;

extern OBJ2D back[MAX_GAMES];

void Game5_Manager::Game5_Manager_init()
{
    //////// �p�����[�^�̐ݒ� ////////
    GameLib::setBlendMode(Blender::BS_ALPHA);
    music::play(0, FALSE);
    //�w�i
    background.pos = {back[4].pos.x, back[4].pos.y};
    background.scale = { 1, 1 };
    background.texPos = { 0,0 };
    background.texSize = { 1280, 540 };
    background.pivot = { 0,0 };
    background.angle = 0;

    //�l�p
    ball3.pos = { background.pos.x + background.texSize.x / 6,
                  SCREEN_H / 2 };
    ball3.scale = { 0.5f, 0.5f };
    ball3.texPos = { 0,0 };
    ball3.texSize = { 150, 150 };
    ball3.pivot = ball3.texSize / 2;
    ball3.angle = 0;
    ball3.Dradius = 32.0f;

    //�{�[���̏����ʒu
    ball3.pos.x += -400.0f;
    ball3.pos.y -= /*background.texSize.y * 0.5f - */ball3.pivot.y * 1.5f;
    
    floor_height = ball3.pos.y;


    hole_init();

    texture::load(TEXNO::GAME3_BG, L"./Data/Images/�Q�[��3_�w�i.png", 5000);
    ball_sprite = sprite_load(L"./Data/Images/�Q�[��3_�{�[��.png");
    hole_sprite = sprite_load(L"./Data/Images/�Q�[��3_��.png");
}

void Game5_Manager::Game5_Manager_deinit()
{
    music::stop(0);
    safe_delete(ball_sprite);
    safe_delete(hole_sprite);
}

void Game5_Manager::Game5_Manager_update()
{
    background.pos = { back[4].pos.x, back[4].pos.y };

    ball_move();
    hole_move();
    game5_timer++;
}

void Game5_Manager::Game5_Manager_render()
{
    //�w�i
    texture::begin(TEXNO::GAME3_BG);
    for (int i = 0; i < 3000; i++)
    {
        texture::draw(
            TEXNO::GAME3_BG,
            { background.pos.x + i * background.texSize.x - (game5_timer * MOVE_SPEED), background.pos.y },
            background.scale,
            background.texPos,
            background.texSize,
            background.pivot,
            background.angle
        );
    }
    texture::end(TEXNO::GAME3_BG);
    //��
    sprite_render(
        hole_sprite,
        hole.pos.x, hole.pos.y,
        hole.scale.x, hole.scale.y,
        hole.texPos.x, hole.texPos.y,
        hole.texSize.x, hole.texSize.y,
        hole.pivot.x, hole.pivot.y,
        hole.angle
    );
    //�{�[��
    sprite_render(
        ball_sprite,
        ball3.pos.x, ball3.pos.y,
        ball3.scale.x, ball3.scale.y,
        ball3.texPos.x, ball3.texPos.y,
        ball3.texSize.x, ball3.texSize.y,
        ball3.pivot.x, ball3.pivot.y,
        ball3.angle
    );
    //�f�o�b�O�p
#if 1

#endif
}

void Game5_Manager::ball_move()
{

    ball3.pos.x = background.pos.x + background.texSize.x / 6;

    //�d��
    ball3.velocity.y += GRAVITY;
    //��]
    ball3.angle += ToRadian(ROTATE_SPEED);
    //�W�����v
    if (TRG(0) & PAD_L1 && is_on_floor)
    {
        ball3.velocity.y = -JUMP_POWER;
    }

    //���x���ʒu�ɑ��
    ball3.pos += ball3.velocity;

    //���̍��E�̈ʒu
    float left = hole.pos.x - hole.texSize.x/2;
    float right = hole.pos.x + hole.texSize.x / 2;
    //�n�ʂɂ���ꍇ
    if (ball3.pos.y > floor_height && !(left < ball3.pos.x && ball3.pos.x < right)) {
            debug::setString("onground");
            ball3.velocity.y = 0;
            ball3.pos.y = floor_height;
            is_on_floor = true;

    }
        
    //��
    else
    {
        is_on_floor = false;
    }
    debug::setString("left :%f", left);
    debug::setString("right :%f", right);
    //�����̔���
    if (ball3.pos.y > BORDER_TO_FALL)   Game6_Manager_init();
}

void Game5_Manager::hole_init()
{

    //���̏����ݒ�
    hole.scale = { 1, 1 };
    hole.texPos = { 0,0 };
    hole.texSize = { 150, 150 };
    hole.pivot = { 0, 0 };
    hole.angle = 0;
    hole.Dradius = 32.0f;


    //�ʒu
    hole.pos = CENTER;
    hole.pos.y = 0+back[4].texSize.y-hole.texSize.y/2;
    hole.pos.x = SPAWN_POS_X;
    //���ɏo������܂ł̎��Ԃ������_���ɐ���
    wait_time = MIN_WAIT_TIME + rand() % MAX_WAIT_TIME;
}

void Game5_Manager::hole_move()
{
    //�������Ɉړ�
    hole.velocity.x = -MOVE_SPEED;
    //�ʒu�����Z�b�g
    if (hole.pos.x < DESPAWN_POS_X - wait_time)
    {
        hole_init();
    }
    //���x���ʒu�ɑ��
    hole.pos += hole.velocity;
}