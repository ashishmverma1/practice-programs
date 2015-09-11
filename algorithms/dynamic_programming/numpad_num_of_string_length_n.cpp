/*
 * Author:		Ashish Verma
 * Title:		Given the mobile numeric keypad. You can only press buttons that are
 * 				up, left, right or down to the current button.
 * 				You are not allowed to press bottom row corner buttons (i.e. * and # ).
 * 				Given a number N, find out the number of possible numbers of given length.
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

int numOfNumbers(int length) {
	int dp[length + 1][10];

	for (int i = 0; i < 10; i++) {
		dp[0][i] = 0;
		dp[1][i] = 1;
	}

	for (int len = 2; len <= length; len++) {
		dp[len][0] = dp[len - 1][0] + dp[len - 1][8];
		
		dp[len][1] = dp[len - 1][1] + dp[len - 1][4] + dp[len - 1][2];
		
		dp[len][2] = dp[len - 1][2] + dp[len - 1][1] + dp[len - 1][3] + dp[len - 1][5];
		
		dp[len][3] = dp[len - 1][3] + dp[len - 1][2] + dp[len - 1][6];
		
		dp[len][4] = dp[len - 1][4] + dp[len - 1][1] + dp[len - 1][5] + dp[len - 1][7];
		
		dp[len][5] = dp[len - 1][5] + dp[len - 1][2] + dp[len - 1][6] + dp[len - 1][8]
				+ dp[len - 1][4];
		
		dp[len][6] = dp[len - 1][6] + dp[len - 1][3] + dp[len - 1][5] + dp[len - 1][9];
		
		dp[len][7] = dp[len - 1][7] + dp[len - 1][4] + dp[len - 1][8];
		
		dp[len][8] = dp[len - 1][8] + dp[len - 1][7] + dp[len - 1][5] + dp[len - 1][9]
				+ dp[len - 1][0];
		
		dp[len][9] = dp[len - 1][9] + dp[len - 1][6] + dp[len - 1][8];
	}

	int result = 0;
	for (int i = 0; i < 10; i++) {
		result += dp[length][i];
	}
	return result;
}

int main() {

	cout << numOfNumbers(5);

	return 0;
}
