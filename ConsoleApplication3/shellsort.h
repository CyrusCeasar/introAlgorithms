#pragma once
#define swap(a,b) a=a+b,b=a-b,a=a-b
class shellsort {
public:
	static void shell_sort(int *datas,int len) {
		int d = len;
		while((d = d >> 1) > 0) 
			for (int index = d; index < len;++index) 
				for (int j = index; datas[j-d] > datas[j ] && j >= 0; j -= d) 
					swap(datas[j], datas[j-d]);
	}
};