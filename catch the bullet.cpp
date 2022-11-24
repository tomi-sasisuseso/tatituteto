#include "catch the bullet.h"
Sprite* circle_sprite;
Sprite* bullet_sprite;

extern OBJ2D back[MAX_GAMES];

void Game3_Manager::Game3_Manager_init()
{
    //////// �p�����[�^�̐ݒ� ////////
    GameLib::setBlendMode(Blender::BS_ALPHA);
    //���S�̉~
    circle.pos = { back[2].pos.x + back[2].texSize.x / 2,
                   back[2].pos.y + back[2].texSize.y / 2 };   
    circle.scale = { 1, 1 };
    circle.texPos = { 0,0 };
    circle.texSize = { 300,300 };
    circle.pivot = circle.texSize / 2;
    circle.Dradius = 150.0f;
    circle.angle = 0;

    bullet_init();
    bullet.scale = { 1, 1 };

    circle_sprite = sprite_load(L"./Data/Images/�Q�[��4_�~.png");
    bullet_sprite = sprite_load(L"./Data/Images/�Q�[��4_�e.png");
}

void Game3_Manager::Game3_Manager_deinit()
{
    music::stop(0);
    safe_delete(circle_sprite);
    safe_delete(bullet_sprite);
}

void Game3_Manager::Game3_Manager_update()
{
    circle_move();
    bullet_move();
    is_safe();
}

void Game3_Manager::Game3_Manager_slide(float x)
{
    if (circle.pos.x > x) {
        circle.pos.x -= 16;
        bullet.pos.x -= 16;
    }
    else circle.pos.x = x;

}

void Game3_Manager::Game3_Manager_shrink()
{
    if (circle.scale.x >= 0.5) {
        circle.scale *= 0.98;
        bullet.scale *= 0.98;
        circle.Dradius *= 0.98;
        bullet.Dradius *= 0.98;
    }
    /*if (stage.pos.y > SCREEN_H / 4) stage.pos.y -= 4;
    else stage.pos.y = SCREEN_H / 4;
    if (ball.pos.y > SCREEN_H / 4) ball.pos.y -= 4;
    else ball.pos.y = SCREEN_H / 4;*/
}

void Game3_Manager::Game3_Manager_render()
{

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
void Game3_Manager::circle_move()
{
    //�x�N�g���A����

    circle.vector_normal = { cosf(circle.angle), sinf(circle.angle) };
    product = inner_product(circle.vector_normal, bullet.vector_normal);
    //����

    if (GetAsyncKeyState('I'))          circle.velocity.x += -CIRCLE_MOVESPEED;
    else if (GetAsyncKeyState('K'))     circle.velocity.x += CIRCLE_MOVESPEED;
    else    circle.velocity.x *= CIRCLE_DECELERATION;

    //���x�̐���
    circle.velocity.x = std::clamp(circle.velocity.x, -CIRCLE_MAXSPEED, CIRCLE_MAXSPEED);
    //���x���ʒu�ɑ��
    circle.angle += ToRadian(circle.velocity.x);
}

//�e��������
void Game3_Manager::bullet_init()
{
    //�e
    bullet.pos = { -100, -600 };
    bullet.texPos = { 0,0 };
    bullet.texSize = { 70, 70 };
    bullet.pivot = bullet.texSize / 2;
    bullet.Dradius = 24;
    bullet.angle = 0;

    //�ʒu��ݒ�
    float angle = rand() % 360;
    float x = (circle.pos.x) + cosf(angle) * back[3].pos.x;
    float y = (circle.pos.y) + sinf(angle) * back[2].texSize.y;
    bullet.pos = { x, y };

    //�J�E���^�[�����Z�b�g
    spawn_counter = 0;
}

//�e�̏���
void Game3_Manager::bullet_move()
{
    //�L���b�`��̃C���^�[�o��
    spawn_counter++;
    if (spawn_counter < spawn_interval)  return;
    debug::setString("Bullet Activated!");
    //���S�Ɉړ�
    bullet.angle = p_to_p_angle(circle.pos, bullet.pos);
    bullet.vector_normal = { cosf(bullet.angle), sinf(bullet.angle) };
    bullet.velocity = bullet.vector_normal * bullet_speed;
    //���x���ʒu�ɑ��
    bullet.pos += bullet.velocity;
}

//�����蔻��
void Game3_Manager::is_safe()
{
    //�����蔲�����ꍇ
    if (circle_collision(circle.pos, bullet.pos, 1, 1))
    {
        bullet_init();
    }
    //�~�X�������ꍇ
    if (circle_collision(circle.pos, bullet.pos, circle.Dradius, bullet.Dradius) && product < SAFE_ANGLE)
    {
        bullet_init();
        missed_game[2] = true;
    }
}
