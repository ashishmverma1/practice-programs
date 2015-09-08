/*
 * Author:		Ashish Verma
 * Title:		print all combinations of r elements from given array
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

void printCombinations(int ar[], int n, int r, int i = 0, int p = 0) {
	static int *data = new int[r];

	if (p == r) {
		for (int i = 0; i < r; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
		return;
	}

	if (i >= n) {
		return;
	}

	data[p] = ar[i];
	printCombinations(ar, n, r, i + 1, p + 1);
	printCombinations(ar, n, r, i + 1, p);
}

int main() {
	int ar[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(ar) / sizeof(ar[0]);

	printCombinations(ar, n, 3);

	return 0;
}
