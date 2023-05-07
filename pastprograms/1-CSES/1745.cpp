#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (int i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int N; cin >> N;
	int coins[N], X = 0;
	for_loop (i, 0, N) {
		cin >> coins[i];
		X += coins[i];
	}

	bool possible[X + 1]; possible[0] = true;
	for_loop (i, 1, X + 1) possible[i] = false;
	int total = 0;
	for (auto c : coins) {
		for (int j = X; j >= c; j --) {
			if(possible[j - c] && !possible[j]) {
				possible[j] = true;
				total ++;
			} 
		}
	}
	cout << total << '\n';
	for_loop (i, 1, X + 1) {
		if(possible[i]) {
			cout << i <<" ";
		}
	}
}