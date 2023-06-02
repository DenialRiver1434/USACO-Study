#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

vector<int> conn[100000];
int teams[100000];
int N, M, a, b;
bool found = true;

void dfs (int pos, short color) {
	if(teams[pos] && (teams[pos] != color)) {
		found = false;
		return;
	}
	if(teams[pos] || !found) return;
	teams[pos] = color;
	if(color == 1) color = 2;
	else color = 1;
	for (auto c : conn[pos]) {
		dfs(c, color);
	}
}

int main() {
	cin >> N >> M;
	while (M --) {
		cin >> a >> b;
		conn[a - 1].pb(b - 1);
		conn[b - 1].pb(a - 1);
	}
	for (int i = 0; i < N; i ++) {
		if(! teams[i]) {
			dfs(i, 1);
		}
	}
	if(!found) cout << "IMPOSSIBLE";
	else {
		for (int i = 0; i < N; i ++) {
			cout << teams[i] << " ";
		}
	}
}