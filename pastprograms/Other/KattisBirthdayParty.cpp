#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
set<int> connections[100];
bool passed[100];

void dfs (int pos) {
	if(passed[pos]) return;
	passed[pos] = true;
	for (auto p : connections[pos]) dfs(p);
}

int main() {
	while(true) {
		cin >> N >> M;
		if(N == 0) break;

		for (int i = 0; i < N; i ++) connections[i].clear();

		vector<tuple<int, int>> bridges;
		for (int i = 0; i < M; i ++) {
			cin >> a >> b;
			bridges.pb(mt(a, b));
			connections[a].is(b);
			connections[b].is(a);
		}
		bool fail = false;
		for (auto br : bridges) {
			a = get<0>(br), b = get<1>(br);
			connections[a].erase(b);
			connections[b].erase(a);

			for (int i = 0; i < N; i ++) passed[i] = false;
			dfs(0);
			for (int i = 0; i < N; i ++) {
				if(!passed[i]) {
					fail = true;
					break;
				}
			}
			if(fail) break;

			connections[a].is(b);
			connections[b].is(a);
		}
		if(fail) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}