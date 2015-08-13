/*
 * Author:		Ashish Verma
 * Title:		segment tree - build, update, sum of range
 *
 */

#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

#define debug(x) cout << endl << "DEBUG: " << x << endl

using namespace std;

int buildSegmentTreeUtil(int ar[], int *segmentTree, int sStart, int sEnd, int sIndex) {
	if (sStart == sEnd) {
		segmentTree[sIndex] = ar[sStart];
		return segmentTree[sIndex];
	}
	int mid = (sStart + sEnd) / 2;
	segmentTree[sIndex] = buildSegmentTreeUtil(ar, segmentTree, sStart, mid, 2 * sIndex + 1)
			+ buildSegmentTreeUtil(ar, segmentTree, mid + 1, sEnd, 2 * sIndex + 2);
	return segmentTree[sIndex];
}

int* buildSegmentTree(int ar[], int n) {
	int height = ceil(log2(n));
	int numOfNodes = 2 * (int) pow(2, height) - 1;
	int *segmentTree = new int(numOfNodes);
	buildSegmentTreeUtil(ar, segmentTree, 0, n - 1, 0);
	return segmentTree;
}

int getSumOfRange(int *segmentTree, int sStart, int sEnd, int qStart, int qEnd, int sIndex) {
	if (qStart <= sStart && sEnd <= qEnd) {
		return segmentTree[sIndex];
	}
	if (sEnd < qStart || sStart > qEnd) {
		return 0;
	}

	int mid = (sStart + sEnd) / 2;
	return getSumOfRange(segmentTree, sStart, mid, qStart, qEnd, 2 * sIndex + 1)
			+ getSumOfRange(segmentTree, mid + 1, sEnd, qStart, qEnd, 2 * sIndex + 2);
}

void updateValueUtil(int *segmentTree, int sStart, int sEnd, int sIndex, int arIndex, int diff) {
	if (arIndex < sStart || sEnd < arIndex) {
		return;
	}
	segmentTree[sIndex] += diff;
	if (sStart != sEnd) {
		int mid = (sStart + sEnd) / 2;
		updateValueUtil(segmentTree, sStart, mid, 2 * sIndex + 1, arIndex, diff);
		updateValueUtil(segmentTree, mid + 1, sEnd, 2 * sIndex + 2, arIndex, diff);
	}
}

void updateValue(int ar[], int n, int arIndex, int value, int *segmentTree) {
	int diff = value - ar[arIndex];
	ar[arIndex] = value;
	updateValueUtil(segmentTree, 0, n - 1, 0, arIndex, diff);
}

int main() {

	int n;
	cin >> n;
	int ar[n];

	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	int *segmentTree = buildSegmentTree(ar, n);
	cout << getSumOfRange(segmentTree, 0, n - 1, 2, 2, 0) << endl;
	updateValue(ar, n, 2, 10, segmentTree);
	cout << getSumOfRange(segmentTree, 0, n - 1, 2, 2, 0) << endl;

	return 0;
}
