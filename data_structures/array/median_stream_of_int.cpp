/*
 * Author:		Ashish Verma
 * Title:		find median from incoming stream of numbers at each point
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

double getMedian(int val) {
	static double median = 0;
	static priority_queue<int, vector<int> > left;
	static priority_queue<int, vector<int>, greater<int> > right;

	if (left.size() < right.size()) {
		if (val < median) {
			left.push(val);
		} else {
			left.push(right.top());
			right.pop();
			right.push(val);
		}
		median = ((double) left.top() + (double) right.top()) / 2.0;
	} else if (left.size() > right.size()) {
		if (val < median) {
			right.push(left.top());
			left.pop();
			left.push(val);
		} else {
			right.push(val);
		}
		median = ((double) left.top() + (double) right.top()) / 2.0;
	} else {
		if (val < median) {
			left.push(val);
			median = left.top();
		} else {
			right.push(val);
			median = right.top();
		}
	}
	return median;
}

int main() {
	int ar[] = { 5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4 };
	int n = sizeof(ar) / sizeof(ar[0]);
	for (int i = 0; i < n; i++) {
		cout << getMedian(ar[i]) << ' ';
	}
	return 0;
}
