#include <bits/stdc++.h> 
using namespace std;
#define pb push_back 
#define is insert
#define ll long long
#define V vector
#define MS multiset
#define PL pair<int, int>
#define F first
#define S second
#define PQ priority_queue
#define f0r(i, begin, end) for (int i = begin; i < end; i ++) 
#define For(i, end, begin) for (int i = end; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000009
#define len(x) (int)x.size()
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

int N;
ll ans = 0;
set<int> nums;
int decomp[10000001];
vector<PL> edges[10000001];

void krustal () {
    int tot = N - 1;
    DSU dsu(N);
    f0r (i, 0, 10000001) {
        for (auto e : edges[i]) {
            if (dsu.unite(e.F, e.S)) {
                ans += i;
                if ((--tot) == 0) break;
            }
        }
        if (tot == 0) break;
    }
}

int main () {
    cin >> N;
    DSU dsu(N);
    f0r (i, 0, N) {
        int a; cin >> a;
        nums.is(a);
    }
    int i = 0;
    for (auto n : nums) {
        decomp[n] = (i ++);
    }

    for (auto n : nums) {
        auto pos = nums.lower_bound(n + 1);
        int factor = 1;
        while (pos != nums.end()) {
            if ((*pos) / n > factor) {
                factor = (*pos) / n;
            }
            edges[(*pos) % n].pb({decomp[n], decomp[*pos]});
            pos = nums.lower_bound((++factor) * n);
        }
    }
    
    krustal();
    cout << ans << endl;
}