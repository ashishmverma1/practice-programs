/*
 * Author:		Ashish Verma
 * Title:		check if a set can be devided into 2 sets with equal sum
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

bool checkIfSubsetPossible(int ar[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += ar[i];
	}

	if (sum % 2 != 0) {
		return false;
	}

	bool dp[sum / 2 + 1][n + 1];
	for (int j = 0; j <= n; j++) {
		dp[0][j] = true;
	}
	for (int i = 1; i <= sum / 2; i++) {
		dp[i][0] = false;
	}

	for (int i = 1; i <= sum / 2; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i][j - 1];
			if (ar[j - 1] <= i) {
				dp[i][j] = dp[i][j] || dp[i - ar[j - 1]][j - 1];
			}
		}
	}
	return dp[sum / 2][n];
}

int main() {
	int ar[] = { 3, 1, 5, 9, 12 };
	int n = sizeof(ar) / sizeof(ar[0]);

	cout << checkIfSubsetPossible(ar, n);

	return 0;
}
