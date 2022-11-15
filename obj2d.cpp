#include "obj2d.h"

extern Sprite* Square;
extern Sprite* Frame;

const VECTOR2 square_offsets[4] =
{
    {0, 0},
    {0, 100},
    {0, 200},
    {0, 300}
};

Squares::Squares(float x, float y)
{
    /*Square = sprite_load(L"./Data/images/�Q�[��2_�l�p.png");
    Frame = sprite_load(L"./Data/images/�Q�[��2_�g.png");
    �@�摜�̓ǂݍ��݂��R���X�g���N�^�ł͂ł��Ȃ��H
    */

    frame.pos = { x,y };
    frame.scale = { 1,1 };
    frame.texPos = { 0,0 };
    frame.texSize = { 102,402 };
    frame.pivot = { 102/2,402/2 };
}

void Squares::pos_Init(float x, float y)
{
    a.pos = { x, y };
}

void Squares::scale_Init(float x, float y)
{
    a.scale = { x,y };

}

void Squares::texP_Init(float x, float y)
{
    a.texPos = { x,y };
}

void Squares::texS_Init(float x, float y)
{
    a.texSize.x = x;
    a.texSize.y = y;
}

void Squares::pivot_Init(float x, float y)
{
    a.pivot = { x,y };
}

void Squares::update()
{
    if (TRG(0) & PAD_UP) {
        a.pos.y -= a.texSize.y;
    }
    if (TRG(0) & PAD_DOWN) {
        a.pos.y += a.texSize.y;
    }
    
    a.pos.y = std::clamp(a.pos.y,
        frame.pos.y - frame.texSize.y / 2 + (a.texSize.y / 2) + 1,
        frame.pos.y + frame.texSize.y / 2 - (a.texSize.y / 2) - 1);
    
}


void Squares::square_slide()
{
    if (a.pos.x > SCREEN_W - SCREEN_W / 4) {
        a.pos.x -= 16;
        frame.pos.x -= 16;
    }
    else {
        a.pos.x = SCREEN_W - SCREEN_W / 4;
        frame.pos.x = SCREEN_W - SCREEN_W / 4;
    }
}

float Squares::frame_getPos(){
    return frame.pos.y+1;// +1�͘g�̑��������炵�Ă���B 
}

float Squares::frame_getScale(){
    return frame.scale.y; 
}

VECTOR2 Squares::getTexP(){
    return a.texPos; 
}

VECTOR2 Squares::getTexS(){
    return a.texSize; 
}

VECTOR2 Squares::getPivot(){
    return a.pivot; 
}

void Squares::square_render()
{    
    sprite_render(Square,
        a.pos.x, a.pos.y,
        a.scale.x, a.scale.y,
        a.texPos.x, a.texPos.y,
        a.texSize.x, a.texSize.y,
        a.pivot.x, a.pivot.y
        );
    
    sprite_render(Frame,
        frame.pos.x, frame.pos.y,
        frame.scale.x, frame.scale.y,
        frame.texPos.x, frame.texPos.y,
        frame.texSize.x, frame.texSize.y,
        frame.pivot.x, frame.pivot.y
        );
    
}

SHOOTER::SHOOTER()
{
    bullet_timer = 0;
    spawnFlag = rand() % 300 + 300;
    for (int i = 0; i < SHOT_MAX; i++)
    {
        bullet[i].parameter.scale = { 1,1 };
        bullet[i].parameter.texPos = { 0,0 };
        bullet[i].parameter.texSize = { 100,100 };
        bullet[i].parameter.pivot = { 100/2,100/2 };
    }
}


/////// �o���������e�𓮂����Ă� ///////
void SHOOTER::Update()
{
    for (int i = 0; i < SHOT_MAX; i++)
    {
        if (bullet[i].parameter.isLiving) {
            bullet[i].Update();
        }
    }
    LivingCheck();
}

/////// �e�̈ʒu�����߂Ă� ///////
VECTOR2 SHOOTER::ShotPosition(VECTOR2 origin, float height, float num)
{
    VECTOR2 shot_pos;
    shot_pos = { origin.x, origin.y + (height + num) };

    return shot_pos;
}

/////// �e���o�������Ă� ///////
void SHOOTER::Shot(VECTOR2 origin, float height, float num)
{
    if (bullet_timer >= spawnFlag) {
        for (int i = 0; i < SHOT_MAX; i++)
        {
            if (!bullet[i].parameter.isLiving)
            {
                bullet[i].parameter.pos = ShotPosition(origin, height, num);

                if (bullet[i].parameter.pos.x < game2_center)
                {
                    bullet[i].parameter.speed = { 5,0 };
                    bullet[i].parameter.scale.x *= -1;
                }
                else
                {
                    bullet[i].parameter.speed = { -5,0 };
                    bullet[i].parameter.scale.x *= 1;
                }

                bullet[i].parameter.isLiving = true;

                spawnFlag = 100;//rand() % 300 + 300;
                bullet_timer = 0;

                return;
            }
        }
    }
}

/////// �e���Q�[���Q�̐^�񒆂Ȃ� isLiving �� false�ɂ���B///////
void SHOOTER::LivingCheck()
{
    for (int i = 0; i < SHOT_MAX; i++)
    {
        if (bullet[i].parameter.pos.x == game2_center)
        {
            bullet[i].parameter.isLiving = false;

            // �e�����]���Ă����� -1 �����Č��̌����ɖ߂� //
            if (bullet[i].parameter.scale.x < 0) {
                bullet[i].parameter.scale.x *= -1;
            }
        }
    }
}

void SHOOTER::shot_render()
{
    texture::begin(1);
    for (int i = 0; i < SHOT_MAX; i++)
    {
        if (bullet[i].parameter.isLiving) {
            texture::draw(1,
                bullet[i].parameter.pos,
                bullet[i].parameter.scale,
                bullet[i].parameter.texPos,
                bullet[i].parameter.texSize,
                bullet[i].parameter.pivot);
        }
    }
    texture::end(1);
}

void SHOOTER::game2_shrink()
{
    for (int i = 0; i < SHOT_MAX; i++)
    {
        bullet[i].parameter.scale *= 0.99;
        bullet[i].parameter.pos.y -= 4;
    }
}
