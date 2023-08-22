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

string S; 
ll lS, dp[1005][1005];

int main () {
	cin >> S; lS = len(S);
	f0r (i, 0, lS + 1) {
		dp[i][i] = dp[i][i + 1] = 0;
	}

	f0r (dist, 2, lS + 1) {
		f0r (start, 0, lS - dist + 1) {
			ll end = start + dist;
			dp[start][end] = 2346758687645;

			if(S[start] == S[end - 1]) {
				dp[start][end] = dp[start + 1][end - 1];
			}
			dp[start][end] = min(dp[start][end], dp[start + 1][end] + 1);
			dp[start][end] = min(dp[start][end], dp[start][end - 1] + 1);
		}
	}

	cout << dp[0][lS] << endl;
}
