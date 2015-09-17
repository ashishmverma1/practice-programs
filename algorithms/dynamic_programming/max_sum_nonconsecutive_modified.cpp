/*
 * Author:		Ashish Verma
 * Title:		max sum of non consecutive, such that 1st and last element cant come together
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

int maxSum(int ar[], int n, int i = 0, bool firstIncluded = true) {
	if (i >= n) {
		return 0;
	}

	int including, excluding;
	if (i == 0) {
		including = ar[i] + maxSum(ar, n, i + 2, true);
		excluding = maxSum(ar, n, i + 1, false);
	} else if (i == n - 1) {
		if (firstIncluded) {
			return 0;
		} else {
			return max(0, ar[i]);
		}
	} else {
		including = ar[i] + maxSum(ar, n, i + 2, firstIncluded);
		excluding = maxSum(ar, n, i + 1, firstIncluded);
	}

	return max(including, excluding);
}

int main() {
	int ar[] = { 5, 4, 10, 40, 50, 35 };
	int n = sizeof(ar) / sizeof(ar[0]);
	cout << maxSum(ar, n);

	return 0;
}
