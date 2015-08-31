/*
 * Author:		Ashish Verma
 * Title:		dijkstra's shortest path from start to all
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

	void dijkstra(int start) {
		// init min heap
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > heap;
		heap.push(make_pair(0, start));

		// init finalized set
		bool finalized[v] = { false };

		// init output array
		int distance[v];
		for (int i = 0; i < v; i++) {
			distance[i] = INT_MAX;
		}
		distance[start] = 0;

		while (!heap.empty()) {
			int u = heap.top().second;
			heap.pop();
			finalized[u] = true;

			vector<pair<int, int> >::iterator it;
			for (it = adjList[u].begin(); it != adjList[u].end(); it++) {
				int v = it->first;
				int uv = it->second;
				if (!finalized[v]) {
					distance[v] = min(distance[v], distance[u] + uv);
					heap.push(make_pair(distance[v], v));
				}
			}
		}

		cout << "Shortest paths from " << start << " are: " << endl;
		for (int i = 0; i < v; i++) {
			cout << "To " << i << " -> " << distance[i] << endl;
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
	g.dijkstra(0);

	return 0;
}
