/*
 * Author:		Ashish Verma
 * Title:		add / subtract with arithmetic operators
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

int add(int a, int b) {
	int carry;
	while (b) {
		carry = a & b;
		a = a ^ b;
		b = carry << 1;
	}
	return a;
}

int subtract(int a, int b) {
	int borrow;
	while (b) {
		borrow = ~a & b;
		a = a ^ b;
		b = borrow << 1;
	}
	return a;
}

int main() {

	cout << add(3, 7) << endl;
	cout << subtract(1, 2) << endl;

	return 0;
}
