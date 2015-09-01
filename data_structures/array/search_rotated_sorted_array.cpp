/*
 * Author:		Ashish Verma
 * Title:		search element in sorted, rotated array
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

int findPivot(int ar[], int n) {
	int low = 0;
	int high = n - 1;
	int mid;
	while (low < high) {
		mid = (high + low) / 2;
		if (ar[mid] > ar[mid + 1]) {
			return mid;
		}
		if (ar[mid] < ar[high]) {
			high = mid - 1;
		} else if (ar[mid] > ar[high]) {
			low = mid + 1;
		}
	}
	return -1;
}

int binarySearch(int ar[], int low, int high, int val) {
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (ar[mid] == val) {
			return mid;
		} else if (ar[mid] < val) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return -1;
}

int find(int ar[], int n, int val) {
	int pivot = findPivot(ar, n);
	if (val >= ar[0]) {
		return binarySearch(ar, 0, pivot, val);
	} else {
		return binarySearch(ar, pivot + 1, n - 1, val);
	}
}

int main() {
	int ar[] = { 3, 4, 5, 1, 2 };
	int n = sizeof(ar) / sizeof(ar[0]);

	cout << find(ar, n, 1);

	return 0;
}
