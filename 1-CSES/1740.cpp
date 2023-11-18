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
// #define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 5e5;

ll N, tot = 0;
map<ll, ll> hori[MAX_N];
V<PL> vert[MAX_N];

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

int main () {
    V<ll> nums;
    V<tuple<ll, ll, ll, ll>> locs;

    cin >> N;
    f0r (i, 0, N) {
        ll x1, x2, y1, y2; 
        cin >> x1 >> y1 >> x2 >> y2;
        nums.pb(x1);
        nums.pb(x2);
        nums.pb(y1);
        nums.pb(y2);
        locs.pb({x1, y1, x2, y2});
    }
    sort(all(nums));

    N *= 4;
    for (auto l : locs) {
        ll x1, y1, x2, y2; tie(x1, y1, x2, y2) = l;
        x1 = lower_bound(all(nums), x1) - nums.begin();
        x2 = lower_bound(all(nums), x2) - nums.begin();
        y1 = lower_bound(all(nums), y1) - nums.begin();
        y2 = lower_bound(all(nums), y2) - nums.begin();
        
        if (x1 == x2) {
            vert[x1].pb({y1, y2});
        }
        else {
            hori[x1][y1] ++;
            hori[x2][y1] --;
        }
    }

    SegmentTree segtree(N);
    f0r (i, 0, N) {
        for (auto h : hori[i]) {
            segtree.set(h.F, segtree.range(h.F, h.F + 1) + h.S);
        }
        for (auto v : vert[i]) {
            tot += segtree.range(v.F, v.S);
        }
    }

    cout << tot << endl;
}
