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

//------< 構造体 >--------------------------------------------------------------
struct OBJ2D
{
    int                 timer;      // タイマー

    bool                onGround;   // 地面フラグ
    bool                jumpEnd;    // 着地フラグ
    char                pad[2];     // パディング（隙間）

    VECTOR2             pos;        // 位置
    VECTOR2             scale;      // スケール
    VECTOR2             texPos;     // 画像位置
    VECTOR2             texSize;    // 画像サイズ
    VECTOR2             pivot;      // 基準点
    float               angle;
    VECTOR4             color;      // 色

    VECTOR2             speed;      // 速度
    int                 jumpCount;  // 残りジャンプ回数
    int                 act;        // プレイヤーの行動遷移用
    int                 anime;      // アニメが現在何コマ目か
    int                 animeTimer; // アニメ用タイマー

    float radius;
    VECTOR2 offset;
};

//------< 関数 >----------------------------------------------------------------


#endif//OBJ2D_H

>>>>>>> 648788432114e43e25373147bd9ea4406e5cc164
#include "all.h"

enum class BulletTag
{
    None,//何もない空状態
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

<<<<<<< HEAD
};
=======
};

>>>>>>> 648788432114e43e25373147bd9ea4406e5cc164
