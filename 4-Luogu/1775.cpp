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

ll N, dp[300][301], qual[300], pref[301];
const ll MAX = 1e18;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> N;
    f0r (i, 0, N) {
        cin >> qual[i];
        pref[i + 1] = pref[i] + qual[i];
    }

    f0r (diff, 2, N + 1) {
        f0r (i, 0, N - diff + 1) {
            ll j = i + diff;
            dp[i][j] = MAX;
            ll cursum = pref[j] - pref[i];
            f0r (k, i + 1, j) {
                dp[i][j] = min(dp[i][j], cursum + dp[i][k] + dp[k][j]);
            }
        }
    }
    cout << dp[0][N] << endl;
}