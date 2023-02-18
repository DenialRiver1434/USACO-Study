#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

ll N, M;
vector<pair<ll, ll>> conn[1001];  
ll dist[1001];

bool comp(ll n1, ll d1, ll n2, ll d2) {// return n1/d1 > n2/d2
	return (n1 * d2) > (n2 * d1);
}

void dijkstra(ll src) {  // Updates dist, src = starting
	for (ll i = 0; i < N; ++i) dist[i] = 1e9;
	
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
			if (cdist + i.second < dist[i.first]) {
				pq.push({dist[i.first] = cdist + i.second, i.first});
			}
		}
	}
}

int main () {
    cin >> N >> M;
	ll bestnum = 0, bestden = 1;
	vector<tuple<ll, ll, ll, ll>> pipes; // flow, start, end, cost
    for_loop (i, 0, M) {
		ll b, c, d, a; cin >> b >> c >> d >> a;
		pipes.pb(mt(a, b - 1, c - 1, d));
	}
	sort(pipes.begin(), pipes.end(), greater<tuple<ll, ll, ll, ll>>());
	for (auto p : pipes) {
		ll best = get<0>(p);
		conn[get<1>(p)].pb(mp(get<2>(p), get<3>(p)));
		conn[get<2>(p)].pb(mp(get<1>(p), get<3>(p)));
		dijkstra(0);
		if(dist[N - 1] == 1e9) continue;
		if(comp(best, dist[N - 1], bestnum, bestden)) {
			bestnum = best;
			bestden = dist[N - 1];
		}
	}
	
	cout << (1000000 * bestnum) / bestden;
}
