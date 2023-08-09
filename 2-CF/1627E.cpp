#include <bits/stdc++.h> 
using namespace std;
#define pb push_back 
#define is insert
#define lb lower_bound
#define ll long long
#define V vector
#define MS multiset
#define PL pair<ll, ll>
#define F first
#define S second
#define pq priority_queue
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define For(i, end, begin) for (ll i = end - 1; i >= begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); fin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

ll N, M, K, floor_damage[100000];
vector<ll> sensitive[100000];
map<ll, vector<pair<ll, ll>>> conn; // x0, y0 -> x1, y1, cost
map<ll, ll> dist;

void dijkstra(ll src) {  // Updates dist, src = starting
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

void tc () {
    conn.clear(); dist.clear();
    f0r (i, 0, N) {
        sensitive[i].clear();
    }

    cin >> N >> M >> K;
    f0r (i, 0, N) {
        cin >> floor_damage[i];
    }
    f0r (i, 0, K) {
        ll a, b, c, d, h; cin >> a >> b >> c >> d >> h;
        a --; b --; c --; d --; h = (1000000 * (c - a)) - h;
        sensitive[a].pb(b);
        sensitive[c].pb(d);
        conn[a * M + b].pb({c * M + d, h});
        dist[a * M + b] = INF;
    }
    sensitive[0].pb(0); sensitive[N - 1].pb(M - 1);
    dist[N * M - 1] = INF;
    f0r (i, 0, N) {
        sort(all(sensitive[i]));
        ll L = len(sensitive[i]);
        f0r (j, 1, L) {
            conn[i * M + sensitive[i][j - 1]].pb({i * M + sensitive[i][j], abs(sensitive[i][j] - sensitive[i][j - 1]) * floor_damage[i]});
            conn[i * M + sensitive[i][j]].pb({i * M + sensitive[i][j - 1], abs(sensitive[i][j] - sensitive[i][j - 1]) * floor_damage[i]});
            dist[i * M + sensitive[i][j]] = INF;
            dist[i * M + sensitive[i][j - 1]] = INF;
        }
    }
    dijkstra (0);
    if (dist[N * M - 1] == INF) {
        cout << "NO ESCAPE" << endl;
        return;
    }
    cout << dist[N * M - 1] - (N - 1) * 1000000 << endl;
}

int main () {
    ll T;
    cin >> T;
    while (T --) {
        tc ();
    }
}