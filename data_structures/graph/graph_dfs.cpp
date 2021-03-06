/*
 * Author:		Ashish Verma
 * Title:		dfs on graph
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

	void printDfs(int startNode, set<int> *visited = new set<int>) {
		cout << startNode << ' ';
		vector<int> curNode = adjList[startNode];
		visited->insert(startNode);
		for (vector<int>::iterator it = curNode.begin(); it != curNode.end(); it++) {
			if (visited->find(*it) == visited->end()) {
				printDfs(*it, visited);
			}
		}
	}
};

int main() {

	graph g(7, true);

	g.insert(0, 1);
	g.insert(1, 2);
	g.insert(0, 3);
	g.insert(0, 4);
	g.insert(4, 5);
	g.insert(5, 6);

	g.printGraph();
	g.printDfs(0);

	return 0;
}
