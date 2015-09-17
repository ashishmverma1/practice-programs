/*
 * Author:		Ashish Verma
 * Title:		print all string permutations
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

void printStringPermutations(string s, int low, int high) {
	if (low == high) {
		cout << s << endl;
	} else {
		for (int i = low; i <= high; i++) {
			swap(s[low], s[i]);
			printStringPermutations(s, low + 1, high);
			swap(s[low], s[i]);
		}
	}
}

int main() {

	string s = "abc";
	printStringPermutations(s, 0, s.length() - 1);

	return 0;
}
