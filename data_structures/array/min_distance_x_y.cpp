/*
 * Author:		Ashish Verma
 * Title:		find min distance b/w x & y in given array
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

int findMinDistance(int ar[], int n, int x, int y) {
	int minDistance = INT_MAX;
	int prevFoundIndex = 0;
	while (ar[prevFoundIndex] != x && ar[prevFoundIndex] != y) {
		prevFoundIndex++;
	}
	for (int i = prevFoundIndex + 1; i < n; i++) {
		if (ar[i] == x || ar[i] == y) {
			if (ar[prevFoundIndex] != ar[i]) {
				minDistance = min(minDistance, i - prevFoundIndex);
			}
			prevFoundIndex = i;
		}
	}
	return minDistance;
}

int main() {
	int ar[] = { 3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3 };
	int n = sizeof(ar) / sizeof(ar[0]);
	cout << findMinDistance(ar, n, 3, 6);
	return 0;
}
