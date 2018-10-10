#pragma once

#include "Boss.h"

struct node {
	Comparable *value;
	node *left;
	node *right;
};

class BSTree
{
public:
	BSTree();
	~BSTree();

	void insert_value(node** tree, Comparable *value);
	void print_tree(node* tree);
	void terminate_tree(node* tree);

	node** getRoot();

private:
	node* root = new node;
};

