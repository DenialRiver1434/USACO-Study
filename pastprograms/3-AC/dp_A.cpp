#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, K, a, grid[800][800], upto[800][800];

int count (int x1, int y1) {
	int x2 = x1 + K - 1, y2 = y1 + K - 1;
	int total = upto[x2][y2];
	if(x1 > 0) total -= upto[x1 - 1][y2];
	if(y1 > 0) total -= upto[x2][y1 - 1];
	if(x1 > 0 && y1 > 0) total += upto[x1 - 1][y1 - 1];
	return total;
}

bool test (int num) {
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			upto[i][j] = 0;
			if(grid[i][j] <= num) upto[i][j] ++;
			if(i > 0 && j > 0) {
				upto[i][j] += (upto[i - 1][j] + upto[i][j - 1] - upto[i - 1][j - 1]);
			}
			else if(i > 0) {
				upto[i][j] += upto[i - 1][j];
			}
			else if(j > 0) {
				upto[i][j] += upto[i][j - 1];
			}
		}
	}

	int bestcount = 0; // counts negative or 0
	for (int i = 0; i < (N - K + 1); i ++) {
		for (int j = 0; j < (N - K + 1); j ++) {
			int result = count(i, j);
			bestcount = max(bestcount, result);
		}
	}
	int minimum;
	if((K % 2) == 0) minimum = (K * K) / 2;
	else minimum = (K * K) / 2 + 1;
	return (bestcount >= minimum);
}

int first_true(int lo, int hi) { // False -> True, more negative the better
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (test(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main() {
	cin >> N >> K;
	int rhs = 0, lhs = 1e9;
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			cin >> a;
			rhs = max(rhs, a);
			lhs = min(lhs, a);
			grid[i][j] = a;
		}
	}
	cout << first_true(lhs, rhs);
}