#pragma once
#include "all.h"

class Game3_Manager {
private:
    //�p�����[�^
    //SAFE_ANGLE�ɂ��ā@-1����1�̊ԂŒ����@�l���傫���Ȃ�قǃZ�[�t�̔��肪�������Ȃ�
    const float CIRCLE_MOVESPEED = 0.15f;
    const float CIRCLE_MAXSPEED = 3.0f;
    const float CIRCLE_DECELERATION = 0.8f;
    const float SAFE_ANGLE = 0.82f;
    int bullet_speed = 5;
    int spawn_interval = 30;

    float product = 0;
    int spawn_counter = 0;

    OBJ2D circle;
    OBJ2D bullet;
public:
    void Game3_Manager_init();
    void Game3_Manager_deinit();
    void Game3_Manager_update();
    void circle_move();
    void bullet_init();
    void bullet_move();
    void is_safe();
    void Game3_Manager_render();
};