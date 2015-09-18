/*
 * Author:		Ashish Verma
 * Title:		given sorted dictionary of alien language, print the order of alphabets
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

void topologicalSort(char start, map<char, vector<char> > vertex, map<char, bool> &visited,
		stack<char> &stk) {

	visited[start] = true;
	vector<char> curAdj = vertex[start];
	vector<char>::iterator it;
	for (it = curAdj.begin(); it != curAdj.end(); it++) {
		if (!visited[*it]) {
			topologicalSort(*it, vertex, visited, stk);
		}
	}
	stk.push(start);
}

void printTopologicalSorting(map<char, vector<char> > vertex) {
	map<char, bool> visited;
	map<char, vector<char> >::iterator it;
	for (it = vertex.begin(); it != vertex.end(); it++) {
		visited[it->first] = false;
	}

	stack<char> stk;

	for (it = vertex.begin(); it != vertex.end(); it++) {
		if (!visited[it->first]) {
			topologicalSort(it->first, vertex, visited, stk);
		}
	}

	while (!stk.empty()) {
		cout << stk.top() << " ";
		stk.pop();
	}
	cout << endl;
}

void printAlphabetOrder(string words[], int numOfWords) {
	map<char, vector<char> > vertex;

	for (int i = 0; i < numOfWords; i++) {
		for (unsigned int j = 0; j < words[i].length(); j++) {
			vertex[words[i][j]] = vector<char>();
		}
	}

	string word1, word2;
	for (int i = 0; i < numOfWords - 1; i++) {
		unsigned int j = 0;
		word1 = words[i];
		word2 = words[i + 1];
		while (j < word1.length() && j < word2.length() && word1[j] == word2[j]) {
			j++;
		}
		if (word1[j] != word2[j]) {
			vertex[word1[j]].push_back(word2[j]);
		}
	}

	printTopologicalSorting(vertex);
}

int main() {
	string ar[] = { "baa", "abcd", "abca", "cab", "cad" };
	int n = sizeof(ar) / sizeof(ar[0]);

	printAlphabetOrder(ar, n);

	return 0;
}
