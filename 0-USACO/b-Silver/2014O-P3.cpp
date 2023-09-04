// CODE IS FROM USACO.GUIDE

#include <bits/stdc++.h> 
using namespace std;
#define pb push_back 
#define is insert
#define ll long long
#define V vector
#define MS multiset
#define PL pair<ll, ll>
#define F first
#define S second
#define PQ priority_queue
#define f0r(i, begin, finish) for (ll i = begin; i < finish; i ++) 
#define For(i, finish, begin) for (ll i = finish; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

ll dp[19][50][2][2];
string num;

void reset() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 50; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) { dp[i][j][k][l] = -1; }
			}
		}
	}
}

ll solve_dp(int pos, int k, bool under, bool started, int targ, int targ2) {
	if (pos == num.size()) {
		if (!started) { return 0; }
		if (targ2 != -1) {
			if (k == 20) {
				return 1;
			} else {
				return 0;
			}
		}
		if (k >= 20) {
			return 1;
		} else {
			return 0;
		}
	}

	if (dp[pos][k][under][started] != -1) { return dp[pos][k][under][started]; }

	ll ans = 0;
	for (int i = 0; i <= 9; i++) {
		int digit_diff = num[pos] - '0';
		if (!under && i > digit_diff) { break; }

		bool is_under = under;
		if (i < digit_diff) { is_under = true; }

		bool is_started = started || i != 0;
		if (is_started && targ2 != -1 && i != targ && i != targ2) { continue; }

		int new_k = k;
		if (is_started) {
			if (targ == i) {
				new_k = k + 1;
			} else {
				new_k = k - 1;
			}
		}
		ans += solve_dp(pos + 1, new_k, is_under, is_started, targ, targ2);
	}
	return dp[pos][k][under][started] = ans;
}

ll count_interesting_to(ll ubound) {
	num = to_string(ubound);
	ll ans = 0;
	for (int i = 0; i <= 9; i++) {
		reset();
		ans += solve_dp(0, 20, false, false, i, -1);
	}
	ll duplicates = 0;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			reset();
			duplicates += solve_dp(0, 20, false, false, i, j);
		}
	}
	return ans - (duplicates / 2);
}

int main() {
	freopen("odometer.in", "r", stdin);
	freopen("odometer.out", "w", stdout);

	ll X, Y;
	cin >> X >> Y;
	cout << count_interesting_to(Y) - count_interesting_to(X - 1) << endl;
}