/*
 * Author:		Ashish Verma
 * Title:		basic trie implementation - init, insert, search
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

class node {
public:
	int val;
	node **children;

	node(int alphabetSize, int val = 0) {
		this->val = val;
		children = new node*[alphabetSize];
		for (int i = 0; i < alphabetSize; i++) {
			children[i] = NULL;
		}
	}
};

class trie {
	int count;
	int alphabetSize;
	node *root;

public:
	trie(int alphabetSize) {
		this->alphabetSize = alphabetSize;
		count = 0;
		root = new node(alphabetSize);
	}

	void insert(string s) {
		int len = s.length();
		node *p = root;
		for (int i = 0; i < len; i++) {
			if (p->children[s[i] - 'a'] == NULL) {
				p->children[s[i] - 'a'] = new node(alphabetSize);
			}
			p = p->children[s[i] - 'a'];
		}
		count++;
		p->val = count;
	}

	bool search(string s) {
		int len = s.length();
		node *p = root;
		for (int i = 0; i < len; i++) {
			if (p->children[s[i] - 'a'] == NULL) {
				return false;
			}
			p = p->children[s[i] - 'a'];
		}
		if (p->val) {
			return true;
		} else {
			return false;
		}
	}
};

int main() {
	string ar[] = { "the", "a", "there", "answer", "any", "by", "bye", "their" };
	int n = sizeof(ar) / sizeof(ar[0]);

	trie t(26);
	for (int i = 0; i < n; i++) {
		t.insert(ar[i]);
	}

	cout << t.search("bye");

	return 0;
}
