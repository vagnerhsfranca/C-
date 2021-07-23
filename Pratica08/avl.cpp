/*
 * avl.cpp
 *
 *  Created on: 3 de nov de 2017
 *      Author: ramide
 */

#include <iostream>
#include "avl.h"

using namespace std;

BinaryTree::Node * AVLTree::insert(BinaryTree::Node * root, int key) {
	root = BinaryTree::insert(root, key);

	if (!balanced(root))
		root = rebalance(root);

	return root;
}

BinaryTree::Node * AVLTree::remove(BinaryTree::Node * root, int key) {
	if (root == NULL)
		return NULL;

	root = BinaryTree::remove(root, key);

	if (root != NULL && !balanced(root))
		root = rebalance(root);

	return root;
}

BinaryTree::Node * AVLTree::removeMax(BinaryTree::Node * root, int & max) {

	root = BinaryTree::removeMax(root, max);

	if (root != NULL && !balanced(root))
			root = rebalance(root);

	return root;
}

BinaryTree::Node * AVLTree::rebalance(Node * root) {
	ASSERT(!balanced(root), "Already balanced!");

	if (leftHeavy(root)) {
		if (rightHeavy(root->left))
			root->left = rotateLeft(root->left);

		root = rotateRight(root);
	} else { // rightHeavy
		if (leftHeavy(root->right))
			root->right = rotateRight(root->right);

		root = rotateLeft(root);
	}

	ASSERT(balanced(root), "Rebalance failed!");
	return root;
}

// Realiza a rotação a esquerda sobre "root" retornando a nova raiz
BinaryTree::Node * AVLTree::rotateLeft(Node * root) {
	Node *nova_raiz = root->right;
	root->right = nova_raiz->left;
	nova_raiz->left = root;
    updateH(root);
    updateH(nova_raiz);
	return nova_raiz;
}

// Realiza a rotação a direita sobre "root" retornando a nova raiz
BinaryTree::Node * AVLTree::rotateRight(Node * root) {
	Node *nova_raiz = root->left;
	root->left = nova_raiz->right;
	nova_raiz->right = root;
	updateH(root);
    updateH(nova_raiz);

	return nova_raiz;
}

void AVLTree::show(Node * root) {
	if (root == NULL)
		return;
	show(root->left);
	cout << "(" << root->key << ", "
			<< root->height << ", "
			<< BF(root) << ") ";
	show(root->right);
}

int AVLTree::validate(Node * root, int &min, int &max) {
	int valid = BinaryTree::validate(root, min, max);

	return valid && balanced(root);
}
