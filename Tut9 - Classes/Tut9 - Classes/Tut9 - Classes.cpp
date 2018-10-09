// Tut9 - Classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "Enemy.h"
#include "Player.h"
#include "BST.h"
#include "Battleship.h"

using namespace std;

//Task 3
BST* binarySearchTree = new BST;

int vals[5] = { 2,1,3,4,5 };

//Task 4
Battleship* bShips = new Battleship;

int main(void) {

	Enemy e1(2,0);
	cout << "hit points = " << e1.get_hit_points() << "\n";

	Enemy* e2 = new Enemy(2, 0);
	e2->set_hit_points(3);
	cout << "hit points = " << e2->get_hit_points() << "\n";

	e2->set_score(2);
	cout << "score = " << e2->get_score() << "\n";

	//task 2
	Player* p1 = new Player(2, 0);
	p1->set_name("sam");

	cout << "player name = " << p1->get_name() << endl;

	//Task 3;
	for (int& e : vals) {
		binarySearchTree->insert_integer(&binarySearchTree->root, e);
	}

	//binarySearchTree->display_tree(binarySearchTree->root);

	binarySearchTree->print_tree(binarySearchTree->root);

	if (binarySearchTree->find_value(binarySearchTree->root, 3)) { 
		cout << "\nThis number exists in the tree!";
	}
	else {
		cout << "\nCould not find number in tree!";
	};

	//Task 4
	cout << endl;
	bShips->printGrid();
	while (!bShips->checkScore()) {
		bShips->inputGuess();
	}

	
	delete e2;
	e2 = NULL;
	delete p1;
	p1 = NULL;
	delete binarySearchTree;
	binarySearchTree = NULL;
	delete bShips;
	bShips = NULL;

	int exit;
	cout << "\nEnter number to exit: ";
	cin >> exit;

	return 0;
}
