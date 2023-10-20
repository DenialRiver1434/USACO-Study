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
#define PQ priority_queue
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define For(i, end, begin) for (ll i = end; i > begin; i --) 
#define all(X) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000009
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

int N;
ios_base::sync_with_stdio(0); cin.tie(nullptr);

// COORD COMPRESS

void twodcoordcomp() {
	vector<ll> xs, ys;
	vector<PL> inps;
	for (int i = 0; i < N; i ++) {
	    ll a, b;
		cin >> a >> b;
		xs.pb(a); ys.pb(b);
		inps.pb({a, b});
	}
	sort(all(xs));
	sort(all(ys));

	for (auto pair : inps) {
		ll cx = lower_bound(all(xs), pair.F) - xs.begin(), cy = lower_bound(all(ys), pair.S) - ys.begin();
        if (seen[cx][cy]) continue;
        seen[cx][cy] = 1;
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