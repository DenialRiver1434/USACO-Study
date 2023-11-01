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

const ll MAX_N = 1e5 + 5;

V<ll> conn[MAX_N];
ll N, M, appear[MAX_N];

ll TN;
V<PL> segtree;

PL f (PL a, PL b) {
    if (a.F < b.F) return a;
    else return b;
}

void set_val (ll pos, PL val) {
    pos += TN;
    segtree[pos] = val;
    while (pos > 1) {
        ll npos = pos / 2;
        if (pos % 2 == 0) {
            segtree[npos] = f(segtree[pos], segtree[pos + 1]);
        }
        else {
            segtree[npos] = f(segtree[pos], segtree[pos - 1]);
        }
        pos = npos;
    }
}

V<PL> sorder;

ll lca (ll x, ll y) {
    if (appear[x] > appear[y]) swap(x, y);
    ll start = appear[x], finish = appear[y] + 1;
    PL ans = {INF, -1};
    start += TN; finish += TN;
    while (start < finish) {
        if (start % 2 == 1) {
            ans = f(ans, segtree[start]);
            start ++;
        }
        if (finish % 2 == 1) {
            finish --;
            ans = f(ans, segtree[finish]);
        }
        start /= 2; finish /= 2;
    }
    return ans.S;
}

ll t1 = 0;
void dfs (ll pos, ll pre, ll d) {
    if (pos == 0) {
        TN = 2 * N;
        segtree = V<PL>(2 * TN, {INF, -1});
    }
    
    appear[pos] = t1;
    set_val(t1 ++, {d, pos});
    sorder.pb({d, pos});
    for (auto c : conn[pos]) {
        if (c != pre) {
            dfs (c, pos, d + 1);
            set_val(t1 ++, {d, pos});
            sorder.pb({d, pos});
        }
    }
}

ll start[MAX_N], finish[MAX_N], timer = 0;

void euler_tour (ll pos, ll pre) {
	start[pos] = timer ++;
	for (auto c : conn[pos]) {
		if (c != pre) {
			euler_tour(c, pos);
		}
	}
	finish[pos] = timer;
}

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

bool ans[MAX_N];
bool on[MAX_N];
V<ll> bycolor[MAX_N];
V<tuple<ll, ll, ll>> queries[MAX_N];

int main () {
    fileread("milkvisits");

    fin >> N >> M;
    f0r (i, 0, N) {
        ll a; fin >> a;
        bycolor[a].pb(i);
    }
    f0r (i, 1, N) {
        ll a, b; fin >> a >> b;
        conn[a - 1].pb(b - 1);
        conn[b - 1].pb(a - 1);
    }
    f0r (i, 0, M) {
        ll a, b, c; fin >> a >> b >> c;
        queries[c].pb({a - 1, b - 1, i});
    }
    dfs (0, -1, 0);
    euler_tour (0, -1);

    SegmentTree segtree (N + 2);
    f0r (col, 1, N + 1) {
        for (auto i : bycolor[col - 1]) {
            segtree.set(start[i], 0);
            segtree.set(finish[i], 0);
            on[i] = 0;
        }
        for (auto i : bycolor[col]) {
            segtree.set(start[i], segtree.range(start[i], start[i] + 1) + 1);
            segtree.set(finish[i], segtree.range(finish[i], finish[i] + 1) - 1);
            on[i] = 1;
        }
        for (auto q : queries[col]) {
            ll p1, p2, anspos;
            tie(p1, p2, anspos) = q;
            ll mpos = lca (p1, p2);
            ll dist1 = segtree.range(0, start[p1] + 1);
            ll dist2 = segtree.range(0, start[p2] + 1);
            ll dist3 = 2 * segtree.range(0, start[mpos] + 1);
            ans[anspos] = (dist1 + dist2 - dist3 + on[mpos]) > 0;
        }
    }

    f0r (i, 0, M) {
        fout << ans[i];
    }
}