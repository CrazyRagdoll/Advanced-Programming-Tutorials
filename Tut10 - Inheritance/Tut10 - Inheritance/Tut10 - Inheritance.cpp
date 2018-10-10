// Tut10 - Inheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "Boss.h"
#include "BSTree.h"

using namespace std;

void some_function(Enemy& enemy) {
	enemy.set_score(6);
}

int main(void) {

	//Task 3
	Boss* b = new Boss(5, 5, 10);
	cout << "Boss hp: " << b->get_hit_points() << "\nBoss armour: " << b->get_armour_level() << endl;
	b->set_armour_level(25);
	cout << "New Boss armour: " << b->get_armour_level() << endl;

	//Task 4
	ArmedEnemy* aeArray[10];
	Enemy* allEnemies[11];
	for (int i = 0; i < 10; i++) {
		aeArray[i] = new ArmedEnemy(2,2);
		allEnemies[i] = aeArray[i];
	}
	allEnemies[10] = b;

	for (int i = 0; i < 11; i++) {
		allEnemies[i]->set_hit_points(allEnemies[i]->get_hit_points() - 1);
		cout << "Enemy " << i << " hp: " << allEnemies[i]->get_hit_points() << endl;
	}

	//Task 5
	Boss* b2 = new Boss(5, 6, 11);
	BSTree* tree = new BSTree;
	tree->insert_value(tree->getRoot(), b);
	tree->insert_value(tree->getRoot(), b2);

	tree->print_tree(*tree->getRoot());

	ArmedEnemy* ae = new ArmedEnemy(2, 5);
	ae->set_hit_points(3);
	cout << "hit points = " << ae->get_hit_points() << "\n";

	ae->shoot();

	some_function(*ae);

	int p;
	cin >> p;

	delete ae;
	ae = NULL;
	delete b;
	b = NULL;
	for (int i = 0; i < 10; i++) {
		delete aeArray[i];
		delete allEnemies[i];
	}
	delete allEnemies[10];
	delete[] *aeArray;
	delete[] *allEnemies;

	return 0;
}

/*	Task 1
	If the destructor class was not virtual in the base class then it would not be inherited by the child and would then not be called when that child object is deleted.
	This will cause memory leaks if the child class has also inherited varibles that have been created on the heap by the parent as they will not die.
*/

/*	Task 2
	When using the keyword virtual it is telling the compiler that if a class inherites from that class it will also want a verison of it's methods with the keyword virtual.
	This means that when the child class calls a method which was inherited from the parent the complier needs to figure out which version of the method should be invoked which
	then requires more memory than just invoking the child's method without consulting the vtable for the parents methods.
*/