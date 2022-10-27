#pragma once
//=========================
// イージング関数
// 
// 参考サイト
//  イージングとは
// https://note.com/ritar/n/n5e8ed0e07917
//  イージングの計算式
// http://gizma.com/easing/#l
// https://2dgames.jp/godot-easing-function/
//=========================
class Easing
{
public:
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

