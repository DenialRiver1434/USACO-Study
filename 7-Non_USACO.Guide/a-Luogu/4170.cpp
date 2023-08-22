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

string N;
ll lN, dp[50][51];
const ll MAX = 1e18;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> N; lN = len(N);
    f0r (i, 0, lN) dp[i][i + 1] = 1;
    
    f0r (diff, 2, lN + 1) {
        f0r (i, 0, lN - diff + 1) {
            ll j = i + diff;
            dp[i][j] = MAX;
            f0r (k, i + 1, j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] - (N[i] == N[j - 1]));
            }
        }
    }
    cout << dp[0][lN] << endl;
}