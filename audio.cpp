#include "all.h"

void audio_init()
{

    music::load(XWB_SYSTEM, L"./Data/Musics/bgm_maoudamashii_8bit29.wav");


    music::load(1, L"./Data/Musics/game_maoudamashii_5_village10.wav");
    music::load(2, L"./Data/Musics/game_maoudamashii_1_battle34.wav");
    music::load(3, L"./Data/Musics/bosu.wav");
    music::load(4, L"./Data/Musics/piano.wav");
    music::load(5, L"./Data/Musics/okesutora.wav");


    sound::load(0, L"./Data/Sounds/system.xwb");   // メニューなどのSE

    sound::load(1, L"./Data/Sounds/stage1.xwb");   // ステージ固有のSE

    sound::load(2, L"./Data/Sounds/Win/oto.xwb");

    sound::setVolume(1, 3, 4.0f);
}


void audio_deinit()
{
    music::clear();
}
