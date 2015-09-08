/*
 * Author:		Ashish Verma
 * Title:		sort in form of wave (arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …)
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

void waveSort(int ar[], int n) {
	for (int i = 0; i < n; i += 2) {
		if (i > 0 && ar[i - 1] > ar[i]) {
			swap(ar[i - 1], ar[i]);
		}
		if (i < n - 1 && ar[i] < ar[i + 1]) {
			swap(ar[i], ar[i + 1]);
		}
	}
}

int main() {
	int ar[] = { 2, 3, 7, 10, 12, 15, 30, 34 };
	int n = sizeof(ar) / sizeof(ar[0]);

	waveSort(ar, n);
	for (int i = 0; i < n; i++) {
		cout << ar[i] << " ";
	}

	return 0;
}
