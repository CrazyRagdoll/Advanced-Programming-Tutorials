#pragma once

template <typename T>
struct node {
	T value;
	node<T>* left;
	node<T>* right;
};

template <typename T>
class BSTemplate
{
public:
	BSTemplate();
	~BSTemplate();

	void insert_node(node<T>** tree, T value);
	void print_tree(node<T>* tree);
	void find_node(node<T>* tree);
	void termniate_tree(node<T>* tree);

	node<T>** getRoot() { return &root; }

private:
	node<T>* root = new node;
};

template <typename T>
BSTemplate<T>::BSTemplate() :
	root(NULL)
{

}

template <typename T>
BSTemplate<T>::~BSTemplate() {
	delete root;
}

template <typename T>
void BSTemplate<T>::insert_node(node<T>** tree, T value) {
	if ((*tree) == NULL) {
		node<T>* child = new node<T>;
		child->value = value; child->left = NULL; child->right = NULL;
		*tree = child;
		//delete child;
	} else if (value < (*tree)->value) {
		insert_node(&(*tree)->left, value);
	}
	else {
		insert_node(&(*tree)->right, value);
	}
}

template <typename T>
void BSTemplate<T>::print_tree(node<T>* tree) {
	if (tree->left != NULL) {
		print_tree(tree->left);
	}
	cout << tree->value << " ";
	if (tree->right != NULL) {
		print_tree(tree->right);
	}
}

template <typename T>
void BSTemplate<T>::find_node(node<T>* tree) {

}

template <typename T>
void BSTemplate<T>::termniate_tree(node<T>* tree) {

}