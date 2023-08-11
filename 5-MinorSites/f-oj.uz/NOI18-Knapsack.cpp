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
#include "bits/stdc++.h"
using namespace std;

struct item {
    ll value, amount;
};
bool comp (item a, item b) {
	return a.value > b.value;
}

vector<item> items[2001];
ll dp[2001], S, N, ans = 0;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> S >> N;
    f0r (i, 0, N) {
        ll a, b, c; cin >> a >> b >> c;
        items[b].pb({a, c});
    }
	f0r (i, 0, 2001) dp[i] = -1e18;
    
	dp[0] = 0;
    f0r (i, 1, 2001) {
		sort(items[i].begin(), items[i].end(), comp);
		vl vals;
		ll rs = 0;
		for (auto it : items[i]) {
			f0r (j, 0, it.amount) {
				rs += i;
				if(rs > S) break;
				vals.pb(it.value);
			}
			if(rs > S) break;
		}

		for (auto v : vals) {
            for (int k = S; k >= i; k --) {
				dp[k] = max(dp[k], dp[k - i] + v);
				ans = max(ans, dp[k]);
            }
		}
	}
	cout << ans << endl;
}