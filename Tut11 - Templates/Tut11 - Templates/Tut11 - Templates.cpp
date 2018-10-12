// Tut11 - Templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"
#include "BSTemplate.h"
#include "Stack.h"

#include <iostream>

using namespace std;

BSTemplate<int>* BSTree = new BSTemplate<int>;

Stack<int>* intStack = new Stack<int>;

int main()
{
	MatrixInt m(3, 4);
	m.set_element(2, 2, 8);
	cout << "element at 2,2 is " << m.get_element(2, 2) << "\n";

	Matrix<int> m_int;
	m_int.set_element(1, 1, 4);
	cout << "element at 1,1 is " << m_int.get_element(1, 1) << "\n";

	Matrix<double> m_doub;
	m_doub.set_element(2, 2, 8.421);
	cout << "element at 2,2 is " << m_doub.get_element(2, 2) << "\n";

	//Task 3
	Matrix<char> m_char;
	int count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			m_char.set_element(j, i, char(97+count));
			count++;
		}
	}
	cout << "element at 2, 2 is " << m_char.get_element(1, 1) << endl;

	//Task 4
	BSTree->insert_node(BSTree->getRoot(), 10);
	
	//BSTree->print_tree(*BSTree->getRoot());

	//Task 5
	intStack->Push(10);
	intStack->Push(11);	

	intStack->printElem(0);

	cout << "Stack size: " << intStack->getSize() << endl;

	intStack->Pop();

	cout << "Stack size: " << intStack->getSize() << endl;

	int x = 0;
	cin >> x;

	return 0;
}

/*	Task 1
	The compiler performs the compilation of a template class when it has been instantiated with the type argument specifying the template type. 
*/

/*	Task 2
	When the compiler generates the code for a template it needs all of the informaton regarding which describes the functionality of that template in the same place. Therefore you 
	need to make all of the code pertaining to the template availible in the same header file.
*/