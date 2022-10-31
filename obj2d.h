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