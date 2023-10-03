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
#define INF 1000000000000000000LL
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 1e5;
ll lo[MAX_N], hi[MAX_N], dp[MAX_N][2];
V<ll> conn[MAX_N];

ll get (ll pos, bool rhs) {
    if (rhs) return hi[pos];
    else return lo[pos];
}

ll dfs (ll pos, ll pre, bool rhs) {
    if (dp[pos][rhs] != -INF) return dp[pos][rhs];
    dp[pos][rhs] = 0;

    ll tot = 0;
    for (auto c : conn[pos]) {
        if (c != pre) {
            tot += max(abs(get(c, 0) - get(pos, rhs)) + dfs(c, pos, 0), abs(get(c, 1) - get(pos, rhs)) + dfs(c, pos, 1));
        }
    }
    return dp[pos][rhs] = tot;
}

int main () {
    fastio;
    ll T; cin >> T;
    while (T --) {
        ll N; cin >> N;
        f0r (i, 0, N) {
            cin >> lo[i] >> hi[i];
            dp[i][0] = dp[i][1] = -INF;
            conn[i].clear();
        }
        f0r (i, 1, N) {
            ll a, b; cin >> a >> b;
            conn[a - 1].pb(b - 1);
            conn[b - 1].pb(a - 1);
        }
        cout << max(dfs (0, -1, 0), dfs (0, -1, 1)) << '\n';
    }
}