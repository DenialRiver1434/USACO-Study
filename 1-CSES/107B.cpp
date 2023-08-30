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

ll N;
V<PL> times;

int main () {
	cin >> N;
    f0r (i, 0, N) {
        ll a, b; cin >> a >> b;
        times.pb({a - b, -a - b});
    }
	sort(all(times));

	vector<tuple<ll, ll, ll>> ans;
	vector<ll> dp;
	for (auto p : times) {
		ll x = p.F, i = -p.S;
		ll pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
		if (pos == dp.size()) {
			dp.push_back(i);
		} else {
			dp[pos] = i;
		}
		
		ans.pb({(x + i) / 2, (i - x) / 2, pos + 1});
	}
	cout << len(dp) << endl;
	for (auto a : ans) {
		cout << get<0>(a) << " " << get<1>(a) << " " << get<2>(a) << endl;
	}
}