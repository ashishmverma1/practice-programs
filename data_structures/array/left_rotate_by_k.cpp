/*
 * Author:		Ashish Verma
 * Title:		rotate array by k positions
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

void reverse(int ar[], int low, int high) {
	int temp;
	while (low < high) {
		temp = ar[low];
		ar[low] = ar[high];
		ar[high] = temp;
		low++;
		high--;
	}
}

void leftRotate(int ar[], int n, int d) {
	reverse(ar, 0, d - 1);
	reverse(ar, d, n - 1);
	reverse(ar, 0, n - 1);
}

int main() {
	int ar[] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = sizeof(ar) / sizeof(ar[0]);
	leftRotate(ar, n, 3);

	for (int i = 0; i < n; i++) {
		cout << ar[i] << ' ';
	}

	return 0;
}
