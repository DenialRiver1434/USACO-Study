#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (int i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

int N, dp[100][1001];
const int MOD = 1e9 + 7;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N;

	if((N % 2) == 0) {
		f0r (i, 0, N) {
			int a; cin >> a;
			if(i == 0) {
				f0r (j, 0, a + 1) dp[0][j] = 1;
			}
			else {
				int c = 0;
				f0r (j, 0, a + 1) {
					c += dp[i - 1][j];
					c %= MOD;
				}
				for (int j = a; j >= 0; j --) {
					dp[i][a - j] = c;
					c -= dp[i - 1][j];
					if(c < 0) c += MOD;
				}
			}
		}
		cout << dp[N - 1][0] << endl;
	}
	else {
		int cnt[100];
		int lo = 1e9;
		f0r (i, 0, N) {
			int a; cin >> a;
			lo = min(lo, a);
			cnt[i] = a;
		}

		int tc = 0;
		f0r (diff, 0, lo + 1) {
			f0r (i, 0, N) {
				f0r (j, 0, 1000) dp[i][j] = 0;
			}

			f0r (i, 0, N) {
				int a = cnt[i] - diff;
				if(i == 0) {
					f0r (j, 0, a + 1) dp[0][j] = 1;
				}
				else {
					int c = 0;
					f0r (j, 0, a + 1) {
						c += dp[i - 1][j];
						c %= MOD;
					}
					for (int j = a; j >= 0; j --) {
						dp[i][a - j] = c;
						c -= dp[i - 1][j];
						if(c < 0) c += MOD;
					}
				}
			}
			tc += dp[N - 1][0];
			tc %= MOD;
		}
		cout << tc << endl;
	}
}
