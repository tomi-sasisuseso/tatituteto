//=========================
// �C�[�W���O�֐�
// 
// ���܂��g���΂��������̓���������֐��ł�
// 
// �T���v���F
//
//	const float DURATION = 30;    //�I���܂ł̊Ԋu
// 
//	//�^�C�}�[���O�ɂ��邱�ƂŊJ�n
//	if (TRG(0) & PAD_TRG1)   ease_timer = 0;
//
//	if (ease_timer < DURATION)
//	{
//		ease_timer++;
// 
//		//�^�C�}�[�̒l���O�`�P�ɕϊ�
//		float t = (float)ease_timer / DURATION;
//			
//		//���ڊ֐����g���ꍇ
//		//�ω�������l�@���@�����l�@�{�@�ω�������ʁ@���@�g���C�[�W���O�֐�
//		Easing_test_pos.x = 200 + 1000 * Easing::back_out(t);
// 
//		//�I�_���Œ肷��ꍇ
//		Easing_test_pos.x = Easing::step(eType::BACK_OUT, 200, 1200, t);
//	}
//	
// 
// ����ҁF����@�[
// 
// �Q�l�T�C�g
// https://easings.net/ja
// https://note.com/ritar/n/n5e8ed0e07917
// http://gizma.com/easing/#l
// https://2dgames.jp/godot-easing-function/
//=========================
#include "Easing.h"

namespace Easing
{
	float step(int type, float start, float end, float v)
	{
		//�J�n�ƏI��������
		if (start == end)	return start;
		//�J�n�ƏI��������
		if (start == end)	return start;

		float a = start;
		float b = end;
		
		//�I����
		//�J�n��菬����
		if (v <= 0.0)	return start;
		//�I�����傫��
		if (v >= 1.0)	return end;

		float d = b - a;
		float t = v;
		//���������s
		float amount = 0;
		switch (type)
		{
		case eType::LINEAR:					amount = Easing::linear(v); break;
		case eType::QUAD_IN:				amount = Easing::quad_in(v); break;
		case eType::QUAD_OUT:				amount = Easing::quad_out(v); break;
		case eType::QUAD_INOUT:				amount = Easing::quad_in_out(v); break;
		case eType::CUBE_IN:				amount = Easing::cube_in(v); break;
		case eType::CUBE_OUT:				amount = Easing::cube_out(v); break;
		case eType::CUBE_INOUT:				amount = Easing::cube_in_out(v); break;
		case eType::QUART_IN:				amount = Easing::quart_in(v); break;
		case eType::QUART_OUT:				amount = Easing::quart_out(v); break;
		case eType::QUART_INOUT:			amount = Easing::quart_in_out(v); break;
		case eType::QUINT_IN:				amount = Easing::quint_in(v); break;
		case eType::QUINT_OUT:				amount = Easing::quint_out(v); break;
		case eType::QUINT_INOUT:			amount = Easing::quint_in_out(v); break;
		case eType::SMOOTH_STEP_IN:			amount = Easing::smooth_step_in(v); break;
		case eType::SMOOTH_STEP_OUT:		amount = Easing::smooth_step_out(v); break;
		case eType::SMOOTH_STEP_INOUT:		amount = Easing::smooth_step_in_out(v); break;
		case eType::SMOOTHER_STEP_IN:		amount = Easing::smoother_step_in(v); break;
		case eType::SMOOTHER_STEP_OUT:		amount = Easing::smoother_step_out(v); break;
		case eType::SMOOTHER_STEP_INOUT:	amount = Easing::smoother_step_in_out(v); break;
		case eType::SIN_IN:					amount = Easing::sine_in(v); break;
		case eType::SIN_OUT:				amount = Easing::sine_out(v); break;
		case eType::SIN_INOUT:				amount = Easing::sine_in_out(v); break;
		case eType::CIRC_IN:				amount = Easing::circ_in(v); break;
		case eType::CIRC_OUT:				amount = Easing::circ_out(v); break;
		case eType::CIRC_INOUT:				amount = Easing::circ_in_out(v); break;
		case eType::BOUNCE_IN:				amount = Easing::bounce_in(v); break;
		case eType::BOUNCE_OUT:				amount = Easing::bounce_out(v); break;
		case eType::BOUNCE_INOUT:			amount = Easing::bounce_in_out(v); break;
		case eType::BACK_IN:				amount = Easing::back_in(v); break;
		case eType::BACK_OUT:				amount = Easing::back_out(v); break;
		case eType::BACK_INOUT:				amount = Easing::back_in_out(v); break;
		case eType::EXPO_IN:				amount = Easing::expo_in(v); break;
		case eType::EXPO_OUT:				amount = Easing::expo_out(v); break;
		case eType::EXPO_INOUT:				amount = Easing::expo_in_out(v); break;
		case eType::ELASTIC_IN:				amount = Easing::elastic_in(v); break;
		case eType::ELASTIC_OUT:			amount = Easing::elastic_out(v); break;
		case eType::ELASTIC_INOUT:			amount = Easing::elastic_in_out(v); break;
		}

		return a + (d * amount);
	}

#pragma region Normal
	//�P���֐�
	float linear(float t) { return t; }
	//�Q���֐�
	float quad_in(float t) { return t * t; }
	float quad_out(float t) { return -t * (t - 2.0f); }
	float quad_in_out(float t)
	{
		if (t <= .5f)	return t * t * 2.0f;
		else			return 1.0f - (t - 1.0f) * (t - 1.0f) * 2.0f;
	}
	//�R���֐�
	float cube_in(float t) { return t * t * t; }
	float cube_out(float t) { return 1.0f + (t - 1.0f) * (t - 1.0f) * (t - 1.0f); }
	float cube_in_out(float t)
	{
		if (t <= .5f) 	return t * t * t * 4.0f;
		else			return 1 + (t - 1.0f) * (t - 1.0f) * (t - 1.0f) * 4.0f;
	}
	//�S���֐�
	float quart_in(float t) { return t * t * t * t; }
	float quart_out(float t) { return 1.0f - (t - 1.0f) * (t - 1.0f) * (t - 1.0f) * (t - 1.0f); }
	float quart_in_out(float t)
	{
		if (t <= 0.5f)	return t * t * t * t * 8.0f;
		else
		{
			t = t * 2.0f - 2.0f;
			return (1.0f - t * t * t * t) / 2.0f + 0.5f;
		}
	}
	//�T���֐�
	float quint_in(float t) { return t * t * t * t * t; }
	float quint_out(float t)
	{
		t = t - 1.0f;
		return t * t * t * t * t + 1;
	}
	float quint_in_out(float t)
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
	float smooth_step_in(float t) { return 2.0f * smooth_step_in_out(t / 2.0f); }
	float smooth_step_out(float t) { return 2.0f * smooth_step_in_out(t / 2.0f + .5f) - 1.0f; }
	float smooth_step_in_out(float t) { return t * t * (t * -2.0f + 3.0f); }

	float smoother_step_in(float t) { return 2.0f * smoother_step_in_out(t / 2.0f); }
	float smoother_step_out(float t) { return 2.0f * smoother_step_in_out(t / 2.0f + .5f) - 1.0f; }
	float smoother_step_in_out(float t) { return t * t * t * (t * (t * 6.0f - 15.0f) + 10.0f); }

#pragma endregion
#pragma region Cicle
	const float PI = 3.1415926f;
	float sine_in(float t) { return -cosf(PI / 2.0f * t) + 1.0f; }
	float sine_out(float t) { return sinf(PI / 2.0f * t); }
	float sine_in_out(float t) { return -cosf(PI * t) / 2.0f + 0.5f; }

	float circ_in(float t) { return -(sqrtf(1 - t * t) - 1); }
	float circ_out(float t) { return sqrtf(1 - (t - 1) * (t - 1)); }
	float circ_in_out(float t)
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
	float bounce_in(float t)
	{
		t = 1 - t;
		if (t < B1)			return 1 - 7.5625f * t * t;
		if (t < B2)			return 1 - (7.5625f * (t - B3) * (t - B3) + .75f);
		if (t < B4)			return 1 - (7.5625f * (t - B5) * (t - B5) + .9375f);

		return 1.0f - (7.5625f * (t - B6) * (t - B6) + 0.984375f);
	}

	float bounce_out(float t)
	{
		if (t < B1)		return 7.5625f * t * t;
		if (t < B2)		return 7.5625f * (t - B3) * (t - B3) + .75f;
		if (t < B4)		return 7.5625f * (t - B5) * (t - B5) + .9375f;

		return 7.5625f * (t - B6) * (t - B6) + 0.984375f;
	}
	float bounce_in_out(float t)
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
	float back_in(float t) { return t * t * (2.70158f * t - 1.70158f); }
	float back_out(float t) { return 1.0f - (t - 1.0f) * (t - 1.0f) * (-2.70158f * (t - 1.0f) - 1.70158f); }
	float back_in_out(float t)
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
	//�w���֐�
	float expo_in(float t) { return powf(2.0f, (10.0f * (t - 1.0f))); }
	float expo_out(float t) { return -powf(2.0f, (-10.0f * t)) + 1.0f; }
	float expo_in_out(float t)
	{
		if (t < 0.5)		return powf(2.0f, (10.0f * (t * 2.0f - 1.0f))) / 2.0f;
		else				return (-powf(2.0f, (-10.0f * (t * 2.0f - 1.0f))) + 2.0f) / 2.0f;
	}
	//�e�͊֐�
	const float ELASTIC_AMPLITUDE = 1.0f;
	const float ELASTIC_PERIOD = 0.4f;

	float elastic_in(float t)
	{
		t -= 1.0f;
		return -(ELASTIC_AMPLITUDE * powf(2.0f, 10.0f * t) *
			sinf((t - (ELASTIC_PERIOD / (2.0f * PI) *
				asinf(1.0f / ELASTIC_AMPLITUDE))) *
				(2.0f * PI) / ELASTIC_PERIOD));
	}
	float elastic_out(float t)
	{
		return (ELASTIC_AMPLITUDE * powf(2.0f, -10.0f * t) *
			sinf((t - (ELASTIC_PERIOD / (2.0f * PI) *
				asinf(1.0f / ELASTIC_AMPLITUDE))) *
				(2.0f * PI) / ELASTIC_PERIOD) + 1.0f);
	}
	float elastic_in_out(float t)
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
}