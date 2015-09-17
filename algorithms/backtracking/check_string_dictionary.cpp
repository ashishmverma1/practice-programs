/*
 * Author:		Ashish Verma
 * Title:		check if given space-less string can be formed using given dictionary of words
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
#include <list>

#define debug(x) cout << "DEBUG: " << x << endl

using namespace std;

bool canBeFormed(string dictionary[], int low, int n, string s) {
	if (low >= n) {
		return false;
	}
	bool exactLengthFound = false;
	string result = "";
	int p;
	unsigned curLength;
	for (p = 0, curLength = 0; p < n && curLength < s.length(); p++) {
		curLength += dictionary[p].length();
		if (curLength == s.length()) {
			exactLengthFound = true;
			break;
		}
	}

	if (exactLengthFound) {
		for (int i = 0; i <= p; i++) {
			result += dictionary[i];
		}
		if (result == s) {
			return true;
		}
	}

	for (int i = low + 1; i < n; i++) {
		swap(dictionary[i], dictionary[low]);
		if (canBeFormed(dictionary, low + 1, n, s)) {
			return true;
		}
		swap(dictionary[i], dictionary[low]);
	}

	return false;
}

int main() {

	string dictionary[] = { "it", "is", "awesome" };
	string s = "awesomeis";
	cout << canBeFormed(dictionary, 0, 3, s);

	return 0;
}
