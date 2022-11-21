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
    float               alpha;

    VECTOR2             vector_normal;     // ���K���ς݃x�N�g��

    VECTOR2             speed;      // ���x
    VECTOR2             speed1;     // ���x
    VECTOR2             speed2;     // ���x
    VECTOR2             speed3;     // ���x
    VECTOR2             speed4;     // ���x

    VECTOR2             velocity;   // �����x

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

