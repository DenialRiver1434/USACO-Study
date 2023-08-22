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

ll N, dp[100][100][2], score[100], tot[100][100];
const ll MAX = 1e18;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> N;
    f0r (i, 0, N) {
        cin >> score[i];
    }
    f0r (i, 0, N) {
        f0r (j, 0, N) {
            bool starting = true; 
            for (ll k = i; starting || k != j; k = (k + 1) % N) {
                tot[i][j] += score[k];
                starting = 0;
            }
        }
    }

    f0r (diff, 2, N + 1) {
        f0r (i, 0, N) {
            ll j = (i + diff) % N;
            dp[i][j][0] = MAX;
            ll cursum = tot[i][j];

            bool starting = true; 
            for (ll k = (i + 1) % N; starting || k != j; k = (k + 1) % N) {
                dp[i][j][0] = min(dp[i][j][0], cursum + dp[i][k][0] + dp[k][j][0]);
                dp[i][j][1] = max(dp[i][j][1], cursum + dp[i][k][1] + dp[k][j][1]);
                starting = false;
            }
            //cout << i << " " << j << " : " << dp[i][j][0] << " " << dp[i][j][1] << endl;
        }
    }

    ll minans = MAX, maxans = 0;
    f0r (i, 0, N) {
        minans = min(minans, dp[i][i][0]);
        maxans = max(maxans, dp[i][i][1]);
    }
    cout << minans << endl << maxans << endl;
}