#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

vector<ll> conn[100000];
ll teams[100000];
ll count1 = 0, count2 = 0;
ll N, M, a, b;
bool found = true;

void dfs (ll pos, short color) {
	if(teams[pos] && (teams[pos] != color)) {
		found = false;
		return;
	}
	if(teams[pos] || !found) return;
	teams[pos] = color;
	if(color == 1) {
		count1 ++;
		color = 2;
	}
	else {
		count2 ++;
		color = 1;
	}
	for (auto c : conn[pos]) {
		dfs(c, color);
	}
}

int main() {
	cin >> N;
	for (ll i = 1; i < N; i ++) {
		cin >> a >> b;
		conn[a - 1].pb(b - 1);
		conn[b - 1].pb(a - 1);
	}
	for (ll i = 0; i < N; i ++) {
		if(! teams[i]) {
			dfs(i, 1);
		}
	}
	cout << (count1 * count2) - (N - 1);
}