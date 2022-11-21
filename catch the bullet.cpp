#include "all.h"

int title_state;
int title_timer;

//�p�����[�^
//SAFE_ANGLE�ɂ��ā@-1����1�̊ԂŒ����@�l���傫���Ȃ�قǃZ�[�t�̔��肪�������Ȃ�
const float CIRCLE_MOVESPEED = 0.15f;
const float CIRCLE_MAXSPEED = 3.0f;
const float CIRCLE_DECELERATION = 0.8f;
const float SAFE_ANGLE = 0.82f;
int bullet_speed = 5;
int spawn_interval = 30;

Sprite* circle_sprite;
Sprite* bullet_sprite;
OBJ2D circle;
OBJ2D bullet;

float product = 0;
int spawn_counter = 0;

void title_init()
{
    title_state = 0;
    title_timer = 0;

    circle_sprite = sprite_load(L"./Data/Images/�Q�[��4_�~.png");
    bullet_sprite = sprite_load(L"./Data/Images/�Q�[��4_�e.png");
}

void title_deinit()
{
    music::stop(0);
    safe_delete(circle_sprite);
    safe_delete(bullet_sprite);
}

void title_update()
{
    switch (title_state)
    {
    case 0:
        //////// �����ݒ� ////////
        title_state++;
        bullet_init();

        /*fallthrough*/
    case 1:
        //////// �p�����[�^�̐ݒ� ////////
        GameLib::setBlendMode(Blender::BS_ALPHA);
        music::play(0, FALSE);
        //���S�̉~
        circle.pos = CENTER;
        circle.scale = { 1, 1 };
        circle.texPos = { 0,0 };
        circle.texSize = { 300,300 };
        circle.pivot = circle.texSize / 2;
        circle.Dradius = 150;
        circle.angle = 0;
        //�e
        bullet.pos = { -100, -600 };
        bullet.scale = { 1, 1 };
        bullet.texPos = { 0,0 };
        bullet.texSize = { 70, 70 };
        bullet.pivot = bullet.texSize / 2;
        bullet.Dradius = 24;
        bullet.angle = 0;

        title_state++;
        /*fallthrough*/

    case 2:
        //////// �ʏ펞 ////////
        //�f�o�b�O�p
        debug::setString("title_state:%d", title_state);
        debug::setString("title_timer:%d", title_timer);
        debug::setString("Bullet Angle: %f", bullet.angle);
        debug::setString("Bullet Vector: %f %f", bullet.vector_normal.x, bullet.vector_normal.y);
        debug::setString("Circle Angle: %f", circle.angle);
        debug::setString("Circle Vector: %f %f", circle.vector_normal.x, circle.vector_normal.y);
        debug::setString("Inner Product: %f", product);
        debug::setString("Spawn Counter: %i", spawn_counter);

        if (TRG(0) & PAD_START)
        {
            nextScene = SCENE_GAME;
            break;
        }
        circle_move();
        bullet_move();
        is_safe();
    }
    title_timer++;
}

void title_render()
{
    // ��ʂ�œh��Ԃ�
    GameLib::clear(0.3f, 0.5f, 1.0f);
    //�~
    sprite_render(
        circle_sprite,
        circle.pos.x, circle.pos.y,
        circle.scale.x, circle.scale.y,
        circle.texPos.x, circle.texPos.y,
        circle.texSize.x, circle.texSize.y,
        circle.pivot.x, circle.pivot.y,
        circle.angle,
        1.0f, 1.0f, 1.0f, 1.0f
    );
    sprite_render(
        bullet_sprite,
        bullet.pos.x, bullet.pos.y,
        bullet.scale.x, bullet.scale.y,
        bullet.texPos.x, bullet.texPos.y,
        bullet.texSize.x, bullet.texSize.y,
        bullet.pivot.x, bullet.pivot.y,
        bullet.angle,
        1.0f, 1.0f, 1.0f, 1.0f
    );
#if 0
    //�����蔻��
    //�~
    primitive::circle(
        circle.pos,
        circle.Dradius,
        { 1, 1 },
        circle.angle,
        { 1.0f, 0.0f, 0.0f, 0.4f }
    );
    //�e
    primitive::circle(
        bullet.pos,
        bullet.Dradius,
        { 1, 1 },
        bullet.angle,
        { 1.0f, 0.0f, 0.0f, 0.4f }
    );
    //�x�N�g��
    primitive::line(
        circle.pos,
        circle.pos + circle.vector_normal * -300,
        { 1.0f, 0.0f, 0.0f, 1.0f },
        3.0f
    );
    primitive::line(
        bullet.pos,
        bullet.pos + bullet.vector_normal * 100,
        { 0.0f, 1.0f, 0.0f, 1.0f },
        3.0f
    );
#endif
}

//�~�̈ړ�
void circle_move()
{
    //�x�N�g���A����
    circle.vector_normal = { cosf(circle.angle), sinf(circle.angle) };
    product = inner_product(circle.vector_normal, bullet.vector_normal);
    //����
    switch (STATE(0) & (PAD_LEFT | PAD_RIGHT))
    {
    case PAD_LEFT:
        circle.velocity.x += -CIRCLE_MOVESPEED;
        break;
    case PAD_RIGHT:
        circle.velocity.x += CIRCLE_MOVESPEED;
        break;
    default:
        circle.velocity.x *= CIRCLE_DECELERATION;
        break;
    }
    //���x�̐���
    circle.velocity.x = std::clamp(circle.velocity.x, -CIRCLE_MAXSPEED, CIRCLE_MAXSPEED);
    //���x���ʒu�ɑ��
    circle.angle += ToRadian(circle.velocity.x);
}

//�e��������
void bullet_init()
{
    //�ʒu��ݒ�
    float angle = rand() % 360;
    float x = (SCREEN_W / 2) + cosf(angle) * SCREEN_W;
    float y = (SCREEN_H / 2) + sinf(angle) * SCREEN_H;
    bullet.pos = { x, y };
    //�J�E���^�[�����Z�b�g
    spawn_counter = 0;
}

//�e�̏���
void bullet_move()
{
    //�L���b�`��̃C���^�[�o��
    spawn_counter++;
    if (spawn_counter < spawn_interval)  return;
    debug::setString("Bullet Activated!");
    //���S�Ɉړ�
    bullet.angle = p_to_p_angle(CENTER, bullet.pos);
    bullet.vector_normal = { cosf(bullet.angle), sinf(bullet.angle) };
    bullet.velocity = bullet.vector_normal * bullet_speed;
    //���x���ʒu�ɑ��
    bullet.pos += bullet.velocity;
}

//�����蔻��
void is_safe()
{
    //�����蔲�����ꍇ
    if (circle_collision(CENTER, bullet.pos, 1, 1))
    {
        bullet_init();
    }
    //�~�X�������ꍇ
    if (circle_collision(circle.pos, bullet.pos, circle.Dradius, bullet.Dradius) && product < SAFE_ANGLE)
    {
        bullet_init();
    }
}
