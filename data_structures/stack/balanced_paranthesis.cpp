/*
 * Author:		Ashish Verma
 * Title:		Check for balanced parentheses in an expression
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

	stack<char> stk;
	string expr;
	bool isBalanced = true;

	cin >> expr;

	for (unsigned int i = 0; i < expr.length(); i++) {
		if (expr[i] == '[' || expr[i] == '{' || expr[i] == '(') {
			stk.push(expr[i]);
		} else if (expr[i] == ']') {
			if (!stk.empty() && stk.top() == '[') {
				stk.pop();
			} else {
				isBalanced = false;
				break;
			}
		} else if (expr[i] == '}') {
			if (!stk.empty() && stk.top() == '{') {
				stk.pop();
			} else {
				isBalanced = false;
				break;
			}
		} else if (expr[i] == ')') {
			if (!stk.empty() && stk.top() == '(') {
				stk.pop();
			} else {
				isBalanced = false;
				break;
			}
		}
	}

	if (isBalanced) {
		cout << "Balanced";
	} else {
		cout << "Not balanced";
	}

	return 0;
}
