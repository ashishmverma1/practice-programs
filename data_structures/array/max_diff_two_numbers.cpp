/*
 * Author:		Ashish Verma
 * Title:		find  max difference between any 2 numbers in array, such that bigger one is on right
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
#include <tr1/unordered_map>
#include <set>
#define debug(x) cout << "DEBUG: " << x << endl

using namespace std;

int findMaxDiff(int ar[], int n) {
	int maxDiff = 0;
	int maxNum = ar[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (ar[i] < maxNum) {
			maxDiff = max(maxDiff, maxNum - ar[i]);
		} else {
			maxNum = ar[i];
		}
	}
	return maxDiff;
}

int main() {
	int ar[] = { 5, 5, 10, 40, 50, 35 };
	int n = sizeof(ar) / sizeof(ar[0]);
	cout << findMaxDiff(ar, n);
	return 0;
}
