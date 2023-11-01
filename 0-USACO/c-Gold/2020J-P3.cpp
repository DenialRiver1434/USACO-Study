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

const ll MAX_P = 2e5 + 5;
ll N, P, best = 0;
V<pair<ll, PL>> starts[MAX_P], fins[MAX_P];

map<ll, ll> compx, compy;
V<ll> decompx, decompy;
map<PL, ll> dp;

struct SegmentTree {
	vector<ll> segtree;
	ll leng;
	
	// Edit below
	ll comb(ll a, ll b) { return max(a, b); }
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
    fileread("boards");

    fin >> N >> P;
    V<pair<PL, PL>> pos;
    f0r (i, 0, P) {
        ll a, b, c, d; 
        fin >> a >> b >> c >> d;
        decompx.pb(a); decompx.pb(c);
        decompy.pb(b); decompy.pb(d);
        pos.pb({{a, b}, {c, d}});
    }
    sort(all(decompx)); sort(all(decompy));

    P *= 2;
    f0r (i, 0, P) {
        compx[decompx[i]] = i;
        compy[decompy[i]] = i;
    }

    for (auto p : pos) {
        starts[compx[p.F.F]].pb({p.F.S, p.S});
        fins[compx[p.S.F]].pb({p.S.S, p.F});
        dp[p.S] = p.S.F + p.S.S;
    }

    SegmentTree segtree(P + 1);
    f0r (i, 0, P) {
        ll xpos = decompx[i];
        for (auto f : fins[i]) {
            ll ypos = f.F, px = f.S.F, py = f.S.S;
            segtree.set(compy[ypos], max(segtree.range(compy[ypos], compy[ypos] + 1), dp[{px, py}] + (xpos - px) + (ypos - py)));
            best = max(best, dp[{px, py}] + (xpos - px) + (ypos - py));
        }
        for (auto f : starts[i]) {
            ll ypos = f.F;
            dp[{xpos, ypos}] = max(dp[{xpos, ypos}], segtree.range(0, compy[ypos] + 1));
            best = max(best, dp[{xpos, ypos}]);
        }
    }
    fout << 2 * N - best << endl;
}