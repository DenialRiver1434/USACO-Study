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

const ll MAX_N = 1e5 + 3; // 10
ll udist[MAX_N], vdist[MAX_N];
tuple<ll, ll, ll> optimal[MAX_N]; // (Distance, best distance from u to v w/ pass, best distance from u to v w/ pass passing through pos)

ll N, M, s, t, u, v;
V<PL> conn[MAX_N];

int main () {
	cin >> N >> M >> s >> t >> u >> v;
	s --; t --; u --; v --;
	f0r (i, 0, M) {
		ll a, b, c; cin >> a >> b >> c;
		a --; b --;
		conn[a].pb({b, c});
		conn[b].pb({a, c});
	}
	f0r (i, 0, N) {
		udist[i] = vdist[i] = INF;
		optimal[i] = make_tuple(INF, INF, INF);
	}
	udist[u] = 0; vdist[v] = 0;

	using T = PL;
	PQ<T, vector<T>, greater<T>> altpq;
	altpq.push({0, u});
	while (altpq.size()) {
		ll cdist;
		ll node;
		tie(cdist, node) = altpq.top();
		altpq.pop();
		if (cdist != udist[node]) continue;
		for (pair<ll, ll> i : conn[node]) {
			if (cdist + i.second < udist[i.first]) {
				altpq.push({udist[i.first] = cdist + i.second, i.first});
			}
		}
	}
	
	altpq.push({0, v});
	while (altpq.size()) {
		ll cdist;
		ll node;
		tie(cdist, node) = altpq.top();
		altpq.pop();
		if (cdist != vdist[node]) continue;
		for (pair<ll, ll> i : conn[node]) {
			if (cdist + i.second < vdist[i.first]) {
				altpq.push({vdist[i.first] = cdist + i.second, i.first});
			}
		}
	}

	ll ans = udist[v];
	
	using X = pair<tuple<ll, ll, ll>, ll>;
	PQ<X, vector<X>, greater<X>> pq;
	pq.push({{0, udist[v], vdist[s] + udist[s]}, s});
	optimal[s] = {0, udist[v], vdist[s] + udist[s]};

	while (pq.size()) {
		tuple<ll, ll, ll> score = pq.top().F; ll pos = pq.top().S;
		ll dist, optdist, ridedist;
		tie(dist, optdist, ridedist) = score;
		if (score == make_tuple(7LL, 15LL, 15LL)) {
			cout << "";
		}

		pq.pop();
		if (score != optimal[pos]) continue;
		
		for (pair<ll, ll> i : conn[pos]) {
			ll newpos = i.F, cost = i.S;
			ll potov = dist + cost;
			ll potdist = min(ridedist - vdist[pos] + vdist[newpos], udist[newpos] + vdist[newpos]);
			ll potopt = min(optdist, potdist);

			if (make_tuple(potov, potopt, potdist) < optimal[newpos]) {
				pq.push({optimal[newpos] = {potov, potopt, potdist}, newpos});
			}
		}
	}
	ans = min(ans, get<1>(optimal[t]));

	f0r (i, 0, N) {
		optimal[i] = make_tuple(INF, INF, INF);
	}
	swap (s, t);

	pq.push({{0, udist[v], vdist[s] + udist[s]}, s});
	optimal[s] = {0, udist[v], vdist[s] + udist[s]};

	while (pq.size()) {
		tuple<ll, ll, ll> score = pq.top().F; ll pos = pq.top().S;
		ll dist, optdist, ridedist;
		tie(dist, optdist, ridedist) = score;

		pq.pop();
		if (score != optimal[pos]) continue;
		
		for (pair<ll, ll> i : conn[pos]) {
			ll newpos = i.F, cost = i.S;
			ll potov = dist + cost;
			ll potdist = min(ridedist - vdist[pos] + vdist[newpos], udist[newpos] + vdist[newpos]);
			ll potopt = min(optdist, potdist);

			if (make_tuple(potov, potopt, potdist) < optimal[newpos]) {
				pq.push({optimal[newpos] = {potov, potopt, potdist}, newpos});
			}
		}
	}
	ans = min(ans, get<1>(optimal[t]));
	cout << ans << endl;
}