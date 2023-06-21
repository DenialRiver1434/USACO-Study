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

ll N, inp[100000], conseq[20][20], dp[1048576];
const ll MAX = 1e18;

void read () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    map<char, int> translate;
    translate['m'] = 0; translate['i'] = 2; translate['l'] = 3; translate['d'] = 4; translate['r'] = 5; translate['e'] = 6;
    int j = 0;
    f0r (i, 97, 123) {
        if(translate.find(i) != translate.end()) {
            continue;
        }
        translate[i] = j ++;
    }
    string temp; cin >> temp;
    int i = 0;
    for (auto t : temp) {
        inp[i] = translate[t];
        if(i > 0) {
            conseq[inp[i - 1]][inp[i]] ++;
        }
        i ++;
    }
}

int main () {
    read ();
    f0r (i, 1, 1048576) {
        dp[i] = MAX;
        f0r (j, 0, 20) { // something included, last
            if (((1 << j) & i) == 0) continue;

            int cur = 0;
            f0r (k, 0, 20) { 
                if (((1 << k) & i) == 0) continue;
                cur += conseq[j][k];
            }
            dp[i] = min(dp[i], cur + dp[i - (1 << j)]);
        }
    }
    cout << dp[1048575] + 1 << endl;
}