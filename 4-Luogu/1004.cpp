#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define vl vector<ll>
#define sl set<ll>
#define msl multiset<ll>
#define pl pair<ll, ll>
#define vpl vector<pair<ll, ll>>
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

string S; 
ll N, ogrid[9][9], ngrid[9][9], dp[9][9], cur, best = 0;
vector<string> paths;

void gpath (ll x, ll y, string tfar) {
	if((x == (N - 1)) && (y == (N - 1))) {
		paths.pb(tfar);
		return;
	}
	if((x == N) || (y == N)) return;

	gpath (x + 1, y, tfar + 'd');
	gpath (x, y + 1, tfar + 'r');
}

void test (string p) {
	cur = 0;
	f0r (i, 0, N) {
		f0r (j, 0, N) {
			ngrid[i][j] = ogrid[i][j];
			dp[i][j] = 0;
		}
	}
	ll x = 0, y = 0;
	cur += ngrid[x][y]; ngrid[x][y] = 0;
	for (auto ch : p) {
		if(ch == 'd') {
			x ++;
			cur += ngrid[x][y]; ngrid[x][y] = 0;
		}
		else {
			y ++;
			cur += ngrid[x][y]; ngrid[x][y] = 0;
		}
	}
	f0r (i, 0, N) {
		f0r (j, 0, N) {
			if(i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if(j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			dp[i][j] += ngrid[i][j];
		}
	}

	best = max(cur + dp[N - 1][N - 1], best);
}

int main () {
	cin >> N;
	while (true) {
		ll a, b, c; cin >> a >> b >> c;
		if((a == 0) && (b == 0) && (c == 0)) break;
		ogrid[a - 1][b - 1] = c;
	}
	gpath(0, 0, "");
	for (auto p : paths) {
		test(p);
	}
	cout << best << endl;
}
