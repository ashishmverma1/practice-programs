/*
 * Author:		Ashish Verma
 * Title:		color a graph with minimum colors
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

	void colorGraph() {
		int color[v];
		for (int i = 0; i < v; i++) {
			color[i] = -1;
		}

		for (int i = 0; i < v; i++) {
			int curColor = 0;
			bool adjColors[v] = { false };
			for (unsigned int j = 0; j < adjList[i].size(); j++) {
				if (color[adjList[i][j]] != -1) {
					adjColors[color[adjList[i][j]]] = true;
				}
			}
			for (curColor = 0; curColor < v; curColor++) {
				if (!adjColors[curColor]) {
					break;
				}
			}
			color[i] = curColor;
		}

		for (int i = 0; i < v; i++) {
			cout << "Color of " << i << " is " << color[i] << endl;
		}
	}
};

int main() {

	graph g(9);
	g.insert(0, 1);
	g.insert(0, 7);
	g.insert(1, 2);
	g.insert(1, 7);
	g.insert(2, 3);
	g.insert(2, 8);
	g.insert(2, 5);
	g.insert(3, 4);
	g.insert(3, 5);
	g.insert(4, 5);
	g.insert(5, 6);
	g.insert(6, 7);
	g.insert(6, 8);
	g.insert(7, 8);

//	g.printGraph();
	g.colorGraph();

	return 0;
}
