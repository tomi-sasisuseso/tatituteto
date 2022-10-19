#ifndef COMMON_H
#define COMMON_H

//******************************************************************************
//
//
//      common.h
//
//
//******************************************************************************

// ��ʂ̑傫��
#define SCREEN_W        1280
#define SCREEN_H        720

// �V�[���̃��x��
#define SCENE_NONE      -1
#define SCENE_TITLE     0
#define SCENE_GAME      1

// �}�N��
#define ToRadian( x )   DirectX::XMConvertToRadians( x )
#define ToDegree( x )   DirectX::XMConvertToDegrees( x )
#define PI              DirectX::XM_PI

// �ϐ�
extern int curScene;
extern int nextScene;

#endif//COMMON_H