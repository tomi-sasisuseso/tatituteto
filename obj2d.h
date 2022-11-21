#ifndef OBJ2D_H
#define OBJ2D_H


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

    /*privateにOBJ2D a[4]を入れてget関数を作って試してみたけど背景を動かすときに
    posも動かしたかったからpublicに戻した。drowで描画するときも
    getだと配列の1番目のやつしか返さないのでget関数を配列分作る必要があるの？
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
    * bulletは今回のゲームでは基本的に一画面に１つしか出ないけど
    * 練習として１００発出せるようなコードの組み方をしてる。
    * たくさん出したければbulletのようにすればいいよ。
    */
    SHOT bullet[SHOT_MAX];
    
    inline static float mag[4] = {  0.4f, 0.6f, 0.8f };

public:
    int spawnFlag;
    SHOOTER();
    int bullet_timer;

    void Update(); // 出現させた弾を動かしてる

    VECTOR2 ShotPosition(VECTOR2 origin, float height, float num); // 弾の位置を決めてる

    void Shot(VECTOR2 origin, float height, float num); // 弾を出現させてる

    void LivingCheck(); // 弾がゲーム２の真ん中なら isLiving を falseにする。

    void game2_shrink(); // 縮小してる

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