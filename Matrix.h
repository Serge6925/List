#pragma once
#include <iostream>
#include <vector>
class Matrix
{
protected:
	int size = 0;
	double* data = nullptr;
public:
	Matrix(int size_n) : size(size_n)
	{
		data = new double(size*size);
		for (int i = 0; i < size * size; i++)
			data[i] = 1;
	}

	double& operator () (int i, int j)
	{
		return this->data[i * size + j];
	}

	Matrix& operator * (Matrix B)
	{
		Matrix A = *this;
		Matrix C(A.size);
		for (int i = 0; i < C.size; i++)
			for (int j = 0; j < C.size; j++)
				for (int k = 0; k < C.size; k++)
					C(i, j) += A(i, k) * B(k, j);
		return C;
	}

};