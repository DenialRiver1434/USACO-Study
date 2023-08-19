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
#define MOD 1000000009
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

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
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

ll tot = 0;
vector<tuple<ll, ll, ll>> edges;
DSU dsu(0);

void krustal (ll N) {
    ll rem = N - 1;
    sort(all(edges));
    for (auto e : edges) {
        if (dsu.unite(get<1>(e), get<2>(e))) {
            tot += get<0>(e);
            if ((--rem) == 0) break;
        }
    }
}

int main () {
    ll N;
    cin >> N;
    vector<ll> appeared (2 * N, -1);
    dsu = DSU(4 * N);

    f0r (i, 0, N) {
        ll cost, a, b, c, d; cin >> cost >> a >> b >> c >> d;
        a --; b --; c --; d --;

        if(appeared[a] >= 0) {
            dsu.unite(appeared[a], 4 * i);
        }
        else {
            appeared[a] = 4 * i;
        }

        if(appeared[b] >= 0) {
            dsu.unite(appeared[b], 4 * i + 1);
        }
        else {
            appeared[b] = 4 * i + 1;
        }

        if(appeared[c] >= 0) {
            dsu.unite(appeared[c], 4 * i + 2);
        }
        else {
            appeared[c] = 4 * i + 2;
        }
        
        if(appeared[d] >= 0) {
            dsu.unite(appeared[d], 4 * i + 3);
        }
        else {
            appeared[d] = 4 * i + 3;
        }
        edges.pb({0, 4 * i, 4 * i + 1});
        edges.pb({0, 4 * i + 2, 4 * i + 3});
        edges.pb({cost, 4 * i, 4 * i + 2});
        edges.pb({cost, 4 * i, 4 * i + 3});
        edges.pb({cost, 4 * i + 1, 4 * i + 2});
        edges.pb({cost, 4 * i + 1, 4 * i + 3});
    }
    
    krustal (2 * N);
    cout << tot << endl;
}