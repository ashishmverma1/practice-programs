/*
 * Author:		Ashish Verma
 * Title:		place all positive at even index and negative at odd index. extra elements at end.
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

void segregatePositiveNegative(int ar[], int n) {
	int low, high;

	low = 0;
	high = n - 1;
	while (low < high) {
		while (low < high && ar[low] < 0) {
			low++;
		}
		while (high > low && ar[high] > 0) {
			high--;
		}
		swap(ar[low], ar[high]);
		low++;
		high--;
	}

	low = 0;
	for (int i = 0; i < n; i++) {
		if (ar[i] > 0) {
			high = i;
			break;
		}
	}
	while (low < n && high < n && ar[low] < 0) {
		swap(ar[low], ar[high]);
		high++;
		low += 2;
	}
}

int main() {
	int ar[] = { -1, -2, -3, -4, -5, 6, -7, 8, 9 };
//	int ar[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
	int n = sizeof(ar) / sizeof(ar[0]);

	segregatePositiveNegative(ar, n);
	for (int i = 0; i < n; i++) {
		cout << ar[i] << " ";
	}

	return 0;
}
