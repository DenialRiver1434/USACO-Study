#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define vl vector<ll>
#define sl set<ll>
#define msl multiset<ll>
#define pl pair<ll, ll>
#define vpl vector<pair<ll, ll>>
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

bool cmp (vector<ll> &a, vector<ll> &b) {
    return a[0] > b[0];
}

ll N, P, K, dp[100001][128];
vector<vector<ll>> power; // power[0] = audience

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> N >> P >> K;
    f0r (i, 0, N) {
        ll a; cin >> a;
        power.pb({});
        power[i].pb(a);
    }
    f0r (i, 0, N) {
        f0r (j, 0, P) {
            ll a; cin >> a;
            power[i].pb(a);
        }
    }
    sort(power.begin(), power.end(), cmp);
    f0r (i, 0, N) {
        f0r (j, 0, 1 << P) { // current situation
            if(__builtin_popcount(j) > i) continue;
            if((i - __builtin_popcount(j)) < K) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + power[i][0]);
            else dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

            f0r (k, 0, P) { // new position for i+1
                if((j & (1 << k)) != 0) continue;
                dp[i + 1][j + (1 << k)] = max(dp[i + 1][j + (1 << k)], dp[i][j] + power[i][k + 1]);
            }
        }
    }
    
    cout << dp[N][(1 << P) - 1] << endl;
}