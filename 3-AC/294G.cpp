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

struct LCA {
    vector<ll> height, euler, first, segtree;
    vector<bool> visited;
    ll n;
 
    LCA(vector<vector<ll>> &adj, ll root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        ll m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }
 
    void dfs(vector<vector<ll>> &adj, ll node, ll h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }
 
    void build(ll node, ll b, ll e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            ll mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            ll l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }
 
    ll query(ll node, ll b, ll e, ll L, ll R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        ll mid = (b + e) >> 1;
 
        ll left = query(node << 1, b, mid, L, R);
        ll right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }
 
    ll lca(ll u, ll v) {
        ll left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

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
 
V<ll> start, finish, val, loc;
V<V<tuple<ll, ll, ll>>> conn;
V<V<ll>> mirconn;
ll timer = 0;
void euler_tour (ll pos, ll pre) {
	start[pos] = timer ++;
	for (auto c : conn[pos]) {
		if (get<0>(c) != pre) {
			euler_tour(get<0>(c), pos);
			val[get<0>(c)] = get<1>(c);
			loc[get<2>(c)] = get<0>(c);
		}
	}
	finish[pos] = timer;
}

int main () {
	fileread("promote");
	ll N; cin >> N;
    start = finish = val = loc = V<ll>(N);
	conn = V<V<tuple<ll, ll, ll>>>(N);
	mirconn = V<V<ll>>(N);
	
	val[0] = 0;
    f0r (i, 1, N) {
        ll a, b, c; cin >> a >> b >> c;
        mirconn[a - 1].pb(b - 1);
        mirconn[b - 1].pb(a - 1);
        conn[a - 1].pb({b - 1, c, i});
        conn[b - 1].pb({a - 1, c, i});
    }
    euler_tour (0, -1);

    SegmentTree segtree(N + 1);
	LCA lca(mirconn);
    f0r (i, 0, N) {
        segtree.set(start[i], val[i] + segtree.range(start[i], start[i] + 1));
        segtree.set(finish[i], -val[i] + segtree.range(finish[i], finish[i] + 1));
    }

	ll Q; cin >> Q;
	f0r (i, 0, Q) {
        ll typ; cin >> typ;
        if (typ == 1) {
            ll a, b; cin >> a >> b;
			a = loc[a];
			segtree.set(start[a], (b - val[a]) + segtree.range(start[a], start[a] + 1));
			segtree.set(finish[a], (val[a] - b) + segtree.range(finish[a], finish[a] + 1));
			val[a] = b;
        }
		else {
			ll a, b; cin >> a >> b;
			a --; b --;
			ll dista = segtree.range(0, start[a] + 1);
			ll distb = segtree.range(0, start[b] + 1);
			ll distc = segtree.range(0, start[lca.lca(a, b)] + 1);
			cout << dista + distb - 2 * distc << endl;
		}
	}
}