/*
 * Author:		Ashish Verma
 * Title:		print all n-queen solutions
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

const int n = 4;
unsigned long long int solCount = 0;

bool isSafe(bool board[n][n], int x, int y) {
	for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j]) {
			return false;
		}
	}
	for (int i = x, j = y; i >= 0 && j < n; i--, j++) {
		if (board[i][j]) {
			return false;
		}
	}
	for (int i = x; i >= 0; i--) {
		if (board[i][y]) {
			return false;
		}
	}
	return true;
}

void printBoard(bool board[n][n]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j]) {
				cout << "X ";
			} else {
				cout << ". ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void solveNQueen(int row = 0) {
	static bool board[n][n] = { false };

	if (row >= n) {
		printBoard(board);
		solCount++;
	} else {
		for (int j = 0; j < n; j++) {
			if (isSafe(board, row, j)) {
				board[row][j] = true;
				solveNQueen(row + 1);
				board[row][j] = false;
			}
		}
	}
}

int main() {

	solveNQueen();
	cout << "Solution Count: " << solCount << endl;

	return 0;
}
