#include "Ray.h"

Ray::Ray()
{
	origin = Vector3(0.0f);
	direction = Vector3(0.0f);
}

Ray::Ray(const Vector3& rayOrigin, const Vector3& rayDirection) :
	origin(rayOrigin), direction(rayDirection){}

Vector3 Ray::pointAtParameter(float t)
{
	return origin + direction * t;
}
