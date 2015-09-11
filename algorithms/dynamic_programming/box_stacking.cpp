/*
 * Author:		Ashish Verma
 * Title:		create a stack of boxes which is as tall as possible,
 * 				but you can only stack a box on top of another box if the
 * 				dimensions of the 2-D base of the lower box are each strictly larger
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

struct box {
	int h, w, d;
};

using namespace std;

bool compare(box a, box b) {
	return (a.d * a.w) > (b.d * b.w);
}

int findMaxHeight(box ar[], int n) {
	box rotatedBox[3 * n];
	int j = 0;
	for (int i = 0; i < n; i++) {
		rotatedBox[j] = ar[i];
		j++;

		rotatedBox[j].h = ar[i].w;
		rotatedBox[j].d = ar[i].h;
		rotatedBox[j].w = ar[i].d;
		j++;

		rotatedBox[j].h = ar[i].d;
		rotatedBox[j].d = ar[i].w;
		rotatedBox[j].w = ar[i].h;
		j++;
	}

	n *= 3;

	sort(rotatedBox, rotatedBox + n, compare);

	int dp[n];
	for (int i = 0; i < n; i++) {
		dp[i] = rotatedBox[i].h;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (rotatedBox[j].w > rotatedBox[i].w && rotatedBox[j].d > rotatedBox[i].d) {
				dp[i] = max(dp[i], dp[j] + rotatedBox[i].h);
			}
		}
	}

	return dp[n - 1];
}

int main() {

	box ar[] = { { 4, 6, 7 }, { 1, 2, 3 }, { 4, 5, 6 }, { 10, 12, 32 } };
	int n = sizeof(ar) / sizeof(ar[0]);
	cout << findMaxHeight(ar, n);

	return 0;
}
