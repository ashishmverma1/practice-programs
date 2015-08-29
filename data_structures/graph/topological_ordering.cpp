/*
 * Author:		Ashish Verma
 * Title:		print topological order
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

	void topologicalSort(int start, bool visited[], stack<int> &stk) {
		visited[start] = true;
		vector<int> curNode = adjList[start];
		for (vector<int>::iterator it = curNode.begin(); it != curNode.end(); it++) {
			if (!visited[*it]) {
				topologicalSort(*it, visited, stk);
			}
		}
		stk.push(start);
	}

	void printTopologicalOrder() {
		bool *visited = new bool[v];
		stack<int> stk;
		for (int i = 0; i < v; i++) {
			visited[i] = false;
		}
		for (int i = 0; i < v; i++) {
			if (!visited[i]) {
				topologicalSort(i, visited, stk);
			}
		}
		while (!stk.empty()) {
			cout << stk.top() << ' ';
			stk.pop();
		}
		cout << endl;
	}
};

int main() {

	graph g(6, true);
	g.insert(5, 2);
	g.insert(5, 0);
	g.insert(4, 0);
	g.insert(4, 1);
	g.insert(2, 3);
	g.insert(3, 1);

	g.printGraph();
	cout << endl;
	g.printTopologicalOrder();

	return 0;
}
