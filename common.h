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
#define SCREEN_W        1280
#define SCREEN_H        720

// シーンのラベル
#define SCENE_NONE      -1
#define SCENE_TITLE     0
#define SCENE_GAME      1

// マクロ
#define ToRadian( x )   DirectX::XMConvertToRadians( x )
#define ToDegree( x )   DirectX::XMConvertToDegrees( x )
#define PI              DirectX::XM_PI

// 変数
extern int curScene;
extern int nextScene;

#endif//COMMON_H