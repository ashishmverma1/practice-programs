/*
 * Author:		Ashish Verma
 * Title:		Given fixed T tanks and O abjects and their coordinates,
 * 				tell in which direction tank can fire so it doesnt hit any tank or object
 * 				If multiple directions possible, o/p direction with least ASCII
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

class tank {
public:
	int x, y;
	bool canFireE, canFireN, canFireS, canFireW;
	tank(int _x, int _y) {
		x = _x;
		y = _y;
		canFireE = canFireN = canFireS = canFireW = true;
	}
};

int main() {
	int t, o;
	cin >> t >> o;

	vector<tank> tanks;
	int x, y;

	cin >> x >> y;
	tanks.push_back(tank(x, y));

	for (int i = 1; i < t; i++) {
		cin >> x >> y;
		for (int j = 0; j < i; j++) {
			if (tanks[j].x == x) {
				if (tanks[j].y > y) {
					tanks[j].canFireS = false;
				} else {
					tanks[j].canFireN = false;
				}
			} else if (tanks[j].y == y) {
				if (tanks[j].x > x) {
					tanks[j].canFireW = false;
				} else {
					tanks[j].canFireE = false;
				}
			}
		}
		tanks.push_back(tank(x, y));
	}

	for (int i = 0; i < o; i++) {
		cin >> x >> y;
		for (int j = 0; j < t; j++) {
			if (tanks[j].x == x) {
				if (tanks[j].y > y) {
					tanks[j].canFireS = false;
				} else {
					tanks[j].canFireN = false;
				}
			} else if (tanks[j].y == y) {
				if (tanks[j].x > x) {
					tanks[j].canFireW = false;
				} else {
					tanks[j].canFireE = false;
				}
			}
		}
	}

	for (int i = 0; i < t; i++) {
		if (tanks[i].canFireE) {
			cout << "(" << tanks[i].x << ", " << tanks[i].y << ") E" << endl;
		} else if (tanks[i].canFireN) {
			cout << "(" << tanks[i].x << ", " << tanks[i].y << ") N" << endl;
		} else if (tanks[i].canFireS) {
			cout << "(" << tanks[i].x << ", " << tanks[i].y << ") S" << endl;
		} else if (tanks[i].canFireW) {
			cout << "(" << tanks[i].x << ", " << tanks[i].y << ") W" << endl;
		} else {
			cout << "Can't fire!" << endl;
		}
	}

	return 0;
}
