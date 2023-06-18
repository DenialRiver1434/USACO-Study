#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, K;
// Since N, M <= 1e6, we cannot just use an array
vector<vector<ll>> grid, pref;

/**
 * @return the sum from (row1, column1) to (row2, column2)
 * Assumes row1 < row2 and column1 < column2
 */
ll rangesum(int row1, int column1, int row2, int column2) {
	// Sometimes, the range the mentor can reach goes outside the grid
	if (row1 < 0) { row1 = 0; }
	if (row2 >= N) { row2 = N - 1; }
	if (column1 < 0) { column1 = 0; }
	if (column2 >= M) { column2 = M - 1; }

	ll answer = 0;
	answer += pref[row2][column2];
	if (row1 > 0) { answer -= pref[row1 - 1][column2]; }
	if (column1 > 0) { answer -= pref[row2][column1 - 1]; }
	if (row1 > 0 && column1 > 0) { answer += pref[row1 - 1][column1 - 1]; }

	return answer;
}

/** @return whether the given distance will work */
bool test(int distance) {
	// Try centering the mentor at every room
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (grid[i][j] == 0) {
				// The mentor has to at least be able to stay in this room
				continue;
			}
			if (rangesum(i - distance, j - distance, i + distance,
			             j + distance) >= (K + 1)) {
				return true;
			}
		}
	}
	return false;
}

/** Binary search, adapted from the code in its module. */
int first_true(int lo, int hi) {
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
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M >> K;

		// Filling in the grid
		ll tot = 0;
		grid.clear();
		for (int i = 0; i < N; i++) {
			vector<ll> row;
			for (int j = 0; j < M; j++) {
				ll a;
				cin >> a;
				tot += a;
				row.push_back(a);
			}
			grid.push_back(row);
		}
		if (tot < (K + 1)) {  // Print -1 and go to next testcase if not enough
			                  // space in hotel
			cout << -1 << endl;
			continue;
		}

		// Setting up the size of the prefix sum array
		pref.clear();
		for (int i = 0; i < N; i++) { pref.push_back(vector<ll>(M)); }

		// Filling in the prefix sum array
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				pref[i][j] = grid[i][j];
				if (i > 0) { pref[i][j] += pref[i - 1][j]; }
				if (j > 0) { pref[i][j] += pref[i][j - 1]; }
				if (i > 0 && j > 0) { pref[i][j] -= pref[i - 1][j - 1]; }
			}
		}

		cout << first_true(0, max(N, M)) << endl;
	}
}