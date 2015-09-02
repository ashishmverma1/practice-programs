/*
 * Author:		Ashish Verma
 * Title:		find subarray of minimum length sorting which sorts the whole array
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

void findUnsortedSubarray(int ar[], int n) {
	int start = -1, end = -1;
	for (int i = 0; i < n - 1; i++) {
		if (ar[i] > ar[i + 1]) {
			start = i;
			break;
		}
	}
	for (int i = n - 1; i > 0; i--) {
		if (ar[i] < ar[i - 1]) {
			end = i;
		}
	}

	if (start == -1 || end == -1) {
		cout << "Already sorted!" << endl;
	}

	int minNum = INT_MAX;
	int maxNum = INT_MAX;
	for (int i = start; i <= end; i++) {
		minNum = min(minNum, ar[i]);
		maxNum = max(maxNum, ar[i]);
	}
	for (int i = 0; i < start; i++) {
		if (ar[i] > minNum) {
			start = i;
			break;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (ar[i] < maxNum) {
			end = i;
			break;
		}
	}
	cout << "Start: " << start << endl;
	cout << "End: " << end << endl;
}

int main() {
	int ar[] = { 10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60 };
	int n = sizeof(ar) / sizeof(ar[0]);

	findUnsortedSubarray(ar, n);

	return 0;
}
