/*
 * Author:		Ashish Verma
 * Title:		basic heap implementation
 *
 */

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <fstream>

#define debug(x) cout << "DEBUG: " << x << endl

using namespace std;

class heap {
	int *heapArray;
	int capacity;
	int curSize;

	int parent(int i) {
		return (i - 1) / 2;
	}

	int leftChild(int i) {
		return (i * 2) + 1;
	}

	int rightChild(int i) {
		return (i * 2) + 2;
	}

public:
	heap(int _capacity) {
		capacity = _capacity;
		curSize = 0;
		heapArray = new int[capacity];
	}

	void insert(int val) {
		if (curSize == capacity) {
			cout << "Overflow!" << endl;
			return;
		}
		heapArray[curSize++] = val;
		int i = curSize - 1;
		while (i > 0 && heapArray[parent(i)] > heapArray[i]) {
			swap(heapArray[parent(i)], heapArray[i]);
			i = parent(i);
		}
	}

	int getMin() {
		if (curSize == 0) {
			cout << "Empty!" << endl;
			return INT_MAX;
		}
		return heapArray[0];
	}

	void pop() {
		if (curSize == 0) {
			cout << "Empty!" << endl;
			return;
		}
		heapArray[0] = heapArray[--curSize];
		heapify(0);
	}

	void heapify(int i) {
		int smallestIndex = i;
		if (leftChild(i) < curSize && heapArray[leftChild(i)] < heapArray[smallestIndex]) {
			smallestIndex = leftChild(i);
		}
		if (rightChild(i) < curSize && heapArray[rightChild(i)] < heapArray[smallestIndex]) {
			smallestIndex = rightChild(i);
		}
		if (smallestIndex != i) {
			swap(heapArray[i], heapArray[smallestIndex]);
			heapify(smallestIndex);
		}
	}

	bool empty() {
		return (curSize == 0);
	}
};

int main() {
	heap h(10);
	h.insert(10);
	h.insert(5);
	h.insert(1);
	h.insert(12);
	h.insert(4);
	h.insert(23);
	h.insert(0);
	h.insert(3);
	h.insert(7);

	while (!h.empty()) {
		cout << h.getMin() << endl;
		h.pop();
	}

	return 0;
}
