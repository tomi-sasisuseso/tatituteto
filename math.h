#ifndef MATH_H
#define MATH_H
//インクルード
#include "all.h"

//プロトタイプ宣言

/// <summary>
/// 円と円の当たり判定
/// </summary>
/// <param name="pos1">:円１の位置</param>
/// <param name="pos2">円２の位置</param>
/// <param name="r1">円１の半径</param>
/// <param name="r2">円２の半径</param>
/// <returns>当たっているならtrue   そうでないならfalse</returns>
bool circle_collision(VECTOR2 pos1, VECTOR2 pos2, float r1, float r2);


/// <summary>
/// 点と点の距離を計算
/// </summary>
/// <param name="pos1">座標１</param>
/// <param name="pos2">座標２</param>
/// <returns>距離</returns>
float p_to_p_distance(VECTOR2 pos1, VECTOR2 pos2);

/// <summary>
/// 点と点の角度
/// </summary>
/// <param name="pos1">座標１</param>
/// <param name="pos2">座標２</param>
/// <returns>角度（ラジアン）</returns>
float p_to_p_angle(VECTOR2 pos1, VECTOR2 pos2);

/// <summary>
/// 内積を計算
/// </summary>
/// <param name="vec1">ベクトル１</param>
/// <param name="vec2">ベクトル２</param>
/// <returns>-1から1の範囲の値</returns>
float inner_product(VECTOR2 vec1, VECTOR2 vec2);


//参考サイト (https://gist.github.com/snorpey/8134c248296649433de2)
//バランス取りゲーム用の関数なのでほかで使わないように
bool CircleWithRotatedRectanglecollide(VECTOR2 rect_pos, VECTOR2 rect_pivot, float rect_angle, VECTOR2 rect_tSize, VECTOR2 circle_pos, float circle_radius);
float getDistance(float, float, float, float);

#endif//math_h