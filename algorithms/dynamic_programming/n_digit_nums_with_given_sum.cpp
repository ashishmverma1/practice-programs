/*
 * Author:		Ashish Verma
 * Title:		Count of n digit numbers whose sum of digits equals to given sum
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

int dp[1000][1000];

int _numOfNumbers(int digits, int sum) {

	if (digits == 0) {
		if (sum == 0) {
			return 1;
		} else {
			return 0;
		}
	}

	if (dp[digits][sum] != -1) {
		return dp[digits][sum];
	}

	int ans = 0;
	for (int i = 0; i <= 9 && i <= sum; i++) {
		ans += _numOfNumbers(digits - 1, sum - i);
	}

	dp[digits][sum] = ans;
	return dp[digits][sum];
}

int numOfNumbers(int digits, int sum) {
	memset(dp, -1, sizeof(dp));

	int ans = 0;
	for (int i = 1; i <= 9 && i <= sum; i++) {
		ans += _numOfNumbers(digits - 1, sum - i);
	}
	return ans;
}

int main() {

	cout << numOfNumbers(3, 6);

	return 0;
}
