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

struct SegmentTree {
	ll leng;
	vector<ll> segtree;

	SegmentTree(ll leng) : leng(leng), segtree(leng * 2, DEFAULT) {}

	// Edit below
	ll comb(ll a, ll b) { return a + b; }
	const ll DEFAULT = 0; 
	// Edit above

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

int main() {
    ll N, Q; cin >> N >> Q;
	SegmentTree segtree(N);
	ll prev = 0;
	f0r (i, 0, N) {
		ll n; cin >> n;
		segtree.set(i, n - prev);
		prev = n;
	}
	f0r (i, 0, Q) {
		int typ; cin >> typ;
		if (typ == 1) {
			ll a, b, c; cin >> a >> b >> c;
			a --;
			segtree.set(a, segtree.range(a, a + 1) + c);
			if (b != N) { segtree.set(b, segtree.range(b, b + 1) - c); }
		}
		else {
			int x; cin >> x;
			cout << segtree.range(0, x) << endl;
		}
	}
}
