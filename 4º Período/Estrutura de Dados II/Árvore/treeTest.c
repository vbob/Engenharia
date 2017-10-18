#include "tree.h"

void main() {
	bTree binaryTree;
	init(&binaryTree);
	add(1, binaryTree.root);
	add(3, binaryTree.root);
	add(2, binaryTree.root);
	add(5, binaryTree.root);
	add(7, binaryTree.root);
	add(4, binaryTree.root);
	add(5, binaryTree.root);
	add(6, binaryTree.root);
	add(8, binaryTree.root);
	showInOrder(binaryTree.root);
}
