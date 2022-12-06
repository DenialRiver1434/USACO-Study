#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N;
ios_base::sync_with_stdio(0); cin.tie(nullptr);

int lowerbound(vector<int> array, int x){
    return lower_bound(array.begin(), array.end(), x) - array.begin();
}

ll first_true(ll lo, ll hi) {
	hi++;
	while (lo < hi) {
		ll mid = lo + (hi - lo) / 2;
		if (test(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

ll last_true(ll lo, ll hi) {
	lo--;
	while (lo < hi) {
		ll mid = lo + (hi - lo + 1) / 2;
		if (test(mid)) lo = mid;
		else hi = mid - 1;
	}
	return lo;
}

void twodcoordcomp() {
	int getCompressedIndex(int a, vector<int> indices) {
		return lower_bound(indices.begin(), indices.end(), a) - indices.begin();
	}
	int a, b;
	vector<int> xs, ys;
	vector<tuple<int, int>> inps, coords;

	for (int i = 0; i < N; i ++) {
		cin >> a >> b;
		int x = max(a, b), y = min(a, b);
		xs.pb(x);
		ys.pb(y);
		inps.pb(mt(x, y));
	}
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());

	for (auto pair : inps) {
		int cx = getCompressedIndex(get<0>(pair), xs), cy = getCompressedIndex(get<1>(pair), ys);
		coords.pb(mt(cx, cy));
	}
}

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

bool cmp(tuple<int, int> a, tuple<int, int> b) {
	return get<1>(a) < get<1>(b);
}
set<tuple<int, int>, decltype(cmp)*> alpha(cmp); // set custom compare