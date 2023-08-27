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
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define For(i, end, begin) for (ll i = end; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0LL); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

struct SegmentTree {
	vector<ll> segtree;
	ll leng;
	
	// Edit below
	ll comb(ll a, ll b) { return (a + b) % MOD; }
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

V<PL> nums;
ll N;

int main () {
	cin >> N;
	V<PL> alt;
	f0r (i, 0, N) {
		ll a; cin >> a;
		alt.pb({a, i});
		nums.pb({a, i});
	}
	sort(all(alt));
	V<PL> copier;
	f0r (i, 0, N) {
		copier.pb({nums[i].F, lower_bound(all(alt), nums[i]) - alt.begin()});
		nums[i] = {lower_bound(all(alt), nums[i]) - alt.begin(), nums[i].F};
	}
	sort(all(copier));
	
	SegmentTree segtree(N);
	ll tot = 0;
	for (auto nU : nums) {
		ll n = nU.F, disc = nU.S;
		auto tpos = lower_bound(all(copier), make_pair(disc, -1LL)) - copier.begin();
		ll new_val = segtree.range(0, tpos) + 1;
		tot += new_val;
		tot %= MOD;
		segtree.set(n, new_val);
	}
	cout << tot << endl;
}