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

ll N, M;
V<ll> conn[40];
bool path[40][40];

const ll DP_MAX = 1LL << 20LL;
ll minA[DP_MAX], minB[DP_MAX];
ll match[DP_MAX];

int main () {
	cin >> N >> M;
	f0r (i, 0LL, N) {
		f0r (j, 0LL, N) {
			if (i != j) conn[i].pb(j);
			path[i][j] = 1LL;
			path[j][i] = 1LL;
		}
	}
	f0r (i, 0LL, M) {
		ll a, b; cin >> a >> b;
		conn[a].erase(find(all(conn[a]), b));
		conn[b].erase(find(all(conn[b]), a));
		path[a][b] = 0LL;
		path[b][a] = 0LL;
	}
	f0r (i, 0LL, DP_MAX) {
		minA[i] = minB[i] = match[i] = 0LL;
	}

	f0r (i, 20LL, N) {
		ll bmask = 0LL;
		for (auto c : conn[i]) {
			if (c < 20LL) {
				bmask += 1LL << c;
			}
		}
		f0r (j, 0LL, DP_MAX) {
			if ((j | bmask) == bmask) {
				match[j] += 1LL << (i - 20LL);
			}
		}
	}
	
	f0r (i, 1LL, DP_MAX) {
		f0r (j, 0LL, min(20LL, N)) {
			if ((1LL << j & i) > 0LL) {
				ll alt = minA[i - (1LL << j)];
				bool good = 1LL;
				f0r (k, 0LL, min(20LL, N)) {
					if (((1LL << k & alt) > 0LL) && !path[k][j]) {
						good = 0LL;
					}
				}
				if (good) alt += (1LL << j);
				if (__builtin_popcountll(alt) > __builtin_popcountll(minA[i])) {
					minA[i] = alt;
				}
			}
		}
		
		f0r (j, 20LL, min(40LL, N)) {
			if ((1LL << (j - 20LL) & i) > 0LL) {
				ll alt = minB[i - (1LL << (j - 20LL))];
				bool good = 1LL;
				f0r (k, 20LL, min(40LL, N)) {
					if (((1LL << (k - 20LL) & alt) > 0LL) && !path[k][j]) {
						good = 0LL;
					}
				}
				if (good) alt += (1LL << (j - 20LL));
				if (__builtin_popcountll(alt) > __builtin_popcountll(minB[i])) {
					minB[i] = alt;
				}
			}
		}
	}

	ll best = 0LL;
	f0r (i, 0LL, DP_MAX) {
		if (minA[i] == i) {
			ll pos = i + (minB[match[i]] << 20LL);
			if (__builtin_popcountll(pos) > __builtin_popcountll(best)) {
				best = pos;
			}
		}
	}
	cout << __builtin_popcountll(best) << endl;
	f0r (i, 0LL, N) {
		if ((1LL << i & best) > 0LL) {
			cout << i << " ";
		}
	}
}