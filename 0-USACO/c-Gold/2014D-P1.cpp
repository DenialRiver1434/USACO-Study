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

bool val[1048576];
ll dp[1048576], N, H, ans = -1;
vector<tuple<ll, ll, ll>> cows;
const ll MAX = -1e18;

int main () {
    ifstream fin; ofstream fout;
    fin.open("guard.in"); fout.open("guard.out");
    fin >> N >> H;
    f0r (i, 0, N) {
        ll a, b, c; fin >> a >> b >> c;
        cows.pb(mt(a, b, c));
    }

    f0r (i, 0, 1 << N) {
        ll run = 0;
        f0r (j, 0, N) {
            if ((i & (1 << j)) > 0) {
                run += get<0>(cows[j]);
            }
        }
        val[i] = (run >= H);
    }

    dp[0] = -MAX;
    f0r (i, 1, (1 << N)) {
        dp[i] = MAX;
        f0r (j, 0, N) {
            if(((1 << j) & i) == 0) continue;
            ll weight = get<1>(cows[j]), canhold = get<2>(cows[j]);
            dp[i] = max(dp[i], min(canhold, dp[i - (1 << j)] - weight));
        }
        if(val[i]) {
            ans = max(ans, dp[i]);
        }
    }

    if(ans < 0) {
        fout << "Mark is too tall" << endl;
    }
    else {
        fout << ans << endl;
    }
}