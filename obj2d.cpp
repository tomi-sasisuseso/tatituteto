#include "obj2d.h"

static const VECTOR2 square_offsets[4] =
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
    a[0].pos = { x, y };
    a[1].pos = a[0].pos + square_offsets[1];
    a[2].pos = a[1].pos + square_offsets[2];
    a[3].pos = a[2].pos + square_offsets[3];

}

void Squares::scale_Init(float x, float y)
{
    a[0].scale = { x,y };
    a[1].scale = { x,y };
    a[2].scale = { x,y };
    a[3].scale = { x,y };
}

void Squares::texP_Init(float x, float y)
{
    a[0].texPos = { x,y };
    a[1].texPos = { x,y };
    a[2].texPos = { x,y };
    a[3].texPos = { x,y };
}

void Squares::texS_Init(float x, float y)
{
    a[0].texSize = { x,y };
    a[1].texSize = { x,y };
    a[2].texSize = { x,y };
    a[3].texSize = { x,y };
}

void Squares::pivot_Init(float x, float y)
{
    a[0].pivot = { x,y };
    a[1].pivot = { x,y };
    a[2].pivot = { x,y };
    a[3].pivot = { x,y };
}

void Squares::update()
{
}

VECTOR2 Squares::getPos(){
    return a[0].pos; 
}

VECTOR2 Squares::getScale(){
    return a[0].scale; 
}

VECTOR2 Squares::getTexP(){
    return a[0].texPos; 
}

VECTOR2 Squares::getTexS(){
    return a[0].texSize; 
}

VECTOR2 Squares::getPivot(){
    return a[0].pivot; 
}

