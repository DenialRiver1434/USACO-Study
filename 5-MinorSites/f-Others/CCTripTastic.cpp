#define ll long long // defining a macro to make code legible
#include <bits/stdc++.h>
using namespace std;

ll N, M, K;
vector<vector<ll>> grid, pref; // Since N, M <= 1e6, we cannot just use an array

ll rangesum (ll row1, ll column1, ll row2, ll column2) { // Requires row1 < row2; column1 < column2
    // We make this function to make applying prefix sums easier

    // Sometimes, the range of squares the mentor can reach goes outside the grid
    if (row1 < 0) row1 = 0;
    if (row2 >= N) row2 = N - 1;
    if (column1 < 0) column1 = 0;
    if (column2 >= M) column2 = M - 1;

    ll answer = 0;
    answer += pref[row2][column2];
    if (row1 > 0) {
        answer -= pref[row1 - 1][column2];
    }
    if (column1 > 0) {
        answer -= pref[row2][column1 - 1];
    }
    if (row1 > 0 && column1 > 0) {
        answer += pref[row1 - 1][column1 - 1];
    }
    return answer;
}

bool test (ll distance) { // Testing whether a certain distance will work
    // Test centering the mentor at every room
    for (ll i = 0; i < N; i ++) {
        for (ll j = 0; j < M; j ++) {
            if (grid[i][j] == 0) { // The mentor has to at least be able to stay in this room
                continue;
            } 
            if (rangesum(i - distance, j - distance, i + distance, j + distance) >= (K + 1)) {
                return true;
            }
        }
    }
    return false;
}

ll first_true(ll lo, ll hi) {
    // This binary search program is from the guide
	hi++;
	while (lo < hi) {
		ll mid = lo + (hi - lo) / 2;
		if (test(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

void solve () {
    cin >> N >> M >> K;

    // Filling in the grid
    ll tot = 0;
    grid.clear();
    for (ll i = 0; i < N; i ++) {
        vector<ll> row;
        for (ll j = 0; j < M; j ++) {
            ll a;
            cin >> a;
            tot += a;
            row.push_back(a);
        }
        grid.push_back(row);
    }
    if(tot < (K + 1)) {
        cout << -1 << endl;
        return ;
    }

    // Setting up the size of the prefix sum array
    pref.clear();
    for (ll i = 0; i < N; i ++) {
        vector<ll> row(M, 0);
        pref.push_back(row);
    }

    // Filling in the prefix sum array
    for (ll i = 0; i < N; i ++) {
        for (ll j = 0; j < M; j ++) {
            pref[i][j] = grid[i][j];
            if (i > 0) {
                pref[i][j] += pref[i - 1][j];
            }
            if (j > 0) {
                pref[i][j] += pref[i][j - 1];
            }
            if (i > 0 && j > 0) {
                pref[i][j] -= pref[i - 1][j - 1];
            }
        }
    }

    // Binary search for the answer (minimal = first true) and directly outputting it
    cout << first_true(0, max(N, M)) << endl;
}

int main () {
    ll T; 
    cin >> T;
    while (T --) {
        solve (); // solves each testcase
    }
}