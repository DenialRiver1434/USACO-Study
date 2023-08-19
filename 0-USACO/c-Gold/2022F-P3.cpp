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

ll cost (PL a, PL b) {
    return (a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S);
}

ll N, tot = 0;
V<PL> cows[11];

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

vector<tuple<ll, ll, ll>> edges, filtered;
void krustal () {
    ll tot = N - 1;
    DSU dsu(N);
    sort(all(edges));
    for (auto e : edges) {
        if (dsu.unite(get<1>(e), get<2>(e))) {
            filtered.pb(e);
            if ((--tot) == 0) break;
        }
    }
}

int main () {
    cin >> N;
    f0r (i, 0, N) {
        ll a, b; cin >> a >> b;
        cows[b].pb({a, i});
    }

    f0r (i, 0, 11) {
        sort(all(cows[i]));
        for (auto c : cows[i]) {
            ll curplace = c.F, curind = c.S;
            f0r (j, 0, i) {
                if(cows[j].empty()) continue;
                ll pos = lower_bound(all(cows[j]), c) - cows[j].begin();
                if (pos == len(cows[j])) {
                    pos --;
                    edges.pb({cost({i, curplace}, {j, cows[j][pos].F}), curind, cows[j][pos].S});
                }
                else {
                    edges.pb({cost({i, curplace}, {j, cows[j][pos].F}), curind, cows[j][pos].S});
                    if (pos > 0) {
                        pos --;
                        edges.pb({cost({i, curplace}, {j, cows[j][pos].F}), curind, cows[j][pos].S});
                    }
                }
            }

            ll bpos = lower_bound(all(cows[i]), c) - cows[i].begin();
            if ((bpos + 1) != len(cows[i])) {
                bpos ++;
                edges.pb({cost({i, curplace}, {i, cows[i][bpos].F}), curind, cows[i][bpos].S});
            }
        }
    }
    krustal();
    for (auto f : filtered) {
        tot += get<0>(f);
    }
    cout << tot << endl;
}