/*
 * Author:		Ashish Verma
 * Title:		shift all 0 to right. order of other elements should remain same
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

void shiftZeroes(int ar[], int n) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (ar[i] != 0) {
			ar[j++] = ar[i];
		}
	}
	while (j < n) {
		ar[j++] = 0;
	}
}

int main() {
	int ar[] = { 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0 };
	int n = sizeof(ar) / sizeof(ar[0]);

	shiftZeroes(ar, n);
	for (int i = 0; i < n; i++) {
		cout << ar[i] << " ";
	}

	return 0;
}
