/*
 * Author:		Ashish Verma
 * Title:		find num ways to reach nth stair if person can take 1...m steps at a time
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

int numOfWays(int n, int m) {
	int ways[n + 1];
	ways[0] = ways[1] = 1;

	for (int i = 2; i <= n; i++) {
		ways[i] = 0;
		for (int j = max(0, i - m); j < i; j++) {
			ways[i] += ways[j];
		}
	}
	return ways[n];
}

int main() {

	cout << numOfWays(20, 2);

	return 0;
}
