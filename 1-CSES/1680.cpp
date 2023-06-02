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
int N, M, dist[100000], origin[100000];
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
	for (auto s : sorted) {
		if(s == 0) started = true;
		if(!started) continue;
		if(dist[s] == 0) origin[s] = -1;
		for (auto c : conn[s]) {
			if((dist[s] + 1) > dist[c]) {
				origin[c] = s;
				dist[c] =  dist[s] + 1;
			}
		}
	}
	if(dist[N - 1] == 0) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	
	cout << dist[N - 1] + 1 << endl;
	vector<int> out;
	int pos = N - 1;
	while (pos != 0) {
		out.pb(pos);
		pos = origin[pos];
	}
	out.pb(pos);
	reverse(out.begin(), out.end());
	for (auto o : out) {
		cout << o + 1 << " ";
	}
}
