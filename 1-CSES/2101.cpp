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

struct DSU {
	V<pair<int, int>> e;
	DSU(int N) { e = V<pair<int, int>>(N, {0, -1}); }

	// get representive component (uses path compression)
	int get(int x) { return e[x].S < 0 ? x : get(e[x].S); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)].S; }

	bool unite(int x, int y, int t) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x].S > e[y].S) swap(x, y);
		e[x].S += e[y].S;
		e[y] = {t, x};
		return true;
	}
};

int main () {
    fastio;
    int N, M, Q;
	cin >> N >> M >> Q;
	DSU dsu(N);

	f0r (i, 1, M + 1) {
        int a, b; cin >> a >> b;
		dsu.unite(a - 1, b - 1, i);
	}

    f0r (i, 0, Q) {
        int a, b; cin >> a >> b; 
        a --; b --;
        if(dsu.get(a) == dsu.get(b)) {
            map<int, int> timechange;
            timechange[a] = 0;
            while (dsu.e[a].S >= 0) {
                timechange[a = dsu.e[a].S] = dsu.e[a].F;
            }

            if(timechange.find(b) != timechange.end()) {
                cout << timechange[b] << endl;
                continue;
            }
            while (dsu.e[b].S >= 0) {
                int time;
                tie(time, b) = dsu.e[b];
                if(timechange.find(b) != timechange.end()) {
                    cout << max(timechange[b], time) << endl;
                    break;
                }
            }
        }
        else cout << -1 << endl;
    }
}