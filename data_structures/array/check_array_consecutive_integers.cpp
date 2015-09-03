/*
 * Author:		Ashish Verma
 * Title:		check if all elements in array are consecutive integers
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

bool checkConsecutive(int ar[], int n) {
	int start = INT_MAX;
	for (int i = 0; i < n; i++) {
		start = min(start, ar[i]);
	}
	int end = start + n - 1;
	// check if all elements lie in range
	for (int i = 0; i < n; i++) {
		if (ar[i] < start || ar[i] > end) {
			return false;
		}
	}
	// check if any duplicate present
	for (int i = 0; i < n; i++) {
		if (ar[abs(ar[i]) - start] > 0) {
			ar[abs(ar[i]) - start] *= -1;
		} else {
			return false;
		}
	}

	return true;
}

int main() {
	int ar[] = { 83, 78, 80, 81, 79, 82 };
	int n = sizeof(ar) / sizeof(ar[0]);

	cout << checkConsecutive(ar, n);

	return 0;
}
