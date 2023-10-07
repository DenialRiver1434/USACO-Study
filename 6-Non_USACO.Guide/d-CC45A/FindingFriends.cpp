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
#define MOD 998244353
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 1e5;

ll T, N, K;
V<ll> pos, val;
PL dp[MAX_N + 5];

ll solve (ll lhs, ll rhs) {
    ll n = rhs - lhs;
    if (n == 0) return 0;
    if (T == 1) {
        if (n % 2 == 0) return 0;
        ll ans = min(val[lhs], val[rhs - 1]);
        f0r (i, lhs + 1, rhs - 1) {
            if (pos[i + 1] - pos[i - 1] <= K) {
                ans = min(ans, val[i]);
            }
            if ((i - lhs) % 2 == 0) { // No need to check RHS since odd
                ans = min(ans, val[i]);
            }
        }
        return ans;
    }
    
    dp[rhs] = {0, -INF};
    For (i, rhs - 1, lhs - 1) {
        dp[i] = dp[i + 1];
        ll ub = upper_bound(all(pos), pos[i] + K) - pos.begin();

        if (i == lhs || i == rhs - 1 || pos[i + 1] - pos[i - 1] <= K || (rhs - i) % 2 == 0) {
            dp[i].F = max(dp[i].F, dp[ub].S + val[i]);
        }
        if (i == lhs || i == rhs - 1 || pos[i + 1] - pos[i - 1] <= K || (rhs - i) % 2 == 1) {
            dp[i].S = max(dp[i].S, dp[ub].F + val[i]);
        }
    }
    dp[rhs] = {-INF, -INF};

    if (n % 2 == 1) return dp[lhs].S;
    return dp[lhs].F;
}

int main () {
    cin >> T >> N >> K;
    f0r (i, 0, N) {
        dp[i] = {-INF, -INF};
        ll a, b; cin >> a >> b;
        pos.pb(a); val.pb(b);
    }

    ll lpos = 0, tot = 0;
    f0r (i, 0, N) {
        if (i == lpos) continue;
        if (pos[i] - pos[i - 1] > K) {
            tot += solve (lpos, i);
            lpos = i;
        }
    }
    tot += solve (lpos, N);
    cout << tot << endl;
}