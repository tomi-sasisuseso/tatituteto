#pragma once
#include <math.h>

enum eType {
    LINEAR = 0,         // 線形
    QUAD_IN,            // 二次関数
    QUAD_OUT,
    QUAD_INOUT,
    CUBE_IN,            // 三次関数
    CUBE_OUT,
    CUBE_INOUT,
    QUART_IN,           // 四次関数
    QUART_OUT,
    QUART_INOUT,
    QUINT_IN,           // 五次関数
    QUINT_OUT,
    QUINT_INOUT,
    SMOOTH_STEP_IN,     // スムーズ曲線
    SMOOTH_STEP_OUT,
    SMOOTH_STEP_INOUT,
    SMOOTHER_STEP_IN,   // よりスムーズな曲線
    SMOOTHER_STEP_OUT,
    SMOOTHER_STEP_INOUT,
    SIN_IN,             // SIN関数
    SIN_OUT,
    SIN_INOUT,
    BOUNCE_IN,          // バウンス
    BOUNCE_OUT,
    BOUNCE_INOUT,
    CIRC_IN,            // サークル
    CIRC_OUT,
    CIRC_INOUT,
    EXPO_IN,            // 指数関数
    EXPO_OUT,
    EXPO_INOUT,
    BACK_IN,            // バック
    BACK_OUT,
    BACK_INOUT,
    ELASTIC_IN,         // 弾力関数
    ELASTIC_OUT,
    ELASTIC_INOUT,
};


namespace Easing
{
    /// <summary>
    /// 開始地点と終了地点を指定
    /// </summary>
    /// <param name="type">イージングの種類（eTypeから選択）</param>
    /// <param name="start">初期値</param>
    /// <param name="end">終了値</param>
    /// <param name="v">タイマー</param>
    /// <returns>変化量（0~1）</returns>
    float step(int type, float start, float end, float v);

    //１次関数
    float linear(float);
    //２次関数
    float quad_in(float);
    float quad_out(float);
    float quad_in_out(float);
    //３次関数
    float cube_in(float t);
    float cube_out(float t);
    float cube_in_out(float t);
    //４次関数
    float quart_in(float t);
    float quart_out(float t);
    float quart_in_out(float t);
    //５次関数
    float quint_in(float t);
    float quint_out(float t);
    float quint_in_out(float t);
    //スムース関数
    float smooth_step_in(float t);
    float smooth_step_out(float t);
    float smooth_step_in_out(float t);
    //よりスムースな曲線
    float smoother_step_in(float t);
    float smoother_step_out(float t);
    float smoother_step_in_out(float t);
    //サイン関数
    float sine_in(float t);
    float sine_out(float t);
    float sine_in_out(float t);
    //円
    float circ_in(float t);
    float circ_out(float t);
    float circ_in_out(float t);
    //バウンス関数
    float bounce_in(float t);
    float bounce_out(float t);
    float bounce_in_out(float t);
    //バック
    float back_in(float t);
    float back_out(float t);
    float back_in_out(float t);
    //指数関数
    float expo_in(float);
    float expo_out(float);
    float expo_in_out(float);
    //弾力関数
    float elastic_in(float);
    float elastic_out(float t);
    float elastic_in_out(float t);
}
