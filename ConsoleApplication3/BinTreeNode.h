#pragma once
template <typename Type>
class BinaryTree;
template <typename Type>
class BinTreeNode {
public:
	friend class BinaryTree<Type>;
	BinTreeNode(Type item):m_data(item),m_pleft(NULL),m_pright(NULL),m_pparent(NULL){}
	BinTreeNode(Type item, BinTreeNode<Type> *left,BinTreeNode<Type> *right):m_data(item),m_pleft(left),m_pright(right),m_pparent(NULL){}
	BinTreeNode(Type item, BinTreeNode<Type> *left, BinTreeNode<Type> *right,BinTreeNode<Type> *parent) :m_data(item), m_pleft(left), m_pright(right), m_pparent(parent) {}
	Type GetData()const { return m_data; }
	BinTreeNode<Type> *GetLeft()const { return m_pleft; }
	BinTreeNode<Type> *GetRight() const { return m_pright; }
	void SetData(const Type data) { this->m_data = data }
	void SetLeft(const BinTreeNode<Type> *left) { this->m_pleft = left }
	void SetRight(const BinTreeNode<Type> *right) { this->m_pright = right }
	
	void InOrder();
	void PreOrder();
	void PostOrder();
	int Size();
	int Height();
	BinTreeNode<Type>* Copy(const BinTreeNode<Type> *);
	void Destory() {
		if (this) {
			this->m_pleft->Destory();
			this->m_pright->Destory();
			delete this;
		}
	}
	template<class Type>
	friend bool equal(const BinTreeNode<Type> *, const BinTreeNode<Type> *);

	
private:
	BinTreeNode<Type> *m_pleft, *m_pright ,*m_pparent;
	Type m_data;
};

template<typename Type>
bool equal(const BinTreeNode<Type> *s, const BinTreeNode<Type> *t) {
	if (!s && !t) {
		return true;
	}
	if (s && t && s->m_data == t->m_data && equal(s->m_pleft, t->m_pleft) && equal(s->m_pright, t->m_pright)) {
		return 1;
	}
	return 0;
}

template <typename Type>
BinTreeNode<Type>*  BinTreeNode<Type>::Copy(const BinTreeNode<Type> *copy) {
	if (!copy ) {
		return NULL;
	}
	BinTreeNode<Type> *temp = new BinTreeNode<Type>(copy->m_data);
	temp->m_pleft = Copy(copy->m_pleft);
	temp->m_pright = Copy(copy->m_pright);
	return temp;
}



template <typename Type>
void BinTreeNode<Type>::InOrder() {
	if (!this) {
		return;
	}
	if (m_pleft) {
		m_pleft->InOrder();
	}
	cout << m_data << endl;
	if (m_pright) {
		m_pright->InOrder();
	}
}
template <typename Type>
void BinTreeNode<Type>::PreOrder() {
	if (!this) {
		return;
	}
		cout << m_data << endl;
		if (m_pleft) {
			m_pleft->PreOrder();
		}
		if (m_pright) {
			m_pright->PreOrder();
		}
}
template <typename Type>
void BinTreeNode<Type>::PostOrder() {
	if (!this) {
		return;
	}
	if (m_pleft) {
		m_pleft->PostOrder();
	}
	if (m_pright) {
		m_pright->PostOrder();
	}
	cout << m_data << endl;
}

template <typename Type>
int BinTreeNode<Type>::Size() {
	int left = 0,right = 0;
	if (m_pleft) {
		left =  m_pleft->Size();
	}
	if (m_pright) {
		right = m_pright->Size();
	}
	return left + right+1;
}
template <typename Type>
int BinTreeNode<Type>::Height() {
	int leftHeight = 0, rightHeight = 0;
	if (m_pleft) {
		leftHeight = m_pleft->Height();
	}
	if (m_pright) {
		rightHeight = m_pright->Height();
	}
	return (leftHeight > rightHeight ? leftHeight : rightHeight)+1;
}
template <typename Type>
BinTreeNode<Type>* Copy(const BinTreeNode<Type> *copy) {
	this->m_data = copy->m_data;
	this->m_pleft = copy->m_pleft;
	this->m_pright = copy->m_pright;
	return this;
}