#pragma once
#include "all.h"

class Game3_Manager {
private:
    //パラメータ
    //SAFE_ANGLEについて　-1から1の間で調整　値が大きくなるほどセーフの判定が厳しくなる
    const float CIRCLE_MOVESPEED = 0.15f;
    const float CIRCLE_MAXSPEED = 3.0f;
    const float CIRCLE_DECELERATION = 0.8f;
    const float SAFE_ANGLE = 0.82f;
    int bullet_speed = 2;
    int spawn_interval = 300;

    float product = 0;
    int spawn_counter = 0;

    OBJ2D circle;
public:
    OBJ2D bullet;
    void Game3_Manager_init();
    void Game3_Manager_deinit();
    void Game3_Manager_update();
    void Game3_Manager_slide(float x);
    void Game3_Manager_shrink();

    void circle_move();
    void bullet_init();
    void bullet_move();
    void is_safe();
    void Game3_Manager_render();
};