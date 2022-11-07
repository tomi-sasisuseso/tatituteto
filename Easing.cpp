//=========================
// イージング関数
// 
// うまく使えばいい感じの動きが作れる関数です
// 
// サンプル：
//
//	const float DURATION = 30;    //終わるまでの間隔
// 
//	//タイマーを０にすることで開始
//	if (TRG(0) & PAD_TRG1)   ease_timer = 0;
//
//	if (ease_timer < DURATION)
//	{
//		ease_timer++;
// 
//		//タイマーの値を０～１に変換
//		float t = (float)ease_timer / DURATION;
//			
//		//一定量変化させる場合
//		//変化させる値　＝　初期値　＋　変化させる量　＊　使うイージング関数
//		Easing_test_pos.x = 200 + 1000 * Easing::back_out(t);
// 
//		//終点を固定する場合
//		Easing_test_pos.x = Easing::step(eType::BACK_OUT, 200, 1200, t);
//	}
//	
//	(もっといい使い方があるかも)
// 
// 制作者：矢尾　啓
// 
// 参考サイト
// https://easings.net/ja
// https://note.com/ritar/n/n5e8ed0e07917
// http://gizma.com/easing/#l
// https://2dgames.jp/godot-easing-function/
//=========================
#include "Easing.h"

float Easing::step(int type, float start, float end, float v)

{
	//開始と終了が同じ
	if (start == end)	return start;

	float a = start;
	float b = end;

	//if (start > end)
	//{
	//	//開始と終了が逆転
	//	a = end;
	//	b = start;
	//}
	//
	// 
	//開始より小さい
	if (v <= 0.0)	return start;
	//終了より大きい
	if (v >= 1.0)	return end;

	float d = b - a;
	float t = v;
	//処理を実行
	switch (type)
	{
	case eType::LINEAR:					return a + (d * Easing::linear(v));
	case eType::QUAD_IN:				return a + (d * Easing::quad_in(v));
	case eType::QUAD_OUT:				return a + (d * Easing::quad_out(v));
	case eType::QUAD_INOUT:				return a + (d * Easing::quad_in_out(v));
	case eType::CUBE_IN:				return a + (d * Easing::cube_in(v));
	case eType::CUBE_OUT:				return a + (d * Easing::cube_out(v));
	case eType::CUBE_INOUT:				return a + (d * Easing::cube_in_out(v));
	case eType::QUART_IN:				return a + (d * Easing::quart_in(v));
	case eType::QUART_OUT:				return a + (d * Easing::quart_out(v));
	case eType::QUART_INOUT:			return a + (d * Easing::quart_in_out(v));
	case eType::QUINT_IN:				return a + (d * Easing::quint_in(v));
	case eType::QUINT_OUT:				return a + (d * Easing::quint_out(v));
	case eType::QUINT_INOUT:			return a + (d * Easing::quint_in_out(v));
	case eType::SMOOTH_STEP_IN:			return a + (d * Easing::smooth_step_in(v));
	case eType::SMOOTH_STEP_OUT:		return a + (d * Easing::smooth_step_out(v));
	case eType::SMOOTH_STEP_INOUT:		return a + (d * Easing::smooth_step_in_out(v));
	case eType::SMOOTHER_STEP_IN:		return a + (d * Easing::smoother_step_in(v));
	case eType::SMOOTHER_STEP_OUT:		return a + (d * Easing::smoother_step_out(v));
	case eType::SMOOTHER_STEP_INOUT:	return a + (d * Easing::smoother_step_in_out(v));
	case eType::SIN_IN:					return a + (d * Easing::sine_in(v));
	case eType::SIN_OUT:				return a + (d * Easing::sine_out(v));
	case eType::SIN_INOUT:				return a + (d * Easing::sine_in_out(v));
	case eType::CIRC_IN:				return a + (d * Easing::circ_in(v));
	case eType::CIRC_OUT:				return a + (d * Easing::circ_out(v));
	case eType::CIRC_INOUT:				return a + (d * Easing::circ_in_out(v));
	case eType::BOUNCE_IN:				return a + (d * Easing::bounce_in(v));
	case eType::BOUNCE_OUT:				return a + (d * Easing::bounce_out(v));
	case eType::BOUNCE_INOUT:			return a + (d * Easing::bounce_in_out(v));
	case eType::BACK_IN:				return a + (d * Easing::back_in(v));
	case eType::BACK_OUT:				return a + (d * Easing::back_out(v));
	case eType::BACK_INOUT:				return a + (d * Easing::back_in_out(v));
	case eType::EXPO_IN:				return a + (d * Easing::expo_in(v));
	case eType::EXPO_OUT:				return a + (d * Easing::expo_out(v));
	case eType::EXPO_INOUT:				return a + (d * Easing::expo_in_out(v));
	case eType::ELASTIC_IN:				return a + (d * Easing::elastic_in(v));
	case eType::ELASTIC_OUT:			return a + (d * Easing::elastic_out(v));
	case eType::ELASTIC_INOUT:			return a + (d * Easing::elastic_in_out(v));
	}
}

#pragma region Normal
//１次関数
float Easing::linear(float t)	{ return t; }
//２次関数
float Easing::quad_in(float t)	{ return t * t; }
float Easing::quad_out(float t) { return -t * (t - 2.0f); }
float Easing::quad_in_out(float t)
{
	if (t <= .5f)	return t * t * 2.0f;
	else			return 1.0f - (t - 1.0f) * (t - 1.0f) * 2.0f;
}
//３次関数
float Easing::cube_in(float t)	{ return t * t * t; }
float Easing::cube_out(float t) { return 1.0f + (t - 1.0f) * (t - 1.0f) * (t - 1.0f); }
float Easing::cube_in_out(float t)
{
	if (t <= .5f) 	return t * t * t * 4.0f;
	else			return 1 + (t - 1.0f) * (t - 1.0f) * (t - 1.0f) * 4.0f;
}
//４次関数
float Easing::quart_in(float t)		{ return t * t * t * t; }
float Easing::quart_out(float t)	{ return 1.0f - (t - 1.0f) * (t - 1.0f) * (t - 1.0f) * (t - 1.0f); }
float Easing::quart_in_out(float t)
{
	if (t <= 0.5f)	return t * t * t * t * 8.0f;
	else
	{
		t = t * 2.0f - 2.0f;
		return (1.0f - t * t * t * t) / 2.0f + 0.5f;
	}
}
//５次関数
float Easing::quint_in(float t) { return t * t * t * t * t; }
float Easing::quint_out(float t)
{
	t = t - 1.0f;
	return t * t * t * t * t + 1;
}
float Easing::quint_in_out(float t)
{
	t *= 2.0f;
	if (t < 1.0f)	return (t * t * t * t * t) / 2.0f;
	else
	{
		t -= 2.0f;
		return (t * t * t * t * t + 2.0f) / 2.0f;
	}
}
#pragma endregion
#pragma region Smooth
float Easing::smooth_step_in(float t)		{ return 2.0f * smooth_step_in_out(t / 2.0f); }
float Easing::smooth_step_out(float t)		{ return 2.0f * smooth_step_in_out(t / 2.0f + .5f) - 1.0f; }
float Easing::smooth_step_in_out(float t)	{ return t * t * (t * -2.0f + 3.0f); }

float Easing::smoother_step_in(float t)		{ return 2.0f * smoother_step_in_out(t / 2.0f); }
float Easing::smoother_step_out(float t)	{ return 2.0f * smoother_step_in_out(t / 2.0f + .5f) - 1.0f; }
float Easing::smoother_step_in_out(float t) { return t * t * t * (t * (t * 6.0f - 15.0f) + 10.0f); }

#pragma endregion
#pragma region Cicle
const float PI = 3.1415926f;
float Easing::sine_in(float t)		{ return -cosf(PI / 2.0f * t) + 1.0f; }
float Easing::sine_out(float t)		{ return sinf(PI / 2.0f * t); }
float Easing::sine_in_out(float t)	{ return -cosf(PI * t) / 2.0f + 0.5f; }

float Easing::circ_in(float t)		{ return -(sqrtf(1 - t * t) - 1); }
float Easing::circ_out(float t)		{ return sqrtf(1 - (t - 1) * (t - 1)); }
float Easing::circ_in_out(float t)
{
	if (t <= 0.5)		return (sqrtf(1 - t * t * 4) - 1) / -2;
	else 				return (sqrtf(1 - (t * 2 - 2) * (t * 2 - 2)) + 1) / 2;
}
#pragma endregion
#pragma region Bounce
const float B1 = 1.0f / 2.75f;
const float B2 = 2.0f / 2.75f;
const float B3 = 1.5f / 2.75f;
const float B4 = 2.5f / 2.75f;
const float B5 = 2.25f / 2.75f;
const float B6 = 2.625f / 2.75f;
float Easing::bounce_in(float t)
{
	t = 1 - t;
	if (t < B1)			return 1 - 7.5625f * t * t;
	if (t < B2)			return 1 - (7.5625f * (t - B3) * (t - B3) + .75f);
	if (t < B4)			return 1 - (7.5625f * (t - B5) * (t - B5) + .9375f);

	return 1.0f - (7.5625f * (t - B6) * (t - B6) + 0.984375f);
}

float Easing::bounce_out(float t)
{
	if (t < B1)		return 7.5625f * t * t;
	if (t < B2)		return 7.5625f * (t - B3) * (t - B3) + .75f;
	if (t < B4)		return 7.5625f * (t - B5) * (t - B5) + .9375f;

	return 7.5625f * (t - B6) * (t - B6) + 0.984375f;
}
float Easing::bounce_in_out(float t)
{
	if (t < 0.5f)
	{
		t = 1.0f - t * 2.0f;
		if (t < B1)		return (1.0f - 7.5625f * t * t) / 2;
		if (t < B2)		return (1.0f - (7.5625f * (t - B3) * (t - B3) + .75f)) / 2.0f;
		if (t < B4)		return (1.0f - (7.5625f * (t - B5) * (t - B5) + .9375f)) / 2.0f;

		return (1.0f - (7.5625f * (t - B6) * (t - B6) + .984375f)) / 2.0f;
	}
	else
	{
		t = t * 2.0f - 1.0f;
		if (t < B1)		return (7.5625f * t * t) / 2.0f + .5f;
		if (t < B2)		return (7.5625f * (t - B3) * (t - B3) + .75f) / 2.0f + .5f;
		if (t < B4)		return (7.5625f * (t - B5) * (t - B5) + .9375f) / 2.0f + .5f;

		return (7.5625f * (t - B6) * (t - B6) + .984375f) / 2.0f + .5f;
	}
}
#pragma endregion
#pragma region Back
float Easing::back_in(float t)	{ return t * t * (2.70158f * t - 1.70158f); }
float Easing::back_out(float t) { return 1.0f - (t - 1.0f) * (t - 1.0f) * (-2.70158f * (t - 1.0f) - 1.70158f); }
float Easing::back_in_out(float t)
{
	t *= 2;
	if (t < 1)		return t * t * (2.70158f * t - 1.70158f) / 2.0f;
	else
	{
		t -= 1;
		return (1.0f - (t - 1.0f) * (t - 1.0f) * (-2.70158f * (t - 1.0f) - 1.70158f)) / 2.0f + .5f;
	}
}
#pragma endregion
#pragma region Others
//指数関数
float Easing::expo_in(float t)	{ return powf(2.0f, (10.0f * (t - 1.0f))); }
float Easing::expo_out(float t) { return -powf(2.0f, (-10.0f * t)) + 1.0f; }
float Easing::expo_in_out(float t)
{
	if (t < 0.5)		return powf(2.0f, (10.0f * (t * 2.0f - 1.0f))) / 2.0f;
	else				return (-powf(2.0f, (-10.0f * (t * 2.0f - 1.0f))) + 2.0f) / 2.0f;
}
//弾力関数
const float ELASTIC_AMPLITUDE = 1.0f;
const float ELASTIC_PERIOD = 0.4f;

float Easing::elastic_in(float t)
{
	t -= 1.0f;
	return -(ELASTIC_AMPLITUDE * powf(2.0f, 10.0f * t) * 
		sinf((t - (ELASTIC_PERIOD / (2.0f * PI) * 
			asinf(1.0f / ELASTIC_AMPLITUDE))) * 
			(2.0f * PI) / ELASTIC_PERIOD));
}
float Easing::elastic_out(float t)
{
	return (ELASTIC_AMPLITUDE * powf(2.0f, -10.0f * t) * 
		sinf((t - (ELASTIC_PERIOD / (2.0f * PI) * 
			asinf(1.0f / ELASTIC_AMPLITUDE))) * 
			(2.0f * PI) / ELASTIC_PERIOD) + 1.0f);
}
float Easing::elastic_in_out(float t)
{
	if (t < 0.5f)
	{
		t -= 0.5f;
		return -0.5f * 
			(powf(2.0f, 10.0f * t) * 
				sinf((t - (ELASTIC_PERIOD / 4.0f)) * 
					(2.0f * PI) / ELASTIC_PERIOD));
	}
	else
	{
		t -= 0.5f;
		return powf(2.0f, -10.0f * t) * 
			sinf((t - (ELASTIC_PERIOD / 4.0f)) * 
				(2.0f * PI) / ELASTIC_PERIOD) * 
			0.5f + 1.0f;
	}
}
#pragma endregion