// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "stdafx.h"
#include "BinaryTree.h"
#include "MinHeap.h"
#include "AvlTree.h"
#include "Quenen.h"
#include "mergesort.h"
#include "shellsort.h"
#include "quicksort.h"

#define swap(a,b)  {a= a+b; b = a-b;a = a-b;}

using namespace std;
void testBinaryTree() {
	BinaryTree<int>   tree(-1);
	//  t int  init[10]={3,6,0,2,8,4,9,1,5,7};
	int  init[30] = { 17,6,22,29,14,0,21,13,27,18,2,28,8,26,3,12,20,4,9,23,15,1,11,5,19,24,16,7,10,25 };
	for (int i = 0; i < 30; i++) {
		tree.Insert(init[i]);
	}

	//cin>>tree;
	cout << tree << endl;
	//cout << tree.GetParent(tree.Find(20))->GetData() << endl;
	//cout << tree.Find(15)->GetRight()->GetData() << endl;

	cout << "size=" << tree.Size() << endl;
	cout << "height=" << tree.Height() << endl;
	cout << "inorder" << endl;
	//tree.InOrder();
	for (int i = 0; i < 5; i++) {
		cout << "删除数据：" << tree.remove(init[i]) << endl;
	}
	cout << "inorder" << endl;
	tree.InOrder();
	cout << "size=" << tree.Size() << endl;
	cout << "height=" << tree.Height() << endl;
	cout << "inorder" << endl;
	//cout << endl << endl;
	//tree.PreOrder();
	//cout << endl << endl;

	//tree.PostOrder();

	//cout << endl << endl;
	//BinaryTree<int>   tree2 = tree;
	//cout << tree2 << endl;

	/*cout << tree2.GetParent(tree2.Find(20))->GetData() << endl;
	cout << tree2.Find(15)->GetRight()->GetData() << endl;*/
	/*cout << (tree == tree2) << endl;*/
}
void testAvlTree() {
	AVLTree<int>* tree = new AVLTree<int>();
	//  t int  init[10]={3,6,0,2,8,4,9,1,5,7};
	int  init[30] = { 17,6,22,29,14,0,21,13,27,18,2,28,8,26,3,12,20,4,9,23,15,1,11,5,19,24,16,7,10,25 };
	for (int i = 0; i < 30; i++) {
		tree->insert(init[i]);
	}
	tree->print();
	//cin>>tree;
//	cout << tree << endl;
	//cout << tree.GetParent(tree.Find(20))->GetData() << endl;
	//cout << tree.Find(15)->GetRight()->GetData() << endl;

	//cout << "size=" << tree.Size() << endl;
	//cout << "height=" << tree.Height() << endl;
	//cout << "inorder" << endl;
	/*tree.InOrder();
	for (int i = 0; i < 30; i++) {
		cout << "删除数据：" << tree.remove(init[i]) << endl;
	}
	cout << "inorder" << endl;*/
}

void testMinHeap() {
	int init[30] = { 17,6,22,29,14,0,21,13,27,18,2,28,8,26,3,12,20,4,9,23,15,1,11,5,19,24,16,7,10,25 };
	MinHeap<int> heap(init, 30);
	heap.Print();
	cout << endl << endl << endl;

	heap.Insert(20);
	heap.Print();
	cout << endl << endl << endl;
	cout<< heap.Delete(20)<<endl;
	heap.Print();
	cout << endl << endl << endl;
}


int bornTuzi(int n = 12) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		return bornTuzi(n - 1) + bornTuzi(n - 2);
	}
}

void testQuenen() {
	QuenenCalcer* qu = new QuenenCalcer();
	qu->queens();
	cout << "count:" << qu->count;
}
bool paixu_maopao(int* datas, int i) {
	bool change = false;
	for (int j = 0; j < i; ++j) {
		if (datas[j] > datas[j + 1]) {
			swap(datas[j], datas[j + 1]);
			change = true;
		}
	}
	return change;
}

void recursive_maopao(int* datas, int size) {
	if (size == 1) {
		return;
	}
	if (datas && size > 0) {
		paixu_maopao(datas, size - 1);
		recursive_maopao(datas, size - 1);
	}
}


void maopao(int* datas,int size) {
	if (datas && size > 0) {
		int temp;
		bool change;
		for (int i = size - 1; i > 0; --i) {
			if (!paixu_maopao(datas, i)) {
				break;
			}
		}
	}
}



void paixu_xuanze(int* datas, int i) {
	int min = i;
	for (int j = 0; j < i; ++j) {
		if (datas[j] < datas[min]) {
			min = j;
		}
	}
	if (min != i) {
		swap(datas[min], datas[i]);
	}
}

void recursive_xuanze(int* datas, int i) {
	if (i == 1) {
		return;
	}
	paixu_xuanze(datas, i-1);
	recursive_xuanze(datas, i - 1);
}

void xuanze(int* datas, int size) {
	if (datas && size > 0) {
		int min;
		for (int i = size - 1; i > 0; --i) {
			paixu_xuanze(datas, i);
		}
	}
}

void paixu_charu(int* datas,int i) {
	int j = i - 1;
	int temp = datas[i];
	while (j >= 0 && temp < datas[j]) {
		datas[j + 1] = datas[j];
		--j;
	}
	datas[j + 1] = temp;
}
void merge(int* datas, int p, int m, int q) {
	int	a = m - p + 1;
	int b = q - m;
	
}

void recursive_charu(int* datas, int size) {
	if (size == 1) {
		return;
	}
	recursive_charu(datas, size - 1);
	paixu_charu(datas, size - 1);
}

void charu(int* datas, int size) {
	if (datas && size > 0) {
		int j,temp;
		for (int i = 1; i < size ; ++i) {
			paixu_charu(datas, i);
		}
	}
}




int main()
{
//	testAvlTree();
//	testMinHeap();
	//testBinaryTree();
	int datas[8] = {3,1,2,3,4,7,2,3};
	quicksort::quick_sort(datas, 0, 8);
//	mergesort::MergeSort(datas, 8);
//	shellsort::shell_sort(datas, 8);
//	recursive_xuanze(datas, 8);

//	charu(datas,8);
	for (int i = 0; i < 8; i++) {
		cout << datas[i];
	}

	system("pause");
	return 0;
}

