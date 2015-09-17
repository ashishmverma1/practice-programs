/*
 * Author:		Ashish Verma
 * Title:		tug of war - divide set into 2 halves such that diff is minimum
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

vector<int> tugOfWar(int w[], int n, int start, vector<int> curSol, int curW, int totalW) {
	static vector<int> sol;
	static int minDiffYet = INT_MAX;

	if (start >= n) {
		return vector<int>();
	}
	if (abs(totalW - 2 * curW) < minDiffYet && (int) curSol.size() == n / 2) {
		minDiffYet = abs(totalW - 2 * curW);
		sol = curSol;
	}

	curSol.push_back(w[start]);
	tugOfWar(w, n, start + 1, curSol, curW + w[start], totalW);
	curSol.pop_back();
	tugOfWar(w, n, start + 1, curSol, curW, totalW);

	return sol;
}

void tugOfWar(int w[], int n) {
	int totalW = 0;
	for (int i = 0; i < n; i++) {
		totalW += w[i];
	}

	vector<int> sol = tugOfWar(w, n, 0, vector<int>(), 0, totalW);
	for (unsigned int i = 0; i < sol.size(); i++) {
		cout << sol[i] << " ";
	}
}

int main() {

	int ar[] = { 23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4 };
	int n = sizeof(ar) / sizeof(ar[0]);

	tugOfWar(ar, n);

	return 0;
}
