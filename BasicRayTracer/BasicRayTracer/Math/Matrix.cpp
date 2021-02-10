#include "Matrix.h"
#include <iostream>
#include <cmath>
#include <math.h>
#include "Vector3.h"
#include "Quaternion.h"

Matrix::Matrix()
{
	set(Matrix::identity());
}

Matrix::Matrix(float matrixArray[])
{
	set(matrixArray);
}

Matrix::Matrix(float m11, float m21, float m31, float m41, float m12, float m22, float m32, float m42, float m13, float m23, float m33, float m43, float m14, float m24, float m34, float m44)
{
	set(m11, m21, m31, m41, m12, m22, m32, m42, m13, m23, m33, m43, m14, m24, m34, m44);
}

void Matrix::set(Matrix setMatrix)
{
	set(setMatrix.matrix);
}

void Matrix::set(float matrixArray[])
{
	matrix[0] = matrixArray[0];
	matrix[1] = matrixArray[1];
	matrix[2] = matrixArray[2];
	matrix[3] = matrixArray[3];
	matrix[4] = matrixArray[4];
	matrix[5] = matrixArray[5];
	matrix[6] = matrixArray[6];
	matrix[7] = matrixArray[7];
	matrix[8] = matrixArray[8];
	matrix[9] = matrixArray[9];
	matrix[10] = matrixArray[10];
	matrix[11] = matrixArray[11];
	matrix[12] = matrixArray[12];
	matrix[13] = matrixArray[13];
	matrix[14] = matrixArray[14];
	matrix[15] = matrixArray[15];
}

void Matrix::set(float m11, float m21, float m31, float m41, float m12, float m22, float m32, float m42, float m13, float m23, float m33, float m43, float m14, float m24, float m34, float m44)
{
	matrix[0] = m11;
	matrix[1] = m21;
	matrix[2] = m31;
	matrix[3] = m41;
	matrix[4] = m12;
	matrix[5] = m22;
	matrix[6] = m32;
	matrix[7] = m42;
	matrix[8] = m13;
	matrix[9] = m23;
	matrix[10] = m33;
	matrix[11] = m43;
	matrix[12] = m14;
	matrix[13] = m24;
	matrix[14] = m34;
	matrix[15] = m44;
}

Matrix Matrix::operator+(Matrix const &rhs)
{
	return Matrix
	(matrix[0] + rhs.matrix[0], matrix[1] + rhs.matrix[1], matrix[2] + rhs.matrix[2], matrix[3] + rhs.matrix[3],
		matrix[4] + rhs.matrix[4], matrix[5] + rhs.matrix[5], matrix[6] + rhs.matrix[6], matrix[7] + rhs.matrix[7],
		matrix[8] + rhs.matrix[8], matrix[9] + rhs.matrix[9], matrix[10] + rhs.matrix[10], matrix[11] + rhs.matrix[11],
		matrix[12] + rhs.matrix[12], matrix[13] + rhs.matrix[13], matrix[14] + rhs.matrix[14], matrix[15] + rhs.matrix[15]);
}

Matrix Matrix::operator-(Matrix const &rhs)
{
	return Matrix
	(matrix[0] - rhs.matrix[0], matrix[1] - rhs.matrix[1], matrix[2] - rhs.matrix[2], matrix[3] - rhs.matrix[3],
		matrix[4] - rhs.matrix[4], matrix[5] - rhs.matrix[5], matrix[6] - rhs.matrix[6], matrix[7] - rhs.matrix[7],
		matrix[8] - rhs.matrix[8], matrix[9] - rhs.matrix[9], matrix[10] - rhs.matrix[10], matrix[11] - rhs.matrix[11],
		matrix[12] - rhs.matrix[12], matrix[13] - rhs.matrix[13], matrix[14] - rhs.matrix[14], matrix[15] - rhs.matrix[15]);
}

Matrix Matrix::operator*(Matrix const &rhs)
{
	return Matrix
	(matrix[0] * rhs.matrix[0] + matrix[4] * rhs.matrix[1] + matrix[8] * rhs.matrix[2] + matrix[12] * rhs.matrix[3], 
		matrix[1] * rhs.matrix[0] + matrix[5] * rhs.matrix[1] + matrix[9] * rhs.matrix[2] + matrix[13] * rhs.matrix[3],
		matrix[2] * rhs.matrix[0] + matrix[6] * rhs.matrix[1] + matrix[10] * rhs.matrix[2] + matrix[14] * rhs.matrix[3],
		matrix[3] * rhs.matrix[0] + matrix[7] * rhs.matrix[1] + matrix[11] * rhs.matrix[2] + matrix[15] * rhs.matrix[3],
		matrix[0] * rhs.matrix[4] + matrix[4] * rhs.matrix[5] + matrix[8] * rhs.matrix[6] + matrix[12] * rhs.matrix[7],
		matrix[1] * rhs.matrix[4] + matrix[5] * rhs.matrix[5] + matrix[9] * rhs.matrix[6] + matrix[13] * rhs.matrix[7],
		matrix[2] * rhs.matrix[4] + matrix[6] * rhs.matrix[5] + matrix[10] * rhs.matrix[6] + matrix[14] * rhs.matrix[7],
		matrix[3] * rhs.matrix[4] + matrix[7] * rhs.matrix[5] + matrix[11] * rhs.matrix[6] + matrix[15] * rhs.matrix[7],
		matrix[0] * rhs.matrix[8] + matrix[4] * rhs.matrix[9] + matrix[8] * rhs.matrix[10] + matrix[12] * rhs.matrix[11],
		matrix[1] * rhs.matrix[8] + matrix[5] * rhs.matrix[9] + matrix[9] * rhs.matrix[10] + matrix[13] * rhs.matrix[11],
		matrix[2] * rhs.matrix[8] + matrix[6] * rhs.matrix[9] + matrix[10] * rhs.matrix[10] + matrix[14] * rhs.matrix[11],
		matrix[3] * rhs.matrix[8] + matrix[7] * rhs.matrix[9] + matrix[11] * rhs.matrix[10] + matrix[15] * rhs.matrix[11],
		matrix[0] * rhs.matrix[12] + matrix[4] * rhs.matrix[13] + matrix[8] * rhs.matrix[14] + matrix[12] * rhs.matrix[15],
		matrix[1] * rhs.matrix[12] + matrix[5] * rhs.matrix[13] + matrix[9] * rhs.matrix[14] + matrix[13] * rhs.matrix[15],
		matrix[2] * rhs.matrix[12] + matrix[6] * rhs.matrix[13] + matrix[10] * rhs.matrix[14] + matrix[14] * rhs.matrix[15],
		matrix[3] * rhs.matrix[12] + matrix[7] * rhs.matrix[13] + matrix[11] * rhs.matrix[14] + matrix[15] * rhs.matrix[15]);
}

void Matrix::operator=(Matrix const& rhs)
{
	this->set(rhs);
}

Matrix Matrix::identity()
{
	return Matrix
	(1,0,0,0,
	0,1,0,0,
	0,0,1,0,
	0,0,0,1
	);
}

Matrix Matrix::zero()
{
	return Matrix
	(0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0);
}

Matrix Matrix::translation(Vector3 transVec)
{
	return Matrix
	(1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	transVec.x, transVec.y, transVec.z, 1
	);
}

Matrix Matrix::rotation(Quaternion rotQuat)
{
	Vector3 v1(1, 0, 0);
	Vector3 v2(0, 1, 0);
	Vector3 v3(0, 0, 1);

	v1 = v1.rotate(rotQuat);
	v2 = v2.rotate(rotQuat);
	v3 = v3.rotate(rotQuat);

	return Matrix
	(v1.x, v1.y, v1.z, 0,
	v2.x, v2.y, v2.z, 0,
	v3.x, v3.y, v3.z, 0,
	0, 0, 0, 1
	);
}

Matrix Matrix::scale(Vector3 scaleVec)
{
	return Matrix
	(scaleVec.x, 0, 0, 0,
	0, scaleVec.y, 0, 0,
	0, 0, scaleVec.z, 0,
	0, 0, 0, 1
	);
}

Matrix Matrix::view(Vector3 eye, Vector3 targetPosition, Vector3 upVector)
{
	Vector3 eyeZVec = (eye - targetPosition).normalize();
	Vector3 eyeXVec = (upVector.cross(eyeZVec)).normalize();
	Vector3 eyeYVec = (eyeZVec.cross(eyeXVec)).normalize();

	return Matrix
	(eyeXVec.x, eyeYVec.x, eyeZVec.x, 0,
	eyeXVec.y, eyeYVec.y, eyeYVec.y, 0,
	eyeXVec.z, eyeYVec.z, eyeZVec.z, 0,
	-eyeXVec.dot(eye), -eyeYVec.dot(eye), -eyeZVec.dot(eye), 1
	);
}

Matrix Matrix::perspective(float viewRadians, float aspect, float near, float far)
{
	float farClip = 1 / std::tan(viewRadians / 2);
	float nearClip = 1 / (near - far);

	return Matrix
	(farClip/aspect, 0, 0, 0,
	0, farClip, 0, 0,
	0, 0, (near+far)*nearClip, -1,
	0, 0, 2*near*far*nearClip, 0);
}

Matrix Matrix::orthographic(float left, float right, float bottom, float top, float near, float far)
{
	float lr = 1 / (left - right);
	float bt = 1 / (bottom - top);
	float nf = 1 / (near - far);

	return Matrix
	(-2*lr, 0, 0, 0,
	0, -2*bt, 0, 0,
	0, 0, 2*nf, 0,
	(left+right)*lr, (top+bottom)*bt, (near+far)*nf, 1
	);
}

void Matrix::printMatrix()
{
	std::cout << "\nMatrix Print\n";

	int rowNum = 0;
	int colNum = 0;
	for (int i = 0; i < 16; i++)
	{
		std::cout << "Element " << i << " " << matrix[i] << std::endl;
	}
}
