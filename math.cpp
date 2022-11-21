#include "all.h"
#include <math.h>

bool circle_collision(VECTOR2 pos1, VECTOR2 pos2, float r1, float r2)
{
    float dx = pos2.x - pos1.x;
    float dy = pos2.y - pos1.y;
    float r = r1 + r2;
	return sqrtf(dx * dx + dy * dy) <= r;
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
    return atan2(dy, dx);
}

float inner_product(VECTOR2 vec1, VECTOR2 vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y;
}

bool CircleWithRotatedRectanglecollide(VECTOR2 rect_pos, VECTOR2 rect_pivot, float rect_angle, VECTOR2 rect_tSize,
										VECTOR2 circle_pos, float circle_radius)
{
	float rectCenterX = rect_pos.x;
	float rectCenterY = rect_pos.y;

	float rectX = rectCenterX - rect_pivot.x;
	float rectY = rectCenterY - rect_pivot.y;

	float rectReferenceX = rectX;
	float rectReferenceY = rectY;

	// Rotate circle's center point back
	float unrotatedCircleX = cosf(rect_angle) * (circle_pos.x - rectCenterX) - sinf(rect_angle) * (circle_pos.y - rectCenterY) + rectCenterX;
	float unrotatedCircleY = sinf(rect_angle) * (circle_pos.x - rectCenterX) + cosf(rect_angle) * (circle_pos.y - rectCenterY) + rectCenterY;

	// Closest point in the rectangle to the center of circle rotated backwards(unrotated)
	float closestX, closestY;

	// Find the unrotated closest x point from center of unrotated circle
	if (unrotatedCircleX < rectReferenceX) {
		closestX = rectReferenceX;
	}
	else if (unrotatedCircleX > rectReferenceX + rect_tSize.x) {
		closestX = rectReferenceX + rect_tSize.x;
	}
	else {
		closestX = unrotatedCircleX;
	}

	// Find the unrotated closest y point from center of unrotated circle
	if (unrotatedCircleY < rectReferenceY) {
		closestY = rectReferenceY;
	}
	else if (unrotatedCircleY > rectReferenceY + rect_tSize.y) {
		closestY = rectReferenceY + rect_tSize.y;
	}
	else {
		closestY = unrotatedCircleY;
	}

	// Determine collision
	float distance = getDistance(unrotatedCircleX, unrotatedCircleY, closestX, closestY);

	if (distance < circle_radius) {
		return true;
	}
	else {
		return false;
	}
}


float getDistance(float fromX, float fromY, float toX, float toY) {
	float dX = abs(fromX - toX);
	float dY = abs(fromY - toY);

	return sqrtf((dX * dX) + (dY * dY));
}
