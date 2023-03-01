#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (int i = begin; i < end; i ++) 
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M, spec = -1;
bool searched[100000], cycle = false;
vector<int> conn[100000];
set<int> searching;

void dfs (int i) {
	if(searched[i] || cycle) return;
	searching.is(i);
	searched[i] = true;
	for (auto c : conn[i]) {
		if(searching.find(c) != searching.end()) {
			cycle = true;
			spec = c;
			return;
		}
		dfs(c);
		if(cycle) return;
	}
	searching.erase(i);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	vector<pair<int, int>> inps;
	cin >> N >> M;
	f0r (i, 0, M) {
		int a, b; cin >> a >> b;
		conn[a - 1].pb(b - 1);
		inps.pb(mp(a - 1, b - 1));
	}
	f0r (i, 0, N) {
		dfs(i);
	}
	if(!cycle) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		vector<int> out = {spec};
		while(true) {
			bool leave = false;
			for (auto c : conn[spec]) {
				if(c == out[0]) {
					leave = true;
					out.pb(c);
					break;
				}
				if(searching.find(c) != searching.end()) {
					searching.erase(c);
					out.pb(c);
					spec = c;
					break;
				}
			}
			if(leave) break;
		}
		cout << out.size() << endl;
		for (auto o : out) {
			cout << o + 1 << " ";
		}
	}
}
