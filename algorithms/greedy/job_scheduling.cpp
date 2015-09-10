/*
 * Author:		Ashish Verma
 * Title:		greedy job scheduling
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

struct job {
	char id;
	int deadline, profit;
};

bool compare(job a, job b) {
	return a.profit > b.profit;
}

void jobScheduling(job ar[], int n) {
	sort(ar, ar + n, compare);

	int maxDeadline = 0;
	for (int i = 0; i < n; i++) {
		maxDeadline = max(maxDeadline, ar[i].deadline);
	}
	int slot[maxDeadline];
	for (int i = 0; i < maxDeadline; i++) {
		slot[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = ar[i].deadline - 1; j >= 0; j--) {
			if (slot[j] == -1) {
				slot[j] = i;
				break;
			}
		}
	}

	for (int i = 0; i < maxDeadline; i++) {
		if (slot[i] != -1) {
			cout << "Profit: " << ar[slot[i]].profit << "\tDeadline: " << ar[slot[i]].deadline
					<< endl;
		}
	}
}

int main() {
	job ar[] = { { 'a', 2, 100 }, { 'b', 1, 19 }, { 'c', 2, 27 }, { 'd', 1, 25 }, { 'e', 3, 15 } };
	int n = sizeof(ar) / sizeof(ar[0]);

	jobScheduling(ar, n);

	return 0;
}
