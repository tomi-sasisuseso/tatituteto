#ifndef OBJ2D_H
#define OBJ2D_H

#include "all.h"

enum class BulletTag
{
    None,//何もない空状態
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

    VECTOR2             pos;        // 位置
    VECTOR2             posLefet;   // 左側の敵位置
    VECTOR2             scale;      // スケール
    VECTOR2             size;       // 幅高さ
    VECTOR2             texPos;     // 画像位置
    VECTOR2             texSize;    // 画像サイズ
    VECTOR2             pivot;      // 基準点
    float               angle;
    VECTOR4             color;      // 色

    VECTOR2             speed;      // 速度
    VECTOR2             speed1;      // 速度
    VECTOR2             speed2;      // 速度
    VECTOR2             speed3;      // 速度
    VECTOR2             speed4;      // 速度
    VECTOR2             velocity;

    //円と円の当たり判定
    float Dradius;
    VECTOR2 offset;

    //これがtrueなら生存中、生存中なら更新や描画を行う
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

    //VECTOR2             pos;        // 位置
    //VECTOR2             scale;      // スケール
    //VECTOR2             size;       // 幅高さ
    //VECTOR2             texPos;     // 画像位置
    //VECTOR2             texSize;    // 画像サイズ
    //VECTOR2             pivot;      // 基準点
    //VECTOR4             color;      // 色

    //VECTOR2             speed;      // 速度

    ////円と円の当たり判定
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

    /*privateにOBJ2D a[4]を入れてget関数を作って試してみたけど背景を動かすときに
    posも動かしたかったからpublicに戻した。drowで描画するときも
    getだと配列の1番目のやつしか返さないのでget関数を配列分作る必要があるの？
    こういう場合はprivateよりpublicのほうがいいの？
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