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
#define MOD 1000000009
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

V<ll> usednums;
vector<tuple<bool, ll, ll>> q; // true = query, false = change

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
            segtree.pb(0);
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
vector<ll> nums;
SegmentTree segtree(4000000);

int main () {
    ifstream fin; fin.open("walk.in");
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    fin >> N >> Q;
    f0r (i, 0, N) {
        ll a; fin >> a;
        usednums.pb(a);
        nums.pb(a);
    }
    f0r (i, 0, Q) {
        char typ; fin >> typ;
        ll a, b; fin >> a >> b;
        if(typ == '!') {
            q.pb({0, a - 1, b});
            usednums.pb(b);
        }
        else {
            q.pb({1, a, b + 1});
            usednums.pb(a);
            usednums.pb(b + 1);
        }
    }
    sort(all(usednums));

    f0r (i, 0, N) {
        nums[i] = lower_bound(all(usednums), nums[i]) - usednums.begin();
        segtree.set(nums[i], segtree.range(nums[i], nums[i] + 1) + 1);
    } 
    f0r (i, 0, Q) {
        if (get<0>(q[i]) == 0) {
            get<2>(q[i]) = lower_bound(all(usednums), get<2>(q[i])) - usednums.begin();
        }
        else {
            get<1>(q[i]) = lower_bound(all(usednums), get<1>(q[i])) - usednums.begin();
            get<2>(q[i]) = lower_bound(all(usednums), get<2>(q[i])) - usednums.begin();
        }
    }

    for (auto query : q) {
        bool typ; ll a, b;
        tie (typ, a, b) = query;
        if (typ) {
            cout << segtree.range(a, b) << '\n';
        }
        else {
            segtree.set(nums[a], segtree.range(nums[a], nums[a] + 1) - 1);
            segtree.set(b, segtree.range(b, b + 1) + 1);
        }
    }
}