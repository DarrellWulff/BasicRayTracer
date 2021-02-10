#pragma once
#include <string>

class Quaternion;

class Vector3
{
public:

	Vector3(float xVal = 0, float yVal = 0, float zVal = 0);

	float x;
	float y;
	float z;

	void set(float xVal, float yVal, float zVal);
	void set(Vector3 vectorVal);

	Vector3 operator +(Vector3 const &rhs);

	Vector3 operator -(Vector3 const &rhs);
	Vector3 operator -();

	Vector3 operator *(Vector3 const &rhs);
	Vector3 operator *(float const scalar);

	Vector3 operator /(Vector3 const &rhs);
	Vector3 operator /(float const scalar);

	void operator=(Vector3 const &rhs);

	//bool operator ==(Vector3 const &rhs);
	//bool operator !=(Vector3 const &rhs);

	float fastMagnitude();
	Vector3 fastNormalize();

	float magnitude();
	float magnitudeSquared();

	Vector3 normalize();

	float dot(Vector3 rhs);
	Vector3 cross(Vector3 rhs);

	float maxAxis();
	float minAxis();

	float distanceTo(Vector3 target);
	float distanceToSquared(Vector3 target);
	Vector3 directionTo(Vector3 target);

	//TODO add rotation based operations with Quats
	Vector3 rotate(Quaternion rotationQuat);
	static Vector3 fromQuaternion(Quaternion fromQuat);

	void printVector(std::string vecName);
};

//Additional Operator Overloads
inline Vector3 operator +(float scalar, Vector3 const& rhs)
{
	return Vector3(scalar + rhs.x, scalar + rhs.y, scalar + rhs.z);
}

inline Vector3 operator -(float scalar, Vector3 const& rhs)
{
	return Vector3(scalar - rhs.x, scalar - rhs.y, scalar - rhs.z);
}

inline Vector3 operator *(float scalar, Vector3 const& rhs)
{
	return Vector3(scalar * rhs.x, scalar * rhs.y, scalar * rhs.z);
}

inline Vector3 operator /(float scalar, Vector3 const& rhs)
{
	return Vector3(scalar / rhs.x, scalar / rhs.y, scalar / rhs.z);
}

