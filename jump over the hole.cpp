#include "all.h"

int title_state;
int title_timer;

//�p�����[�^
const float GRAVITY = 0.5f;
const float MOVE_SPEED = 5.0f;
const float ROTATE_SPEED = MOVE_SPEED * 0.6f;
const float JUMP_POWER = 20.0f;
const float SPAWN_POS_X = SCREEN_W + 100;
const float DESPAWN_POS_X = -100;
const float BORDER_TO_FALL = 780.0f;
//�ő傩��ŏ��܂ł̊Ԃ��烉���_���ɑҋ@���Ԃ�ݒ�
const int MAX_WAIT_TIME = 1000;
const int MIN_WAIT_TIME = 100;

OBJ2D background;
OBJ2D ball3;
OBJ2D hole;

Sprite* ball_sprite;
Sprite* hole_sprite;

float wait_time = 0;
float floor_height = 0;
bool is_on_floor = false;

void title_init()
{
    title_state = 0;
    title_timer = 0;

    texture::load(TEXNO::GAME3_BG, L"./Data/Images/�Q�[��3_�w�i.png", 5000);
    ball_sprite = sprite_load(L"./Data/Images/�Q�[��3_�{�[��.png");
    hole_sprite = sprite_load(L"./Data/Images/�Q�[��3_��.png");
}

void title_deinit()
{
    music::stop(0);
    safe_delete(ball_sprite);
    safe_delete(hole_sprite);
}

void title_update()
{
    switch (title_state)
    {
    case 0:
        //////// �����ݒ� ////////
        title_state++;

        /*fallthrough*/
    case 1:
        //////// �p�����[�^�̐ݒ� ////////
        GameLib::setBlendMode(Blender::BS_ALPHA);
        music::play(0, FALSE);
        //�w�i
        background.pos = CENTER;
        background.scale = { 1, 1 };
        background.texPos = { 0,0 };
        background.texSize = { 1280, 540 };
        background.pivot = background.texSize / 2;
        background.angle = 0;
        //�l�p
        ball3.pos = CENTER;
        ball3.scale = { 0.5f, 0.5f };
        ball3.texPos = { 0,0 };
        ball3.texSize = { 150, 150 };
        ball3.pivot = ball3.texSize / 2;
        ball3.angle = 0;
        ball3.Dradius = 32.0f;
        //��
        hole.scale = { 1, 1 };
        hole.texPos = { 0,0 };
        hole.texSize = { 150, 150 };
        hole.pivot = hole.texSize / 2;
        hole.angle = 0;
        hole.Dradius = 32.0f;
        //�{�[���̏����ʒu
        ball3.pos.x += -400.0f;
        ball3.pos.y += background.texSize.y * 0.5f - ball3.pivot.y * 1.5f;
        floor_height = ball3.pos.y;

        hole_init();
        title_state++;
    case 2:
        //////// �ʏ펞 ////////
        //�f�o�b�O�p
        debug::setString("title_state:%d", title_state);
        debug::setString("title_timer:%d", title_timer);
        debug::setString("Ball Position: %f %f", ball3.pos.x, ball3.pos.y);
        debug::setString("Hole Position: %f %f", hole.pos.x, hole.pos.y);
        debug::setString("Hole Waittime: %f", wait_time);

        ball_move();
        hole_move();
        break;
    }
    title_timer++;
}

void title_render()
{
    // ��ʂ�œh��Ԃ�
    GameLib::clear(0.3f, 0.5f, 1.0f);
    //�w�i
    texture::begin(TEXNO::GAME3_BG);
    for (int i = 0; i < 3000; i++)
    {
        texture::draw(
            TEXNO::GAME3_BG,
            { background.pos.x * i - (title_timer * MOVE_SPEED), background.pos.y },
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

void ball_move()
{
    //�d��
    ball3.velocity.y += GRAVITY;
    //��]
    ball3.angle += ToRadian(ROTATE_SPEED);
    //�W�����v
    if (TRG(0) & PAD_TRG1 && is_on_floor)
    {
        ball3.velocity.y = -JUMP_POWER;
    }
    //���x���ʒu�ɑ��
    ball3.pos += ball3.velocity;
    //���̍��E�̈ʒu
    float left = hole.pos.x - hole.pivot.x;
    float right = hole.pos.x + hole.pivot.x;
    //�n�ʂɂ���ꍇ
    if (ball3.pos.y > floor_height && !(left < ball3.pos.x && ball3.pos.x < right))
    {
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
    //�����̔���
    if (ball3.pos.y > BORDER_TO_FALL)   title_init();
}

void hole_init()
{
    //�ʒu
    hole.pos = CENTER;
    hole.pos.y += background.pivot.y - 5;
    hole.pos.x = SPAWN_POS_X;
    //���ɏo������܂ł̎��Ԃ������_���ɐ���
    wait_time = MIN_WAIT_TIME + rand() % MAX_WAIT_TIME;
}

void hole_move()
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