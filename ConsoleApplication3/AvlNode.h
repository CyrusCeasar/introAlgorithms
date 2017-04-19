template <class Type>
class AVLTree;

template <class Type>
class AVLNode {
public:
	friend class AVLTree<Type>;
	Type getData() const { return m_data; }
	AVLNode(Type item = NULL, AVLNode<Type> *left = NULL, AVLNode<Type> *right = NULL):m_data(item), m_pleft(left), m_pright(right) {}

private:
	AVLNode<Type> *m_pleft, *m_pright;
	Type m_data;
	int m_nfrens;
	int m_nheight;
};