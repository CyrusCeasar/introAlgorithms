#pragma once


#include <iostream>

#include "BinTreeNode.h"

using namespace std;





template <typename Type>
class BinaryTree {


public:
	BinaryTree() :m_proot(NULL) {}
	BinaryTree(const Type stop) :m_stop(stop), m_proot(NULL) {}
	BinaryTree(BinaryTree<Type>& copy);
	virtual ~BinaryTree() {
		m_proot->Destory();
	}
	virtual bool IsEmpty() {
		return m_proot == NULL;
	}

	virtual BinTreeNode<Type> *GetLeft(BinTreeNode<Type> *current);
	virtual BinTreeNode<Type> *GetRight(BinTreeNode<Type> *current);
	virtual BinTreeNode<Type> *GetParent(BinTreeNode<Type> *current);
	 BinTreeNode<Type>* GetRoot() const { return this->m_proot; }
	virtual bool Insert(const Type item);
	virtual BinTreeNode<Type>* Find(const Type item) const;

	void InOrder() { this->m_proot->InOrder(); }
	void PreOrder() { this->m_proot->PostOrder(); }
	void PostOrder() { this->m_proot->PostOrder(); }
	int Size() { return this->m_proot->Size(); }
	int Height() { return  this->m_proot->Height(); }

	virtual BinTreeNode<Type> *GetMin( BinTreeNode<Type> *)const;
	virtual BinTreeNode<Type> *GetMax( BinTreeNode<Type> *)const;
	virtual BinTreeNode<Type> *GetPrecessor( BinTreeNode<Type> *)const;
	virtual BinTreeNode<Type> *GetSuccesser( BinTreeNode<Type> *)const;

	bool remove(const Type item) {
		BinTreeNode<Type>* removeNode = Find(item);
		return remove(removeNode);
	};

	virtual bool remove(BinTreeNode<Type>* &);

	

	BinaryTree<Type>& operator=(const BinaryTree<Type> copy);
	bool operator==(const BinaryTree<Type> t);
	template<class Type>
	friend ostream& operator<<(ostream&, BinaryTree<Type>&);
	template<class Type>
	friend istream& operator>>(istream&, BinaryTree<Type>&);
private:
	Type m_stop;
	BinTreeNode<Type> *m_proot;
	BinTreeNode<Type>* GetParent(BinTreeNode<Type> *start, BinTreeNode<Type> *current);
	void Print(BinTreeNode<Type> *start, int n = 0);
};

template <typename Type>
istream& operator>>(istream& is, BinaryTree<Type>& in) {
	Type item;
	return is;
}


template <typename Type>
bool BinaryTree<Type>::operator==(const BinaryTree<Type> t) {
	return equal(t.m_proot, this->m_proot);
}
template <typename Type>
ostream& operator<<(ostream& os, BinaryTree<Type>& out) {
	out.Print(out.m_proot,0);
	return os;
}


template <typename Type>
bool BinaryTree<Type>::remove(BinTreeNode<Type>* &node) {
	if (!node) {
		return false;
	}



	//左右子树都为空的情况下
	if (node->m_pleft == NULL && node->m_pright == NULL) {
		if (node->m_pparent) {
			if (node->m_pparent->m_pleft == node) {
				node->m_pparent->m_pleft = NULL;
			}
			else {
				node->m_pparent->m_pright = NULL;
			}
		}
		else {
			m_proot = NULL;
		}
		delete node;
		node = NULL;
		return true;
	}

	//左子树为空，右子树不为空
	if (node->m_pleft == NULL && node->m_pright) {
		if (node->m_pparent) {
			if (node->m_pparent->m_pleft == node) {
				node->m_pparent->m_pleft = node->m_pright;
			}
			else {
				node->m_pparent->m_pright = node->m_pright;
			}
			
		}
		else {
			m_proot = node->m_pright;
		}
		delete node;
		node = NULL;
		return true;
	}
	//左子树不为空，右子树为空
	if (node->m_pright == NULL && node->m_pleft) {
		if (node->m_pparent) {
			if (node->m_pparent->m_pleft == node) {
				node->m_pparent->m_pleft = node->m_pleft;
			}
			else {
				node->m_pparent->m_pright = node->m_pleft;
			}

		}
		else {
			m_proot = node->m_pleft;
		}
		delete node;
		node = NULL;
		return true;
	}
	//左右子树都为空
	if(node->m_pleft && node->m_pright){
		BinTreeNode<Type>* successer = GetSuccesser(node);
		node->m_data = successer->m_data;
		return remove(successer);
	}
	return false;

	
}

template <typename Type>
BinTreeNode<Type> *BinaryTree<Type>::GetMax( BinTreeNode<Type> *t) const{
	if(!t)
		return NULL;
	
	if (t->m_pright) {
		return GetMax(t->m_pright);
	}
	else {
		return t;
	}
}
template <typename Type>
BinTreeNode<Type> *BinaryTree<Type>::GetMin( BinTreeNode<Type> *t)const {
	if (!t) 
		return NULL;
	
	if (t->m_pleft) {
		return GetMin(t->m_pleft);
	}
	else {
	
		return t;
	}
}

template <typename Type>
BinTreeNode<Type> *BinaryTree<Type>::GetPrecessor( BinTreeNode<Type> *t) const{
	if (!t) 
		return NULL;
	if (t->m_pleft) {
		return GetMax(t->m_pleft);
	}
	else {
		BinTreeNode<Type> *parent_node,*node;
		node = t;
		parent_node = node->m_pparent;
		while(parent_node && parent_node->m_pleft == node) {
			node = parent_node;
			parent_node = parent_node->m_pparent;
		}
		return parent_node;
	}
	
}
template <typename Type>
BinTreeNode<Type> *BinaryTree<Type>::GetSuccesser( BinTreeNode<Type> *t)const {
	if (!t)
		return NULL;
	if (t->m_pright) {
		return GetMin(t->m_pright);
	}
	else {
		BinTreeNode<Type> *parent_node,*node;
		node = t;
		parent_node = node->m_pparent;
		while (parent_node && parent_node->m_pright == node) {
			node = parent_node;
			parent_node = parent_node->m_pparent;
		}
		return parent_node;
	}
	
}


template <typename Type>
BinaryTree<Type>& BinaryTree<Type>::operator=(const BinaryTree<Type> copy) {
	m_proot= m_proot->Copy(copy.m_proot);
	return *this;
}
template <typename Type>
BinaryTree<Type>::BinaryTree(BinaryTree<Type>& copy) {
	m_proot = m_proot->Copy(copy.m_proot);
}

template <typename Type>
BinTreeNode<Type>* BinaryTree<Type>::GetLeft(BinTreeNode<Type> *current) {
	return m_proot && current ? current->m_pleft : NULL;
}

template <typename Type>
BinTreeNode<Type>* BinaryTree<Type>::GetRight(BinTreeNode<Type> *current) {
	return m_proot && current ? current->m_pright : NULL;
}

template<typename Type>
BinTreeNode<Type>* BinaryTree<Type>::GetParent(BinTreeNode<Type>* start, BinTreeNode<Type>* current)
{


	if (!start || !current) {
		return NULL;
	}
	if (start->m_pleft == current || start->m_pright == current) {
		return start;
	}

	BinTreeNode<Type> *presult;
	if ((presult = GetParent(start->m_pleft, current)) != NULL) {
		return presult;
	}
	else {
		return GetParent(start->m_pright, current);
	}

}

template <typename Type>
BinTreeNode<Type>* BinaryTree<Type>::GetParent(BinTreeNode<Type> *current) {
	return (m_proot == NULL || current == m_proot) ? NULL : GetParent(m_proot, current);
}

template <typename Type>
bool BinaryTree<Type>::Insert(const Type item) {
	BinTreeNode<Type> *pstart, *pnewnode;
	pstart = m_proot;
	pnewnode = new BinTreeNode<Type>(item);
	if (m_proot == NULL) {
		m_proot = pnewnode;
		m_proot->m_pparent = NULL;
		return 1;
	}
	while (1) {
		if (item == pstart->m_data) {
			cout << "data alerady exists" << endl;
			return 0;
		}
		if (item < pstart->m_data) {
			if (!pstart->m_pleft) {
				pstart->m_pleft = pnewnode;
				pnewnode->m_pparent = pstart;
				return 1;
			}
			pstart = pstart->m_pleft;
		}
		else if (item > pstart->m_data) {
			if (!pstart->m_pright) {
				pstart->m_pright = pnewnode;
				pnewnode->m_pparent = pstart;
				return 1;
			}
			pstart = pstart->m_pright;
		}
	}
}

template <typename Type>
BinTreeNode<Type>* BinaryTree<Type>::Find(const Type item) const {
	BinTreeNode<Type>* pstart = m_proot;
	while (pstart) {
		if (item == pstart->m_data) {
			return pstart;
		}
		else if (item < pstart->m_data) {
			pstart = pstart->m_pleft;
		}
		else if (item > pstart->m_data) {
			pstart = pstart->m_pright;
		}
	}
	return NULL;
}

template <typename Type>
void BinaryTree<Type>::Print(BinTreeNode<Type> *start, int n = 0) {

	if (start == NULL) {
		for (int i = 0; i < n; i++) {
			cout << " ";
		}
		cout << "NULL" << endl;
		return;
	}
	Print(start->m_pright, n + 1);   //print   the   right  subtree

	for (int i = 0; i < n; i++) {
		//print   blanks   with   the   height   of   the  node
		cout << " ";
	}
	if (n >= 0) {
		cout << start->m_data << "--->" << endl; //print   the  node
	}

	Print(start->m_pleft, n + 1); //print   the   left 
}

