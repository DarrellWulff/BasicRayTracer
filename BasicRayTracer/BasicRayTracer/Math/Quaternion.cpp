#include "Quaternion.h"
#include <cmath>
#include "MathFunctions.h"
#include "Vector3.h"

Quaternion::Quaternion(float thetaAngle, float xVal, float yVal, float zVal)
{
	float halfTheta = thetaAngle * 0.5f;
	double sinFactor = sin(halfTheta);

	w = (float) cos(sinFactor);
	x = (float) sinFactor * xVal;
	y = (float) sinFactor * yVal;
	z = (float) sinFactor * zVal;

	float axisMag = std::sqrt(w * w + x * x + y * y + z * z);

	x = x / axisMag;
	y = y / axisMag;
	z = z / axisMag;
}

void Quaternion::set(float wVal, float xVal, float yVal, float zVal)
{
	w = wVal;
	x = xVal;
	y = yVal;
	z = zVal;
}

void Quaternion::set(Quaternion quatVal)
{
	w = quatVal.w;
	x = quatVal.x;
	y = quatVal.y;
	z = quatVal.z;
}

void Quaternion::operator=(Quaternion const& rhs)
{
	w = rhs.w;
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
}

Quaternion Quaternion::operator*(Quaternion const &q2)
{
	float newX = x * q2.w + y * q2.z - z * q2.y + w * q2.x;
	float newY = -x * q2.z + y * q2.w + z * q2.x + w * q2.y;
	float newZ = x * q2.y - y * q2.x + z * q2.w + w * q2.z;
	float newW = -x * q2.x - y * q2.y - z * q2.z + w * q2.w;

	this->renormalize();

	return Quaternion(newW, newX, newY, newZ);
}

float Quaternion::magnitude()
{
	return std::sqrt(w * w + x * x + y * y + z * z);
}

Quaternion Quaternion::inverse()
{
	return Quaternion(-w, -x, -y, -z);
}

void Quaternion::renormalize()
{
	float angleValue = std::sqrt(1 - w * w);
	Vector3 vectorComp = Vector3::fromQuaternion(*this).normalize();

	x = vectorComp.x;
	y = vectorComp.y;
	z = vectorComp.z;
}

Quaternion Quaternion::applyQuatRotation(Quaternion quatRotation)
{
	Quaternion rotatedQuat = this->inverse() * quatRotation * (*this);
	return rotatedQuat;
}

Quaternion Quaternion::applyLocalQuatRotation(Quaternion quatRotation)
{
	Quaternion localQuatRot = this->applyQuatRotation(quatRotation);

	localQuatRot = *this * localQuatRot;

	return localQuatRot;
}

Quaternion Quaternion::quaternionSLERP(Quaternion toQuat, float t)
{
	Vector3 fromVec = Vector3::fromQuaternion(*this).normalize();
	Vector3 toVec = Vector3::fromQuaternion(toQuat).normalize();

	float dotBetween = fromVec.dot(toVec);

	if (dotBetween > SLERP_DOT_THRESHOLD) 
	{
		Quaternion slerpResult = Quaternion::fromVector((fromVec + (toVec - fromVec) * t));
		return slerpResult;
	}

	dotBetween = MathFunctions::clamp(dotBetween, -1, 1);

	float angleBetween = std::acos(dotBetween);
	float theta = angleBetween * t;

	Vector3 basisVector = (toVec - fromVec * dotBetween).normalize();

	return Quaternion::fromVector(fromVec * cos(theta) + toVec * sin(theta));
}

Quaternion Quaternion::fromVector(Vector3 fromVec)
{
	return Quaternion(0, fromVec.x, fromVec.y, fromVec.z);
}
