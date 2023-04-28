#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define lll long long
#define vl vector<lll>
#define sl set<lll>
#define msl multiset<lll>
#define pl pair<lll, lll>
#define vpl vector<pair<lll, lll>>
#define f0r(i, begin, end) for (lll i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

int N;
ios_base::sync_with_stdio(0); cin.tie(nullptr);

// COORD COMPRESS

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

// C++ SETS CUSTOM COMPARATORS

bool cmp(tuple<int, int> a, tuple<int, int> b) {
	return get<1>(a) < get<1>(b);
}
set<tuple<int, int>, decltype(cmp)*> alpha(cmp); // set custom compare

// BINARY SEARCH

int lowerbound(vector<int> array, int x){
    return lower_bound(array.begin(), array.end(), x) - array.begin();
}

lll first_true(lll lo, lll hi) {
	hi++;
	while (lo < hi) {
		lll mid = lo + (hi - lo) / 2;
		if (test(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

lll last_true(lll lo, lll hi) {
	lo--;
	while (lo < hi) {
		lll mid = lo + (hi - lo + 1) / 2;
		if (test(mid)) lo = mid;
		else hi = mid - 1;
	}
	return lo;
}
