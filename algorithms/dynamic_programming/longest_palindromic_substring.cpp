/*
 * Author:		Ashish Verma
 * Title:		find longest palindromic substring
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

using namespace std;

void longestP(string s) {
	int n = s.length();

	bool dp[n][n];
	for (int i = 0; i < n; i++) {
		dp[i][i] = true;
	}

	for (int length = 2; length <= n; length++) {
		for (int i = 0; i < n - length + 1; i++) {
			int j = i + length - 1;
			if (length == 2) {
				dp[i][j] = (s[i] == s[j]);
			} else {
				dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
			}
		}
	}

	int start;
	int maxLen = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] && j - i + 1 > maxLen) {
				maxLen = j - i + 1;
				start = i;
			}
		}
	}

	cout << maxLen << endl;
	cout << s.substr(start, maxLen) << endl;
}

int main() {

	string s = "forgeeksskeegfor";
	longestP(s);

	return 0;
}
