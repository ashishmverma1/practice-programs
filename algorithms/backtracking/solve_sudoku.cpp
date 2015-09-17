/*
 * Author:		Ashish Verma
 * Title:		solve soduku given some cell values
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

const int n = 9;

void printBoard(int board[n][n]) {
	for (int i = 0; i < n; i++) {
		if (i && i % 3 == 0) {
			for (int j = 0; j < n + 2; j++) {
				cout << "--";
			}
			cout << endl;
		}
		for (int j = 0; j < n; j++) {
			if (j && j % 3 == 0) {
				cout << "| ";
			}
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

bool isSafe(int board[n][n], int x, int y, int num) {
	for (int i = 0; i < n; i++) {
		if (board[i][y] == num) {
			return false;
		}
	}
	for (int j = 0; j < n; j++) {
		if (board[x][j] == num) {
			return false;
		}
	}

	int cellStartI = floor(x / 3) * 3;
	int cellStartJ = floor(y / 3) * 3;
	for (int i = cellStartI; i < cellStartI + 3; i++) {
		for (int j = cellStartJ; j < cellStartJ + 3; j++) {
			if (board[i][j] == num) {
				return false;
			}
		}
	}

	return true;
}

bool solveSoDuKu(int board[n][n]) {
	bool cellFound = false;
	int i, j;
	for (i = 0; i < n && !cellFound; i++) {
		for (j = 0; j < n && !cellFound; j++) {
			if (board[i][j] == 0) {
				cellFound = true;
			}
		}
	}

	if (!cellFound) {
		printBoard(board);
		return true;
	} else {
		i--;
		j--;
		for (int num = 1; num <= 9; num++) {
			if (isSafe(board, i, j, num)) {
				board[i][j] = num;
				if (solveSoDuKu(board)) {
					return true;
				}
				board[i][j] = 0;
			}
		}
	}
	return false;
}
int main() {

	int grid[n][n] = {
			{3, 0, 6, 5, 0, 8, 4, 0, 0},
			{5, 2, 0, 0, 0, 0, 0, 0, 0},
			{0, 8, 7, 0, 0, 0, 0, 3, 1},
			{0, 0, 3, 0, 1, 0, 0, 8, 0},
			{9, 0, 0, 8, 6, 3, 0, 0, 5},
			{0, 5, 0, 0, 9, 0, 6, 0, 0},
			{1, 3, 0, 0, 0, 0, 2, 5, 0},
			{0, 0, 0, 0, 0, 0, 0, 7, 4},
			{0, 0, 5, 2, 0, 6, 3, 0, 0}
	};


	solveSoDuKu(grid);

	return 0;
}
