#pragma once

class Vector3;
class Quaternion;

class Matrix
{
public:

	Matrix();
	Matrix(float matrixArray[]);
	Matrix(float m11, float m21, float m31, float m41, 
		float m12, float m22, float m32, float m42, 
		float m13, float m23, float m33, float m43,
		float m14, float m24, float m34, float m44);

	float matrix[16];

	void set(Matrix setMatrix);
	void set(float matrixArray[]);
	void set(float m11, float m21, float m31, float m41,
		float m12, float m22, float m32, float m42,
		float m13, float m23, float m33, float m43,
		float m14, float m24, float m34, float m44);

	Matrix operator +(Matrix const &rhs);
	Matrix operator -(Matrix const &rhs);
	Matrix operator *(Matrix const &rhs);
	void operator =(Matrix const &rhs);

	static Matrix identity();
	static Matrix zero();
	
	static Matrix translation(Vector3 transVec);
	static Matrix rotation(Quaternion rotQuat);
	static Matrix scale(Vector3 scaleVec);

	static Matrix view(Vector3 eye, Vector3 targetPosition, Vector3 upVector);
	static Matrix perspective(float viewRadians, float aspect, float near, float far);
	static Matrix orthographic(float left, float right, float bottom, float top, float near, float far);

	void printMatrix();
};

