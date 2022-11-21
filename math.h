#ifndef MATH_H
#define MATH_H
//�C���N���[�h
#include "all.h"

//�v���g�^�C�v�錾

/// <summary>
/// �~�Ɖ~�̓����蔻��
/// </summary>
/// <param name="pos1">:�~�P�̈ʒu</param>
/// <param name="pos2">�~�Q�̈ʒu</param>
/// <param name="r1">�~�P�̔��a</param>
/// <param name="r2">�~�Q�̔��a</param>
/// <returns>�������Ă���Ȃ�true   �����łȂ��Ȃ�false</returns>
bool circle_collision(VECTOR2 pos1, VECTOR2 pos2, float r1, float r2);


/// <summary>
/// �_�Ɠ_�̋������v�Z
/// </summary>
/// <param name="pos1">���W�P</param>
/// <param name="pos2">���W�Q</param>
/// <returns>����</returns>
float p_to_p_distance(VECTOR2 pos1, VECTOR2 pos2);

/// <summary>
/// �_�Ɠ_�̊p�x
/// </summary>
/// <param name="pos1">���W�P</param>
/// <param name="pos2">���W�Q</param>
/// <returns>�p�x�i���W�A���j</returns>
float p_to_p_angle(VECTOR2 pos1, VECTOR2 pos2);

/// <summary>
/// ���ς��v�Z
/// </summary>
/// <param name="vec1">�x�N�g���P</param>
/// <param name="vec2">�x�N�g���Q</param>
/// <returns>-1����1�͈̔͂̒l</returns>
float inner_product(VECTOR2 vec1, VECTOR2 vec2);


//�Q�l�T�C�g (https://gist.github.com/snorpey/8134c248296649433de2)
//�o�����X���Q�[���p�̊֐��Ȃ̂łق��Ŏg��Ȃ��悤��
bool CircleWithRotatedRectanglecollide(VECTOR2 rect_pos, VECTOR2 rect_pivot, float rect_angle, VECTOR2 rect_tSize, VECTOR2 circle_pos, float circle_radius);
float getDistance(float, float, float, float);

#endif//math_h