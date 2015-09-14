/*
 * Author:		Ashish Verma
 * Title:		weighted job scheduling
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

struct job {
	int start, end, profit;
};

bool compare(job a, job b) {
	return a.end < b.end;
}

int prevNonconflictingJob(job ar[], int cur) {
	int i = cur - 1;
	while (i >= 0 && ar[i].end > ar[cur].start) {
		i--;
	}
	return i;
}

int findMaxProfit(job ar[], int n) {
	sort(ar, ar + n, compare);
	int dp[n];
	dp[0] = ar[0].profit;

	for (int i = 1; i < n; i++) {
		int lastJob = prevNonconflictingJob(ar, i);
		if (lastJob == -1) {
			dp[i] = dp[i - 1];
		} else {
			dp[i] = max(dp[i - 1], dp[lastJob] + ar[i].profit);
		}
	}

	return dp[n - 1];
}

int main() {

	job ar[] = { { 3, 10, 20 }, { 1, 2, 50 }, { 6, 19, 100 }, { 2, 100, 200 } };
	int n = sizeof(ar) / sizeof(ar[0]);

	cout << findMaxProfit(ar, n);

	return 0;
}
