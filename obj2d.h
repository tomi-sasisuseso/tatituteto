#ifndef OBJ2D_H
#define OBJ2D_H

#include "all.h"

extern float game2_center;

enum class BulletTag
{
    None,//�����Ȃ�����
    W,
    A,
    S,
    D
};


struct OBJ2D {
    
    int state;
    int hp;
    int ap;

    std::string wasd;

    VECTOR2             pos;        // �ʒu
    VECTOR2             posLefet;   // �����̓G�ʒu
    VECTOR2             scale;      // �X�P�[��
    VECTOR2             size;       // ������
    VECTOR2             texPos;     // �摜�ʒu
    VECTOR2             texSize;    // �摜�T�C�Y
    VECTOR2             pivot;      // ��_
    float               angle;
    VECTOR4             color;      // �F

    VECTOR2             speed;      // ���x
    VECTOR2             speed1;      // ���x
    VECTOR2             speed2;      // ���x
    VECTOR2             speed3;      // ���x
    VECTOR2             speed4;      // ���x
    VECTOR2             velocity;

    //�~�Ɖ~�̓����蔻��
    float Dradius;
    VECTOR2 offset;

    //���ꂪtrue�Ȃ琶�����A�������Ȃ�X�V��`����s��
    bool isLivingBack;
    bool isLiving=false;

    int anime, animetimer;
    int anime2, animetimer2;
    int anime3, animetimer3;
    int anime4, animetimer4;
    int deathtimer;
    int deathanime;
    int Cradius;
    BulletTag bulletTag;

    int shotCount;
};

class SHOT 
{
public:
    /* 1���Ƀp�����[�^��ݒ肷��Ȃ�
       OBJ2D parameter ��z��ɂ���K�v������ 
       �����1���̒e�̃p�����[�^�͓����Ȃ̂�
       OBJ2D�͈�ł����B*/

    //OBJ2D parameter[SHOT_MAX];
    OBJ2D parameter;


    GameLib::Sprite* sprite;
    BulletTag tag;

    void Update()
    {
        parameter.pos += parameter.speed;
    }
};

class SHOOTER
{
private:
    SHOT bullet[SHOT_MAX];
    
    inline static float mag[4] = { 0.2, 0.4, 0.6, 0.8 };

public:
    int spwaonFlag;
    SHOOTER();
    int bullet_timer;

    /////// �o���������e�𓮂����Ă� ///////
    void Update()
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
    VECTOR2 ShotPosition(VECTOR2 origin, float height, int num)
    {
        VECTOR2 shot_pos;
        shot_pos = { origin.x, origin.y + (height * mag[num]) };

        return shot_pos;
    }

    /////// �e���o�������Ă� ///////
    void Shot(VECTOR2 origin, float height, int num)
    {
        if (bullet_timer >= spwaonFlag) {
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

                    spwaonFlag = 100;//rand() % 300 + 300;
                    bullet_timer = 0;

                    return;
                }
            }
        }
    }

    /////// �e���Q�[���Q�̐^�񒆂Ȃ� isLiving �� false�ɂ���B///////
    void LivingCheck()
    {
        for (int i = 0; i < SHOT_MAX; i++)
        {
            if (bullet[i].parameter.pos.x == game2_center) 
            {
                bullet[i].parameter.isLiving = false;
                // 
                if (bullet[i].parameter.scale.x < 0) {
                    bullet[i].parameter.scale.x *= -1;
                }
            }
        }
    }

    void game2_shrink();

    void shot_render();

};


class Squares {
public:
    Squares() {}
    Squares(float x, float y);

    void pos_Init(float x, float y);
    void scale_Init(float x, float y);
    void texP_Init(float x, float y);
    void texS_Init(float x, float y);
    void pivot_Init(float x, float y);
    
    void update();

    /*private��OBJ2D a[4]������get�֐�������Ď����Ă݂����ǔw�i�𓮂����Ƃ���
    pos��������������������public�ɖ߂����Bdrow�ŕ`�悷��Ƃ���
    get���Ɣz���1�Ԗڂ̂�����Ԃ��Ȃ��̂�get�֐���z�񕪍��K�v������́H
    */
    
    VECTOR2 getPos();
    VECTOR2 getScale();
    VECTOR2 getTexP();
    VECTOR2 getTexS();
    VECTOR2 getPivot();

    OBJ2D a;
private:
};


#endif