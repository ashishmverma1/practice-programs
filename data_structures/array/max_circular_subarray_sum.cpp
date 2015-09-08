/*
 * Author:		Ashish Verma
 * Title:		max  circular subarray  contiguous sum
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

int maxLinearSum(int ar[], int n) {
	int maxSumLinear, curSum;
	maxSumLinear = curSum = 0;

	for (int i = 0; i < n; i++) {
		curSum += ar[i];
		curSum = max(curSum, 0);
		maxSumLinear = max(maxSumLinear, curSum);
	}
	return maxSumLinear;
}

int maxSum(int ar[], int n) {
	int maxSumLinear, maxSumCircular;

	maxSumLinear = maxLinearSum(ar, n);

	for (int i = 0; i < n; i++) {
		maxSumCircular += ar[i];
		ar[i] *= -1;
	}
	maxSumCircular += maxLinearSum(ar, n);

	return max(maxSumCircular, maxSumLinear);
}

int main() {
	int ar[] = { 11, 10, -20, 5, -3, -5, 8, -13, 10 };
	int n = sizeof(ar) / sizeof(ar[0]);

	cout << maxSum(ar, n);

	return 0;
}
