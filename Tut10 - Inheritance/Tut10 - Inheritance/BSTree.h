#pragma once

#include "Boss.h"

struct node {
	Boss value;
	node *left;
	node *right;
};

class BSTree
{
public:
	BSTree();
	~BSTree();

	void insert_value(node** tree, Boss boss);
	void print_tree(node* tree);
	void terminate_tree(node* tree);


private:
	node** root;
};

