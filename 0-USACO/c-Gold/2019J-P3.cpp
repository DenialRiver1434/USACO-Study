#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

ll N, M, K, dist[10001], pass[10001], dest[10001];
bool topped[10001];
vector<ll> origins[10001];
vector<pair<ll, ll>> conn[10001];

void dijkstra(ll src) {  // Updates dist, src = starting
	for (ll i = 0; i < N; ++i) dist[i] = 1e18;
	
	using T = pair<ll, ll>;
	priority_queue<T, vector<T>, greater<T>> pq;
	dist[src] = 0;  
	pq.push({0, src});

	while (pq.size()) {
		ll cdist;
		ll node;
		tie(cdist, node) = pq.top();
		pq.pop();
		if (cdist != dist[node]) continue;
		for (pair<ll, ll> i : conn[node]) {
			if ((cdist + i.second == dist[i.first]) && node < dest[i.first]) {
				dest[i.first] = node;
			}
			if (cdist + i.second < dist[i.first]) {
				dest[i.first] = node;
				pq.push({dist[i.first] = cdist + i.second, i.first});
			}
		}
	}
}

ll dfs (ll pos) {
	if(topped[pos]) return pass[pos];
	topped[pos] = true;
	for (auto e : origins[pos]) {
		pass[pos] += dfs(e);
	}
	return pass[pos];
}

int main () {
	ifstream fin; ofstream fout;
	fin.open("shortcut.in"); fout.open("shortcut.out");

    fin >> N >> M >> K;
	for_loop (i, 0, N) {
		ll a; fin >> a;
		pass[i] = a; 
	}
	for_loop (i, 0, M) {
		ll a, b, c;
		fin >> a >> b >> c;
		conn[a - 1].pb(mp(b - 1, c));
		conn[b - 1].pb(mp(a - 1, c));
	}
	dijkstra(0);
	for_loop (i, 1, N) {
		origins[dest[i]].pb(i);
	}
	for_loop (i, 0, N) {
		if(!topped[i]) {
			dfs(i);
		}
	}
	ll best = 0;
	for_loop (i, 0, N) {
		best = max(best, pass[i] * (dist[i] - K));
	}
	fout << best << endl;
}