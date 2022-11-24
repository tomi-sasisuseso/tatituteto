#include "all.h"

//�p�����[�^
const float DURATION = 60;
const float MOVE_SPEED = 5.0f;
const float SPAWN_POS_X = SCREEN_W + 200.0f;
const float DESPAWN_POS_X = -100.0f;
const float COYOTE_TIME = 20.0f;

OBJ2D triangle;
OBJ2D background;
OBJ2D barrier;

int triangle_easetimer = INT_MAX;
VECTOR2 upperpos = CENTER, downerpos = CENTER;

Sprite* background_sprite;
Sprite* triangle_sprite;
Sprite* barrier_sprite;

extern OBJ2D back[MAX_GAMES];


void Game6_Manager::Game6_Manager_init()
{
    Game6_timer = 0;

    //////// �p�����[�^�̐ݒ� ////////
    GameLib::setBlendMode(Blender::BS_ALPHA);
    //�l�p
    triangle.scale = { 0.5f, 0.5f };
    triangle.texPos = { 0,0 };
    triangle.texSize = { 200, 160 };
    triangle.pivot = triangle.texSize / 2;
    triangle.angle = 0;
    triangle.Dradius = 32.0f;

    //�w�i
    background.pos = back[5].pos;
    background.scale = { 1, 1 };
    background.texPos = { 0,0 };
    background.texSize = { 1280, 540 };
    background.pivot = { 0,0 };
    background.angle = 0;

    //��Q��
    barrier.pos = {50000,50000};
    barrier.scale = { 1, 1 };
    barrier.texPos = { 0,0 };
    barrier.texSize = { 60, 160 };
    barrier.pivot = barrier.texSize / 2;
    barrier.angle = 0;
    barrier.Dradius = 32;

    //�����ʒu
    upperpos = { 0, (SCREEN_H / 2 + triangle.pivot.y / 2) + Stage_error };
    downerpos = { 0, (SCREEN_H - triangle.pivot.y / 2) - Stage_error };
    triangle.pos = downerpos;
    triangle.pos.x = background.pos.x + background.texSize.x / 6;
    
    //barrier_init();

    background_sprite = sprite_load(L"./Data/Images/�Q�[��6_�w�i.png");
    triangle_sprite = sprite_load(L"./Data/Images/�Q�[��6_�O�p.png");
    barrier_sprite = sprite_load(L"./Data/Images/�Q�[��6_��Q��.png");
}

void Game6_Manager::Game6_Manager_deinit()
{
    music::stop(0);

    float MOVE_SPEED = 0.0f;
    safe_delete(background_sprite);
    safe_delete(triangle_sprite);
    safe_delete(barrier_sprite);
}

void Game6_Manager::Game6_Manager_update()
{
    background.pos = back[5].pos;

    triangle_move();
    barrier_move();
    Game6_timer++;
}

void Game6_Manager::Game6_Manager_render()
{
    //�w�i
    for (int i = 0; i < 5000; i++)
    {
        sprite_render(
            background_sprite,
            background.pos.x + i * background.texSize.x - (Game6_timer * MOVE_SPEED), background.pos.y,
            background.scale.x, background.scale.y,
            background.texPos.x, background.texPos.y,
            background.texSize.x, background.texSize.y,
            background.pivot.x, background.pivot.y,
            background.angle
        );
    }
    //�O�p
    sprite_render(
        triangle_sprite,
        triangle.pos.x, triangle.pos.y,
        triangle.scale.x, triangle.scale.y,
        triangle.texPos.x, triangle.texPos.y,
        triangle.texSize.x, triangle.texSize.y,
        triangle.pivot.x, triangle.pivot.y,
        triangle.angle
    );
    //��Q��
    sprite_render(
        barrier_sprite,
        barrier.pos.x, barrier.pos.y,
        barrier.scale.x, barrier.scale.y,
        barrier.texPos.x, barrier.texPos.y,
        barrier.texSize.x, barrier.texSize.y,
        barrier.pivot.x, barrier.pivot.y,
        barrier.angle
    );
    //�f�o�b�O�p
#if 1
    //��Q��
    primitive::circle(
        barrier.pos,
        32,
        { 1, 1 },
        0,
        { 1.0f, 0.0f, 0.0f, 0.5f }
    );
    //��
    primitive::circle(
        triangle.pos,
        triangle.Dradius,
        { 1, 1 },
        0,
        { 1.0f, 0.0f, 0.0f, 0.5f }
    );
#endif
}

void Game6_Manager::triangle_move()
{
    triangle.pos.x = background.pos.x + background.texSize.x / 6;

    //���E�ɔ��]
    if (TRG(0) & PAD_L3 && !(0 < triangle_easetimer && triangle_easetimer < DURATION - COYOTE_TIME))
    {
        reverse = !reverse;
        triangle_easetimer = 0;
    }
    //�ړ�
    if (triangle_easetimer < DURATION)
    {
        triangle_easetimer++;
        float t = (float)triangle_easetimer / DURATION;
        if (reverse)
        {
            triangle.pos.y = Easing::step(eType::BOUNCE_OUT, upperpos.y, downerpos.y, t);
            triangle.angle = Easing::step(eType::EXPO_OUT, PI, TAU, t * 1.3f);
        }
        else
        {
            triangle.pos.y = Easing::step(eType::BOUNCE_OUT, downerpos.y, upperpos.y, t);
            triangle.angle = Easing::step(eType::EXPO_OUT, TAU, PI, t * 1.3f);
        }        
    }
}

void Game6_Manager::barrier_init()
{
    MOVE_SPEED = 5.0f;

    //�㉺�ǂ��炩�ݒ�
    int choise = rand() % 2;

    //��
    if (choise == 0)
    {
        barrier.pos.y = SCREEN_H  - interval;
    }

    //��
    else
    {
        barrier.pos.y = SCREEN_H / 2 + interval;
    }
    //x����
    barrier.pos.x = SPAWN_POS_X;
}

void Game6_Manager::barrier_move()
{
    //��ʊO�ɏo���烊�X�|�[��
    if (barrier.pos.x < DESPAWN_POS_X)
    {
        barrier_init();
    }
    //��Q���Ƀq�b�g
    if (circle_collision(triangle.pos, barrier.pos, triangle.Dradius, barrier.Dradius))
    {
        barrier_init();
    }

    barrier.velocity.x = -MOVE_SPEED;
    barrier.pos += barrier.velocity;
}