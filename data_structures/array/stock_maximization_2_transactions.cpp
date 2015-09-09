/*
 * Author:		Ashish Verma
 * Title:		find max profit gainable using 2 transactions
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

int findMaxProfit(int price[], int n) {
	int profit[n] = { 0 };

	int maxPrice = price[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		maxPrice = max(maxPrice, price[i]);
		profit[i] = max(profit[i + 1], maxPrice - price[i]);
	}

	int minPrice = price[0];
	for (int i = 1; i < n; i++) {
		minPrice = min(minPrice, price[i]);
		profit[i] = max(profit[i - 1], profit[i] + price[i] - minPrice);
	}

	return profit[n - 1];
}

int main() {
	int ar[] = { 2, 30, 15, 10, 8, 25, 80 };
	int n = sizeof(ar) / sizeof(ar[0]);

	cout << findMaxProfit(ar, n);

	return 0;
}
