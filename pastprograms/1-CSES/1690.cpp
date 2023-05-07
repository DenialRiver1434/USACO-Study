#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define lll long long
#define f0r(i, begin, n) for (lll i = begin; i < n; i ++)
#define len(x) x.size()
#define vi vector<lll>
#define vpi vector<pair<lll, lll>>
#include <bits/stdc++.h>
using namespace std;

lll MOD = 1e9+7;
lll N, M, cnt[20][1048576];
vi conn[20];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N >> M;
	f0r (i, 0, M) {
		lll a, b; cin >> a >> b;
		a --; b --;
		conn[a].pb(b);
	}
	cnt[0][1] = 1;
	for (int i = 1; i < (1 << N); i += 2) {
		if ((i & (1 << (N - 1))) && i != ((1 << N) - 1)) continue;
		f0r (j, 0, N) {
			if(i & (1 << j)) {
				if(cnt[j][i] == 0) continue;
				for (auto c : conn[j]) {
					if(!(i & (1 << c))) {
						cnt[c][i + (1 << c)] += cnt[j][i];
						cnt[c][i + (1 << c)] %= MOD;
					}
				}
			}
		}
	}
	cout << cnt[N - 1][(1 << N) - 1] << endl;
}