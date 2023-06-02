#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (int i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

int main () {
	int N; cin >> N;
	vector<int> possible = {0, 0, 0, 0, 0, 1};
	for_loop (i, 6, N + 6) {
		int pot = (possible[i - 6]) % MOD;
		pot = (pot + possible[i - 5]) % MOD;
		pot = (pot + possible[i - 4]) % MOD;
		pot = (pot + possible[i - 3]) % MOD;
		pot = (pot + possible[i - 2]) % MOD;
		pot = (pot + possible[i - 1]) % MOD;
		possible.pb(pot);
	}
	cout << possible[N + 5] << endl;
}
