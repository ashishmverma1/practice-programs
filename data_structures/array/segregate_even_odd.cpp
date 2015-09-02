/*
 * Author:		Ashish Verma
 * Title:		segregate even to left and odd to right
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

void segregateOddEven(int ar[], int n) {
	int low = 0;
	int high = n - 1;
	while (low < high) {
		if (ar[low] % 2 == 1 && ar[high] % 2 == 0) {
			swap(ar[low], ar[high]);
			low++;
			high--;
		}
		while (low < high && ar[low] % 2 == 0) {
			low++;
		}
		while (high > low && ar[high] % 2 == 1) {
			high--;
		}
	}
}

int main() {
	int ar[] = { 12, 34, 45, 9, 8, 90, 3 };
	int n = sizeof(ar) / sizeof(ar[0]);

	segregateOddEven(ar, n);
	for (int i = 0; i < n; i++) {
		cout << ar[i] << " ";
	}

	return 0;
}
