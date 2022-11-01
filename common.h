#ifndef COMMON_H
#define COMMON_H

//******************************************************************************
//
//
//      common.h
//
//
//******************************************************************************

// 画面の大きさ
#define SCREEN_W        1920
#define SCREEN_H        1080
#define CENTER          {SCREEN_W / 2, SCREEN_H / 2}

// シーンのラベル
#define SCENE_NONE      -1
#define SCENE_TITLE     0
#define SCENE_GAME      1
#define SCENE_SCORE     2

// マクロ
#define ToRadian( x )   DirectX::XMConvertToRadians( x )
#define ToDegree( x )   DirectX::XMConvertToDegrees( x )
#define PI              DirectX::XM_PI

/////// ゲーム数 ///////
#define MAX_GAMES       6

// 変数
extern int curScene;
extern int nextScene;

#endif//COMMON_H