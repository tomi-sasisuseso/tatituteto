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
    float               alpha;

    VECTOR2             vector_normal;     // 正規化済みベクトル

    VECTOR2             speed;      // 速度
    VECTOR2             speed1;     // 速度
    VECTOR2             speed2;     // 速度
    VECTOR2             speed3;     // 速度
    VECTOR2             speed4;     // 速度

    VECTOR2             velocity;   // 加速度

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

