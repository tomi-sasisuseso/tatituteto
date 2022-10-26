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
/// <param name="pos1"></param>
/// <param name=""></param>
/// <param name=""></param>
/// <returns></returns>
float p_to_p_angle(VECTOR2 pos1, VECTOR2 pos2);

#endif//math_h