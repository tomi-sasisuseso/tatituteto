#pragma once
#include "change gravity.h"

#define Stage_error 40 //ステージのグレーの枠の誤差

class Game6_Manager {
private:

    int Game6_timer;

    //パラメータ
    const float DURATION = 60;
    const float SPAWN_POS_X = SCREEN_W + 200.0f;
    const float DESPAWN_POS_X = -300.0f;
    const float COYOTE_TIME = 20.0f;
    float MOVE_SPEED = 0.0f;

    OBJ2D background;
    OBJ2D barrier;

    int triangle_easetimer = INT_MAX;
    VECTOR2 upperpos;
    VECTOR2 downerpos;

    bool reverse = true;
    float interval = 112.5f;

public:
    OBJ2D triangle;
    void Game6_Manager_init();
    void Game6_Manager_deinit();
    void Game6_Manager_update();
    void Game6_Manager_render();
    void triangle_move();
    void barrier_init();
    void barrier_move();
};

