#pragma once
//=========================
// �C�[�W���O�֐�
// 
// �Q�l�T�C�g
//  �C�[�W���O�Ƃ�
// https://note.com/ritar/n/n5e8ed0e07917
//  �C�[�W���O�̌v�Z��
// http://gizma.com/easing/#l
// https://2dgames.jp/godot-easing-function/
//=========================
class Easing
{
public:
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

