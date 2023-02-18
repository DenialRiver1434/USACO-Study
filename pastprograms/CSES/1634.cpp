#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (int i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

int INF = 1e9;

int main () {
	vector<int> past = {0}, coins;
	int N, X; cin >> N >> X;
	for_loop (i, 0, N) {
		int a; cin >> a;
		coins.pb(a);
	}

	for_loop (i, 1, X + 1) {
		int best = INF;
		for (auto c : coins) {
			if((i - c) >= 0) {
				best = min(past[i - c] + 1, best);
			}
		}
		past.pb(best);
	}
	if(past[X] == INF) cout << -1 << endl;
	else cout << past[X] << endl;
}
