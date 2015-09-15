/*
 * Author:		Ashish Verma
 * Title:		find longest even length substring such that first and second halves have equal sum
 * 				(given string is a numeric string)
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

string maxStringLength(string s) {
	int n = s.length();
	int start, end, lSum, rSum;
	int maxLength = INT_MIN;

	string ans;
	for (int mid = 0; mid < n - 1; mid++) {
		start = mid;
		end = mid + 1;
		lSum = rSum = 0;
		while (start >= 0 && end < n) {
			lSum += s[start] - '0';
			rSum += s[end] - '0';

			if (lSum == rSum && (end - start + 1) > maxLength) {
				maxLength = end - start + 1;
				ans = s.substr(start, maxLength);
			}

			start--;
			end++;
		}
	}
	return ans;
}

int main() {

	string s = "1538023";

	cout << maxStringLength(s);

	return 0;
}
