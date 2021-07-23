/*
 * bst.cpp
 *
 *  Created on: 30 de out de 2017
 *      Author: ramide
 */

#include <iostream>
#include <stdlib.h>
#include <climits> // INT_MIN e INT_MAX

#include "bst.h"

BinaryTree::Node * BinaryTree::insert(BinaryTree::Node * root, int key) {
	if(root == NULL){
        Node *novo_no = new Node(key);
        root = novo_no;
        BinaryTree::updateH(root);
	}else if(key > root->key){
        root->right = insert(root->right, key);
        BinaryTree::updateH(root);
    }
	else if(key < root->key){
        root->left = insert(root->left, key);
        BinaryTree::updateH(root);
	}

	return root;
}

BinaryTree::Node * BinaryTree::search(BinaryTree::Node * root, int key) {
	if (root == NULL) return NULL;

	if (root->key == key) return root;

	if (root->key < key)
		return search(root->right, key);
	else
		return search(root->left, key);
}

BinaryTree::Node * BinaryTree::remove(BinaryTree::Node * root, int key) {

	if (root == NULL) return NULL; // (sub)�rvore vazia, nada a fazer

	if (key == root->key) { // Chave encontrada!
		if (root->left != NULL && root->right != NULL) { // Caso 3
			int maxLeft;
			// Removo o maior filho da esquerda e
			// substituo o valor do n� atual com o valor que era dele
			root->left = removeMax(root->left, maxLeft);
			root->key = maxLeft;
		} else { // Casos 1 e 2
			Node * tmp = root;
			root = (root->right != NULL)?root->right:root->left;
			delete tmp;
		}
	} else {
		if (key > root->key)
			root->right = remove(root->right, key);
		else
			root->left = remove(root->left, key);
	}

	// Lembrar sempre de atualizar a altura; importante para a AVL
	if (root != NULL) updateH(root);

	return root;
}

BinaryTree::Node * BinaryTree::removeMax(BinaryTree::Node * root, int & max) {
	if (root == NULL) throw "ERRO";

	if (root->right != NULL) {
		root->right = removeMax(root->right, max);
	} else {
		max = root->key;
		Node * tmp = root;
		root = root->left;
		delete tmp;
	}

	if (root != NULL)
		updateH(root);

	return root;
}

// Acha n� predecessor (pred) a chave (key)
void BinaryTree::predecessor(Node * root, Node * & pred, int key) {
	if (root == NULL) return;

	if (root->key == key) { 		// Chave encontrada
		root = root->left;			// Desce a esquerda, pred n�o � mexido inicialmente
		while (root != NULL) {
			pred = root;			// pred vai ser o elemento mais a direita
			root = root->right;
		}
	} else {
		if (key < root->key)		// Chave se encontra a esquerda da raiz
			// n�o mexemos em pred aqui
			predecessor(root->left, pred, key);
		else						// Chave se encontra a direita
			// No caso de predecessor, pred � atualizado quando descemos a direita
			predecessor(root->right, pred = root, key);
	}
}

// Acha n� sucessor (succ) a chave (key)
void BinaryTree::successor(Node * root, Node * & succ, int key) {
    if (root == NULL) return;

	if (root->key == key) { 		// Chave encontrada
		root = root->right;			// Desce a esquerda, pred n�o � mexido inicialmente
		while (root != NULL) {
			succ = root;			// pred vai ser o elemento mais a direita
			root = root->left;
		}
	} else {
		if (key > root->key)		// Chave se encontra a esquerda da raiz
			// n�o mexemos em pred aqui
			successor(root->right, succ, key);
		else						// Chave se encontra a direita
			// No caso de predecessor, pred � atualizado quando descemos a direita
			successor(root->left, succ = root, key);
	}

}

// Valida a �rvore
// min e max s�o o menor e o maior valores contidas na �rvore, respectivamente
int BinaryTree::validate(Node * root, int &min, int &max) {

	if (root == NULL) { // �rvore vazia � v�lida
		min = INT_MAX;
		max = INT_MIN;
		return 1;
	}

	int lmin, lmax; // menor e maior a esquerda
	int rmin, rmax; // menor e maior a direita

	// Se �rvore � esquerda � inv�lida ou maior a esquerda > raiz ent�o INV�LIDA
	if (!validate(root->left, lmin, lmax) || (lmax > root->key)) return 0;

	// Se �rvore � direita � inv�lida ou menor � direita < raiz ent�o INV�LIDA
	if (!validate(root->right, rmin, rmax) || (rmin < root->key)) return 0;

	// Computando menor e maior para �rvore em root
	min = (root->left != NULL)?lmin:root->key;
	max = (root->right != NULL)?rmax:root->key;

	return 1;
}


void BinaryTree::show(Node * root) {
	if (root == NULL) return;

	show(root->left);
	cout << "(" << root->key << ", " << root->height << ") ";
	show(root->right);
}


