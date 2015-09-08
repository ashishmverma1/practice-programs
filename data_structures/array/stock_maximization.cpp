/*
 * Author:		Ashish Verma
 * Title:		find buy and sell points of stock to earn max profit
 * 				unit stocks can be purchased on multiple dates
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

void findOptimalStock(int price[], int n) {
	int start, end;
	vector < pair<int, int> > result;
	int i = 0;
	while (i < n - 1) {
		while (i < n - 1 && price[i + 1] <= price[i]) {
			i++;
		}
		if (i == n - 1) {
			break;
		}
		start = i++;

		while (i < n && price[i - 1] <= price[i]) {
			i++;
		}
		end = i - 1;
		result.push_back(make_pair(start, end));
	}
	vector<pair<int, int> >::iterator it;
	for (it = result.begin(); it != result.end(); it++) {
		cout << "Buy: " << it->first << ", Sell: " << it->second << endl;
	}
}

int main() {
	int ar[] = { 100, 180, 260, 310, 40, 535, 695 };
	int n = sizeof(ar) / sizeof(ar[0]);

	findOptimalStock(ar, n);

	return 0;
}
