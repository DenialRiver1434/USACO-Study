#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll int
#define vl vector<ll>
#define sl set<ll>
#define msl multiset<ll>
#define pl pair<ll, ll>
#define vpl vector<pair<ll, ll>>
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

bool val[1048576];
ll dp[20][1048576], N, H, ans = -1;
vector<tuple<ll, ll, ll>> cows;

bool cmp (tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) {
    return (get<2>(a) - get<1>(b)) > (get<2>(b) - get<1>(a));
}

int main () {
    ifstream fin; ofstream fout;
    fin.open("guard.in"); fout.open("guard.out");
    fin >> N >> H;
    f0r (i, 0, N) {
        ll a, b, c; fin >> a >> b >> c;
        cows.pb(mt(a, b, c));
    }
    sort(cows.begin(), cows.end(), cmp);

    f0r (i, 0, 1 << N) {
        ll run = 0;
        f0r (j, 0, N) {
            if ((i & (1 << j)) > 0) {
                run += get<0>(cows[j]);
            }
        }
        val[i] = (run >= H);
    }

    f0r (i, 0, N) {
        ll weight = get<1>(cows[i]), canhold = get<2>(cows[i]);
        dp[i][1 << i] = canhold;
        f0r (j, 0, (1 << N)) {
            if((j & (1 << i)) == 0) {
                if(i > 0) dp[i][j] = dp[i - 1][j];
                continue;
            }
            if(j == (1 << i)) continue;
            if(j >= (2 * (1 << i))) continue;

            dp[i][j] = max(-1, min(dp[i - 1][j - (1 << i)] - weight, canhold));
            if(val[j]) {
                ans = max(ans, dp[i][j]);
            }
        }
    }

    if(ans < 0) {
        fout << "Mark is too tall" << endl;
    }
    else {
        fout << ans << endl;
    }
}