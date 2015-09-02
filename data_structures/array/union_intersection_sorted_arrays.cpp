/*
 * Author:		Ashish Verma
 * Title:		union and intersection of 2 sorted arrays
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

vector<int> findUnion(int a[], int nA, int b[], int nB) {
	vector<int> result;
	int i = 0;
	int j = 0;
	while (i < nA && j < nB) {
		if (a[i] < b[j]) {
			result.push_back(a[i]);
			i++;
		} else if (a[i] > b[j]) {
			result.push_back(b[j]);
			j++;
		} else {
			result.push_back(a[i]);
			i++;
			j++;
		}
	}
	while (i < nA) {
		result.push_back(a[i]);
		i++;
	}
	while (j < nB) {
		result.push_back(b[j]);
		j++;
	}
	return result;
}

vector<int> findIntersection(int a[], int nA, int b[], int nB) {
	vector<int> result;
	int i = 0;
	int j = 0;
	while (i < nA && j < nB) {
		if (a[i] < b[j]) {
			i++;
		} else if (a[i] > b[j]) {
			j++;
		} else {
			result.push_back(a[i]);
			i++;
			j++;
		}

	}
	return result;
}

int main() {
	int arr1[] = { 1, 2, 4, 5, 6 };
	int arr2[] = { 2, 3, 5, 7 };
	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	vector<int> un = findUnion(arr1, m, arr2, n);
	cout << "Union: ";
	for (unsigned int i = 0; i < un.size(); i++) {
		cout << un[i] << ' ';
	}
	cout << endl;

	vector<int> inter = findIntersection(arr1, m, arr2, n);
	cout << "Intersection: ";
	for (unsigned int i = 0; i < inter.size(); i++) {
		cout << inter[i] << ' ';
	}
	cout << endl;

	return 0;
}
