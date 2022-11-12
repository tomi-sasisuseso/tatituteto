#ifndef OBJ2D_H
#define OBJ2D_H

#include "all.h"

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
    bool isLiving;

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

class SHOT : public OBJ2D
{
public:
    GameLib::Sprite* sprite;
    BulletTag tag;
};

struct OBJ2DE {

    int hp;
    int ap;

    std::string wasd;

    //VECTOR2             pos;        // �ʒu
    //VECTOR2             scale;      // �X�P�[��
    //VECTOR2             size;       // ������
    //VECTOR2             texPos;     // �摜�ʒu
    //VECTOR2             texSize;    // �摜�T�C�Y
    //VECTOR2             pivot;      // ��_
    //VECTOR4             color;      // �F

    //VECTOR2             speed;      // ���x

    ////�~�Ɖ~�̓����蔻��
    //float radius;
    //VECTOR2 offset;

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
    ���������ꍇ��private���public�̂ق��������́H
    */
    
    VECTOR2 getPos();
    VECTOR2 getScale();
    VECTOR2 getTexP();
    VECTOR2 getTexS();
    VECTOR2 getPivot();

    OBJ2D a[4];
private:
};

#endif