/*
 * Author:		Ashish Verma
 * Title:		convert array to all possible char string, order remains same
 *
 */

#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

#define debug(x) cout << "DEBUG: " << x << endl

using namespace std;

string arrayToString(int ar[], int start, int end) {
	string ans = "";
	int index = 0;
	if (end == start + 1) {
		index = ar[start] * 10 + ar[start + 1] - 1;
	} else if (start == end) {
		index = ar[start] - 1;
	}
	if (index < 26) {
		ans += 'a' + index;
	}
	return ans;
}

void printPossibleStrings(int ar[], int start, int end, string curStr) {
	if (start > end) {
		cout << curStr << endl;
		return;
	}
	if (arrayToString(ar, start, start).length() > 0) {
		printPossibleStrings(ar, start + 1, end, curStr + arrayToString(ar, start, start));
	}
	if (start + 1 <= end && arrayToString(ar, start, start + 1).length() > 0) {
		printPossibleStrings(ar, start + 2, end, curStr + arrayToString(ar, start, start + 1));
	}
}

int main() {
	int ar[] = { 1, 2, 2, 1 };
	int n = 4;
	printPossibleStrings(ar, 0, n - 1, string());
	return 0;
}
