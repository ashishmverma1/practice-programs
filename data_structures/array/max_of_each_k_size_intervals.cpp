/*
 * Author:		Ashish Verma
 * Title:		find max of all k sized intervals
 *
 */

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define debug(x) cout << "DEBUG: " << x << endl

using namespace std;

void printMaxOfEachKIntervals(int ar[], int n, int k) {
	deque<int> maxIndex;
	for (int i = 0; i < k; i++) {
		while (!maxIndex.empty() && ar[maxIndex.back()] < ar[i]) {
			maxIndex.pop_back();
		}
		maxIndex.push_back(i);
	}
	for (int i = k; i < n; i++) {
		cout << ar[maxIndex.front()] << ' ';
		while (!maxIndex.empty() && maxIndex.front() <= i - k) {
			maxIndex.pop_front();
		}
		while (!maxIndex.empty() && ar[maxIndex.back()] < ar[i]) {
			maxIndex.pop_back();
		}
		maxIndex.push_back(i);
	}
	cout << ar[maxIndex.front()] << endl;
}

int main() {
	int ar[] = { 3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3 };
	int n = sizeof(ar) / sizeof(ar[0]);
	printMaxOfEachKIntervals(ar, n, 2);
	return 0;
}
