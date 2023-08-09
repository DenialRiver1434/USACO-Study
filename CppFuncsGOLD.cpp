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
#define pq priority_queue
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

// ORDER STASTISTIC TREE (INDEXED SETS)
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DIVISIBILITY

map<ll, ll> primefactorize(ll N) {
    map<ll, ll> primefactors;
    ll tester = 2, c;
    while (N != 1) {
        c = 0;
        while ((tester * tester) <= N) {
            if((N % tester) == 0) {
                c = 0;
                while ((N % tester) == 0) {
                    N /= tester;
                    c ++;
                }
                primefactors[tester ++] = c;
                break;
            }
            tester ++;
        }
        if (!c) {
            primefactors[N] = 1;
            break;
        }
    }
    return primefactors;
}

// FACTORS

vector<ll> factor(ll n) {
	vector<ll> ret;
	for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret.push_back(i);
			n /= i;
		}
	}
	if (n > 1) ret.push_back(n);
	return ret;
}

void SieveOfEratosthenes(ll n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (ll p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

// KNAPSACK 
// Order does not matter -> Coins loop outside
// Else -> Space loop outside
// Infinite coins -> Space loop left to right
// 1 of each / multiple of each -> Space loop right to left

void knapsack () {
	ll weights[n]; for (ll i = 0; i < n; i++) cin >> weights[i];
	bitset<1000001> possible;
	possible.set(0);
	for (ll i = 0; i < n; i++) {
		bitset<1000001> temp = possible;
		temp <<= weights[i];
		possible = possible | temp;
	}
}

// LIS (LEAST INCREASING SUBSEQUENCE)

ll find_lis(vector<ll> a) {
	vector<ll> dp;
	for (ll i : a) {
		ll pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
		if (pos == dp.size()) {
			// we can have a new, longer increasing subsequence!
			dp.push_back(i);
		} else {
			// oh ok, at least we can make the ending element smaller
			dp[pos] = i;
		}
	}
	return dp.size();
}

ll min_lis (vector<ll> a) {
	vector<ll> A;
	for (auto x : a) {
		x = -x;
		if (A.empty() || x >= A.back()) {
		A.push_back(x);
		} else {
		*upper_bound(A.begin(), A.end(), x) = x;
		}
  	}
	return len(A);
}

// MOD, COMBO

ll MOD = 1e9 + 7;

ll powermod(ll base, ll exp) {
	base %= MOD;
	ll result = 1;
	while (exp > 0) {
		if (exp % 2 == 1) // if n is odd
			result = result * base % MOD;
		base = base * base % MOD;
		exp /= 2; // divide by two
	}
	return result;
}

ll nPk(ll n, ll k) {
    ll c = 1;
    if(k == 0) return 1;
    for (ll i = (n - k + 1); i <= n; i ++) {
        c = (c * i) % MOD;
    }
    return c;
}

ll nCk(ll n, ll k) {
    if(k == 0 || (n == k)) return 1;
    ll c = nPk(n, k);
    c = (c * powermod(nPk(k, k), MOD - 2));
    return c;
}

// TOPOLOGICAL SORT (Kahn)
queue<ll> q;
ll N, M, indegree[100000];
vector<ll> conn[100000];
vector<ll> sorted;
void ts () {
	f0r (i, 0, N) {
		if(indegree[i] == 0) q.push(i);
	}
	while(!q.empty()) {
		ll pos = q.front();
		q.pop();
		sorted.pb(pos);
		for (auto c : conn[pos]) {
			if((--indegree[c]) == 0) q.push(c);
		}
	}
}

// DSU
struct DSU {
	vector<ll> e;
	DSU(ll N) { e = vector<ll>(N, -1); }

	// get representive component (uses path compression)
	ll get(ll x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(ll a, ll b) { return get(a) == get(b); }

	ll size(ll x) { return -e[get(x)]; }

	bool unite(ll x, ll y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x; return true;
	}
};

// DIJKSTRA'S

vector<pair<ll, ll>> conn[100000]; // location, distance
ll dist[100000];

void dijkstra(ll src) {  // Updates dist, src = starting
	for (ll i = 0; i < N; ++i) dist[i] = LLONG_MAX;
	
	using T = pair<ll, ll>;
	priority_queue<T, vector<T>, greater<T>> pq;
	dist[src] = 0;  
	pq.push({0, src});

	while (pq.size()) {
		ll cdist;
		ll node;
		tie(cdist, node) = pq.top();
		pq.pop();
		if (cdist != dist[node]) continue;
		for (pair<ll, ll> i : conn[node]) {
			if (cdist + i.second < dist[i.first]) {
				pq.push({dist[i.first] = cdist + i.second, i.first});
			}
		}
	}
}

// MST (krustal)
template <class T> T kruskal(ll N, vector<pair<T, pair<ll, ll>>> edges) {
	sort(edges.begin(), edges.end());
	T ans = 0;
	DSU D(N + 1);  // edges that unite are in MST
	for (pair<T, pair<ll, ll>> &e : edges) {
		if (D.unite(e.second.first, e.second.second)) { ans += e.first; }
	}
	// -1 if the graph is not connected, otherwise the sum of the edge lengths
	return (D.size(1) == N ? ans : -1);
}

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

// STRING HASHING

const ll A = 257274504162904133, B = 1720921529140328231;
ll pref[1000005], powmod[1000005];
string S;
 
ll modmul (ll a, ll b) {
    __int128_t xa = a, xb = b;
    ll xm = (xa * xb) % B;
    if(xm < 0) xm += B;
    return xm;
}
 
void hsh (string s) {
    ll ls = len(s);
    pref[0] = s[0];
    powmod[0] = 1;
    f0r (i, 1, ls) {
        pref[i] = (modmul(pref[i - 1], A) + s[i]) % B;
        powmod[i] = modmul(powmod[i - 1], A);
    }
}
 
ll hashrange (ll a, ll b) {
    if(a == 0) {
        return pref[b - 1];
    }
    ll hs = (pref[b - 1] - modmul(pref[a - 1], powmod[b - a])) % B;
    if(hs < 0) hs += B;
    return hs;
}

// END

int main () {
	ll N; // number of vertices
}
