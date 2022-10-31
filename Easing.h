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

class Easing
{
public:
    /// <summary>
    /// �J�n�n�_�ƏI���n�_���w��
    /// </summary>
    /// <param name="type">�C�[�W���O�̎�ށieType����I���j</param>
    /// <param name="start">�����l</param>
    /// <param name="end">�I���l</param>
    /// <param name="v">�^�C�}�[</param>
    /// <returns></returns>
    static float step(int type, float start, float end, float v);

    //�P���֐�
    static float linear(float);
    //�Q���֐�
    static float quad_in(float);
    static float quad_out(float);
    static float quad_in_out(float);
    //�R���֐�
    static float cube_in(float t);
    static float cube_out(float t);
    static float cube_in_out(float t);
    //�S���֐�
    static float quart_in(float t);
    static float quart_out(float t);
    static float quart_in_out(float t);
    //�T���֐�
    static float quint_in(float t);
    static float quint_out(float t);
    static float quint_in_out(float t);
    //�X���[�X�֐�
    static float smooth_step_in(float t);
    static float smooth_step_out(float t);
    static float smooth_step_in_out(float t);
    //���X���[�X�ȋȐ�
    static float smoother_step_in(float t);
    static float smoother_step_out(float t);
    static float smoother_step_in_out(float t);
    //�T�C���֐�
    static float sine_in(float t);
    static float sine_out(float t);
    static float sine_in_out(float t);
    //�~
    static float circ_in(float t);
    static float circ_out(float t);
    static float circ_in_out(float t);
    //�o�E���X�֐�
    static float bounce_in(float t);
    static float bounce_out(float t);
    static float bounce_in_out(float t);
    //�o�b�N
    static float back_in(float t);
    static float back_out(float t);
    static float back_in_out(float t);
    //�w���֐�
    static float expo_in(float);
    static float expo_out(float);
    static float expo_in_out(float);
    //�e�͊֐�
    static float elastic_in(float);
    static float elastic_out(float t);
    static float elastic_in_out(float t);
};

