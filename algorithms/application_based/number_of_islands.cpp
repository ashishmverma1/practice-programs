/*
 * Author:		Ashish Verma
 * Title:		find number of islands formed by '1' in boolean matrix
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

const int n = 10;

bool findUnvisitedLand(bool map[n][n], int &i, int &j) {
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (map[i][j] == true) {
				return true;
			}
		}
	}
	return false;
}

void floodFill(bool map[n][n], int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= n || !map[i][j]) {
		return;
	}
	map[i][j] = false;
	floodFill(map, i + 1, j);
	floodFill(map, i - 1, j);
	floodFill(map, i, j + 1);
	floodFill(map, i, j - 1);
}

int countIslands(bool map[n][n]) {
	int count = 0;
	int i, j;
	while (findUnvisitedLand(map, i, j)) {
		count++;
		floodFill(map, i, j);
	}
	return count;
}

int main() {

	bool map[n][n] = {

	{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },

	{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },

	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

	{ 0, 1, 1, 0, 0, 1, 1, 1, 1, 0 },

	{ 0, 1, 1, 0, 0, 1, 1, 1, 1, 0 },

	{ 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 },

	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },

	{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },

	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }

	};

	cout << countIslands(map);

	return 0;
}
