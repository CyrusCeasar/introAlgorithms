#pragma once


class mergesort {
public:
	static bool MergeSort(int* a, int size) {
		if (!a || size <= 0) {
			return false;
		}

		int* temp = new int[size];
		MergeSort(a, 0, size - 1,temp);
		return true;
	}
private:
	static void MergeArray(int* a, int first, int mid, int last, int* temp) {
		int i = first, j = mid + 1;
		int m = mid, n = last;
		int k = 0;
		while (i <= m && j <= n) {
			if (a[i] <= a[j])
				temp[k++] = a[i++];
			else
				temp[k++] = a[j++];
		}
		while (i <= m)
			temp[k++] = a[i++];
		while (j <= n)
			temp[k++] = a[j++];
		for (int x = 0; x < k; x++)
			a[first + x] = temp[x];
	}
	static void MergeSort(int* a, int first, int last, int* temp) {
		if (first >= last) {
			return;
		}
		int mid = (first + last) >> 1;
		MergeSort(a, first, mid, temp);
		MergeSort(a, mid + 1, last, temp);
		MergeArray(a, first, mid, last, temp);
	}
};