#include <bits/stdc++.h> 
using namespace std;
#define pb push_back 
#define is insert
#define ll long long
#define V vector
#define MS multiset
#define PL pair<ll, ll>
#define F first
#define S second
#define PQ priority_queue
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define For(i, end, begin) for (ll i = end; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0LL); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 2002;

ll N, M, start, fin, conndist[MAX_N][MAX_N];

ll distfin[MAX_N], diststart[MAX_N], dir[MAX_N];
V<PL> conn[MAX_N];
V<tuple<ll, ll, ll>> roads;
V<ll> revdir[MAX_N];

int main () {
	fastio;
	cin >> N >> M >> start >> fin;
	start --; fin --;
	f0r (i, 0, N) {
		dir[i] = distfin[i] = diststart[i] = INF;
		f0r (j, 0, N) conndist[i][j] = INF;
	}

	f0r (i, 0, M) {
		ll a, b, c; cin >> a >> b >> c;
		roads.pb({a - 1, b - 1, c});
		conn[a - 1].pb({b - 1, c});
		conn[b - 1].pb({a - 1, c});
		conndist[a - 1][b - 1] = min(conndist[a - 1][b - 1], c);
		conndist[b - 1][a - 1] = min(conndist[b - 1][a - 1], c);
	}
	V<ll> road;
	ll K; cin >> K;
	f0r (i, 0, K) {
		ll a; cin >> a;
		road.pb(a - 1);
	}
	reverse(all(road));
	distfin[fin] = 0; dir[fin] = -1;
	f0r (i, 0, K - 1) {
		dir[road[i + 1]] = road[i];
	}
	reverse(all(road));

	using T = tuple<ll, ll, ll>;
	priority_queue<T, vector<T>, greater<T>> pq;
	pq.push({0, fin, 0});
	while (pq.size()) {
		ll cdist, node, prepos;
		tie(cdist, node, prepos) = pq.top();
		pq.pop();
		if (cdist != distfin[node]) continue;
		if (dir[node] == INF) {
			dir[node] = prepos;
		}
		for (pair<ll, ll> i : conn[node]) {
			if (cdist + i.second < distfin[i.first]) {
				pq.push({distfin[i.first] = cdist + i.second, i.first, node});
			}
		}
	}
	f0r (i, 0, N) {
		if (dir[i] != -1) {
			revdir[dir[i]].pb(i);
		}
	}

	pq.push({0, start, 0});
	diststart[start] = 0;
	while (pq.size()) {
		ll cdist, node, prepos;
		tie(cdist, node, prepos) = pq.top();
		pq.pop();
		if (cdist != diststart[node]) continue;
		for (pair<ll, ll> i : conn[node]) {
			if (cdist + i.second < diststart[i.first]) {
				pq.push({diststart[i.first] = cdist + i.second, i.first, node});
			}
		}
	}
	
	ll color[N];
	f0r (i, 0, K - 1) {
		f0r (j, 0, N) color[j] = -1;
		ll pointa = road[i], pointb = road[i + 1];
		queue<ll> q;
		q.push(pointa);
		color[pointa] = 0;
		while (q.size()) {
			ll pos = q.front();
			q.pop();
			for (auto c : revdir[pos]) {
				if (pointa == c && pointb == pos) {
					continue;
				}
				else {
					if (color[c] == -1) {
						color[c] = 0;
						q.push(c);
					}
				}
			}
		}
		q.push(fin);
		color[fin] = 1;
		while (q.size()) {
			ll pos = q.front();
			q.pop();
			for (auto c : revdir[pos]) {
				if (pointa == c && pointb == pos) {
					continue;
				}
				else {
					if (color[c] == -1) {
						color[c] = 1;
						q.push(c);
					}
				}
			}
		}

		ll best = INF;
		for (auto r : roads) {
			ll a, b, c; tie(a, b, c) = r;
			if (a == pointa && b == pointb) continue;
			if (b == pointa && a == pointb) continue;
			if (color[a] == 0 && color[b] == 1) {
				best = min(best, diststart[a] + c + distfin[b]);
			}
			if (color[a] == 1 && color[b] == 0) {
				best = min(best, distfin[a] + c + diststart[b]);
			}
		}
		if (best == INF) cout << -1 << endl;
		else cout << best << endl;
	}
}