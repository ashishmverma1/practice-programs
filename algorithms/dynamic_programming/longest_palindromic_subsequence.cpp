/*
 * Author:		Ashish Verma
 * Title:		find length of the longest palindromic subsequence
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

int lps(string s) {
	int n = s.length();
	int dp[n][n];
	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}

	for (int length = 2; length <= n; length++) {
		for (int i = 0; i <= n - length + 1; i++) {
			int j = i + length - 1;
			if (s[i] == s[j]) {
				if (length == 2) {
					dp[i][j] = 2;
				} else {
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}
			} else {
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[0][n - 1];
}

int main() {

	string s = "BBABCBCAB";

	cout << lps(s);

	return 0;
}
