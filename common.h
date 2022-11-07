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
#define SCREEN_W        1920
#define SCREEN_H        1080
#define CENTER          {SCREEN_W / 2, SCREEN_H / 2}

// �V�[���̃��x��
#define SCENE_NONE      -1
#define SCENE_TITLE     0
#define SCENE_GAME      1
#define SCENE_SCORE     2

// �}�N��
#define ToRadian( x )   DirectX::XMConvertToRadians( x )
#define ToDegree( x )   DirectX::XMConvertToDegrees( x )
#define PI              DirectX::XM_PI

/////// �Q�[���� ///////
#define MAX_GAMES       6

// �ϐ�
extern int curScene;
extern int nextScene;

#endif//COMMON_H