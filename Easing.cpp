#include "Easing.h"
#include <math.h>
#include <cmath>

const float PI = 3.1415926f;

//ƒC[ƒWƒ“ƒOŠÖ”iˆø”Fƒ^ƒCƒ}[i‚O`‚Pjj
#pragma region Normal function
//‚PŸŠÖ”
float Easing::linear(float t)		{ return t; }
//‚QŸŠÖ”
float Easing::quad_in(float t)		{ return t * t; }
float Easing::quad_out(float t)		{ return -t * (t - 2.0f); }
float Easing::quad_in_out(float t)
{
	if (t <= .5f)	return t * t * 2.0f;
	else			return 1.0f - (t - 1.0f) * (t - 1.0f) * 2.0f;
}
//‚RŸŠÖ”
float Easing::cube_in(float t)		{ return t * t * t; }
float Easing::cube_out(float t)		{ return 1.0f + (t - 1.0f) * (t - 1.0f) * (t - 1.0f); }
float Easing::cube_in_out(float t)
{
	if (t <= .5f) 	return t * t * t * 4.0f;
	else			return 1 + (t - 1.0f) * (t - 1.0f) * (t - 1.0f) * 4.0f;
}
//‚SŸŠÖ”
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
//‚TŸŠÖ”
float Easing::quint_in(float t)		{ return t * t * t * t * t; }
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
float Easing::back_in(float t)		{ return t * t * (2.70158f * t - 1.70158f); }
float Easing::back_out(float t)		{ return 1.0f - (t - 1.0f) * (t - 1.0f) * (-2.70158f * (t - 1.0f) - 1.70158f); }
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
//w”ŠÖ”
float Easing::expo_in(float t)		{ return powf(2.0f, (10.0f * (t - 1.0f))); }
float Easing::expo_out(float t)		{ return -powf(2.0f, (-10.0f * t)) + 1.0f; }
float Easing::expo_in_out(float t)
{
	if (t < 0.5)		return powf(2.0f, (10.0f * (t * 2.0f - 1.0f))) / 2.0f;
	else			return (-powf(2.0f, (-10.0f * (t * 2.0f - 1.0f))) + 2.0f) / 2.0f;
}
//’e—ÍŠÖ”
const float ELASTIC_AMPLITUDE = 1.0f;
const float ELASTIC_PERIOD = 0.4f;

float Easing::elastic_in(float t)
{
	t -= 1.0f;
	return -(ELASTIC_AMPLITUDE * powf(2.0f, 10.0f * t) * sinf((t - (ELASTIC_PERIOD / (2.0f * PI) * asinf(1.0f / ELASTIC_AMPLITUDE))) * (2.0f * PI) / ELASTIC_PERIOD));
}
float Easing::elastic_out(float t)
{
	return (ELASTIC_AMPLITUDE * powf(2.0f, -10.0f * t) * sinf((t - (ELASTIC_PERIOD / (2.0f * PI) * asinf(1.0f / ELASTIC_AMPLITUDE))) * (2.0f * PI) / ELASTIC_PERIOD) + 1.0f);
}
float Easing::elastic_in_out(float t)
{
	if (t < 0.5f)
	{
		t -= 0.5f;
		return -0.5f * (powf(2.0f, 10.0f * t) * sinf((t - (ELASTIC_PERIOD / 4.0f)) * (2.0f * PI) / ELASTIC_PERIOD));
	}
	else
	{
		t -= 0.5f;
		return powf(2.0f, -10.0f * t) * sinf((t - (ELASTIC_PERIOD / 4.0f)) * (2.0f * PI) / ELASTIC_PERIOD) * 0.5f + 1.0f;
	}
}
#pragma endregion
