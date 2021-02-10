#pragma once

class Vector3;

class Quaternion
{
public:

	Quaternion(float thetaAngle = 0, float xVal = 0, float yVal = 0, float zVal = 0);

	float w;
	float x;
	float y;
	float z;

	void set(float wVal, float xVal, float yVal, float zVal);
	void set(Quaternion quatVal);

	void operator=(Quaternion const& rhs);
	Quaternion operator*(Quaternion const &q2);

	float magnitude();
	Quaternion inverse();
	void renormalize();

	Quaternion applyQuatRotation(Quaternion quatRotation);
	Quaternion applyLocalQuatRotation(Quaternion quatRotation);

	Quaternion quaternionSLERP(Quaternion toQuat, float t);

	static Quaternion fromVector(Vector3 fromVec);

private:

	const float SLERP_DOT_THRESHOLD = 0.9995f;
};

