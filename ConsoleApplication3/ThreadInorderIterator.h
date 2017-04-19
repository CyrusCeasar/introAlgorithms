#pragma once
#include "ThreadNode.h"
template <typename Type>
class ThreadInorderIterator {

public:
	ThreadNode<Type> *First();
	ThreadNode<Type> *Prior();
	ThreadNode<Type> *Next();
	void Print();
	void Print(ThreadNode<Type> *start,int n = 0);
	void InOrder();
	void InsertLeft(ThreadNode<Type> *left);
	void InsertRight(ThreadNode<Type> *right);
	ThreadNode<Type> *GetParent(ThreadNode<Type> *current);
private:
	ThreadTree<Type> &m_ptree;
	ThreadNode<Type> *m_pcurrent;
	void InThread(ThreadNode<Type> *current, ThreadNode<Type> *pre);
};

template <typename Type>
void ThreadInorderIterator<Type>::InThread(ThreadNode<Type> *current, ThreadNode<Type> *pre) {
}