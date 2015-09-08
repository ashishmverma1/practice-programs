/*
 * Author:		Ashish Verma
 * Title:		find all pairs with difference k
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

void findPairs(int ar[], int n, int k) {
	sort(ar, ar + n);

	int j = 0;
	for (int i = 0; i < n && j < n; i++) {
		while (j < n && ar[j] - ar[i] < k) {
			j++;
		}
		if (j < n && ar[j] - ar[i] == k) {
			cout << ar[i] << ", " << ar[j] << endl;
		}
	}
}

int main() {
	int ar[] = { 1, 2, 3, 4, 5, 7, 9, 8 };
	int n = sizeof(ar) / sizeof(ar[0]);

	findPairs(ar, n, 6);

	return 0;
}
