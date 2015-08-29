/*
 * Author:		Ashish Verma
 * Title:		minimize cash flow
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

class graph {
	int v;
	bool isDirected;
	vector<pair<int, int> > *adjList;

public:
	graph(int v, bool isDirected = false) {
		this->v = v;
		this->isDirected = isDirected;
		adjList = new vector<pair<int, int> > [v];
	}

	void insert(int src, int dest, int weight) {
		adjList[src].push_back(pair<int, int>(dest, weight));
		if (!isDirected) {
			adjList[dest].push_back(pair<int, int>(src, weight));
		}
	}

	void printGraph() {
		for (int i = 0; i < v; i++) {
			cout << i << " -> ";
			for (unsigned int j = 0; j < adjList[i].size(); j++) {
				cout << adjList[i][j].first << ' ';
			}
			cout << endl;
		}
	}

	void calcMaxFlow() {
		// find delta amounts for each person
		int *amount = new int[v];
		for (int i = 0; i < v; i++) {
			amount[i] = 0;
		}
		for (int i = 0; i < v; i++) {
			for (unsigned int j = 0; j < adjList[i].size(); j++) {
				amount[adjList[i][j].first] += adjList[i][j].second;
				amount[i] -= adjList[i][j].second;
			}
		}
		// keep transacting between highest debtor and highest creditor untill all is settled
		int min, max, minI, maxI;
		while (true) {
			min = INT_MAX;
			max = INT_MIN;
			for (int i = 0; i < v; i++) {
				if (amount[i] > max) {
					max = amount[i];
					maxI = i;
				}
				if (amount[i] < min) {
					min = amount[i];
					minI = i;
				}
			}

			if (min == 0 && max == 0) {
				break;
			}

			if (-1 * min > max) {
				amount[minI] += max;
				amount[maxI] = 0;
				cout << minI << " gives $" << max << " to " << maxI << endl;
			} else if (-1 * min < max) {
				amount[maxI] += min;
				amount[minI] = 0;
				cout << minI << " gives $" << -1 * min << " to " << maxI << endl;
			} else {
				amount[minI] = amount[maxI] = 0;
				cout << minI << " gives $" << max << " to " << maxI << endl;
			}
		}
	}
};

int main() {

	graph g(3, true);

	g.insert(0, 1, 3);
	g.insert(0, 2, 2);
	g.insert(1, 2, 5);

//	g.printGraph();
	g.calcMaxFlow();

	return 0;
}
