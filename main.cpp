//******************************************************************************
//
//
//      main
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include "all.h"

//------< 変数 >----------------------------------------------------------------
int curScene    = SCENE_NONE;
int nextScene   = SCENE_TITLE;

//------------------------------------------------------------------------------
//  WinMain（エントリポイント）
//------------------------------------------------------------------------------
int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
    GameLib::init(L"ゲームプログラミングⅠ", SCREEN_W, SCREEN_H);

    // オーディオの初期設定
    audio_init();

    while (GameLib::gameLoop())
    {
        // シーン切り替え処理
        if (curScene != nextScene)
        {
            // 現在のシーンに応じた終了処理
            switch (curScene)
            {
            case SCENE_TITLE:
                title_deinit();
                break;

            case SCENE_GAME:
                game_deinit();
                break;
            }

            // 次のシーンに応じた初期設定処理
            switch (nextScene)
            {
            case SCENE_TITLE:
                title_init();
                break;

            case SCENE_GAME:
                game_init();
                break;
            }

            curScene = nextScene;
        }

        // 入力を更新する
        input::update();

#if 10
//******************************************************************************
// TODO:10 音楽の更新処理
//------------------------------------------------------------------------------
/*
課題）
    □ 音楽も毎フレーム更新処理を行う。

手順）
    使用関数）
        music::update

    引数）
        なし

解説）
    フェードインやフェードアウトが行えるよう、音楽の更新をここで呼んでおきます。
*/
//******************************************************************************
#endif
        //TODO_10 音楽の更新処理
        music::update();

        // 現在のシーンに応じた更新・描画処理
        switch (curScene)
        {
        case SCENE_TITLE:
            title_update();
            title_render();
            break;

        case SCENE_GAME:
            game_update();
            game_render();
            break;
        }

        // デバッグ文字列の描画
        debug::display(1.0f, 0.4f, 0.6f, 1, 1);

        //debug::setString("GP1_07 SAMPLE");

        // バックバッファの内容を表示
        GameLib::present(1, 0);
    }

    // 現在のシーンに応じた終了処理
    switch (curScene)
    {
    case SCENE_TITLE:
        title_deinit();
        break;

    case SCENE_GAME:
        game_deinit();
        break;
    }

    // オーディオの終了処理
    audio_deinit();

    // ゲームライブラリの終了処理
    GameLib::uninit();

    return 0;
}