#include "stdafx.h"
#include "BST.h"

#include <iostream>

using namespace std;

BST::BST():
	root(NULL){
}


BST::~BST() {
	delete root;
}

void BST::insert_integer(node** tree, int val) {
	if ((*tree) == NULL) {
		node* child = new node;
		child->value = val;
		child->left = NULL; child->right = NULL;
		(*tree) = child;
	}
	else if (val <= (*tree)->value) {
		insert_integer(&(*tree)->left, val);
	}
	else {
		insert_integer(&(*tree)->right, val);
	}
}

void BST::print_tree(node * tree) {
	if (tree->left != NULL) {
		print_tree(tree->left);
	}
	cout << tree->value << " ";
	if (tree->right != NULL) {
		print_tree(tree->right);
	}
}

void BST::display_tree(node * tree) {

}

bool BST::find_value(node * tree, int val) {
	if (tree == NULL) { return false; }
	if (tree->value == val) {
		return true;
	} else {
		if (val <= tree->value) {
			find_value(tree->left, val);
		}
		else {
			find_value(tree->right, val);
		}
	}
}
