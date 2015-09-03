/*
 * Author:		Ashish Verma
 * Title:		find min total jumps to reach last element from first,
 * 				where each array element is max jumps allowed from that position
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
#define INFINITE 99999

using namespace std;

int findMinJump(int ar[], int n, int start = 0) {
	static int *dp = new int[n];
	if (dp[start] != 0) {
		return dp[start];
	}
	if (start + ar[start] >= n - 1) {
		dp[start] = 1;
	} else {
		dp[start] = INFINITE;
		if (ar[start] != 0) {
			for (int i = start + 1; i <= start + ar[start]; i++) {
				dp[start] = min(dp[start], findMinJump(ar, n, i) + 1);
			}
		}
	}

	return dp[start];
}

int main() {
	int ar[] = { 1, 3, 6, 3, 2, 3, 6, 8, 9, 5 };
	int n = sizeof(ar) / sizeof(ar[0]);
	cout << findMinJump(ar, n) << endl;
	return 0;
}
