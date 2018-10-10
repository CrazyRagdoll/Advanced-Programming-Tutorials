#include "stdafx.h"
#include "BSTree.h"

#include <iostream>

BSTree::BSTree() :
	root(NULL){
}


BSTree::~BSTree(){
	delete root;
}

void BSTree::insert_value(node** tree, Comparable *value) {
	if (*tree == NULL) {
		node* child = new node;
		child->value = value;
		child->left = NULL; child->right = NULL;
		(*tree) = child;
	}
	else if ((*tree)->value->compare_to(*value) == 1) {
		insert_value(&(*tree)->left, value);
	}
	else {
		insert_value(&(*tree)->right, value);
	}
}

void BSTree::print_tree(node* tree) {
	if (tree->left != NULL) {
		print_tree(tree->left);
	} 
	std::cout << tree->value << std::endl;
	if (tree->right != NULL) {
		print_tree(tree->right);
	}
}

void BSTree::terminate_tree(node* tree) {
	if (tree->left != NULL) {
		terminate_tree(tree->left);
	}
	if (tree->right != NULL) {
		terminate_tree(tree->right);
	}
	delete tree;
}

node** BSTree::getRoot() {
	return &root;
}