/*
 * Author:		Ashish Verma
 * Title:		greatest number divisible by 3 from given digits
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

int main() {

	int n;
	cin >> n;

	vector<int> digits(n);
	vector<int> ans;

	for (int i = 0; i < n; i++) {
		cin >> digits[i];
	}

	sort(digits.begin(), digits.end());
	queue<int> rem0, rem1, rem2;
	int sumDigits = 0;
	bool ansPossible = true;

	for (int i = 0; i < n; i++) {
		if (digits[i] % 3 == 0) {
			rem0.push(digits[i]);
		} else if (digits[i] % 3 == 1) {
			rem1.push(digits[i]);
		} else {
			rem2.push(digits[i]);
		}
		sumDigits += digits[i];
	}

	if (sumDigits % 3 == 0) {
		for (int i = 0; i < n; i++) {
			ans.push_back(digits[i]);
		}
	} else if (sumDigits % 3 == 1) {
		if (!rem1.empty()) {
			rem1.pop();
		} else if (rem2.size() >= 2) {
			rem2.pop();
			rem2.pop();
		} else {
			ansPossible = false;
		}
		while (!rem0.empty()) {
			ans.push_back(rem0.front());
			rem0.pop();
		}
		while (!rem1.empty()) {
			ans.push_back(rem1.front());
			rem1.pop();
		}
		while (!rem2.empty()) {
			ans.push_back(rem2.front());
			rem2.pop();
		}
	} else {
		if (!rem2.empty()) {
			rem2.pop();
		} else if (rem1.size() >= 2) {
			rem2.pop();
			rem2.pop();
		} else {
			ansPossible = false;
		}
		while (!rem0.empty()) {
			ans.push_back(rem0.front());
			rem0.pop();
		}
		while (!rem1.empty()) {
			ans.push_back(rem1.front());
			rem1.pop();
		}
		while (!rem2.empty()) {
			ans.push_back(rem2.front());
			rem2.pop();
		}
	}

	if (ansPossible) {
		sort(ans.begin(), ans.end(), greater<int>());
		for (unsigned int i = 0; i < ans.size(); i++) {
			cout << ans[i];
		}
	} else {
		cout << "Not possible";
	}

	cout << endl;
	return 0;
}
