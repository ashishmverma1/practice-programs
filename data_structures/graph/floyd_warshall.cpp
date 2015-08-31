/*
 * Author:		Ashish Verma
 * Title:		floyd warshall shortest path from all to all
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
		adjList[src].push_back(make_pair(dest, weight));
		if (!isDirected) {
			adjList[dest].push_back(make_pair(src, weight));
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

	void floydWarshall() {
		// init output array
		int distance[v][v];
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				if (i == j) {
					distance[i][j] = 0;
				} else {
					distance[i][j] = 9999999;
				}
			}
		}
		for (int u = 0; u < v; u++) {
			vector<pair<int, int> >::iterator it;
			for (it = adjList[u].begin(); it != adjList[u].end(); it++) {
				int v = it->first;
				int d = it->second;
				distance[u][v] = d;
			}
		}

		// floyd warshall stuff
		for (int k = 0; k < v; k++) {
			for (int i = 0; i < v; i++) {
				for (int j = 0; j < v; j++) {
					distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
				}
			}
		}

		for (int i = 0; i < v; i++) {
			cout << "Shortest paths from " << i << " are: " << endl;
			for (int j = 0; j < v; j++) {
				cout << "To " << j << " -> " << distance[i][j] << endl;
			}
			cout << endl;
		}

	}
};

int main() {

	graph g(9);
	g.insert(0, 1, 4);
	g.insert(0, 7, 8);
	g.insert(1, 2, 8);
	g.insert(1, 7, 11);
	g.insert(2, 3, 7);
	g.insert(2, 8, 2);
	g.insert(2, 5, 4);
	g.insert(3, 4, 9);
	g.insert(3, 5, 14);
	g.insert(4, 5, 10);
	g.insert(5, 6, 2);
	g.insert(6, 7, 1);
	g.insert(6, 8, 6);
	g.insert(7, 8, 7);

//	g.printGraph();
	g.floydWarshall();

	return 0;
}
