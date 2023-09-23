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

ll M, N;
V<ll> before, after;
V<ll> prefb, prefa;

ll dp[1001][1001]; // max days to solve first j problems having previously finished first i

int main () {
	cin >> M >> N;
	prefb.pb(0); prefa.pb(0);
	f0r (j, 0, N) {
		ll a, b; cin >> a >> b;
		before.pb(a); after.pb(b);
		prefb.pb(prefb[j] + a);
		prefa.pb(prefa[j] + b);
	}
    f0r (i, 0, 1000) {
        f0r (j, 0, 1000) {
            dp[i][j] = INF;
        }
    }

    ll best = INF;
    dp[0][0] = 1;
    f0r (j, 1, N + 1) {
        f0r (i, 0, j + 1) {
            ll req_space = prefb[j] - prefb[i];
            if (req_space > M || prefa[j] - prefa[i] > M) continue;

            f0r (k, 0, i + 1) {
                if (M - (prefa[i] - prefa[k]) >= req_space) {
                    dp[i][j] = min(dp[i][j], dp[k][i] + 1);
                }
            }
            if (j == N) best = min(best, dp[i][j]);
        }
    }
    cout << best + 1 << endl;
}