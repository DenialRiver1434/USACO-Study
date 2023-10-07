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

const ll MAX_N = 3e5 + 5;

V<PL> conn[MAX_N];
ll dp[MAX_N][2];
ll N, d[MAX_N], ans = 0;

void dfs (ll pos, ll pre) {
    ll baseline = 0;
    V<ll> options;
    for (auto c : conn[pos]) {
        if (c.F != pre) {
            dfs (c.F, pos);
            baseline += dp[c.F][0];
            options.pb(c.S + dp[c.F][1] - dp[c.F][0]);
        }
    }
    sort(all(options), greater<ll>());
    
    if (d[pos] == 0) {
        dp[pos][1] = -inf;
    }
    else {
        ll s = baseline;
        dp[pos][1] = max(dp[pos][1], baseline);
        f0r (i, 0, d[pos] - 1) {
            s += options[i];
            dp[pos][1] = max(dp[pos][1], s);
        }
    }

    dp[pos][0] = max(dp[pos][0], baseline);
    f0r (i, 0, min(d[pos], len(options))) {
        baseline += options[i];
        dp[pos][0] = max(dp[pos][0], baseline);
    }
    ans = max(ans, dp[pos][0]);
}

int main () {
    cin >> N;
    f0r (i, 0, N) cin >> d[i];
    f0r (i, 0, N - 1) {
        ll a, b, c; cin >> a >> b >> c;
        conn[a - 1].pb({b - 1, max(0LL, c)});
        conn[b - 1].pb({a - 1, max(0LL, c)});
    }
    
    dfs (0, -1);
    cout << ans << endl;
}