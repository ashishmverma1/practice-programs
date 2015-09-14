/*
 * Author:		Ashish Verma
 * Title:		sum of digits of all numbers 1 to n
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
#include <list>

#define debug(x) cout << "DEBUG: " << x << endl

using namespace std;

int findSumOfDigits(int n) {
	int dp[n + 1];

	for (int i = 0; i <= 9; i++) {
		dp[i] = i;
	}

	for (int i = 10; i <= n; i++) {
		dp[i] = (i % 10) + dp[i / 10];
	}

	int result = 0;
	for (int i = 1; i <= n; i++) {
		result += dp[i];
	}

	return result;
}

int main() {

	cout << findSumOfDigits(328);

	return 0;
}
