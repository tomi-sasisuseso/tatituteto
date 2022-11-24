#pragma once
#include"all.h"
class Game5_Manager {
private:
    //パラメータ
    const float GRAVITY = 0.5f;
    const float MOVE_SPEED = 5.0f;
    const float ROTATE_SPEED = MOVE_SPEED * 0.6f;
    const float JUMP_POWER = 20.0f;
    const float SPAWN_POS_X = SCREEN_W + 100;
    const float DESPAWN_POS_X = -100;
    const float BORDER_TO_FALL = 780.0f;
    //最大から最少までの間からランダムに待機時間を設定
    const int MAX_WAIT_TIME = 1000;
    const int MIN_WAIT_TIME = 100;

    int game5_timer;

    OBJ2D ball3;
    OBJ2D hole;

    float wait_time = 0;
    float floor_height = 0;
    bool is_on_floor = false;
public:
    OBJ2D background;
    void Game5_Manager_init();
    void Game5_Manager_deinit();
    void Game5_Manager_update();

    void Game5_Manager_render();
    void ball_move();
    void hole_init();
    void hole_move();
};
