/*
 * Author:		Ashish Verma
 * Title:		greedy activity selection
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

struct activity {
	int start, end;
};

bool compare(activity a, activity b) {
	return a.end < b.end;
}

void activitySelection(activity ar[], int n) {
	sort(ar, ar + n, compare);
	activity last;
	last.end = -1;

	for (int i = 0; i < n; i++) {
		if (ar[i].start >= last.end) {
			cout << "Start: " << ar[i].start << "\tEnd: " << ar[i].end << endl;
			last = ar[i];
		}
	}
}

int main() {
	activity ar[] = { { 1, 2 }, { 3, 4 }, { 0, 6 }, { 5, 7 }, { 8, 9 }, { 5, 9 } };
	int n = sizeof(ar) / sizeof(ar[0]);

	activitySelection(ar, n);

	return 0;
}
