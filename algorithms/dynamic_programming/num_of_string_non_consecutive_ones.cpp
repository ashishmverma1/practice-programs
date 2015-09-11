/*
 * Author:		Ashish Verma
 * Title:		find num of binary strings of length n that dont contain any consecutive 1s
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

int numOfString(int n) {
	int last0[n], last1[n];
	last0[0] = last1[0] = 1;
	for (int i = 1; i < n; i++) {
		last0[i] = last0[i - 1] + last1[i - 1];
		last1[i] = last0[i - 1];
	}
	return last0[n - 1] + last1[n - 1];
}

int main() {

	cout << numOfString(5);

	return 0;
}
