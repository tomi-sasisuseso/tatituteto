#pragma once
#include "all.h"
class Game1_Manager {
private:
    OBJ2D stage;
    OBJ2D ball;

    int control = 0;

public:
    void Game1_init();
    void Game1_deinit();
    void Game1_Manager_update();
    void Game1_Manager_slide(float x);
    void Game1_Manager_shrink();
    void Game1_judge();
    void stage_move();
    void ball_init();
    void ball_move();
   

    void Game1_render();
};