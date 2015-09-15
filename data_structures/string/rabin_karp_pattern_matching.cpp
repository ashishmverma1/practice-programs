/*
 * Author:		Ashish Verma
 * Title:		rabin karp pattern matching
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

void rabinKarp(string text, string pattern) {
	int tLen = text.length();
	int pLen = pattern.length();

	int tHash = 0;
	int pHash = 0;

	const int prime = 101;
	const int charSet = 256;
	const int h = (int) pow(charSet, pLen - 1) % prime;

	for (int i = 0; i < pLen; i++) {
		pHash = (charSet * pHash + pattern[i]) % prime;
		tHash = (charSet * tHash + text[i]) % prime;
	}

	for (int i = 0; i <= tLen - pLen; i++) {

		if (pHash == tHash) {
			int j;
			for (j = 0; j < pLen; j++) {
				if (text[i + j] != pattern[j]) {
					break;
				}
			}
			if (j == pLen) {
				cout << "Match at: " << i << endl;
			}
		}

		if (i + pLen < tLen) {
			tHash = (charSet * (tHash - text[i] * h) + text[i + pLen]) % prime;
			if (tHash < 0) {
				tHash += prime;
			}
		}
	}

}

int main() {

	string s = "THIS IS A TEST TEXT FOR TESTING RABIN KARP";
	string p = "TEST";

	rabinKarp(s, p);

	return 0;
}
