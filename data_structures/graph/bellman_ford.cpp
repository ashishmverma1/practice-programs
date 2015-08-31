/*
 * Author:		Ashish Verma
 * Title:		bellman ford shortest path from start to all, detecting negative edge
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

	void bellmanFord(int start) {
		// init output array
		int distance[v];
		for (int i = 0; i < v; i++) {
			distance[i] = 9999999;
		}
		distance[start] = 0;

		bool containsNegativeEdge = false;

		// repeat V - 1 times
		for (int i = 0; i < v - 1; i++) {
			// select vertex
			for (int j = 0; j < v; j++) {
				// select edges from that vertex
				int u = j;
				vector<pair<int, int> >::iterator it;
				for (it = adjList[j].begin(); it != adjList[j].end(); it++) {
					int v = it->first;
					int d = it->second;
					distance[v] = min(distance[v], distance[u] + d);
				}
			}
		}

		// repeat one more time to check if there is a negetive edge
		for (int j = 0; j < v && !containsNegativeEdge; j++) {
			// select edges from that vertex
			int u = j;
			vector<pair<int, int> >::iterator it;
			for (it = adjList[j].begin(); it != adjList[j].end(); it++) {
				int v = it->first;
				int d = it->second;
				if (distance[v] > distance[u] + d) {
					containsNegativeEdge = true;
					break;
				}
			}
		}

		if (containsNegativeEdge) {
			cout << "Negative edge present!" << endl;
		} else {
			cout << "Shortest paths from " << start << " are: " << endl;
			for (int i = 0; i < v; i++) {
				cout << "To " << i << " -> " << distance[i] << endl;
			}
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
	g.bellmanFord(0);

	return 0;
}
