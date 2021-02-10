#pragma once
#include "Math/Vector3.h"

class Ray
{
public:

	Ray();
	Ray(const Vector3& rayOrigin, const Vector3& rayDirection);

	Vector3 pointAtParameter(float t);

	Vector3 origin;
	Vector3 direction;
};

