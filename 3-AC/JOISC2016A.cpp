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
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define For(i, end, begin) for (ll i = end; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 998244353
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0LL); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

bool comp (PL a, PL b) {
	if (a.F == b.F) return a.S > b.S;
	else return a.F < b.F;
}

V<V<ll>> dp;

ll first_true (ll x) {
	ll lo = 0, hi = len(dp);
	while (lo < hi) {
		ll mid = lo + (hi - lo) / 2;
		if (mid == len(dp)) {
			hi = mid;
		} else if (dp[mid][len(dp[mid]) - 1] < x) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main () {
	fastio;
	ll N, Q;
	cin >> N >> Q;

	V<PL> dolls;
	f0r (i, 0, N) {
		ll a, b;
		cin >> a >> b;
		dolls.pb({b, a});
	}
	sort(all(dolls), comp);
	
	V<tuple<ll, ll, ll>> queries;
	f0r (i, 0, Q) {
		ll a, b;
		cin >> a >> b;
		queries.pb({b, a, i});
	}
	sort(all(queries));

	ll i = 0;
	V<ll> ans(Q);
	for (auto q : queries) {
		ll mah, mid, pos; 
		tie(mah, mid, pos) = q;

		while (dolls[i].F <= mah && i < N) {
			ll loc = first_true(dolls[i].S);
			if (loc == len(dp)) {
				dp.pb({dolls[i].S});
			}
			else {
				dp[loc].pb(dolls[i].S);
			}
			i ++;
		}
		ans[pos] = first_true(mid);
	}
	for (auto a : ans) {
		cout << a << endl;
	}
}