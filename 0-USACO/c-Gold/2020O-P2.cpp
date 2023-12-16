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
#define f0r(i, begin, finish) for (ll i = begin; i < finish; i ++) 
#define For(i, finish, begin) for (ll i = finish; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, pair<T, T>& a) {out << a.F << ", " << a.S << endl; return out;};
template<typename T> ostream& operator<<(ostream& out, tuple<T, T, T>& a) {out << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << endl; return out;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 2e5;
ll assign[MAX_N];

struct DSU {
	vector<PL> e;
	DSU(ll N) { e = vector<PL>(N, {-1, -1}); }

	// get representive component (uses path compression)
	ll get(ll x) { return e[x].F < 0 ? x : e[x].F = get(e[x].F); }

	bool same_set(ll a, ll b) { return get(a) == get(b); }

	ll size(ll x) { return -e[get(x)].F; }

	void unite(ll x, ll y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return;
		if (x > y) swap(x, y);
		e[x].F += e[y].F; e[y].F = x; // e[y] disappear
        if (e[y].S == -1) {
            return;
        }
        else if (e[x].S == -1) {
            e[x].S = e[y].S;
            e[y].S = -1;
        }
        else {
            // Both 1
            unite(e[x].S, e[y].S);
            e[y].S = -1;
        }
	}

    void set_tail (ll pos, ll t) {
        pos = get(pos);
        if (e[pos].S == -1) {
            e[pos].S = t;
        }
        else {
            unite(e[pos].S, t);
            e[pos].S = t;
        }
    }
};

V<ll> grouppos[MAX_N];

int main () {
    fileread("fcolor");

    ll N, M;
    fin >> N >> M;
    DSU dsu(N);

    f0r (i, 0, M) {
        ll a, b; fin >> a >> b;
        dsu.set_tail(a - 1, b - 1);
    }

    ll col = 1;
    f0r (i, 0, N) {
        ll npos = dsu.get(i);
        if (npos == i) {
            assign[i] = col ++;
        }
        else {
            assign[i] = assign[npos];
        }
        fout << assign[i] << endl;
    }
}
