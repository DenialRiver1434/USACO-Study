#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main () {
	int N, M, possible[1000001]; cin >> N >> M;
	vector<int> coins;
	for_loop (i, 0, N) {
		int a; cin >> a;
		coins.pb(a);
	}
	for_loop (i, 1, M + 1) {
		possible[i] = 0;
	}
	possible[0] = 1;
	for (auto c : coins) {
		for_loop (i, c, M + 1) {
			possible[i] = (possible[i] + possible[i - c]) % MOD;
		}
	}
	cout << possible[M] << endl;
}