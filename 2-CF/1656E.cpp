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

void tc () {
	ll N; cin >> N;
	V<V<ll>> conn(N);
	V<ll> distroot(N, -1);
	f0r (i, 0, N - 1) {
		ll a, b; cin >> a >> b;
		a --; b --;
		conn[a].pb(b);
		conn[b].pb(a);
	}

	queue<PL> q;
	q.push({0, 0});
	while (!q.empty()) {
		PL x = q.front();
		q.pop();

		distroot[x.F] = x.S;
		for (auto c : conn[x.F]) {
			if (distroot[c] == -1) {
				q.push({c, x.S + 1});
			}
		}
	}

	f0r (i, 0, N) {
		if (distroot[i] % 2) {
			cout << len(conn[i]) << " ";
		}
		else {
			cout << -len(conn[i]) << " ";
		}
	}
	cout << endl;
}

int main () {
	ll T; cin >> T;
	while (T --) {
		tc ();
	}
}