#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (int i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int N; cin >> N;
	int X = (N * N + N) / 2;
	if(X % 2 == 1) {
		cout << 0 << endl;
		return 0;
	}
	X = X/2 + 1;

	int count[X]; count[0] = 1;
	for_loop (i, 1, X) count[i] = 0;

	for_loop (i, 1, N + 1) {
		for (int j = X - 1; j >= i; j --) {
			count[j] = (count[j] + count[j - i]) % MOD;
		}
	}
	
	if(count[X - 1] % 2 == 1) cout << (count[X - 1] + MOD) / 2 << endl;
	else cout << count[X - 1] / 2 << endl;
}