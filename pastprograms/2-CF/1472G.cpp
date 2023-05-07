#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define f0r(i, begin, n) for (int i = begin; i < n; i ++)
#define len(x) x.length()
#define sz(x) x.size()
#include <bits/stdc++.h>
using namespace std;

void test () {
	int N, M; cin >> N >> M;
	int olddist[N + 1], dist[N + 1], indegree[N + 1];
	vector<int> conn[N + 1], legal[N + 1];
	vector<pair<int, int>> roads;

	f0r (i, 1, N + 1) {
		olddist[i] = -1;
		dist[i] = 1000000000;
		indegree[i] = 0;
	}
	olddist[1] = 0; dist[1] = 0;
	f0r (i, 0, M) {
		int a, b; cin >> a >> b;
		conn[a].pb(b);
		roads.pb(mp(a, b));
	}
	queue<int> q; q.push(1);
	while (!q.empty()) {
		int pos = q.front();
		q.pop();
		for (auto c : conn[pos]) {
			if(olddist[c] == -1) {
				olddist[c] = olddist[pos] + 1;
				dist[c] = olddist[c];
				q.push(c);
			}
		}
	}
	
	for (auto p : roads) {
		if(olddist[p.first] < olddist[p.second]) {
			legal[p.first].pb(p.second);
			indegree[p.second] ++;
		}
	}
	f0r (i, 1, N + 1) {
		for (auto c : conn[i]) {
			dist[i] = min(dist[i], olddist[c]);
		}
	}

	// Topological Sort

	vector<int> sorted;
	f0r (i, 0, N) {
		if(indegree[i] == 0) q.push(i);
	}
	while(!q.empty()) {
		int pos = q.front();
		q.pop();
		sorted.pb(pos);
		for (auto c : legal[pos]) {
			if((--indegree[c]) == 0) q.push(c);
		}
	}
	reverse(sorted.begin(), sorted.end());
	for (auto s : sorted) {
		for (auto c : legal[s]) dist[s] = min(dist[c], dist[s]);
	}
	f0r (i, 1, N + 1) {
		cout << dist[i] << " ";
	}
	cout << endl;
}

int main () {
	int N; cin >> N;
	while (N --) {
		test ();
	}
}