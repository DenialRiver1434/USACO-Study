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
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

ll N, M, K, ans[300000];
V<tuple<ll, ll, ll, ll>> edges;
vector<DSU> dsu;

ll first_true (ll lo, ll hi, ll a, ll b) {
	hi++;
	while (lo < hi) {
		ll mid = lo + (hi - lo) / 2;
		if (!dsu[mid].same_set(a, b)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

void krustal () {
    f0r (i, 0, K) {
        dsu.pb(DSU(N));
    }

    ll tot = N - 1;
    sort(all(edges), greater<tuple<ll, ll, ll, ll>>());
    for (auto e : edges) {
        ll cost, a, b, ind;
        tie(cost, a, b, ind) = e;
        ll bpos = first_true(0, K - 1, a, b);
        if (bpos == K) ans[ind] = 0;
        else {
            ans[ind] = bpos + 1;
            dsu[bpos].unite(a, b);
        }
    }
}

int main () {
    cin >> N >> M >> K;
    f0r (i, 0, M) {
        ll a, b, c; cin >> a >> b >> c;
        edges.pb({c, a - 1, b - 1, i});
    }
    krustal ();
    f0r (i, 0, M) {
        cout << ans[i] << endl;
    }
}