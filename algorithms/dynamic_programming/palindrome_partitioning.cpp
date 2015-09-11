/*
 * Author:		Ashish Verma
 * Title:		find min number of partitions of string such that each partition is palindrome
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

int findMinCuts(string s) {
	int n = s.length();

	bool isPalindrome[n][n];
	int numOfCuts[n];

	for (int i = 0; i < n; i++) {
		isPalindrome[i][i] = true;
	}

	for (int length = 2; length <= n; length++) {
		for (int i = 0; i < n - length + 1; i++) {
			int j = i + length - 1;
			if (length == 2) {
				isPalindrome[i][j] = (s[i] == s[j]);
			} else {
				isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i + 1][j - 1];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (isPalindrome[0][i]) {
			numOfCuts[i] = 0;
		} else {
			int minCuts = INT_MAX;
			for (int j = 0; j < i; j++) {
				if (isPalindrome[j + 1][i]) {
					minCuts = min(minCuts, numOfCuts[j] + 1);
				}
			}
		}
	}

	return numOfCuts[n - 1];
}

int main() {

	string s = "ababbbabbababa";
	cout << findMinCuts(s);

	return 0;
}
