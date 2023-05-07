#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

ll dist[501][501];

ll led (ll a, ll b) {
    if(a == -1) return b;
    if(b == -1) return a;
    return min(a, b);
}

int main () {
    ll N, M, Q; cin >> N >> M >> Q;
    for (ll i = 0; i <= N; i ++) {
        for (ll j = 0; j <= N; j ++) {
            if(i != j) dist[i][j] = -1;
        }
    }
    for (ll i = 0; i < M; i ++) {
        ll a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = led(dist[a][b], c);
        dist[b][a] = led(dist[a][b], c);
    }
    
    for (ll i = 1; i <= N; i ++) {
        for (ll j = 1; j <= N; j ++) {
            for (ll k = 1; k <= N; k ++) {
                if((j == i) || (j == k) || (i == k)) continue;
                if(dist[i][k] >= 0 && dist[i][j] >= 0) dist[j][k] = led(dist[j][k], dist[i][k] + dist[i][j]);
            }
        }
    } 
    
    for (ll i = 0; i < Q; i ++) {
        ll a, b; cin >> a >> b;
        cout << dist[a][b] << endl;
    }
}