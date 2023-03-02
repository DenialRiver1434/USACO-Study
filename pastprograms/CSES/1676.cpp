#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

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
		e[x] += e[y]; e[y] = x; return true;
	}
};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int N, M; cin >> N >> M;
	DSU D = DSU(N);
	int comp = N, best = 1;
	f0r (i, 0, M) {
		int a, b; cin >> a >> b;
		a --; b --;
		if(!D.same_set(a, b)) {
			comp --;
			D.unite(a, b);
		}
		best = max(best, D.size(a));
		cout << comp << " " << best << endl;
	}
}
