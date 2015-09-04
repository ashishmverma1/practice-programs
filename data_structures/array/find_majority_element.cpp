/*
 * Author:		Ashish Verma
 * Title:		check if any element occurs more than n/2 times (majority element)
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
#define INFINITE 99999

using namespace std;

void findMajorityElement(int ar[], int n) {
	int count = 1;
	int majorityIndex = 0;
	for (int i = 1; i < n; i++) {
		if (ar[i] == ar[majorityIndex]) {
			count++;
		} else {
			count--;
		}
		if (count == 0) {
			count = 1;
			majorityIndex = i;
		}
	}

	count = 0;
	for (int i = 0; i < n; i++) {
		if (ar[i] == ar[majorityIndex]) {
			count++;
		}
	}
	if (count > n / 2) {
		cout << ar[majorityIndex] << endl;
	} else {
		cout << "No majority element" << endl;
	}
}

int main() {
	int ar[] = { 2, 2, 3, 5, 2, 2, 6 };
	int n = sizeof(ar) / sizeof(ar[0]);
	findMajorityElement(ar, n);
	return 0;
}
