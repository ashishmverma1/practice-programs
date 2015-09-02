/*
 * Author:		Ashish Verma
 * Title:		max sum of non consecutive
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

int maxSum(int ar[], int n, int i = 0) {
	if (i >= n) {
		return 0;
	}
	int including, excluding;
	including = ar[i] + maxSum(ar, n, i + 2);
	excluding = maxSum(ar, n, i + 1);
	return max(including, excluding);
}

int main() {
	int ar[] = { 5, 5, 10, 40, 50, 35 };
	int n = sizeof(ar) / sizeof(ar[0]);
	cout << maxSum(ar, n);

	return 0;
}
