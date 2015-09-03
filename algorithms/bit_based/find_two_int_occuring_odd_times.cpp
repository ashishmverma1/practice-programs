/*
 * Author:		Ashish Verma
 * Title:		find 2 nums which occur odd number of times
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
#define INFINITE 99999

using namespace std;

void findTwoNum(int ar[], int n) {
	int xorAll = 0;
	for (int i = 0; i < n; i++) {
		xorAll = xorAll ^ ar[i];
	}

	int firstNum = 0, secondNum = 0;
	for (int i = 0; i < n; i++) {
		if (ar[i] & (xorAll & ~(xorAll - 1))) {
			firstNum = firstNum ^ ar[i];
		} else {
			secondNum = secondNum ^ ar[i];
		}
	}
	cout << firstNum << " " << secondNum << endl;
}

int main() {
	int ar[] = { 4, 2, 4, 5, 2, 3, 3, 1 };
	int n = sizeof(ar) / sizeof(ar[0]);
	findTwoNum(ar, n);

	return 0;
}
