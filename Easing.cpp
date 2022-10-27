#include "Easing.h"

float Easing::linear(float time, float b, float c, float d)
{
    return c * t / d + b;
}