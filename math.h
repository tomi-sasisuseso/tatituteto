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
/// <param name="pos1"></param>
/// <param name=""></param>
/// <param name=""></param>
/// <returns></returns>
float p_to_p_angle(VECTOR2 pos1, VECTOR2 pos2);

#endif//math_h