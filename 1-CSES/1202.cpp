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
#define PQ priority_queue
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

vector<pair<ll, ll>> conn[100000]; // location, distance
ll dist[100000], N, M, cnt[100000], flightc[100000];

void dijkstra1 (ll src) {  // Updates dist, src = starting
	for (ll i = 0; i < N; ++i) dist[i] = LLONG_MAX;
	
	using T = tuple<ll, ll, ll, bool>;
	priority_queue<T, vector<T>, greater<T>> pq;
	dist[src] = 0;  
    cnt[src] = 1;
	pq.push({0, src, -1, 0});

	while (pq.size()) {
		ll cdist, node, orig;
        bool excep;
		tie(cdist, node, orig, excep) = pq.top();
		pq.pop();
		if (cdist > dist[node]) continue;
        if(orig != -1) {
            cnt[node] += cnt[orig];
            cnt[node] %= MOD;
        }
        if(excep) continue;
		for (pair<ll, ll> i : conn[node]) {
			if ((cdist + i.second) < dist[i.first]) {
				pq.push({dist[i.first] = cdist + i.second, i.first, node, 0});
			}
            else if ((cdist + i.second) == dist[i.first]) {
				pq.push({dist[i.first] = cdist + i.second, i.first, node, 1});
            }
		}
	}
    cout << dist[N - 1] << " " << cnt[N - 1] << " ";
}

void dijkstra2 (ll src) {  // Updates dist, src = starting
	for (ll i = 0; i < N; ++i) {
        dist[i] = LLONG_MAX;
        flightc[i] = LLONG_MAX;
    }
	
	using T = tuple<ll, ll, ll>;
	priority_queue<T, vector<T>, greater<T>> pq;
	dist[src] = 0;  
    flightc[src] = 0;
	pq.push({0, 0, src});

	while (pq.size()) {
		ll cdist, fdist, node;
		tie(cdist, fdist, node) = pq.top();
        if(node == (N - 1)) {
            cout << flightc[node] << " ";
            break;
        }
		pq.pop();
		if (cdist != dist[node]) continue;
		for (pair<ll, ll> i : conn[node]) {
			if (cdist + i.second < dist[i.first]) {
				pq.push({dist[i.first] = cdist + i.second, flightc[node] + 1, i.first});
                flightc[i.F] = flightc[node] + 1;
			}
            else if ((cdist + i.second) == dist[i.first]) {
                if ((flightc[node] + 1) < flightc[i.first]) {
				    pq.push({cdist + i.second, flightc[node] + 1, node});
                    flightc[i.F] = flightc[node] + 1;
                }
            }
		}
	}
    cout << "";
}

void dijkstra3 (ll src) {  // Updates dist, src = starting
	for (ll i = 0; i < N; ++i) {
        dist[i] = LLONG_MAX;
        flightc[i] = -1;
    }
	
	using T = tuple<ll, ll, ll>;
	priority_queue<T, vector<T>, greater<T>> pq;
	dist[src] = 0;  
    flightc[src] = 0;
	pq.push({0, 0, src});

	while (pq.size()) {
		ll cdist, fdist, node;
		tie(cdist, fdist, node) = pq.top();
        fdist = -fdist;
        if(node == (N - 1)) {
            cout << flightc[node] << " ";
            break;
        }
		pq.pop();
		if (cdist != dist[node]) continue;
		for (pair<ll, ll> i : conn[node]) {
			if (cdist + i.second < dist[i.first]) {
				pq.push({dist[i.first] = cdist + i.second, -(flightc[node] + 1), i.first});
                flightc[i.F] = flightc[node] + 1;
			}
            else if ((cdist + i.second) == dist[i.first]) {
                if ((flightc[node] + 1) > flightc[i.first]) {
				    pq.push({cdist + i.second, -(flightc[node] + 1), node});
                    flightc[i.F] = flightc[node] + 1;
                }
            }
		}
	}
}

int main () {
    cin >> N >> M;
    f0r (i, 0, M) {
        ll a, b, c; cin >> a >> b >> c;
        conn[a - 1].pb({b - 1, c});
    }
    dijkstra1(0);
    dijkstra2(0);
    dijkstra3(0);
}