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

//------< �\���� >--------------------------------------------------------------
struct OBJ2D
{
    int                 timer;      // �^�C�}�[

    bool                onGround;   // �n�ʃt���O
    bool                jumpEnd;    // ���n�t���O
    char                pad[2];     // �p�f�B���O�i���ԁj

    VECTOR2             pos;        // �ʒu
    VECTOR2             scale;      // �X�P�[��
    VECTOR2             texPos;     // �摜�ʒu
    VECTOR2             texSize;    // �摜�T�C�Y
    VECTOR2             pivot;      // ��_
    float               angle;
    VECTOR4             color;      // �F

    VECTOR2             speed;      // ���x
    int                 jumpCount;  // �c��W�����v��
    int                 act;        // �v���C���[�̍s���J�ڗp
    int                 anime;      // �A�j�������݉��R�}�ڂ�
    int                 animeTimer; // �A�j���p�^�C�}�[

    float radius;
    VECTOR2 offset;
};

//------< �֐� >----------------------------------------------------------------


#endif//OBJ2D_H