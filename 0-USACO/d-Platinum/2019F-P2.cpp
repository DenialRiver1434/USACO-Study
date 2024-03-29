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
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 1505;

ll N, M, X, Y;
V<PL> roads[MAX_N];
V<V<ll>> groups;

ll dist[MAX_N][MAX_N];

// Functions

ll fact[MAX_N];

ll powermod (ll base, ll exp, ll mod = MOD) {
	base %= mod;
	ll result = 1;
	while (exp > 0) {
		if (exp % 2 == 1) // if n is odd
			result = result * base % mod;
		base = base * base % mod;
		exp /= 2; // divide by two
	}
	return result;
}

// Find grups dfs
bool searched[MAX_N];
V<ll> tempgroup;
void dfs1 (ll pos) {
	if (searched[pos]) return;
	searched[pos] = 1;
	tempgroup.pb(pos);
	for (auto r : roads[pos]) {
		dfs1(r.F);
	}
}

// Find distance dfs
void dfs2 (ll pos, ll stt, ll d) {
	if (dist[stt][pos] != -1) return;
	dist[stt][pos] = d;
	for (auto r : roads[pos]) {
		dfs2 (r.F, stt, d + r.S);
	}
}

int main () {
    fileread("mooriokart");

	fin >> N >> M >> X >> Y;
	f0r (i, 0, M) {
		ll a, b, c; fin >> a >> b >> c;
		a --; b --;
		roads[a].pb({b, c});
		roads[b].pb({a, c});
	}

    fact[0] = 1;
    f0r (i, 1, MAX_N) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

	// Generate groups
	f0r (i, 0, N) {
		tempgroup.clear();
		dfs1(i);
		if (!tempgroup.empty()) {
			groups.pb(tempgroup);
		}
	}

	memset(dist, -1, sizeof(dist));

	f0r (i, 0, N) {
		dfs2 (i, i, 0);
	}

	ll K = len(groups), alldist = 0, totway = 1;
	// Calculate total distance
    for (auto g : groups) {
        ll lg = len(g), tot = 0, cnt = 0;
        f0r (i, 0, lg) {
            f0r (j, i + 1, lg) {
                tot += 2 * dist[g[i]][g[j]];
                cnt += 2;
            }
        }
        // We take the average
        tot *= powermod(cnt, MOD - 2);
        tot %= MOD;
        alldist += (tot + X);
        alldist %= MOD;
        totway *= cnt;
        totway %= MOD;
    }

    alldist *= fact[K - 1];
    alldist %= MOD;
    alldist *= powermod(2, MOD - 2);
    alldist %= MOD;
    alldist *= totway;
    alldist %= MOD;
    
    // Calculate distance (strictly) under Y
    Y -= K * X;
    ll dp[2][2505], cur[2505], csum;
    dp[1][0] = 1;
    f0r (gr, 0, K) {
        f0r (i, 0, Y) {
            cur[i] = 0;
        }
        memset(dp[gr % 2], 0, sizeof(dp[gr % 2]));

        ll lg = len(groups[gr]);
        f0r (i, 0, lg) {
            f0r (j, 0, lg) {
                if (i == j) continue;
                ll t = dist[groups[gr][i]][groups[gr][j]];
                if (t < Y) {
                    cur[t] ++;
                }
            }
        }

        f0r (ndist, 0, Y) {
            f0r (pdist, 0, Y - ndist) {
                dp[gr % 2][pdist + ndist] += dp[(gr + 1) % 2][pdist] * cur[ndist];
                dp[gr % 2][pdist + ndist] %= MOD;
            }
        }
        csum = 0;
        f0r (i, 0, Y) {
            csum += (i + K * X) * dp[gr % 2][i];
            csum %= MOD;
        }
    }

    csum *= fact[K - 1];
    csum %= MOD;
    csum *= powermod(2, MOD - 2);
    csum %= MOD;

    fout << ((alldist - csum) % MOD + MOD) % MOD << endl;
}