/*
 * Author:		Ashish Verma
 * Title:		print chess knight tour path such that a knight traverses all cells
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

const int n = 8;

void printBoard(int board[n][n]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%2d ", board[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}

bool solveKnightTour(int row = 0, int col = 0, int freeCellCount = n * n - 1) {
	static int board[n][n] = { 0 };
	board[0][0] = 1;

	if (freeCellCount == 0) {
		printBoard(board);
		return true;
	} else {
		int x, y;
		for (int i = -2; i <= 2; i++) {
			for (int j = -2; j <= 2; j++) {

				x = row + i;
				y = col + j;

				if ((abs(row - x) == 2 && abs(col - y) == 1)
						|| (abs(row - x) == 1 && abs(col - y) == 2)) {

					if (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == 0) {
						board[x][y] = board[row][col] + 1;
						if (solveKnightTour(x, y, freeCellCount - 1)) {
							return true;
						}
						board[x][y] = 0;
					}

				}

			}
		}
		return false;
	}
}

int main() {

	solveKnightTour();

	return 0;
}
