#pragma once

struct node {
	int value;
	struct node * left;
	struct node * right;
};

class BST
{
public:
	BST();
	~BST();

	void insert_integer(node** tree, int val);
	void print_tree(node* tree);
	void display_tree(node* tree);
	bool find_value(node* tree, int val);
	void terminate_tree(node* tree);

	node** getRoot();

private:
	node* root = new node;
};

