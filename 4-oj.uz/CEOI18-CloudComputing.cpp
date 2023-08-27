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
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0LL); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 1e5+5;

ll best[2][MAX_N];
V<tuple<ll, ll, ll>> transactions;

bool comp (tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) {
	if (get<1>(a) == get<1>(b)) return get<0>(a) > get<0>(b);
	return get<1>(a) > get<1>(b);
}

int main () {
	fastio;
	ll N, M, ans = 0;
	cin >> N;
	f0r (i, 0, N) {
		ll a, b, c; cin >> a >> b >> c;
		transactions.pb({a, b, -c});
	}
	cin >> M;
	f0r (i, 0, M) {
		ll a, b, c; cin >> a >> b >> c;
		transactions.pb({-a, b, c});
	}
	sort(all(transactions), comp);
	
	best[1][0] = 0;
	f0r (i, 1, MAX_N) best[1][i] = -INF;
	f0r (i, 0, N + M) {
		ll core = get<0>(transactions[i]), value = get<2>(transactions[i]);
		f0r (j, 0, MAX_N) {
			best[i % 2][j] = best[(i + 1) % 2][j];
		}
		f0r (j, max(0LL, core), min(MAX_N, MAX_N + core)) {
			best[i % 2][j] = max(best[(i + 1) % 2][j], best[(i + 1) % 2][j - core] + value);
			ans = max(ans, best[i % 2][j]);
		}
	}
	cout << ans << '\n';
}