/*
 * Author:		Ashish Verma
 * Title:		inversion count - swaps needed to sort an array
 * 				nlog(n) - modified merge sort
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
#include <list>

#define debug(x) cout << "DEBUG: " << x << endl

using namespace std;

int merge(int ar[], int low, int mid, int high) {
	int invCount = 0;
	int i = low;
	int j = mid + 1;

	while (i <= mid && j <= high) {
		if (ar[i] <= ar[j]) {
			i++;
		} else {
			invCount += mid - i;
			j++;
		}
	}

	return invCount;
}

int mergeSort(int ar[], int low, int high) {
	int invCount = 0;
	if (low < high) {
		int mid = (low + high) / 2;
		invCount = mergeSort(ar, low, mid);
		invCount += mergeSort(ar, mid + 1, high);
		invCount += merge(ar, low, mid, high);
	}
	return invCount;
}

int main() {

	int ar[] = { 1, 20, 6, 4, 5 };
	int n = sizeof(ar) / sizeof(ar[0]);

	cout << mergeSort(ar, 0, n - 1);

	return 0;
}
