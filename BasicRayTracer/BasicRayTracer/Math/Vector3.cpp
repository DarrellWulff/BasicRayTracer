#include "Vector3.h"
#include <iostream>
#include <math.h>
#include "Quaternion.h"

Vector3::Vector3(float xVal, float yVal, float zVal) : 
	x(xVal), y(yVal), z(zVal){}

void Vector3::set(float xVal, float yVal, float zVal)
{
	x = xVal;
	y = yVal;
	z = zVal;
}

void Vector3::set(Vector3 vectorVal)
{
	x = vectorVal.x;
	y = vectorVal.y;
	z = vectorVal.z;
}

Vector3 Vector3::operator+(Vector3 const &rhs)
{
	return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector3 Vector3::operator-(Vector3 const &rhs)
{
	return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vector3 Vector3::operator-()
{
	return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator*(Vector3 const &rhs)
{
	return Vector3(x * rhs.x, y * rhs.y, z * rhs.z);
}

Vector3 Vector3::operator*(float const scalar)
{
	return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3 Vector3::operator/(Vector3 const &rhs)
{
	return Vector3(x / rhs.x, y / rhs.y, z / rhs.z);
}

Vector3 Vector3::operator/(float const scalar)
{
	return Vector3(x / scalar, y / scalar, z / scalar);
}

void Vector3::operator=(Vector3 const& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
}

float Vector3::fastMagnitude()
{
	float lenSq = x * x * + y * y + z * z;

	const float a0 = 15.0f / 8.0f;
	const float a1 = -5.0f / 4.0f;
	const float a2 = 3.0f / 8.0f;

	return a0 + a1 * lenSq + a2 * lenSq * lenSq;
}

Vector3 Vector3::fastNormalize()
{
	float lenInv = fastMagnitude();

	return Vector3(lenInv * x, lenInv * y, z * lenInv);
}

float Vector3::magnitude()
{
	return std::sqrt(x * x + y * y + z * z);
}

float Vector3::magnitudeSquared()
{
	return x * x + y * y + z * z;
}

Vector3 Vector3::normalize()
{
	float mag = magnitude();

	return Vector3(x/mag, y/mag, z/mag);
}

float Vector3::dot(Vector3 rhs)
{
	return x * rhs.x + y * rhs.y + z * rhs.z;
}

Vector3 Vector3::cross(Vector3 rhs)
{
	return Vector3(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);
}

float Vector3::maxAxis()
{
	float maxVal = x;

	if (y > maxVal) 
	{
		maxVal = y;
	}

	if (z > maxVal) 
	{
		maxVal = z;
	}

	return maxVal;
}

float Vector3::minAxis()
{
	float minVal = x;

	if (y < minVal)
	{
		minVal = y;
	}

	if (z < minVal)
	{
		minVal = z;
	}

	return minVal;
}

float Vector3::distanceTo(Vector3 target)
{
	return Vector3(target - *this).magnitude();
}

float Vector3::distanceToSquared(Vector3 target)
{
	return Vector3(target - *this).magnitudeSquared();
}

Vector3 Vector3::directionTo(Vector3 target)
{
	return Vector3(target - *this).normalize();
}

Vector3 Vector3::rotate(Quaternion rotationQuat)
{
	Quaternion pureQuat = Quaternion::fromVector(*this);

	pureQuat = rotationQuat.applyQuatRotation(pureQuat);

	return Vector3::fromQuaternion(pureQuat);
}

Vector3 Vector3::fromQuaternion(Quaternion fromQuat)
{
	return Vector3(fromQuat.x, fromQuat.y, fromQuat.z);
}

void Vector3::printVector(std::string vecName)
{
	std::cout << "\nVector " << vecName << " X: " << x << " Y: " << y << " Z: " << z << std::endl;
}
