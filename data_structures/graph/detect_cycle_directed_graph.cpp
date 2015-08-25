/*
 * Author:		Ashish Verma
 * Title:		detect cycle in directed graph
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
	vector<int> *adjList;

public:
	graph(int v, bool isDirected = false) {
		this->v = v;
		this->isDirected = isDirected;
		adjList = new vector<int> [v];
	}

	void insert(int src, int dest) {
		adjList[src].push_back(dest);
		if (!isDirected) {
			adjList[dest].push_back(src);
		}
	}

	void printGraph() {
		for (int i = 0; i < v; i++) {
			cout << i << " -> ";
			for (unsigned int j = 0; j < adjList[i].size(); j++) {
				cout << adjList[i][j] << ' ';
			}
			cout << endl;
		}
	}

	bool cyclePresent(int startNode, set<int> *visited = new set<int>, vector<int> path = vector<int>()) {
		path.push_back(startNode);
		vector<int> curNode = adjList[startNode];
		visited->insert(startNode);

		for (vector<int>::iterator it = curNode.begin(); it != curNode.end(); it++) {
			if (find(path.begin(), path.end(), *it) != path.end()) {
				return true;
			}
			if (visited->find(*it) == visited->end() && cyclePresent(*it, visited, path)) {
				return true;
			}
		}
		return false;
	}

	bool cyclePresent() {
		for (int i = 0; i < v; i++) {
			if (cyclePresent(i)) {
				return true;
			}
		}
		return false;
	}
};

int main() {
	graph g(4, true);
	g.insert(0, 1);
	g.insert(0, 2);
	g.insert(1, 2);
	g.insert(2, 0);
	g.insert(2, 3);
	g.insert(3, 3);

	g.printGraph();
	cout << endl;
	cout << g.cyclePresent();

	return 0;
}
