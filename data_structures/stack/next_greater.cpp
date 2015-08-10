/*
 * Author:		Ashish Verma
 * Title:		find next greater element for each element
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
	stack<int> stk;

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	stk.push(v[0]);
	for (int i = 1; i < n; i++) {
		while (!stk.empty() && v[i] > stk.top()) {
			cout << stk.top() << '-' << v[i] << endl;
			stk.pop();
		}
		stk.push(v[i]);
	}

	while (!stk.empty()) {
		cout << stk.top() << '-' << -1 << endl;
		stk.pop();
	}

	return 0;
}
