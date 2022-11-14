#ifndef OBJ2D_H
#define OBJ2D_H

#include "all.h"

extern float game2_center;

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
    /* 1つずつにパラメータを設定するなら
       OBJ2D parameter を配列にする必要がある 
       今回は1ずつの弾のパラメータは同じなので
       OBJ2Dは一つでいい。*/

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

    /////// 出現させた弾を動かしてる ///////
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

    /////// 弾の位置を決めてる ///////
    VECTOR2 ShotPosition(VECTOR2 origin, float height, int num)
    {
        VECTOR2 shot_pos;
        shot_pos = { origin.x, origin.y + (height * mag[num]) };

        return shot_pos;
    }

    /////// 弾を出現させてる ///////
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

    /////// 弾がゲーム２の真ん中なら isLiving を falseにする。///////
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

    /*privateにOBJ2D a[4]を入れてget関数を作って試してみたけど背景を動かすときに
    posも動かしたかったからpublicに戻した。drowで描画するときも
    getだと配列の1番目のやつしか返さないのでget関数を配列分作る必要があるの？
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