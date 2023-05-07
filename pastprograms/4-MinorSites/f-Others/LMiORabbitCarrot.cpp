#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define f0r(i, begin, n) for (ll i = begin; i < n; i ++)
#define len(x) x.length()
#define sz(x) x.size()
#include <bits/stdc++.h>
using namespace std;

int main () {
	ifstream fin; ofstream fout;
	fin.open("cowjog.in"); fout.open("cowjog.out");

	ll N, M; cin >> N >> M;
	vector<ll> lis = {0};
	f0r (i, 1, N + 1) {
		ll a; cin >> a;
		a -= M * i;
		lis.pb(-a);
	}
	
	vector<ll> dp;
	for (ll i : lis) {
		if(i < 0) {
			continue;
		}
		ll pos = upper_bound(dp.begin(), dp.end(), i) - dp.begin();
		if (pos == dp.size()) {
			// we can have a new, longer increasing subsequence!
			dp.push_back(i);
		} else {
			// oh ok, at least we can make the ending element smaller
			dp[pos] = i;
		}
	}
	cout << N - dp.size() + 1 << endl;
}