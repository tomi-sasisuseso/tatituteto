#include "all.h"
#include <math.h>

//â~ÇÃìñÇΩÇËîºåa(ç¿ïWÅAîºåa)
bool circle_collision(VECTOR2 pos1, VECTOR2 pos2, float r1, float r2)
{
    float dx = pos2.x - pos1.x;
    float dy = pos2.y - pos1.y;
    float r = r1 + r2;
    if (sqrtf(dx * dx + dy * dy) <= r)
    {
        return true;
    }
    else return false;
}

float p_to_p_distance(VECTOR2 pos1, VECTOR2 pos2)
{
    float dx = pos2.x - pos1.x;
    float dy = pos2.y - pos1.y;

    return sqrtf(dx * dx + dy * dy);
}

float p_to_p_angle(VECTOR2 pos1, VECTOR2 pos2)
{
    float dx = (pos1.x - pos2.x);
    float dy = (pos1.y - pos2.y);

    return atan2((double)dy, (double)dx);
}
