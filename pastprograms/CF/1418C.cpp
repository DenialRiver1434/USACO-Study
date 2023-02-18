#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

void solve () {
	int N; cin >> N;
	if(N == 1) {
		int a; cin >> a;
		cout << a << endl;
		return;
	}
	int a, b; cin >> a >> b;
	vector<int> yy = {100000000, 100000000}, yf = {100000000, 100000000}, fy = {100000000, a}, ff = {100000000, a + b};
	for_loop (i, 2, N) {
		cin >> a;
		yy.pb(fy[i - 1]);
		yf.pb(a + min(yy[i - 1], fy[i - 1]));
		fy.pb(min(yf[i - 1], ff[i - 1]));
		ff.pb(a + yf[i - 1]);
	}
	cout << min({yy[N - 1], yf[N - 1], fy[N - 1], ff[N - 1]}) << endl;

}

int main () {
	int T; cin >> T;
	while (T --) {
		solve();
	}
}