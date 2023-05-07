#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (int i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

int N, M, K, yummy[50000], orgdist[50000], newdist[50000];
vector<pair<int, int>> conn[50000];

void dijkstra(int src) {  // Updates dist, src = starting
	for (int i = 0; i < N; ++i) orgdist[i] = 1e9;
	
	using T = pair<int, int>;
	priority_queue<T, vector<T>, greater<T>> pq;
	orgdist[src] = 0;  
	pq.push({0, src});

	while (pq.size()) {
		int cdist;
		int node;
		tie(cdist, node) = pq.top();
		pq.pop();
		if (cdist != orgdist[node]) continue;
		for (pair<int, int> i : conn[node]) {
			if (cdist + i.second < orgdist[i.first]) {
				pq.push({orgdist[i.first] = cdist + i.second, i.first});
			}
		}
	}
}

void dijkstra2(int src) {  // Updates dist, src = starting
	for (int i = 0; i < N; ++i) newdist[i] = 1e9;
	
	using T = pair<int, int>;
	priority_queue<T, vector<T>, greater<T>> pq;
	newdist[src] = 0;  
	pq.push({0, src});

	while (pq.size()) {
		int cdist;
		int node;
		tie(cdist, node) = pq.top();
		pq.pop();
		if (cdist != newdist[node]) continue;
		for (pair<int, int> i : conn[node]) {
			int possible = min(cdist + i.second, orgdist[i.first] - yummy[i.first]);
			if (possible < newdist[i.first]) {
				pq.push({newdist[i.first] = possible, i.first});
			}
		}
	}
}

int main () {
	ifstream fin; ofstream fout;
	fin.open("dining.in"); fout.open("dining.out");
    fin >> N >> M >> K;
	for_loop (i, 0, M) {
		int a, b, c;
		fin >> a >> b >> c; a--; b--;
		conn[a].pb(mp(b, c));
		conn[b].pb(mp(a, c));
	}
	
	dijkstra(N - 1);
	for_loop (i, 0, K) {
		int a, b;
		fin >> a >> b;
		yummy[a - 1] = b + 1; // +1 for the purpose of making it such that taking grass must be shorter
	}
	dijkstra2(N - 1);
	for_loop (i, 0, N - 1) {
		fout << (orgdist[i] != newdist[i]) << endl;
	}
}
