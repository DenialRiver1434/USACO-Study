#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (int i = begin; i < end; i ++) 
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

int N, M, ways[100000];
bool searched[100000];
vector<int> conn[100000];
vector<int> sorted;

void dfs (int i) {
	if(searched[i]) return;
	searched[i] = true;
	for (auto c : conn[i]) {
		dfs(c);
	}
	sorted.pb(i);
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
	reverse(sorted.begin(), sorted.end());
	map<int, int> positions;
	f0r (i, 0, N) {
		positions[sorted[i]] = i;
	}
	
	bool started = false;
	ways[0] = 1;
	for (auto s : sorted) {
		if(s == 0) started = true;
		if(!started) continue;
		for (auto c : conn[s]) {
			ways[c] += ways[s];
			ways[c] %= 1000000007;
		}
	}
	cout << ways[N - 1] << endl;
}
