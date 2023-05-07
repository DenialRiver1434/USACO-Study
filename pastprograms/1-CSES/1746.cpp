#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, n) for (int i = begin; i < n; i ++) 
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int paths[102][100000];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int N, M, a; cin >> N >> M >> a;
	if(a == 0) {
		f0r (i, 1, M + 1) {
			paths[i][0] = 1;
		}
	}
	else paths[a][0] = 1;

	f0r (i, 1, N) {
		cin >> a;
		if (a == 0) {
			f0r (j, 1, M + 1) {
				paths[j][i] = ((paths[j - 1][i - 1] + paths[j][i - 1]) % MOD + paths[j + 1][i - 1]) % MOD;
			}
		}
		else {
			paths[a][i] = ((paths[a - 1][i - 1] + paths[a][i - 1]) % MOD + paths[a + 1][i - 1]) % MOD;
		}
	}
	int s = 0;
	f0r (i, 1, M + 1) {
		s += paths[i][N - 1];
		s %= MOD;
	}
	cout << s;
}