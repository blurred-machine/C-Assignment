#ifndef BST_H
#define BST_H


#include <iostream>

using namespace std;

template <class T>
class BST
{
	struct node{
		T value;
		struct node* right;
		struct node* left;
	};

public:
	BST();
	~BST();
	void Insert(T data);
    bool Search(T data);
    void InOrder();
	void PreOrder();
	void PostOrder();
	int size();


private:
	struct node* root;
	int treeSize;
	void Insert(struct node** node, T data);
	bool Search(struct node* node, T data);
	void InOrder(struct node* node);
	void PreOrder(struct node* node);
	void PostOrder(struct node* node);
	void deleteTree(struct node* node);
};

template <class T>
BST<T>::BST(){
	this->root = NULL;
	this->treeSize = 0;
}

template <class T>
BST<T>::~BST(){
	deleteTree(this->root);
}

template <class T>
int BST<T>::size(){
	return this->treeSize;
}

template <class T>
void BST<T>::Insert(T data){
	Insert(&(this->root), data);
}

template <class T>
void BST<T>::Insert(struct node** node, T data){

	if(*node == NULL)	{
		struct node* tmp = new struct node;
		tmp->value = data;
		tmp->left=NULL;
		tmp->right = NULL;
		*node = tmp;

		this->treeSize++;
	}else{
		if(data > (*node)->value){
			Insert(&(*node)->right, data);
		}else{
			Insert(&(*node)->left, data);
		}
	}
}

template <class T>
void BST<T>::InOrder(){
	InOrder(this->root);
	cout << endl;
}

template <class T>
void BST<T>::InOrder(struct node* node){
	if(node != NULL){
		InOrder(node->left);
		cout << node->value<<endl;
		InOrder(node->right);
	}
}

template <class T>
void BST<T>::PreOrder(){
	PreOrder(this->root);
	cout << endl;
}

template <class T>
void BST<T>::PreOrder(struct node* node){
	if(node != NULL)	{
		cout << node->value;
		InOrder(node->left);
		InOrder(node->right);
	}
}

template <class T>
void BST<T>::PostOrder(){
	PostOrder(this->root);
	cout << endl;
}

template <class T>
void BST<T>::PostOrder(struct node* node){
	if(node != NULL){
		InOrder(node->left);
		InOrder(node->right);
		cout << node->value;
	}
}


template <class T>
void BST<T>::deleteTree(struct node* node){
	if(node != NULL){
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
}

template <class T>
bool BST<T>::Search(T data){
	return Search(this->root, data);
}

template <class T>
bool BST<T>::Search(struct node* node, T data){
	if(node == NULL){
		return false;
	}else{
		if(data == node->value){
			return true;
		}

		if(data > node->value){
			return Search(node->right, data);
		}else{
			return Search(node->left, data);
		}
	}

}

#endif // BST_H

