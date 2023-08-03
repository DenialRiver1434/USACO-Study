#define pb push_back 
#define is insert
#define lb lower_bound
#define ll long long
#define V vector
#define MS multiset
#define PL pair<ll, ll>
#define F first
#define S second
#define pq priority_queue
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define For(i, end, begin) for (ll i = end; i > begin; i --) 
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000009
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
#include <bits/stdc++.h> 
using namespace std;

set<PL> adj; // degree, position
set<ll> conn[100001]; // 100001
map<ll, V<PL>> edges;
ll N, M, degree[100001];

ll r = 0;

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

void link (ll a, ll b) {
    if(adj.find({degree[a], a}) != adj.end()) {
        adj.erase(adj.find({degree[a], a}));
    }
    adj.is({degree[a] + 1, a});
    degree[a] ++;
    conn[a].is(b);
}

bool delink (ll a, ll b) {
    auto c = conn[a].find(b);
    if (c == conn[a].end()) return false;
    conn[a].erase(c);
    adj.erase(adj.find({degree[a], a}));
    degree[a] --;
    if(degree[a] > 0) {
        adj.is({degree[a], a});
    }
    return true;
}

void elim (ll pos) {
    vector<ll> tbd;
    for (auto c : conn[pos]) {
        tbd.pb(c);
    }
    for (auto c : tbd) {
        delink (pos, c);
        delink (c, pos);
        edges[r].pb({pos, c});
        edges[r].pb({c, pos});
        M --;
    }
}

int main () {
    cin >> N >> M;
    f0r (i, 0, M) {
        ll a, b; cin >> a >> b;  
        a --; b --;
        link (a, b);
        link (b, a);
    }

    while (M > 0) {
        r ++;
        while ((*adj.begin()).F <= r) {
            elim((*adj.begin()).S);
            if(M == 0) break;
        }
    }
    
    ll bestans = 0;
    DSU dsu(N);
    for (auto itr = edges.rbegin(); itr != edges.rend(); itr ++) {
        ll bestsize = 0;
        for (auto e : (*itr).S) {
            dsu.unite(e.F, e.S);
            bestsize = max(bestsize, dsu.size(e.F));
        }
        bestans = max(bestans, bestsize * (*itr).F);
    }
    cout << bestans << endl;
}