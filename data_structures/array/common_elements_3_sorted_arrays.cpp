/*
 * Author:		Ashish Verma
 * Title:		Find common elements in 3 sorted arrays
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

void findCommonElements(int a[], int na, int b[], int nb, int c[], int nc) {
	int i, j, k;
	i = j = k = 0;

	while (i < na && j < nb && k < nc) {
		if (a[i] == b[j] && b[j] == c[k]) {
			cout << a[i] << endl;
			i++;
			j++;
			k++;
		} else if (b[j] > a[i] && b[j] > c[k]) {
			i++;
			k++;
		} else if (a[i] > b[j] && a[i] > c[k]) {
			j++;
			k++;
		} else if (c[k] > a[i] && c[k] > b[j]) {
			i++;
			j++;
		} else if (a[i] < b[j] && a[i] < c[k]) {
			i++;
		} else if (b[j] < a[i] && b[j] < c[k]) {
			j++;
		} else if (c[k] < a[i] && c[k] < b[j]) {
			k++;
		}
	}
}

int main() {

	int ar1[] = { 1, 5, 10, 20, 40, 80 };
	int na = sizeof(ar1) / sizeof(ar1[0]);
	int ar2[] = { 6, 7, 20, 80, 100 };
	int nb = sizeof(ar2) / sizeof(ar2[0]);
	int ar3[] = { 3, 4, 15, 20, 30, 70, 80, 120 };
	int nc = sizeof(ar3) / sizeof(ar3[0]);

	findCommonElements(ar1, na, ar2, nb, ar3, nc);

	return 0;
}
