// Tut5 - Memory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// *******************************************
// * New, Delete, the Stack and the Heap *
// *******************************************

// Summary
// -------
// Understand about allocating and freeing memory and
// the Stack versus the Heap

// New Concepts
// ------------
// Memory Allocation

/*
#include <iostream>

using namespace std;

int main() {

	// when we declare the variable 'a' we are telling the compiler
	// to create this variable in an area of memory called the 'stack'. Stack 
	// variables are sometimes referred to as 'local variables' because they
	// only exist within a certain scope (more on scope later)
	int a;

	// variables on the 'stack' can hold any predefined type, including pointers
	// so we can also declare pointers on the stack like so...
	int* b;

	// You have already seen how you can assign a variable on the stack to a value
	// with the assignment operator '='. Here we assign the stack variable 'a' to 
	// hold the value 100
	a = 100;

	// The 'new' keyword allows us to allocate memory on something called 
	// the 'heap' instead of the 'stack'. The keyword 'new' is provided by C++ 
	// to handle the creation of variables on the 'heap' for us. In order to use
	//'new' you must specify the type of variable to create so that the compiler
	// knows how much memory to allocate on the 'heap'. Using 'new' also 'returns' 
	// the memory address where the newly allocated memory is located, so you must
	// assign the result of 'new' to a pointer type. The type of pointer will usually 
	// match the type of memory allocated. 
	b = new int;

	// Now we have a pointer to an integer called 'b' which points to an address	
	// located in 'heap' memory. We say the pointer 'b' exists on the stack but the 
	// memory pointed to by 'b' exists on the heap
	cout << "The pointer b points to the memory address " << b << " located on the heap\n";

	// After calling 'new' the memory is initialised to zero
	// and we can verify this by dereferencing the pointer b	
	cout << "The value in memory location b is " << *b << "\n";

	// If we want to assign the newly created 'heap' memory to a value we
	// must dereference pointer 'b' and assign it to an integer value
	*b = a;

	// Now the area of 'heap' memory pointed to by 'b' contains a copy of the value
	// assigned to the stack variable 'a'. Two memory locations contain the value 
	// 100, one on the stack and the other on the heap 
	cout << "The value of stack variable a is " << a << "\n";
	cout << "The 'heap' memory pointed to by b contains " << *b << "\n";

	// The memory containing 'stack' variables is automatically 'released' 
	// when the program execution leaves their 'scope'. Variables allocated on the
	// 'heap' however are not automatically released like 'stack' variables. 
	// it is very important that the programmer releases 'heap' memory when finished
	// with it or else the memory cannot be reused and a 'memory leak' will be created. 
	// C++ provides the keyword 'delete' for this task which expects a pointer to 
	// a memory address on the 'heap'...
	delete b;

	// when delete it called on a pointer variable it is good programming practise
	// to set the pointer to NULL. If you subsequently try to access a pointer that 
	// has been 'freed' with 'delete' you will probably cause your program to crash
	b = NULL;

	// having reached the end of the function, the stack variables 'int a' and 'int* b'
	// will be automatically released. If you had not released the 'heap' memory previously
	// pointed to by 'b' it would have be lost for the duration of the program execution
	// always remember to free memory allocated with 'new' once you are finished with it,
	// by calling 'delete' on the pointer which points to it! 
	return 0;
}*/

#include <iostream>
#include <string>

using namespace std;

//Task 5
struct node {
	int value;
	struct node * left;
	struct node * right;
};

struct node * root = NULL;

// implement the functions described by these headers
void insert_integer(struct node ** tree, int value);
void print_tree(struct node * tree);
void terminate_tree(struct node * tree);

int main () {

	//Task 3
	char stackChar = 'A';
	string* heapString = new string;
	delete heapString;

	//Task 4
	int* heapArray = new int[10];
	delete[] heapArray;

	//Task 5 
	insert_integer(&root, 4);
	insert_integer(&root, 6);

	print_tree(root);

	terminate_tree(root);


	/*int a;

	int* b;

	a = 100;

	b = new int;

	cout << "The pointer b points to the memory address " << b << " located on the heap\n";
	cout << "The value in memory location b is " << *b << "\n";

	*b = a;

	cout << "The value of stack variable a is " << a << "\n";
	cout << "The 'heap' memory pointed to by b contains " << *b << "\n";

	delete b;
	b = NULL; */

	int close;
	cin >> close;

	return 0;
}

/*	Task 1
	Stack Overflow occurs when a program reachs the limits of the stack memory and attempts to add more data to the stack causing it to "overflow". This is common within recursive methods
	as they call themselves storing each itteration on the stack. If the recursive fucntion does not have a (early) break point it may continue infinitly and quickly fill the stack.
*/

/*	Task 2
	Memory leaks are most commonly associated with pointers that have been assigned on the heap and have not been cleaned up by the; garbage collector (Java) or the programmer (c++).
	Memory that has been assigned on the heap and is not cleaned up cannot be reused by the program and thus create a memory leak, the program may eventually exhaust the programs availble 
	memory and cause a failure.
*/

//Task 5
void insert_integer(struct node ** tree, int value) {
	//If the current node is empty create a new node and add it to the tree
	if ((*tree) == NULL) {
		node * child = new node;
		child->value = value;
		child->left	 = NULL; child->right = NULL;
		(*tree) = child;
	//If the current node has a value compare the new value against it to decide where to put the next node, left or right
	} else if (value <= (*tree)->value)	
	{	
		insert_integer(&(*tree)->left, value);
	} else 
	{	
		insert_integer(&(*tree)->right, value);
	}
}

void print_tree(struct node * tree) {
	//Keep checking left until there are no more nodes on the left then print the current node and check right again.
	if (tree->left != NULL) {
		print_tree(tree->left);
	}
	cout << tree->value << " ";
	if (tree->right != NULL) {
		print_tree(tree->right);
	}
}

void terminate_tree(struct node * tree) {
	//Parse through the whole tree deleteing everything
	if (tree->left != NULL) {
		terminate_tree(tree->left);
	}
	if (tree->right != NULL) {
		terminate_tree(tree->right);
	}
	delete tree;

}