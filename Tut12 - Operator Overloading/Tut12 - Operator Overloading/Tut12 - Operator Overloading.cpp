// Tut12 - Operator Overloading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Matrix.h"
#include "ComplexNumber.h"


using namespace std;

int main() {
	Matrix<int> mtx1;
	mtx1.set_element(0, 0, 1);
	mtx1.set_element(1, 1, 4);
	mtx1.set_element(2, 2, 6);
	cout << "matrix 1:\n" << mtx1;

	Matrix<int> mtx2;
	mtx2.set_element(0, 0, 1);
	mtx2.set_element(1, 1, 4);
	mtx2.set_element(2, 2, 2);
	cout << "matrix 2:\n" << mtx2;

	Matrix<int> mtx3;
	mtx3 = mtx2;
	cout << "matrix 3 assigned from matrix 2:\n" << mtx3;

	Matrix<int> product = (mtx1 * mtx3);
	cout << "matrix product assigned from mtx1 * mtx3:\n" << product;

	//Task 2
	Matrix<int> addProd = (mtx1 + mtx3);
	cout << "matrix product assigned from mtx1 + mtx3:\n" << addProd;

	Matrix<int> subProd = (mtx1 - mtx3);
	cout << "matrix product assigned from mtx1 - mtx3:\n" << subProd;

	cout << "Is mtx1 the same as mtx3? " << ( (mtx1 == mtx3) ? "Yes!\n" : "No!\n");

	//Task 3
	Matrix<ComplexNumber> mtxCN1;
	Matrix<ComplexNumber> mtxCN2;
	mtxCN1.set_element(0, 0, ComplexNumber(3,3));
	mtxCN2.set_element(0, 0, ComplexNumber(3,2));

	cout << mtxCN1;
	cout << mtxCN2;

	Matrix<ComplexNumber> addComplex = (mtxCN1 + mtxCN2);
	cout << "matrix product assigned from complex numbers mtxCN1 + mtxCN2:\n" << addComplex;

	Matrix<ComplexNumber> subComplex = (mtxCN1 - mtxCN2);
	cout << "matrix product assigned from complex numbers mtxCN1 - mtxCN2:\n" << subComplex;

	Matrix<ComplexNumber> multComplex = (mtxCN1 * mtxCN2);
	cout << "matrix product assigned from complex numbers mtxCN1 * mtxCN2:\n" << multComplex;

	cout << "Is mtxCN1 the same as mtxCN2? " << ((mtxCN1 == mtxCN2) ? "Yes!\n" : "No!\n");

	int x;
	cin >> x;
	return 0;
}