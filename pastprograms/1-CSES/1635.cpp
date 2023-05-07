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
	vector<int> past = {1}, coins;
	int N, X; cin >> N >> X;
	for_loop (i, 0, N) {
		int a; cin >> a;
		coins.pb(a);
	}
 
	for_loop (i, 1, X + 1) {
		int best = 0;
		for (auto c : coins) {
			if((i - c) >= 0) {
				best = (best + past[i - c]) % MOD;
			}
		}
		past.pb(best);
	}
	cout << past[X] << endl;
}
