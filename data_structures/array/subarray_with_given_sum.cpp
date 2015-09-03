/*
 * Author:		Ashish Verma
 * Title:		find subarray with given sum
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

void findSubarray(int ar[], int n, int sum) {
	int curSum, start;
	curSum = ar[0];
	start = 0;
	for (int i = 1; i <= n; i++) {
		while (curSum > sum && start < i - 1) {
			curSum -= ar[start++];
		}
		if (curSum == sum) {
			cout << "Start: " << start << endl;
			cout << "End: " << i - 1 << endl;
			return;
		}
		if (i < n) {
			curSum += ar[i];
		}
	}
	cout << "None" << endl;
}

int main() {
	int ar[] = { 1, 4, 20, 3, 10, 5 };
	int n = sizeof(ar) / sizeof(ar[0]);
	findSubarray(ar, n, 33);
	return 0;
}
