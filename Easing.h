#pragma once
#include <math.h>

enum eType {
    LINEAR = 0,         // ���`
    QUAD_IN,            // �񎟊֐�
    QUAD_OUT,
    QUAD_INOUT,
    CUBE_IN,            // �O���֐�
    CUBE_OUT,
    CUBE_INOUT,
    QUART_IN,           // �l���֐�
    QUART_OUT,
    QUART_INOUT,
    QUINT_IN,           // �܎��֐�
    QUINT_OUT,
    QUINT_INOUT,
    SMOOTH_STEP_IN,     // �X���[�Y�Ȑ�
    SMOOTH_STEP_OUT,
    SMOOTH_STEP_INOUT,
    SMOOTHER_STEP_IN,   // ���X���[�Y�ȋȐ�
    SMOOTHER_STEP_OUT,
    SMOOTHER_STEP_INOUT,
    SIN_IN,             // SIN�֐�
    SIN_OUT,
    SIN_INOUT,
    BOUNCE_IN,          // �o�E���X
    BOUNCE_OUT,
    BOUNCE_INOUT,
    CIRC_IN,            // �T�[�N��
    CIRC_OUT,
    CIRC_INOUT,
    EXPO_IN,            // �w���֐�
    EXPO_OUT,
    EXPO_INOUT,
    BACK_IN,            // �o�b�N
    BACK_OUT,
    BACK_INOUT,
    ELASTIC_IN,         // �e�͊֐�
    ELASTIC_OUT,
    ELASTIC_INOUT,
};


namespace Easing
{
    /// <summary>
    /// �J�n�n�_�ƏI���n�_���w��
    /// </summary>
    /// <param name="type">�C�[�W���O�̎�ށieType����I���j</param>
    /// <param name="start">�����l</param>
    /// <param name="end">�I���l</param>
    /// <param name="v">�^�C�}�[</param>
    /// <returns>�ω��ʁi0~1�j</returns>
    float step(int type, float start, float end, float v);

    //�P���֐�
    float linear(float);
    //�Q���֐�
    float quad_in(float);
    float quad_out(float);
    float quad_in_out(float);
    //�R���֐�
    float cube_in(float t);
    float cube_out(float t);
    float cube_in_out(float t);
    //�S���֐�
    float quart_in(float t);
    float quart_out(float t);
    float quart_in_out(float t);
    //�T���֐�
    float quint_in(float t);
    float quint_out(float t);
    float quint_in_out(float t);
    //�X���[�X�֐�
    float smooth_step_in(float t);
    float smooth_step_out(float t);
    float smooth_step_in_out(float t);
    //���X���[�X�ȋȐ�
    float smoother_step_in(float t);
    float smoother_step_out(float t);
    float smoother_step_in_out(float t);
    //�T�C���֐�
    float sine_in(float t);
    float sine_out(float t);
    float sine_in_out(float t);
    //�~
    float circ_in(float t);
    float circ_out(float t);
    float circ_in_out(float t);
    //�o�E���X�֐�
    float bounce_in(float t);
    float bounce_out(float t);
    float bounce_in_out(float t);
    //�o�b�N
    float back_in(float t);
    float back_out(float t);
    float back_in_out(float t);
    //�w���֐�
    float expo_in(float);
    float expo_out(float);
    float expo_in_out(float);
    //�e�͊֐�
    float elastic_in(float);
    float elastic_out(float t);
    float elastic_in_out(float t);
}
