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
#define f0r(i, begin, finish) for (ll i = begin; i < finish; i ++) 
#define For(i, finish, begin) for (ll i = finish; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

struct SegmentTree {
	vector<ll> segtree;
	ll leng;
	
	// Edit below
	ll comb(ll a, ll b) { return a + b; }
	const ll DEFAULT = 0; 
	// Edit above
 
	SegmentTree(ll N) {
        leng = N;
        f0r (i, 0, 2 * N) {
            segtree.pb(DEFAULT);
        }
    }
 
	void set(ll ind, ll val) {
		ind += leng;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind >> 1] = comb(segtree[ind], segtree[ind ^ 1]);
		}
	}
 
	ll range(ll start, ll end) {
		ll sum = DEFAULT;
		for (start += leng, end += leng; start < end; start /= 2, end /= 2) {
			if ((start & 1) != 0) { sum = comb(sum, segtree[start++]); }
			if ((end & 1) != 0) { sum = comb(sum, segtree[--end]); }
		}
		return sum;
	}
};

ll N, Q;
V<ll> start, finish, depth;
V<V<ll>> conn, revdepth;
ll timer = 0;
void euler_tour (ll pos, ll pre) {
	start[pos] = timer ++;
	for (auto c : conn[pos]) {
		if (c != pre) {
			depth[c] = depth[pos] + 1;
			revdepth[depth[pos] + 1].pb(c);
			euler_tour(c, pos);
		}
	}
	finish[pos] = timer;
}

int main () {
	fileread("promote");
    fin >> N;
	start = finish = depth = V<ll>(N);
	conn = revdepth = V<V<ll>>(N);

	f0r (i, 1, N) {
		ll a; fin >> a;
		conn[a - 1].pb(i);
		conn[i].pb(a - 1);
	}
	depth[0] = 0;
	revdepth[0].pb(0);
	euler_tour(0, -1);

	fin >> Q;
	V<tuple<ll, ll, ll>> queries;
	V<ll> ans(Q);
	f0r (i, 0, Q) {
		ll a, b; fin >> a >> b;
		queries.pb({b, a - 1, i});
	}
	sort(all(queries));

	SegmentTree segtree(N + 1);
	ll predepth = -1;
	for (auto q : queries) {
		ll dep, pos, i;
		tie(dep, pos, i) = q;
		if (dep != predepth) {
			if (predepth >= 0) {
				for (auto p : revdepth[predepth]) {
					ll pd = start[p];
					segtree.set(pd, segtree.range(pd, pd + 1) - 1);
				}
			}
			for (auto p : revdepth[dep]) {
				ll pd = start[p];
				segtree.set(pd, segtree.range(pd, pd + 1) + 1);
			}
		}

		ans[i] = segtree.range(start[pos], finish[pos]);
		predepth = dep;
	}
	for (auto a : ans) {
		fout << a << endl;
	}
}