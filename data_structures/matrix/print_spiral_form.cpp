/*
 * Author:		Ashish Verma
 * Title:		print spiral form of matrix
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

const int m = 3;
const int n = 6;

void printSpiral(int ar[m][n]) {
	int endR = m;
	int endC = n;
	int startR = 0;
	int startC = 0;

	while (startR < endR && startC < endC) {
		for (int i = startC; i < endC; i++) {
			cout << ar[startR][i] << " ";
		}
		startR++;

		for (int i = startR; i < endR; i++) {
			cout << ar[i][endC - 1] << " ";
		}
		endC--;

		if (startR < endR) {
			for (int i = endC - 1; i >= startC; i--) {
				cout << ar[endR - 1][i] << " ";
			}
			endR--;
		}

		if (startC < endC) {
			for (int i = endR - 1; i >= startR; i--) {
				cout << ar[i][startC] << " ";
			}
			startC++;
		}
	}
}

int main() {

	int ar[m][n] = { { 1, 2, 3, 4, 5, 6 }, { 7, 8, 9, 10, 11, 12 }, { 13, 14, 15, 16, 17, 18 } };

	printSpiral(ar);

	return 0;
}
