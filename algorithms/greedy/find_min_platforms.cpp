/*
 * Author:		Ashish Verma
 * Title:		given arrival and departure times of trains, find min platforms needed
 *
 */

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <fstream>

#define debug(x) cout << "DEBUG: " << x << endl

using namespace std;

int findMinPlatforms(int arrival[], int departure[], int n) {
	int platformsNeeded = 0, maxPlatformNeeded = INT_MIN;

	int a, d;
	a = d = 0;

	while (a < n) {
		if (arrival[a] < departure[d]) {
			a++;
			platformsNeeded++;
		} else {
			d++;
			platformsNeeded--;
		}
		maxPlatformNeeded = max(maxPlatformNeeded, platformsNeeded);
	}

	return maxPlatformNeeded;
}

int main() {
	int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
	int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
	cout << findMinPlatforms(arr, dep, 6);

	return 0;
}
