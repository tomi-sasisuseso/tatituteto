<<<<<<< HEAD
=======
#ifndef OBJ2D_H
#define OBJ2D_H
//******************************************************************************
//
//
//      obj2d.h
//
//
//******************************************************************************
#include "../GameLib/game_lib.h"

//------< �\���� >--------------------------------------------------------------
struct OBJ2D
{
    int                 timer;      // �^�C�}�[

    bool                onGround;   // �n�ʃt���O
    bool                jumpEnd;    // ���n�t���O
    char                pad[2];     // �p�f�B���O�i���ԁj

    VECTOR2             pos;        // �ʒu
    VECTOR2             scale;      // �X�P�[��
    VECTOR2             texPos;     // �摜�ʒu
    VECTOR2             texSize;    // �摜�T�C�Y
    VECTOR2             pivot;      // ��_
    float               angle;
    VECTOR4             color;      // �F

    VECTOR2             speed;      // ���x
    int                 jumpCount;  // �c��W�����v��
    int                 act;        // �v���C���[�̍s���J�ڗp
    int                 anime;      // �A�j�������݉��R�}�ڂ�
    int                 animeTimer; // �A�j���p�^�C�}�[

    float radius;
    VECTOR2 offset;
};

//------< �֐� >----------------------------------------------------------------


#endif//OBJ2D_H

>>>>>>> 648788432114e43e25373147bd9ea4406e5cc164
#include "all.h"

enum class BulletTag
{
    None,//�����Ȃ�����
    W,
    A,
    S,
    D
};

<<<<<<< HEAD
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
=======
>>>>>>> 648788432114e43e25373147bd9ea4406e5cc164

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

<<<<<<< HEAD
};
=======
};

>>>>>>> 648788432114e43e25373147bd9ea4406e5cc164
