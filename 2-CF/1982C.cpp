#include <bits/stdc++.h> 
using namespace std;
#define pb push_back 
#define is insert
#define lb lower_bound
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
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

void tc () {
	ll N, l, r; cin >> N >> l >> r;
	V<ll> arr, pref = {0}, dp = {0, 0};
	f0r (i, 0, N) {
		ll a; cin >> a;
		arr.pb(a);
		pref.pb(a + pref[i]);
		dp.pb(0);
	}
	
	V<ll> rangenec;
	f0r (i, 0, N) {
		ll csum = pref[i];
		ll low = lb(all(pref), csum + l) - pref.begin();
		if (pref[low] <= (csum + r) && pref[low] >= (csum + l)) {
			rangenec.pb(low);
		}
		else {
			rangenec.pb(-1);
		}
	}
	
	f0r (i, 0, N) {
		dp[i + 1] = max(dp[i + 1], dp[i]); // SKIP
		if (rangenec[i] != -1) {
			dp[rangenec[i]] = max(dp[rangenec[i]], dp[i] + 1);
		}
	}
	cout << dp[N] << endl;
}

int main () {
	ll T; cin >> T;
	while (T --) {
		tc ();
	}
}