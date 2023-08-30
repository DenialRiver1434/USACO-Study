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

ll dp[505][505], nCk[505][505];
ll N, X;

int main () {
	cin >> N >> X;
	f0r (i, 0, N + 1) {
		nCk[i][0] = nCk[i][i] = 1;
		if (i > 0) {
			f0r (j, 1, i) {
				nCk[i][j] = (nCk[i - 1][j] + nCk[i - 1][j - 1]) % MOD;
			}
		}
	}
	dp[N][0] = 1;
	For (i, N, 0) {
		f0r (j, 0, X) {
			if (!dp[i][j]) continue;
			ll pw = 1, nj = min(X, j + i - 1);
			For (k, i, -1) {
				dp[k][nj] += dp[i][j] * ((pw * nCk[i][k]) % MOD);
				dp[k][nj] %= MOD;
				pw *= (nj - j);
				pw %= MOD;
			}
		}
	}
	ll ans = 0;
	f0r (i, 0, X + 1) {
		ans += dp[0][i];
		ans %= MOD;
	}
	cout << ans << endl;
}