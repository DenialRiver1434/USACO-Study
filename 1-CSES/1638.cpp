#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, n) for (int i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

int walks[1001][1001];
bool safe[1001][1001];

const int MOD = 1e9 + 7;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int N; cin >> N;
	f0r (i, 1, N + 1) {
		f0r (j, 1, N + 1) {
			char a; cin >> a;
			safe[i][j] = (a == '.');
		}
	}
	walks[0][1] = 1;
	f0r (i, 1, N + 1) {
		f0r (j, 1, N + 1) {
			walks[i][j] = safe[i][j] * (walks[i - 1][j] + walks[i][j - 1]) % MOD;
		}
	}
	cout << walks[N][N] << endl;
}