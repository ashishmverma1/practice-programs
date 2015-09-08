/*
 * Author:		Ashish Verma
 * Title:		find all elements that appear more than n/k times
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

void findElements(int ar[], int n, int k) {
	if (k < 2) {
		return;
	}

	struct elementCount {
		int e;
		int c;
	} eCount[k - 1];
	for (int i = 0; i < k - 1; i++) {
		eCount[i].c = 0;
	}

	for (int i = 0; i < n; i++) {
		int j;
		for (j = 0; j < k - 1; j++) {
			if (eCount[j].e == ar[i]) {
				eCount[j].c++;
				break;
			}
		}

		if (j == k - 1) {
			int l;
			for (l = 0; l < k - 1; l++) {
				if (eCount[l].c == 0) {
					eCount[l].e = ar[i];
					break;
				}
			}

			if (l == k - 1) {
				for (l = 0; l < k - 1; l++) {
					eCount[l].c--;
				}
			}
		}
	}

	for (int i = 0; i < k - 1; i++) {
		int curCount = 0;
		for (int j = 0; j < n; j++) {
			if (ar[j] == eCount[i].e) {
				curCount++;
			}
		}
		if (curCount > n / k) {
			cout << eCount[i].e << " (Count: " << curCount << ")" << endl;
		}
	}
	cout << endl;
}

int main() {
	int ar[] = { 4, 5, 6, 7, 8, 4, 4 };
	int n = sizeof(ar) / sizeof(ar[0]);

	findElements(ar, n, 3);

	return 0;
}
