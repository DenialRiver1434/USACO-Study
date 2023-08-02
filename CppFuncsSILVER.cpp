#define pb push_back 
#define is insert
#define lb lower_bound
#define ll long long
#define v(T) vector<T>
#define ms(T) multiset<T>
#define pl pair<ll, ll>
#define F first
#define S second
#define pq priority_queue
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define For(i, end, begin) for (ll i = end; i > begin; i --) 
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + (string)".in"); ofstream fout; fout.open((string)file + (string)".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
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

// FLOOD FILL PROCESSER
void process1 (ll x, ll y, ll dist) {
    if ((x < 0) || (y < 0) || (x >= N) || (y >= N) || grid[x][y] || walldist[x][y] != INF) {
        return;
    }
	walldist[x][y] = dist;
    q1.push({x, y});
}