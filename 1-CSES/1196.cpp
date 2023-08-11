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
#define f0r(i, begin, fin) for (ll i = begin; i < fin; i ++) 
#define For(i, fin, begin) for (ll i = fin - 1; i >= begin; i --) 
#define all(x) x.begin(), x.fin()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); fin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 1e5;
ll N, M, K;
V<PL> conn[MAX_N];
MS<ll> dist[MAX_N];

void dijkstra(ll src) {  // Updates dist, src = starting
	using T = pair<ll, ll>;
	priority_queue<T, vector<T>, greater<T>> pq;
	pq.push({0, src});

	while (pq.size()) {
		ll cdist;
		ll node;
		tie(cdist, node) = pq.top();
		pq.pop();
		if (cdist > *(dist[node].rbegin())) continue;
		for (pair<ll, ll> i : conn[node]) {
			if (cdist + i.second < *(dist[i.first].rbegin())) {
                dist[i.first].erase(dist[i.first].find(*(dist[i.first].rbegin())));
                dist[i.first].is(cdist + i.second);
				pq.push({cdist + i.second, i.first});
			}
		}
	}

    for (auto d : dist[N - 1]) cout << d << " ";
    cout << endl;
}

int main () {
    cin >> N >> M >> K;
    f0r (i, 0, M) {
        ll a, b, c; cin >> a >> b >> c;
        conn[a - 1].pb({b - 1, c});
    }

    dist[0].is(0);
    f0r (j, 1, K) {
        dist[0].is(INF);
    }
    f0r (i, 1, N) {
        f0r (j, 0, K) {
            dist[i].is(INF);
        }
    }

    dijkstra(0);
}