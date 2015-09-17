/*
 * Author:		Ashish Verma
 * Title:		check if m colorable
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

const int v = 4;

void printColors(int color[]) {
	for (int i = 0; i < v; i++) {
		cout << color[i] << " ";
	}
	cout << endl;
}

bool checkMColorable(bool adj[v][v], int m, int cur = 0) {
	static int color[v] = { 0 };

	if (cur == v) {
		printColors(color);
		return true;
	} else {
		for (int c = 1; c <= m; c++) {
			bool available = true;

			for (int i = 0; i < v; i++) {
				if (adj[cur][i] && color[i] == c) {
					available = false;
					break;
				}
			}

			if (available) {
				color[cur] = c;
				if (checkMColorable(adj, m, cur + 1)) {
					return true;
				}
				color[cur] = 0;
			}
		}
	}

	return false;
}

int main() {

	bool graph[v][v] = { { 0, 1, 1, 1 }, { 1, 0, 1, 0 }, { 1, 1, 0, 1 }, { 1, 0, 1, 0 }, };

	checkMColorable(graph, 3);

	return 0;
}
