#pragma once
#include <math.h>
class radixsort {
private:
	static int maxBit(int* datas,int size) {
		int maxBit = 0;
		for (int i = 0; i < size; i++) {
			int j = 0;
			while (datas[i] / pow(10,++j) > 0);
			maxBit = maxBit < (--j) ? j:maxBit;
		}
		return maxBit;
	}

public:
	static void sort(int* datas, int size) {
		if (!datas || size <= 0) {
			return;
		}
		int maxbit = maxBit(datas, size);

	}
};