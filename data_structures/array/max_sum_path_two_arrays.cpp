/*
 * Author:		Ashish Verma
 * Title:		find max sum path from 2 sorted arrays, switch at common elements
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

int maxSum(int ar1[], int m, int ar2[], int n) {
	int p, q, sum1, sum2, sum;
	p = q = sum1 = sum2 = sum = 0;

	while (p < m && q < n) {
		if (ar1[p] == ar2[q]) {
			sum += max(sum1, sum2);
			sum1 = sum2 = ar1[p];
			p++;
			q++;
		} else if (ar1[p] < ar2[q]) {
			sum1 += ar1[p++];
		} else {
			sum2 += ar2[q++];
		}
	}
	while (p < m) {
		sum1 += ar1[p++];
	}
	while (q < n) {
		sum2 += ar2[q++];
	}
	sum += max(sum1, sum2);
	return sum;
}

int main() {
	int ar[] = { 2, 3, 7, 10, 12, 15, 30, 34 };
	int n = sizeof(ar) / sizeof(ar[0]);

	int ar1[] = { 1, 5, 7, 8, 10, 15, 16, 19 };
	int m = sizeof(ar1) / sizeof(ar1[0]);

	cout << maxSum(ar1, m, ar, n);

	return 0;
}
