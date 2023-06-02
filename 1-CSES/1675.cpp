#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;
 
ll N, M;
 
struct DSU {
	vector<ll> e;
	DSU(ll N) { e = vector<ll>(N, -1); }
 
	// get representive component (uses path compression)
	ll get(ll x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
 
	bool same_set(ll a, ll b) { return get(a) == get(b); }
 
	ll size(ll x) { return -e[get(x)]; }
 
	bool unite(ll x, ll y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x; return true;
	}
};
 
int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N >> M;
	DSU D = DSU(N + 1);
	vector<tuple<ll, ll, ll>> roads;
 
	f0r (i, 0, M) {
		ll a, b, c; cin >> a >> b >> c;
		roads.pb(mt(c, a, b));
	}
	sort(roads.begin(), roads.end());
 
	ll tc = 0;
	for (auto r : roads) {
		ll cost, start, end;
		tie(cost, start, end) = r;
		if(!D.same_set(start, end)) {
			tc += cost;
			D.unite(start, end);
		}
	}
	if(D.size(1) != N) cout << "IMPOSSIBLE" << endl;
	else cout << tc << endl;
}