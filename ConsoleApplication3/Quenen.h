#pragma once

#include <iostream>

using namespace std;

class QuenenCalcer{
private:
	int num = 8;
	int* arr;
	
public:
	int count = 0;
	QuenenCalcer(int num = 8) :num(num), arr(new int[num]{0}) {}
	void display() {
		for (int y = 0; y < num; ++y) {
			for (int x = 0; x < num; ++x) {
				if (arr[x] == y) {
					cout << "#";
				}
				else {
					cout << "*";
				}
			}
			cout << endl;
		}
		count++;
	}
	void queens(int pos = 0) {
		for (int i = 0; i < pos - 1; ++i) {
			int off = arr[i] - arr[pos - 1];
			if (off == 0 || off == pos - 1 - i || -off == pos - 1 - i)
				return;
		}

		if (pos == num) {
			display();
			cout << endl << endl;
			return;
		}
		for (int k = 0; k < num; ++k) {
			arr[pos] = k;
			queens(pos + 1);
		}
	}
};