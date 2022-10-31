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

class Easing
{
public:
    /// <summary>
    /// 開始地点と終了地点を指定
    /// </summary>
    /// <param name="type">イージングの種類（eTypeから選択）</param>
    /// <param name="start">初期値</param>
    /// <param name="end">終了値</param>
    /// <param name="v">タイマー</param>
    /// <returns></returns>
    static float step(int type, float start, float end, float v);

    //１次関数
    static float linear(float);
    //２次関数
    static float quad_in(float);
    static float quad_out(float);
    static float quad_in_out(float);
    //３次関数
    static float cube_in(float t);
    static float cube_out(float t);
    static float cube_in_out(float t);
    //４次関数
    static float quart_in(float t);
    static float quart_out(float t);
    static float quart_in_out(float t);
    //５次関数
    static float quint_in(float t);
    static float quint_out(float t);
    static float quint_in_out(float t);
    //スムース関数
    static float smooth_step_in(float t);
    static float smooth_step_out(float t);
    static float smooth_step_in_out(float t);
    //よりスムースな曲線
    static float smoother_step_in(float t);
    static float smoother_step_out(float t);
    static float smoother_step_in_out(float t);
    //サイン関数
    static float sine_in(float t);
    static float sine_out(float t);
    static float sine_in_out(float t);
    //円
    static float circ_in(float t);
    static float circ_out(float t);
    static float circ_in_out(float t);
    //バウンス関数
    static float bounce_in(float t);
    static float bounce_out(float t);
    static float bounce_in_out(float t);
    //バック
    static float back_in(float t);
    static float back_out(float t);
    static float back_in_out(float t);
    //指数関数
    static float expo_in(float);
    static float expo_out(float);
    static float expo_in_out(float);
    //弾力関数
    static float elastic_in(float);
    static float elastic_out(float t);
    static float elastic_in_out(float t);
};

