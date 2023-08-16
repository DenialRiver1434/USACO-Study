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
#define MOD 1000000009
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

ll N, M, A, B;
vector<tuple<ll, ll, ll, ll>> edges;

struct DSU {
	vector<ll> e;
	DSU(ll N) { e = vector<ll>(N, -1); }
    
    void reset(ll N) {
        e.clear();
        f0r (i, 0, N) e.pb(-1);
    }

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
DSU dsu(0);

bool test (double x) {
    dsu.reset(N);
    A = 0; B = 0;
    vector<tuple<double, ll, ll, ll, ll>> loc_edges;
    for (auto e : edges) {
        ll start, end, ai, bi; tie(start, end, ai, bi) = e;
        loc_edges.pb({(double)ai - x * (double)bi, start, end, ai, bi});
    }
    sort(all(loc_edges), greater<tuple<double, ll, ll, ll, ll>>());
    
    double tot = 0;
    for (auto l : loc_edges) {
        double weight; ll start, end, ai, bi;
        tie(weight, start, end, ai, bi) = l;
        if(dsu.unite(start, end)) {
            tot += weight;
            A += ai; 
            B += bi;
            if(dsu.size(start) == N) break;
        }
    }
    return tot > 0;
}

double last_true (double lo, double hi) {
    f0r (i, 0, 60) {
		double mid = (hi + lo) / 2;
		if (test(mid)) lo = mid;
		else hi = mid;
	}
	return lo;
}

ll mgcd (ll a, ll b) {
    if (a == 0) return b;
    return mgcd(b % a, a);
}

int main () {
    cin >> N >> M;
    f0r (i, 0, M) {
        ll a, b; cin >> a >> b;
        double ai, bi; cin >> ai >> bi;
        edges.pb({a, b, ai, bi});
    }
    test(last_true(0.009, 100.1));
    ll mg = mgcd(A, B);
    A /= mg; B /= mg;
    cout << A << "/" << B << endl;
}