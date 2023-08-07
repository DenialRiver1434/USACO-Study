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
#define pq priority_queue
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define For(i, end, begin) for (ll i = end; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000009
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); fin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

ll N, M, K, grid[500][500], tot = 0;
bool is_start[500][500];
vector<tuple<ll, ll, ll>> edges;

struct DSU {
	vector<PL> e;
	DSU (ll N, ll M) { 
        f0r (i, 0, N) {
            f0r (j, 0, M) {
                e.pb({is_start[i][j], -1});
            }
        }
    }

	// get representive component (uses path compression)
	ll get(ll x) { return e[x].S < 0 ? x : e[x].S = get(e[x].S); }

	bool same_set(ll a, ll b) { return get(a) == get(b); }

	ll size(ll x) { return -e[get(x)].S; }

	bool unite(ll x, ll y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x].S > e[y].S) swap(x, y);
		e[x].S += e[y].S;
		e[y].S = x;
        e[x].F += e[y].F;
		return true;
	}
};

int main () {
    fileread("skilevel");

    fin >> N >> M >> K;
    f0r (i, 0, N) {
        f0r (j, 0, M) {
            fin >> grid[i][j];
            if(i > 0) {
                edges.pb({abs(grid[i - 1][j] - grid[i][j]), i * M + j, (i - 1) * M + j});
            }
            if(j > 0) {
                edges.pb({abs(grid[i][j - 1] - grid[i][j]), i * M + j, i * M + j - 1});
            }
        }
    }
    f0r (i, 0, N) {
        f0r (j, 0, M) {
            fin >> is_start[i][j];
        }
    }

    DSU dsu(N, M);
    sort(all(edges));
    for (auto e : edges) {
        ll diff, start, end;
        tie(diff, start, end) = e;
        start = dsu.get(start), end = dsu.get(end);

        ll le = dsu.e[start].F * (dsu.size(start) < K) + dsu.e[end].F * (dsu.size(end) < K);
        dsu.unite(start, end);
        if(dsu.size(start) >= K) {
            tot += (le * diff);
        }
    }

    fout << tot << endl;
}