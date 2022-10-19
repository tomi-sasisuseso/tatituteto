#include "all.h"

void audio_init()
{
#if 1
//******************************************************************************
// TODO:01 音楽を読み込む
//------------------------------------------------------------------------------
/*
課題）
    □ 音楽ファイルを読み込みます。

手順）
    1. 音楽ファイルを読み込みます。例を参考に、music::load関数であと2曲読み込みましょう。
       下記の例では、0番のトラックに"bgm_maoudamashii_8bit29.wav"という音楽ファイルを
       読み込んでいます。

       1番のトラックに"game_maoudamashii_5_village10.wav"
       2番のトラックに"game_maoudamashii_1_battle34.wav"

    2. 第3引数に、その音楽のボリュームを入れる事ができます。デフォルト値は0.5fです。

    3. main.cppを確認して、このaudio_init関数がどこから呼ばれているか確認しておき
       ましょう。
*/
//******************************************************************************
#endif
    //例）
    music::load(XWB_SYSTEM, L"./Data/Musics/bgm_maoudamashii_8bit29.wav");

    //TODO_01
    music::load(1, L"./Data/Musics/game_maoudamashii_5_village10.wav");
    music::load(2, L"./Data/Musics/game_maoudamashii_1_battle34.wav");
    music::load(3, L"./Data/Musics/bosu.wav");
    music::load(4, L"./Data/Musics/piano.wav");
    music::load(5, L"./Data/Musics/okesutora.wav");


#if 21
//******************************************************************************
// TODO:21 効果音を読み込む
//------------------------------------------------------------------------------
/*
課題）
    □ 効果音ファイルのセット（*.xwb）を読み込みます。

手順）
    1. 例を参考に、sound::load関数であと1セット読み込みましょう。
       下記の例では、効果音ファイルセットの0番に "./Data/Sounds/system.xwb"を
       読み込んでいます。

       1番に "./Data/Sounds/stage1.xwb" を読み込みます。

    2. 第3引数に、その効果音セットのボリュームを入れる事ができます。デフォルト値は0.5fです。
*/
//******************************************************************************
#endif
    // 効果音を読み込む
    //例）
    sound::load(0, L"./Data/Sounds/system.xwb");   // メニューなどのSE

    //TODO_21
    sound::load(1, L"./Data/Sounds/stage1.xwb");   // ステージ固有のSE

    sound::load(2, L"./Data/Sounds/Win/oto.xwb");

#if 23
//******************************************************************************
// TODO:23 効果音のボリュームを変更する
//------------------------------------------------------------------------------
/*
課題）
    □ 効果音のボリュームを個別に変更してみましょう。
      例えば、xwb1番の効果音3番のボリュームを4.0fにしてみましょう。

手順）
    使用関数）
        sound::setVolume

    引数）
        xwbのインデックス
        効果音のインデックス
        設定したいボリューム
*/
//******************************************************************************
#endif
    //TODO_23
    sound::setVolume(1, 3, 4.0f);
}


void audio_deinit()
{
#if 2
//******************************************************************************
// TODO:02 音楽を全て解放
//------------------------------------------------------------------------------
/*
課題）
    □ 音楽ファイルを全て解放します。

手順）
    1. 下記でmusic::clear関数を呼びます。（引数なし）

    2. clearをクリックしてF12キーを押してみましょう。何を行っているのか考えてみよう。

*/
//******************************************************************************
#endif
//TODO_02
    music::clear();
}
