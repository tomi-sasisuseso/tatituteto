#include "all.h"

extern Sprite* Square;
extern Sprite* Frame;
extern Sprite* Game4_beruto;
extern Sprite* Game4_hole;
extern Sprite* Game4_box;


extern OBJ2D back[MAX_GAMES];

#define box_difference 5
#define belt_conveyor_while 128
#define belt_conveyor_width 161

const VECTOR2 square_offsets[4] =
{
    {0, 0},
    {0, 100},
    {0, 200},
    {0, 300}
};

Squares::Squares(float x, float y)
{
    /*Square = sprite_load(L"./Data/images/ÉQÅ[ÉÄ2_éläp.png");
    Frame = sprite_load(L"./Data/images/ÉQÅ[ÉÄ2_òg.png");
    Å@âÊëúÇÃì«Ç›çûÇ›Ç‡ÉRÉìÉXÉgÉâÉNÉ^Ç≈ÇÕÇ≈Ç´Ç»Ç¢ÅH
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
        a.pos.y -= a.texSize.y*a.scale.y;
    }
    if (TRG(0) & PAD_DOWN) {
        a.pos.y += a.texSize.y*a.scale.y;
    }
    
    a.pos.y = std::clamp(a.pos.y,
        (frame.pos.y - (frame.texSize.y * frame.scale.y) / 2.0f + (a.texSize.y * a.scale.y / 2.0f) + 1.0f),
        (frame.pos.y + (frame.texSize.y * frame.scale.y) / 2.0f - (a.texSize.y * a.scale.y / 2.0f) - 1.0f));
    
}


void Squares::square_slide(float x)
{
    if (a.pos.x > x) {
        a.pos.x -= 16;
        frame.pos.x -= 16;
    }
    else {
        a.pos.x = x;
        frame.pos.x = x;
    }
}

void Squares::square_shrink()
{
    frame.scale *= 0.99;
    if (frame.pos.y > SCREEN_H / 4) frame.pos.y -= 4;
    else frame.pos.y = SCREEN_H / 4;
    
    a.scale *= 0.99;
   /* if ((frame.pos.y - frame.texSize.y / 2 + (a.texSize.y / 2) + 1)* a.scale.y) a.pos.y -= 4;
    else a.pos.y = (frame.pos.y - frame.texSize.y / 2 + (a.texSize.y / 2) + 1) ;*/
}


float Squares::frame_getPos(){
    return frame.pos.y+1;// +1ÇÕògÇÃëæÇ≥ï™Ç∏ÇÁÇµÇƒÇ¢ÇÈÅB 
}

float Squares::frame_getScale(){
    return frame.scale.y; 
}

VECTOR2 Squares::getTexP(){
    return a.texPos; 
}

float Squares::frame_getTexS(){
    return frame.texSize.y; 
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


/////// èoåªÇ≥ÇπÇΩíeÇìÆÇ©ÇµÇƒÇÈ ///////
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

/////// íeÇÃà íuÇåàÇﬂÇƒÇÈ ///////
VECTOR2 SHOOTER::ShotPosition(VECTOR2 origin, float height, float num)
{
    VECTOR2 shot_pos;
    shot_pos = { origin.x, origin.y + (height-(bullet->parameter.texSize.y/2*bullet->parameter.scale.y) + num) };

    return shot_pos;
}

/////// íeÇèoåªÇ≥ÇπÇƒÇÈ ///////
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
                    bullet[i].parameter.scale.x *= 1;
                }
                else
                {
                    bullet[i].parameter.speed = { -5,0 };
                    bullet[i].parameter.scale.x *= -1;
                }

                bullet[i].parameter.isLiving = true;

                spawnFlag = rand() % 300 + 300;
                bullet_timer = 0;

                return;
            }
        }
    }
}

/////// íeÇ™ÉQÅ[ÉÄÇQÇÃê^ÇÒíÜÇ»ÇÁ isLiving Ç falseÇ…Ç∑ÇÈÅB///////
void SHOOTER::LivingCheck()
{
    for (int i = 0; i < SHOT_MAX; i++)
    {
        if (bullet[i].parameter.pos.x == game2_center)
        {
            bullet[i].parameter.isLiving = false;

            // íeÇ™îΩì]ÇµÇƒÇ¢ÇΩÇÁ -1 Ç©ÇØÇƒå≥ÇÃå¸Ç´Ç…ñﬂÇ∑ //
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
        
        //bullet[i].parameter.pos.y -= 4;
    }
    
}

void Game4_Manager::Game4_Manager_update()
{
    belt_conveyor.pos.x = back[3].pos.x+240;
    belt_conveyor.pos.y = back[3].pos.y;
    

    hole.pos.x = belt_conveyor.pos.x;
    hole.pos.y = belt_conveyor.pos.y+belt_conveyor.texSize.y;
   
    //box.pos.x = belt_conveyor.pos.x;
    //box.pos.y = belt_conveyor.pos.y;
    hole_update();
    box_update();
}

void Game4_Manager::Game4_Manager_init()
{
    belt_conveyor.scale = { 1,1 };
    belt_conveyor.texPos = { 0,0 };
    belt_conveyor.texSize = { 450,374 };
    belt_conveyor.pivot = { 0,0 };

    hole.scale = { 1,1 };
    hole.texPos = { 0,0 };
    hole.texSize = { 450,160 };
    hole.pivot = { 0,0 };
    
    box.scale = { 1,1 };
    box.texPos = { 0,0 };
    box.texSize = { 150,150 };
    box.pivot = { 0,0 };

}

void Game4_Manager::hole_update()
{
    //if (STATE(0) & PAD_RIGHT) {
    if (hole.texPos.x != 1 * hole.texSize.x) {
        hole.anime = hole.animetimer / 9 % 2;
        hole.texPos.x = hole.anime * hole.texSize.x;
        ++hole.animetimer;
    }

    else {
        hole.anime = hole.animetimer / 20 % 1;
        hole.texPos.x = hole.anime * hole.texSize.x;
        ++hole.animetimer;
        if (hole.texPos.x = 3 * hole.texSize.x) {
            hole.texPos = {};
            hole.anime = 0;
            hole.animetimer = 0;
        }
    }

}

void Game4_Manager::box_update()
{
    box_timer++;
    if (box_timer >= spwanFlag) {
        box.isLiving = true;
        int r = rand() % 2;
        if (r == 0) {
            box.pos.x = belt_conveyor.pos.x + box_difference;
            box.pos.y = belt_conveyor.pos.y;
        }
        else if (r == 1) {
            box.pos.x = belt_conveyor.pos.x + box_difference + belt_conveyor_while+belt_conveyor_width;
            box.pos.y = belt_conveyor.pos.y;
        }
        box.speed = { 0,5 };
        box_timer = 0;
        spwanFlag = rand() % 300 + 600;
    }

    box.pos.y += box.speed.y;
    LivingCheck();

}

void Game4_Manager::LivingCheck()
{
    if (box.pos.y >= SCREEN_H) {
        /*
        * ïœçXïKóvÅ@judghä÷êîÇ≈Ç†Ç»Ç…Ç®Ç∆ÇπÇÈÇÊÇ§Ç…Ç∑ÇÈÅB
        */
        box.isLiving = false;

    }
}

void Game4_Manager::Game4_render()
{
    sprite_render(Game4_beruto,
        belt_conveyor.pos.x, belt_conveyor.pos.y,
        belt_conveyor.scale.x, belt_conveyor.scale.y,
        belt_conveyor.texPos.x, belt_conveyor.texPos.y,
        belt_conveyor.texSize.x, belt_conveyor.texSize.y,
        belt_conveyor.pivot.x, belt_conveyor.pivot.y);

    sprite_render(Game4_hole,
        hole.pos.x, hole.pos.y,
        hole.scale.x, hole.scale.y,
        hole.texPos.x, hole.texPos.y,
        hole.texSize.x, hole.texSize.y,
        hole.pivot.x, hole.pivot.y);

    if (box.isLiving) {
        sprite_render(Game4_box,
            box.pos.x, box.pos.y,
            box.scale.x, box.scale.y,
            box.texPos.x, box.texPos.y,
            box.texSize.x, box.texSize.y,
            box.pivot.x, box.pivot.y);
    }
}
