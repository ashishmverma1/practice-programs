/*
 * Author:		Ashish Verma
 * Title:		find longest subarray with equal num of 0s and 1s in array of 0 & 1
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

void findSubarray(int ar[], int n) {
	int leftSum[n] = { 0 };
	int maxLeftSum, minLeftSum;
	minLeftSum = maxLeftSum = leftSum[0] = ((ar[0] == 0) ? -1 : 1);
	for (int i = 1; i < n; i++) {
		leftSum[i] = leftSum[i - 1] + ((ar[i] == 0) ? -1 : 1);
		minLeftSum = min(minLeftSum, leftSum[i]);
		maxLeftSum = max(maxLeftSum, leftSum[i]);
	}

	int including0Start = 0, including0End = -1, including0MaxLength;
	for (int i = 1; i < n; i++) {
		if (leftSum[i] == 0) {
			including0End = i;
		}
	}
	including0MaxLength = (including0End == -1) ? -1 : including0End + 1;

	int hash[maxLeftSum - minLeftSum + 1];
	for (int i = 0; i < maxLeftSum - minLeftSum + 1; i++) {
		hash[i] = -1;
	}

	int excluding0Start, excluding0End, excluding0MaxLength = -1;
	for (int i = 0; i < n; i++) {
		if (hash[leftSum[i] - minLeftSum] == -1) {
			hash[leftSum[i] - minLeftSum] = i;
		} else {
			if (i - hash[leftSum[i] - minLeftSum] > excluding0MaxLength) {
				excluding0MaxLength = i - hash[leftSum[i] - minLeftSum];
				excluding0Start = hash[leftSum[i] - minLeftSum] + 1;
				excluding0End = i;
			}
		}
	}

	if (excluding0MaxLength == -1 && including0MaxLength == -1) {
		cout << "Doesn't exist" << endl;
	} else if (excluding0MaxLength > including0MaxLength) {
		cout << "Length: " << excluding0MaxLength << endl;
		cout << "Start: " << excluding0Start << endl;
		cout << "End: " << excluding0End << endl;
	} else {
		cout << "Length: " << including0MaxLength << endl;
		cout << "Start: " << including0Start << endl;
		cout << "End: " << including0End << endl;
	}
}

int main() {
	int ar[] = { 1, 0, 1, 1, 1, 0, 0 };
	int n = sizeof(ar) / sizeof(ar[0]);

	findSubarray(ar, n);

	return 0;
}
