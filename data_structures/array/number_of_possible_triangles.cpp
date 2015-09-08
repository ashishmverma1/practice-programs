/*
 * Author:		Ashish Verma
 * Title:		find number of possible triangles using sides from given array
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

int numOfTriangles(int ar[], int n) {
	sort(ar, ar + n);
	int totalTriangles = 0;

	for (int i = 0; i < n - 2; i++) {
		int k = i + 2;
		for (int j = i + 1; j < n - 1; j++) {
			while (k < n && ar[i] + ar[j] > ar[k]) {
				k++;
			}
			totalTriangles += (k - 1) - j;
		}
	}
	return totalTriangles;
}

int main() {
	int ar[] = { 2, 6, 7 };
	int n = sizeof(ar) / sizeof(ar[0]);

	cout << numOfTriangles(ar, n);

	return 0;
}
