#pragma once

#define swap(a,b) {a=a+b;b=a-b;a=a-b;}
class heapsort {

private:
	static void heapAdjust(int *a, int i, int size) {
		int lchild = i << 1;
		int rchild = lchild + 1;
		int max = i;
		if (i <= size >> 1) {
			if (lchild <= size && a[lchild] > a[max]) {
				max = lchild;
			}
			if (rchild <= size && a[rchild] > a[max]) {
				max = rchild;
			}
			if (max != i) {
				swap(a[i],a[max]);
				heapAdjust(a, max, size);
			}
		}
	}
	static void buildHeap(int *a, int size) {
		int i = size >> 1;
		for (; i >= 1; i--) {
			heapAdjust(a, i, size);
		}
	}
public:
	static bool sort(int* datas,int size) {
		int i;
		buildHeap(datas, size);
		for (i = size; i >= 1; i--) {
			swap(datas[1], datas[i]);
			heapAdjust(datas, 1, i - 1);
		}
	}
};