// Tut13 - Vectors.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>

#include "ArmedEnemy.h"

using namespace std;
using std::vector;

int main() {

	vector<int> scores(5, 0);

	scores[0] = 1; scores[1] = 2; scores[2] = 3;

	for (int i = 0; i < scores.size(); ++i) {
		cout << "scores " << i << " = " << scores[i] << "\n";
	}

	vector<Enemy>* enemies = new vector<Enemy>(3);

	Enemy fourth, fifth;

	enemies->push_back(fourth);
	enemies->push_back(fifth);
	cout << "size of enemies = " << enemies->size() << "\n";

	int i = 0;
	for (vector<Enemy>::iterator it = enemies->begin(); it != enemies->end(); ++it)
	{
		it->set_score(scores[i]);
		cout << "score = " << it->get_score() << "\n";
		++i;
	}

	Enemy newthird;
	enemies->insert(enemies->begin() + 2, newthird);
	enemies->erase(enemies->begin() + 2);

	Enemy& back = enemies->back();
	cout << "hit points last element = " << back.get_hit_points() << "\n";

	enemies->pop_back();
	cout << "new size of enemies = " << enemies->size() << "\n";

	//Task 2
	vector<ArmedEnemy>* theBoys = new vector<ArmedEnemy>(3);

	ArmedEnemy extraBoy1, extraBoy2;

	theBoys->push_back(extraBoy1);
	theBoys->push_back(extraBoy2);
	theBoys->push_back(ArmedEnemy(6,5));

	for (auto it = theBoys->begin(); it != theBoys->end(); it++) {
		it->set_score(theBoys->end() - it);
		cout << "Boy #" << it - theBoys->begin() + 1 << " has a score of " << it->get_score() << " and a HP value of " << it->get_hit_points() << " and an ammo value of " << it->get_ammo() << "!\n";
	}

	//Task 3
	stack<ArmedEnemy>* theMen = new stack<ArmedEnemy>;
	stack<ArmedEnemy>* theManlyMen = new stack<ArmedEnemy>;

	ArmedEnemy extraMan1, extraMan2, extraMan3;

	theMen->push(extraMan1);
	theMen->push(extraMan2);
	theMen->push(extraMan3);

	//cant iterate through STACK AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
	for (int i = 0; i < theMen->size(); i++) {
		//theMen[i]->get_score();
	}

	//Pop the man
	theManlyMen->push(ArmedEnemy());
	cout << "NEW MANLY MAN" << endl;
	cout << "THERE " << (theMen->size() == 1 ? "IS " : "ARE ") << theMen->size() << (theMen->size() == 1 ? " MAN" : " MEN") << " AND " << theManlyMen->size() << " MANLY " << (theMen->size() == 1 ? "MAN!!!!!!!!!!!!!!!!" : "MEN!!!!!!!!!!!!!!!!") << endl;
	theManlyMen->swap(*theMen);
	cout << "SWAP EM MEN ARE NOW MANLY AND MANLY ARE NOW NOT SO MANLY!!!!!" << endl;
	cout << "THERE " << (theMen->size() == 1 ? "IS " : "ARE ") << theMen->size() << (theMen->size() == 1 ? " MAN" : " MEN") << " AND " << theManlyMen->size() << " MANLY " << (theMen->size() == 1 ? "MAN!!!!!!!!!!!!!!!!" : "MEN!!!!!!!!!!!!!!!!") << endl;
	theMen->pop();
	cout << "MAN DOWN" << endl;
	cout << "THERE " << (theMen->size() == 1 ? "IS " : "ARE ") << theMen->size() << (theMen->size() == 1 ? " MAN" : " MEN") << " AND " << theManlyMen->size() << " MANLY " << (theMen->size() == 1 ? "MAN!!!!!!!!!!!!!!!!" : "MEN!!!!!!!!!!!!!!!!") << endl;

	queue<ArmedEnemy>* theSmalls = new queue<ArmedEnemy>;

	//Queues work the same as Stacks except that they are first in first out which differes from the stacks first in last out system.

	//Task 4

	vector<ArmedEnemy>* theDudes = new vector<ArmedEnemy>(10);

	int randy = 0;
	for (auto it = theDudes->begin(); it != theDudes->end(); it++) {
		randy = rand() % 25;
		it->set_hit_points(randy);
		cout << "Dude #" << it - theDudes->begin() + 1 << " has a score of " << it->get_score() << " and a HP value of " << it->get_hit_points() << " and an ammo value of " << it->get_ammo() << endl;
	}

	random_shuffle(theDudes->begin(), theDudes->end());

	cout << "SHUFFLED DUDES!!!!!" << endl;
	for (auto it = theDudes->begin(); it != theDudes->end(); it++) {
		cout << "Dude #" << it - theDudes->begin() + 1 << " has a score of " << it->get_score() << " and a HP value of " << it->get_hit_points() << " and an ammo value of " << it->get_ammo() << endl;
	}

	sort(theDudes->begin(), theDudes->end());

	cout << "SORTED DUDES!!!!!" << endl;
	for (auto it = theDudes->begin(); it != theDudes->end(); it++) {
		cout << "Dude #" << it - theDudes->begin() + 1 << " has a score of " << it->get_score() << " and a HP value of " << it->get_hit_points() << " and an ammo value of " << it->get_ammo() << endl;
	}

	// clear enemies of elements
	enemies->clear();
	theBoys->clear();
	theMen->empty();
	theManlyMen->empty();

	delete enemies;
	delete theBoys;
	delete theMen;
	delete theManlyMen;
	delete theSmalls;

	int x;
	cin >> x;	

	return 0;
}

/*	Task 1
	Vectors store memory in contiguous memory locations like an array, which means they are stored one after the other. Lists however store their elements at non contiguous memory loctions using doubly linked
	lists. Vectors will generally be better when it comes to cache-friendly-ness and cache hit rate due to the fact that it stores memory in a contiguous way. When accessing memory the CPU will sometimes 
	fetch a larger than specified set of memory as it may require that data soon.
*/
