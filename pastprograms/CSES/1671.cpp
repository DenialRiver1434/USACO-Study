#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

ll dist[100000], inf = 1e18, N, M; 
vector<pair<ll, ll>> conn[100000];

void dijkstra (ll start) {
    for (int i = 1; i < N; i ++) {
        dist[i] = inf;
    }

    priority_queue<pair<ll, ll>> pq;
    pq.push(mp(0, start));
    while(pq.size()) {
        ll path = -pq.top().first, pos = pq.top().second;
        pq.pop();
        if(dist[pos] < path) continue;
        for (auto c : conn[pos]) {
            if(dist[c.first] > (dist[pos] + c.second)) {
                dist[c.first] = dist[pos] + c.second;
                pq.push(mp(-dist[c.first], c.first));
            }
        }
    }
}

int main () {
    cin >> N >> M;
    for (int i = 0; i < M; i ++) {
        ll a, b, c; cin >> a >> b >> c; a --; b --;
        conn[a].pb(mp(b, c));
    }
    dijkstra(0);
    
    for (int i = 0; i < N; i ++) {
        cout << dist[i] << " ";
    }
}