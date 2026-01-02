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
#define For(i, end, begin) for (ll i = end; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 1e5 + 5;
set<ll> adj[MAX_N];
set<ll> active;
set<PL> degrees;

ll deg[MAX_N],  dir[MAX_N];
V<ll> indpset;

void delvert (ll pos) {
	active.erase(pos);
	degrees.erase({deg[pos], pos});
	deg[pos] = 0;
	for (auto a : adj[pos]) {
		adj[a].erase(pos);
		degrees.erase({deg[a], a});
		deg[a] --;
		degrees.is({deg[a], a});
	}
	adj[pos].clear();
}

void powerdel (ll pos) {
	indpset.pb(pos);
	V<ll> tmp;
	for (auto a : adj[pos]) {
		tmp.pb(a);
	}
	for (auto t : tmp) {
		delvert(t);
	}
	delvert(pos);
}

ll dist[MAX_N];

int main () {
	fastio;

	ll N, M; cin >> N >> M;
	f0r (i, 0, M) {
		ll a, b; cin >> a >> b;
		active.is(a);
		active.is(b);
		deg[a] ++; deg[b] ++;
		adj[a].is(b);
		adj[b].is(a);
	}

	for (auto a : active) {
		degrees.is({deg[a], a});
	}
	
	bool normexit = true;
	ll limit = floor(sqrt(N)) - 1;
	while (!active.empty()) {
		PL vert = *degrees.begin();
		if (vert.F > limit) {
			normexit = false;
			break;
		}
		powerdel(vert.S);
	}

	if (normexit) {
		cout << 1 << '\n';
		f0r (i, 0, ceil(sqrt(N))) {
			cout << indpset[i] << " ";
		}
	} else {
		cout << 2 << '\n';
		memset(dist, -1, sizeof(dist));

		ll stpos = *(active.begin());
		dist[stpos] = 0;

		while (true) {
			bool found = false;
			for (auto a : adj[stpos]) {
				if (dist[a] == -1) {
					dist[a] = dist[stpos] + 1;
					dir[stpos] = a;
					stpos = a;
					found = true;
					break;
				}
			}
			if (found) continue;

			ll mst = dist[stpos], mstachieve = stpos;
			for (auto a : adj[stpos]) {
				if (dist[a] < mst) {
					mst = dist[a];
					mstachieve = a;
				}
			}

			cout << dist[stpos] - mst + 1 << endl;
			ll curpos = mstachieve;
			cout << curpos << " ";
			while (true) {
				curpos = dir[curpos];
				cout << curpos << " ";
				if (curpos == stpos) break;
			}
			break;
		}
	}
}
