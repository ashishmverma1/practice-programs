/*
 * Author:		Ashish Verma
 * Title:		find duplicates in array of size n where 0 <= a[i] <= n - 1
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

void findDuplicates(int ar[], int n) {
	for (int i = 0; i < n; i++) {
		if (ar[abs(ar[i])] > 0) {
			ar[abs(ar[i])] *= -1;
		} else {
			cout << abs(ar[i]) << ' ';
		}
	}
}

int main() {
	int ar[] = { 1, 2, 3, 1, 3, 6, 6 };
	int n = sizeof(ar) / sizeof(ar[0]);

	findDuplicates(ar, n);

	return 0;
}
