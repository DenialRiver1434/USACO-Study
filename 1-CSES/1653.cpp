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
#define MAX 1e18
#define MOD 1e9+7
#include <bits/stdc++.h>
using namespace std;

ll N, X, dp[1048576], weight[20];

int main() {
	cin >> N >> X;
	f0r (i, 0, N) { cin >> weight[i]; }

	f0r (i, 1, 1 << N) {
		dp[i] = MAX;
		f0r (j, 0, 20) {
			if (((1 << j) & i) == 0) continue; 
			ll excl = dp[i - (1 << j)];
			if(((excl % X) + weight[j]) > X) { excl += (X - (dp[i - (1 << j)] % X)); }
			dp[i] = min(dp[i], excl + weight[j]);
		}
	}

	if((dp[(1 << N) - 1] % X) == 0) cout << dp[(1 << N) - 1] / X << endl;
	else cout << 1 + (dp[(1 << N) - 1] / X) << endl;
}