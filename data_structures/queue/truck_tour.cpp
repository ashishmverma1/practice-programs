/*
 * Author:		Ashish Verma
 * Title:		find start point such that truck completes circular tour with >= petrol
 *
 */

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <fstream>

#define debug(x) cout << "DEBUG: " << x << endl

using namespace std;

int truckStart(int petrol[], int distance[], int n) {
	int start = 0;
	int end = 1;
	int petrolRemaining = 0;
	while (start != end || petrolRemaining < 0) {
		while (start != end && petrolRemaining < 0) {
			petrolRemaining += distance[start] - petrol[start];
			start = (start + 1) % n;
			if (start == 0) {
				return -1;
			}
		}
		petrolRemaining += petrol[end] - distance[end];
		end = (end + 1) % n;
	}
	return start;
}

int main() {
	int ar[] = { 6, 3, 7 };
	int n = sizeof(ar) / sizeof(ar[0]);

	int ds[] = { 4, 6, 3 };
	cout << truckStart(ar, ds, n);

	return 0;
}
