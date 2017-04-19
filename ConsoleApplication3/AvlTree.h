#pragma once
#include <iostream>
#include <algorithm>
#include "AvlNode.h"

using namespace std;
template <class Type>
class AVLTree {
public:
	AVLTree():m_proot(NULL),m_nheight(0),m_nsize(0){}
	~AVLTree() {
		destory(m_proot);
	}
	bool insert(Type &item) {
		if (!this->m_proot) {
			this->m_proot = new AVLNode<Type>(item);
			return true;
		}
		return insert(this->m_proot, item) == NULL;
	}
	void print() const {
		print(this->m_proot);
	}
	
	bool remove(Type &item) {
		return remove(this->m_proot, item);
	}
	
	bool remove(AVLNode<Type>*, Type &);
	bool find(Type &item) const {
		return find(this->m_proot, item);
	}

	
	void destory(AVLNode<Type> node) {
		if (node) {
			if (node->m_pleft) {
				destory(node->m_pleft);
			}
			if (node->m_pright) {
				destory(node->m_pright);
			}
			delete node;
		}
	}

	AVLNode<Type>* getMin(AVLNode<Type>* node)const {
		if (node) {
			while (node->m_pleft) {
				node = node->m_pleft;
			}
			return node;
		}
		else {
			return NULL;
		}
	}

	AVLNode<Type>*  getSuccesser(AVLNode<Type>* node)const {
		if (node) {
			if (node->m_pright) {
				return getMin(node->m_pright);
			}
			else {
				AVLNode<Type>* successor = node->m_pleft;
				while (node->m_pright) {
					node = node->m_pright;
				}
				return successor;
			}
		}
		else {
			return NULL;
		}
	};

	
	
	
private:
	AVLNode<Type> *m_proot;
	int m_nheight;
	int m_nsize;
	void print(const AVLNode<Type>* node)const;
	bool find(const AVLNode<Type> *node, Type& item)const {
		if (!node) {
			return false;
		}
		if (node->m_data == item) {
			return true;
		}
		else if (node->m_data < item) {
			return find(node->m_pleft, item);
		}
		else if (node->m_data > item) {
			return find(node->m_pright, item);
		}
	}
	bool insert(AVLNode<Type> *node, Type& item);

	int getHeight(AVLNode<Type> *node)const {
		return node ? node->m_nheight : 0;
	}
	void setHeight(AVLNode<Type> *node, int height) {
		node->m_nheight = height;
	}
	void SingleRotateRight(AVLNode<Type> *);//右右情况下旋转
	void SingleRotateLeft(AVLNode<Type> *);//左左情况下旋转
	void DoubleRotateLR(AVLNode<Type> *);//左右情况下旋转
	void DoubleRotateRL(AVLNode<Type> *);//右左情况下旋转
	
	
};

//右左情况下旋转
template <class Type>
void AVLTree<Type>::DoubleRotateRL(AVLNode<Type> *k3) {
	SingleRotateLeft(k3->m_pright);
	SingleRotateRight(k3);
}

//左右情况下旋转
template<class Type>
void AVLTree<Type>::DoubleRotateLR(AVLNode<Type> *k3) {
	SingleRotateRight(k3->m_pleft);
	SingleRotateLeft(k3);
}

template <class Type>
void AVLTree<Type>::SingleRotateLeft(AVLNode<Type> *k2) {
	AVLNode<Type>* k1;
	k1 = k2->m_pleft;
	k2->m_pleft = k1->m_pright;
	k1->m_pright = k2;

	k2->m_nheight = max(getHeight(k2->m_pleft), getHeight(k2->m_pright)) + 1;
	k1->m_nheight = max(getHeight(k1->m_pleft), getHeight(k2)) + 1;
	//return k1;
}

template  <class Type>
void AVLTree<Type>::SingleRotateRight(AVLNode<Type> *k2) {
	AVLNode<Type>* k1;
	k1 = k2->m_pright;
	k2->m_pright = k1->m_pleft;
	k1->m_pleft = k2;
	setHeight(k2, max(getHeight(k2->m_pleft),getHeight(k2->m_pright)) + 1);
	setHeight(k1, max(getHeight(k1->m_pright), getHeight(k2)) + 1);
//	return k1;
}


template <class Type>
bool AVLTree<Type>::insert(AVLNode<Type> *node,Type &item) {
	
	
	if (node->m_data == item) {
		++node->m_nfrens;
		return false;
	}
	else if (node-> m_data < item) { //插入到右子树
		if (node->m_pright) {
			bool result = insert(node->m_pright, item);
			if (2 == getHeight(node->m_pleft) - getHeight(node->m_pright))
				if (item > node->m_pleft->m_data)//插入到右子树
					SingleRotateRight(node);
				else//插入到左子树
					DoubleRotateRL(node);
			return result;
		}
		else {
			node->m_pright = new AVLNode<Type>(item);
			return true;
		}
		
	}
	else if (node->m_data > item) {//插入到左子树
		if (node->m_pleft) {
			bool result = insert(node->m_pleft, item);
			if (2 == getHeight(node->m_pright) - getHeight(node->m_pleft))
				if (item < node->m_pright->m_data)//插入到左子树
					SingleRotateLeft(node);
				else//插入到右子树
					DoubleRotateLR(node);
			return result;
		}
		else {
			node->m_pleft = new AVLNode<Type>(item);
			return true;
		}
	}
}

template <class Type>
bool AVLTree<Type>::remove(AVLNode<Type> *node, Type& item) {
	if (!node) {
		return false;
	}

	
	if (node->m_data < item) {

		if (remove(node->m_pright, item)) {
			if (2 == getHeight(node->m_pleft) - getHeight(node->m_pright)) {
				if (node->m_pright->m_pleft && (getHeight(node->m_pright->m_pleft) > getHeight(node->m_pright->m_pright))) {
					DoubleRotateRL(node);
				}
				else {
					SingleRotateRight(node);
				}
			}
		}
		return true;
		
	}else if(node->m_data > item){

		if (remove(node->m_pleft, item)) {
			if (2 == getHeight(node->m_pright) - getHeight(node->m_pleft)) {
				if (node->m_pleft->m_pright && (getHeight(node->m_pleft->m_pright) > getHeight(node->m_pleft->m_pleft))) {
					DoubleRotateLR(node);
				}
				else {
					SingleRotateLeft(node);
				}
			}
			return true;
		}
	
		
	}else if (node->m_data == item) {

		if (!node->m_pright && !node->m_pleft) {
			delete node;
			node = NULL;
			return true;
		}

		if (node->m_pright && !node->m_pleft) {
			AVLNode<Type>* temp = node;
			node = node->m_pright;
			delete temp;
			temp = NULL;
			return true;

		}

		if (node->m_pleft && !node->m_pright) {
			AVLNode<Type>* temp = node;
			node = node->m_pleft;
			delete temp;
			temp = NULL;
			return true;
		}

		if (node->m_pleft && node->m_pright) {
			AVLNode<Type>* temp = node->m_pright;
			while (temp->m_pleft) {
				temp = m_pleft;
			}
			node->m_data = temp->m_data;
			node->m_nfrens = temp->m_nfrens;
			remove(node->m_pright, temp->m_data);
			if (2 == getHeight(node->m_pleft) - getHeight(node->m_pright)) {
				if (node->m_pright->m_pleft && (getHeight(node->m_pright->m_pleft) > getHeight(node->m_pright->m_pright))) {
					DoubleRotateRL(node);
				}
				else {
					SingleRotateRight(node);
				}
			}
		}
	
	}
}

	


template <class Type>
void AVLTree<Type>::print(const AVLNode<Type>* node)const {
	if (node) {
	
		if (node->m_pleft) {
			print(node->m_pleft);
		}
		cout << node->getData() << endl;
		if (node->m_pright) {
			print(node->m_pright);
		}
	}
}