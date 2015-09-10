/*
 * Author:		Ashish Verma
 * Title:		Given two strings of size m, n and set of operations replace (R),
 * 				insert (I) and delete (D) all at equal cost.
 * 				Find minimum number of edits (operations)
 *				required to convert one string into another.
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

int findMinEdits(string a, string b) {
	int dp[a.length() + 1][b.length() + 1];

	for (unsigned int i = 0; i <= a.length(); i++) {
		dp[i][0] = i;
	}
	for (unsigned int i = 0; i <= b.length(); i++) {
		dp[0][i] = i;
	}

	for (unsigned int i = 1; i <= a.length(); i++) {
		for (unsigned int j = 1; j <= b.length(); j++) {
			dp[i][j] = min(dp[i - 1][j - 1] + (int) (a[i - 1] != b[j - 1]),
					min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
		}
	}
	return dp[a.length()][b.length()];
}

int main() {

	string a = "SUNDAY";
	string b = "SATURDAY";

	cout << findMinEdits(a, b);

	return 0;
}
