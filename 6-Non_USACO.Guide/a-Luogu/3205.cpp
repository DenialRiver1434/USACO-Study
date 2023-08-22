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

ll N, dp[1000][1001][2], heights[1000]; // 0 = left, 1 = right
const ll MOD = 19650827;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> N;
    cin >> heights[0];
    f0r (i, 1, N) {
        cin >> heights[i];
        if(heights[i] > heights[i - 1]) {
            dp[i - 1][i + 1][0] = dp[i - 1][i + 1][1] = 1;
        }
    }
    f0r (diff, 3, N + 1) {
        f0r (i, 0, N - diff + 1) {
            ll j = i + diff;

            // insert left now left (0, 0)
            if(heights[i + 1] > heights[i]) dp[i][j][0] += dp[i + 1][j][0];

            // insert left now right (0, 1)
            if(heights[i] < heights[j - 1]) dp[i][j][1] += dp[i][j - 1][0];

            // insert right now left (1, 0)
            if(heights[j - 1] > heights[i]) dp[i][j][0] += dp[i + 1][j][1];

            // insert right now right (1, 1)
            if(heights[j - 2] < heights[j - 1]) dp[i][j][1] += dp[i][j - 1][1];
            dp[i][j][0] %= MOD;
            dp[i][j][1] %= MOD;
        }
    }
    cout << (dp[0][N][0] + dp[0][N][1]) % MOD << endl;
}