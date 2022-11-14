#include "obj2d.h"

const VECTOR2 square_offsets[4] =
{
    {0, 0},
    {0, 100},
    {0, 200},
    {0, 300}
};

Squares::Squares(float x, float y)
{
    pos_Init(x, y);
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
    a.texSize = { x,y };
}

void Squares::pivot_Init(float x, float y)
{
    a.pivot = { x,y };
}

void Squares::update()
{
}

VECTOR2 Squares::getPos(){
    return a.pos; 
}

VECTOR2 Squares::getScale(){
    return a.scale; 
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

SHOOTER::SHOOTER()
{
    bullet_timer = 0;
    spwaonFlag = rand() % 300 + 300;
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
