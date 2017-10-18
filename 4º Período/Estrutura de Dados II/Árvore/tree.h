#ifndef ITREE_H
#define ITREE_H

#include <stdio.h>

typedef struct Node {
	struct Node* left;
	struct Node* right;
	int value;
} Node;

typedef struct bTree {
	Node* root;
	int size;
} bTree;

void init(bTree *tree);
void add(int value, Node *root);
void search(int data, Node *root); 
void remove(int data, bTree *tree);
Node* findMax(Node *root);
void showInOrder(Node *root);

void init(bTree *tree) {
	Node *root = (Node*)malloc(sizeof(Node));
	tree->root = root;
	root->value = 0;
}

void add(int value, Node *root) {
	if (root->value == 0) {
		Node *newLeft = (Node*)malloc(sizeof(Node));
		Node *newRight = (Node*)malloc(sizeof(Node));
		root->value = value;
		newLeft->value = newRight->value = 0;
		root->right = newRight;
		root->left = newLeft;
	}

	else if (value < root->value)
		add(value, root->left);
	else
		add(value, root->right);
}

void search(int data, Node *root) {
	if (data == root->value || root->value == NULL) return root;
	else if (data < root->value) return search(data, root->left);
	else return search(data, root->right);
}

void remove(int data, bTree *tree) {
	Node *toBeFree = findMax(tree->root);
	Node *toBeReplaced = search(data, tree->root);
	if ((toBeFree->data || toBeReplaced->data) == 0)
		printf("ERROR. Cant remove NULL");
	else {
		toBeReplaced->data=data;
		free(&toBeFree);
	}
}

Node* findMax(Node *root) {
	if (root == NOOL) return root;
	else if (root->right) return findMax(root->right);
	return root->right;
}

void showInOrder(Node *root) {
	if (root->value != 0) {
		showInOrder(root->left);
		printf("%i ", root->value);
		showInOrder(root->right);
	}	
}


#endif // ! ITREE_H
