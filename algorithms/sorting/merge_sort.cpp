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

void merge(int ar[], int low, int mid, int high) {
	int i = low;
	int j = mid + 1;

	int temp[high - low + 1];
	int k = 0;

	while (i <= mid && j <= high) {
		if (ar[i] <= ar[j]) {
			temp[k++] = ar[i++];
		} else {
			temp[k++] = ar[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = ar[i++];
	}
	while (j <= high) {
		temp[k++] = ar[j++];
	}

	for (k = 0; k < high - low + 1; k++) {
		ar[low + k] = temp[k];
	}
}

void mergeSort(int ar[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergeSort(ar, low, mid);
		mergeSort(ar, mid + 1, high);
		merge(ar, low, mid, high);
	}
}

int main() {

	int ar[] = { 1, 20, 6, 4, 5 };
	int n = sizeof(ar) / sizeof(ar[0]);

	mergeSort(ar, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << ar[i] << " ";
	}

	return 0;
}
