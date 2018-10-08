// Tut9 - Classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "Enemy.h"
#include "Player.h"
#include "BST.h"

using namespace std;

//Task 3
BST* binarySearchTree = new BST;

int bin[10] = { 1,2,3,4,5,6,7,8,9,10 };

int main(void) {

	Enemy e1(2);
	cout << "hit points = " << e1.get_hit_points() << "\n";

	Enemy* e2 = new Enemy(2);
	e2->set_hit_points(3);
	cout << "hit points = " << e2->get_hit_points() << "\n";

	e2->set_score(2);
	cout << "score = " << e2->get_score() << "\n";

	//Task 2
	Player* p1 = new Player(2);
	p1->set_name("Sam");

	cout << "Player name = " << p1->get_name() << endl;

	//Task 3;
	for (int& e : bin) {
		binarySearchTree->insert_integer(&binarySearchTree->root, e);
	}

	binarySearchTree->print_tree(binarySearchTree->root);

	if (binarySearchTree->find_value(binarySearchTree->root, 3)) { 
		cout << "\nThis number exists in the tree!";
	}
	else {
		cout << "\nCould not find number in tree!";
	};

	
	delete e2;
	e2 = NULL;
	delete p1;
	p1 = NULL;
	delete binarySearchTree;
	binarySearchTree = NULL;

	int exit;
	cout << "\nEnter number to exit: ";
	cin >> exit;

	return 0;
}
