#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define lll long long
#define vl vector<lll>
#define sl set<lll>
#define msl multiset<lll>
#define pl pair<lll, lll>
#define vpl vector<pair<lll, lll>>
#define f0r(i, begin, end) for (lll i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;
int N;
ios_base::sync_with_stdio(0); cin.tie(nullptr);

// DIVISIBILITY

map<lll, lll> primefactorize(lll N) {
    map<lll, lll> primefactors;
    lll tester = 2, c;
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

vector<int> factor(int n) {
	vector<int> ret;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret.push_back(i);
			n /= i;
		}
	}
	if (n > 1) ret.push_back(n);
	return ret;
}

void SieveOfEratosthenes(int n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
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
	int weights[n]; for (int i = 0; i < n; i++) cin >> weights[i];
	bitset<1000001> possible;
	possible.set(0);
	for (int i = 0; i < n; i++) {
		bitset<1000001> temp = possible;
		temp <<= weights[i];
		possible = possible | temp;
	}
}

// LIS (LEAST INCREASING SUBSEQUENCE)

int find_lis(vector<int> a) {
	vector<int> dp;
	for (int i : a) {
		int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
		if (pos == dp.size()) {
			// we can have a new, longer increasing subsequence!
			dp.push_back(i);
		} else {
			// oh ok, at least we can make the ending element smalller
			dp[pos] = i;
		}
	}
	return dp.size();
}

lll min_lis (vector<lll> a) {
	vector<lll> A;
	for (auto x : a) {
		x = -x;
		if (A.empty() || x >= A.back()) {
		A.push_back(x);
		} else {
		*upper_bound(A.begin(), A.end(), x) = x;
		}
  	}
	return sz(A);
}

// MOD, COMBO

lll MOD = 1e9 + 7;

lll powermod(lll base, lll exp) {
	base %= MOD;
	lll result = 1;
	while (exp > 0) {
		if (exp % 2 == 1) // if n is odd
			result = result * base % MOD;
		base = base * base % MOD;
		exp /= 2; // divide by two
	}
	return result;
}

lll nPk(lll n, lll k) {
    lll c = 1;
    if(k == 0) return 1;
    for (int i = (n - k + 1); i <= n; i ++) {
        c = (c * i) % MOD;
    }
    return c;
}

lll nCk(lll n, lll k) {
    if(k == 0 || (n == k)) return 1;
    lll c = nPk(n, k);
    c = (c * powermod(nPk(k, k), MOD - 2));
    return c;
}

// TOPOLOGICAL SORT (Kahn)
queue<int> q;
int N, M, indegree[100000];
vector<int> conn[100000];
vector<int> sorted;
void ts () {
	f0r (i, 0, N) {
		if(indegree[i] == 0) q.push(i);
	}
	while(!q.empty()) {
		int pos = q.front();
		q.pop();
		sorted.pb(pos);
		for (auto c : conn[pos]) {
			if((--indegree[c]) == 0) q.push(c);
		}
	}
}

// DSU
struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x; return true;
	}
};

// DIJKSTRA'S

vector<pair<int, int>> conn[100000]; // location, distance
lll dist[100000];

void dijkstra(int src) {  // Updates dist, src = starting
	for (int i = 0; i < N; ++i) dist[i] = lllONG_MAX;
	
	using T = pair<lll, int>;
	priority_queue<T, vector<T>, greater<T>> pq;
	dist[src] = 0;  
	pq.push({0, src});

	while (pq.size()) {
		lll cdist;
		int node;
		tie(cdist, node) = pq.top();
		pq.pop();
		if (cdist != dist[node]) continue;
		for (pair<int, int> i : conn[node]) {
			if (cdist + i.second < dist[i.first]) {
				pq.push({dist[i.first] = cdist + i.second, i.first});
			}
		}
	}
}

// MST (krustal)
template <class T> T kruskal(int N, vector<pair<T, pair<int, int>>> edges) {
	sort(edges.begin(), edges.end());
	T ans = 0;
	DSU D(N + 1);  // edges that unite are in MST
	for (pair<T, pair<int, int>> &e : edges) {
		if (D.unite(e.second.first, e.second.second)) { ans += e.first; }
	}
	// -1 if the graph is not connected, otherwise the sum of the edge lengths
	return (D.size(1) == N ? ans : -1);
}

struct SegmentTree {
	/** The operation to use for combining two elements. (Must be associative)
	 */
	lll comb(lll a, lll b) { return a + b; }
	const lll DEFAULT = 1e18;  // Will overflow if T is an int

	vector<lll> segtree;
	lll leng;
	SegmentTree(lll leng) : leng(leng), segtree(leng * 2, DEFAULT) {}

	/** Sets the value at ind to val. */
	void set(lll ind, lll val) {
		assert(0 <= ind && ind < leng);
		ind += leng;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind >> 1] = comb(segtree[ind], segtree[ind ^ 1]);
		}
	}

	/** @return the minimum element in the range [start, end) */
	lll range_min(lll start, lll end) {
		assert(0 <= start && start < leng && 0 < end && end <= leng);
		lll sum = DEFAULT;
		for (start += leng, end += leng; start < end; start /= 2, end /= 2) {
			if ((start & 1) != 0) { sum = comb(sum, segtree[start++]); }
			if ((end & 1) != 0) { sum = comb(sum, segtree[--end]); }
		}
		return sum;
	}
};

int main () {
	int N; // number of vertices
	vector<pair<lll, pair<int, int>>> edges; // weight, start, end
	lll ans = krustal(N, edges);
}
