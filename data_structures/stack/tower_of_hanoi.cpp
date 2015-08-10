/*
 * Author:		Ashish Verma
 * Title:		tower of hanoi
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

stack<int> a, b, c;

void printTowers() {
	stack<int> temp;

	// tower a
	cout << "A -> ";
	while (!a.empty()) {
		temp.push(a.top());
		a.pop();
	}

	while (!temp.empty()) {
		a.push(temp.top());
		temp.pop();
		cout << a.top() << ' ';
	}
	cout << endl;

	// tower b
	cout << "B -> ";
	while (!b.empty()) {
		temp.push(b.top());
		b.pop();
	}

	while (!temp.empty()) {
		b.push(temp.top());
		temp.pop();
		cout << b.top() << ' ';
	}
	cout << endl;

	// tower c
	cout << "C -> ";
	while (!c.empty()) {
		temp.push(c.top());
		c.pop();
	}

	while (!temp.empty()) {
		c.push(temp.top());
		temp.pop();
		cout << c.top() << ' ';
	}
	cout << endl << endl;
}

void towerOfHanoi(int n, stack<int> *x, stack<int> *y, stack<int> *z) {
	if (n <= 0) {
		return;
	}
	towerOfHanoi(n - 1, x, z, y);
	printTowers();
	z->push(x->top());
	x->pop();
	towerOfHanoi(n - 1, y, x, z);

}

int main() {

	a.push(4);
	a.push(3);
	a.push(2);
	a.push(1);

	towerOfHanoi(4, &a, &b, &c);
	printTowers();
	return 0;
}
