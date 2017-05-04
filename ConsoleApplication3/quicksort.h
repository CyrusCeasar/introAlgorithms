#pragma once
#define swap_int(a,b) a=a+b,b=a-b,a=a-b;
class quicksort {

private:
	static int sort(int* datas, int beg, int end) {
		int firt_data = datas[beg];
		int left, offset = beg;
		for (left=beg+1; left < end; ++left) {
			if (datas[left] < firt_data) {
				swap_int(datas[left], datas[offset]);
				++offset;
			}
		}
		swap_int(firt_data, datas[offset]);
		return offset;
	}

public:
	static void quick_sort(int* datas ,int beg,int end) {
		if (beg < end) {
			int center = sort(datas, beg, end);
			
			quick_sort(datas, beg, center-1);
			quick_sort(datas, center + 1, end);
		}
	}
};