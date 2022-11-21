#ifndef OBJ2D_H
#define OBJ2D_H


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



class Squares {
public:
    Squares() {}
    Squares(float x, float y);

    void pos_Init(float x, float y);
    void scale_Init(float x, float y);
    void texP_Init(float x, float y);
    void texS_Init(float x, float y);
    void pivot_Init(float x, float y);
    
    void square_render();
    void square_slide(float x);
    void square_shrink();
    void update();

    /*private��OBJ2D a[4]������get�֐�������Ď����Ă݂����ǔw�i�𓮂����Ƃ���
    pos��������������������public�ɖ߂����Bdrow�ŕ`�悷��Ƃ���
    get���Ɣz���1�Ԗڂ̂�����Ԃ��Ȃ��̂�get�֐���z�񕪍��K�v������́H
    */
    
    float frame_getPos();
    float frame_getScale();
    float frame_getTexS();
    
    VECTOR2 getTexP();
    VECTOR2 getPivot();

    OBJ2D a;
protected:
    OBJ2D frame;
};

class SHOOTER /*:public Squares*/
{
private:
    /*
    * bullet�͍���̃Q�[���ł͊�{�I�Ɉ��ʂɂP�����o�Ȃ�����
    * ���K�Ƃ��ĂP�O�O���o����悤�ȃR�[�h�̑g�ݕ������Ă�B
    * ��������o���������bullet�̂悤�ɂ���΂�����B
    */
    SHOT bullet[SHOT_MAX];
    
    inline static float mag[4] = {  0.4f, 0.6f, 0.8f };

public:
    int spawnFlag;
    SHOOTER();
    int bullet_timer;

    void Update(); // �o���������e�𓮂����Ă�

    VECTOR2 ShotPosition(VECTOR2 origin, float height, float num); // �e�̈ʒu�����߂Ă�

    void Shot(VECTOR2 origin, float height, float num); // �e���o�������Ă�

    void LivingCheck(); // �e���Q�[���Q�̐^�񒆂Ȃ� isLiving �� false�ɂ���B

    void game2_shrink(); // �k�����Ă�

    void shot_render();

};

class Game4_Manager
{
private:
    OBJ2D belt_conveyor;
    OBJ2D hole;
    bool animeFlag;
    bool animeFlag_LeftCheck;
    const int interval = 9;
    const int frameCount = 3;
    const int holeKeep = 24;
public:
    OBJ2D box;
    int box_timer = 0;
    int spwanFlag = rand() % 300 + 600;
    void Game4_Manager_update();
    void Game4_Manager_init();
    void hole_update();
    void box_update();
    void LivingCheck(); 

    void Game4_render();
};
#endif