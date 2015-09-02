/*
 * Author:		Ashish Verma
 * Title:		floor and ceil of val from array
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

void findFloorCeil(int ar[], int n, int val) {
	int low = 0;
	int high = n - 1;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (ar[mid] == val) {
			cout << "Floor: " << ar[mid] << endl;
			cout << "Ceil: " << ar[mid] << endl;
			break;
		} else if (mid > 0 && ar[mid - 1] < val && val < ar[mid]) {
			cout << "Floor: " << ar[mid - 1] << endl;
			cout << "Ceil: " << ar[mid] << endl;
			break;
		} else if (mid < n - 1 && ar[mid] < val && val < ar[mid + 1]) {
			cout << "Floor: " << ar[mid] << endl;
			cout << "Ceil: " << ar[mid + 1] << endl;
			break;
		} else if (ar[mid] < val) {
			low = mid + 1;
		} else if (ar[mid] > val) {
			high = mid - 1;
		}
	}
	// check if floor / ceil lies on boundaries
	if (low > high) {
		if (mid == n - 1) {
			cout << "Floor: " << ar[mid];
		} else if (mid == 0) {
			cout << "Ceil: " << ar[mid];
		}
	}
}

int main() {
	int ar[] = { 1, 2, 4, 6, 8 };
	int n = sizeof(ar) / sizeof(ar[0]);

	findFloorCeil(ar, n, 3);

	return 0;
}
