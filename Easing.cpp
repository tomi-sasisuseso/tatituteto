#include "Easing.h"

float Easing::linear(float t, float b, float c, float d)
{
    return c * t / d + b;
}