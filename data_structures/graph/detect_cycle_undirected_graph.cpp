/*
 * Author:		Ashish Verma
 * Title:		detect cycle in undirected graph
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

	bool cyclePresent(int startNode, bool visited[], int parentNode = -1) {
		vector<int> curNode = adjList[startNode];
		visited[startNode] = true;

		for (vector<int>::iterator it = curNode.begin(); it != curNode.end(); it++) {
			if (!visited[*it]) {
				if (cyclePresent(*it, visited, startNode)) {
					return true;
				}
			} else if (*it != parentNode) {
				return true;
			}
		}
		return false;
	}

	bool cyclePresent() {
		bool *visited = new bool[v];
		for (int i = 0; i < v; i++) {
			visited[i] = false;
		}
		for (int i = 0; i < v; i++) {
			if (!visited[i] && cyclePresent(i, visited)) {
				return true;
			}
		}
		return false;
	}
};

int main() {

	graph g(7);
	g.insert(0, 1);
	g.insert(1, 2);
	g.insert(0, 3);
	g.insert(0, 4);
	g.insert(3, 5);
	g.insert(4, 5);
	g.insert(5, 6);

	g.printGraph();
	g.printDfs(0);
	cout << endl;
	cout << g.cyclePresent();

	return 0;
}
