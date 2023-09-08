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

V<ll> start, finish, conn[200000];
ll timer = 0;
void euler_tour (ll pos, ll pre) {
	start[pos] = timer ++;
	for (auto c : conn[pos]) {
		if (c != pre) {
			euler_tour(c, pos);
		}
	}
	finish[pos] = timer;
}

int main () {
    ll N, Q; cin >> N >> Q; 
    start = finish = V<ll>(N);
    V<ll> val(N); cin >> val;
    f0r (i, 0, N - 1) {
        ll a, b; cin >> a >> b;
        conn[a - 1].pb(b - 1);
        conn[b - 1].pb(a - 1);
    }
    euler_tour (0, -1);

    SegmentTree segtree(N + 1);
    f0r (i, 0, N) {
        segtree.set(start[i], val[i] + segtree.range(start[i], start[i] + 1));
        segtree.set(finish[i], -val[i] + segtree.range(finish[i], finish[i] + 1));
    }

    f0r (i, 0, Q) {
        ll typ; cin >> typ;
        if (typ == 1) {
            ll a, b; cin >> a >> b;
            a --;
			segtree.set(start[a], (b - val[a]) + segtree.range(start[a], start[a] + 1));
			segtree.set(finish[a], (val[a] - b) + segtree.range(finish[a], finish[a] + 1));
			val[a] = b;
        }
		else {
			ll a; cin >> a;
			a --;
			cout << segtree.range(0, start[a] + 1) << endl;
		}
	}
}