/*
 * Author:		Ashish Verma
 * Title:		find subset with given sum
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

bool subsetSum(int ar[], int n, int sum, stack<int> sol = stack<int>()) {
	if (n < 0 || sum < 0) {
		return false;
	}
	if (sum == 0) {
		while (!sol.empty()) {
			cout << sol.top() << " ";
			sol.pop();
		}
		cout << endl;
		return true;
	} else {
		sol.push(ar[n - 1]);
		if (subsetSum(ar, n - 1, sum - ar[n - 1], sol)) {
			return true;
		}
		sol.pop();
		if (subsetSum(ar, n - 1, sum, sol)) {
			return true;
		}
	}
	return false;
}

int main() {

	int ar[] = { 15, 22, 14, 26, 32, 9, 16, 8 };
	int n = sizeof(ar) / sizeof(ar[0]);

	subsetSum(ar, n, 53);

	return 0;
}
