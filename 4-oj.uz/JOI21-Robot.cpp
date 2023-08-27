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

const ll MAX_N = 1e5 + 3 ; 
ll N, M;
map<ll, V<PL>> conn[MAX_N];
map<ll, ll> psum[MAX_N];

ll dp[MAX_N];
map<ll, ll> dp2[MAX_N];

int main () {
	cin >> N >> M;
	f0r (i, 0, M) {
		ll a, b, c, d; 
		cin >> a >> b >> c >> d; a --; b --;
		conn[a][c].pb({b, d});
		conn[b][c].pb({a, d});
		psum[a][c] += d; psum[b][c] += d;
	}

	f0r (i, 0, N) {
		dp[i] = INF;
	}
	
	using T = tuple<ll, ll, ll>;
	priority_queue<T, vector<T>, greater<T>> pq;
	dp[0] = 0;  
	pq.push({0, 0, -1});

	while (pq.size()) {
		ll cdist, node, prev;
		tie(cdist, node, prev) = pq.top();
		pq.pop();

		if (prev != -1) {
			if (dp2[node][prev] != cdist) continue;
			for (auto p : conn[node][prev]) {
				ll case1 = psum[node][prev] - p.S + cdist;
				if (case1 < dp[p.F]) {
					pq.push({dp[p.F] = case1, p.F, -1});
				}
			}
		}
		else {
			if (cdist != dp[node]) continue;
			for (auto i : conn[node]) {
				for (auto p : i.S) {
					ll case1 = min(psum[node][i.F] - p.S, p.S) + cdist;
					if (case1 < dp[p.F]) {
						pq.push({dp[p.F] = case1, p.F, -1});
					}

					ll case2 = cdist;
					if (dp2[p.F].find(i.F) == dp2[p.F].end()) {
						pq.push({dp2[p.F][i.F] = case2, p.F, i.F});
					}
					else if (case2 < dp2[p.F][i.F]) {
						pq.push({dp2[p.F][i.F] = case2, p.F, i.F});
					}
				}
			}
		}
	}
	if (dp[N - 1] == INF) {
		cout << -1 << endl;
	}
	else {
		cout << dp[N - 1] << endl;
	}
}