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
#define f0r(i, begin, finish) for (ll i = begin; i < finish; i ++) 
#define For(i, finish, begin) for (ll i = finish; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000LL
#define inf 1000000000LL
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

ll N, C;
V<ll> conn[262144];
ll dist[262144];

int main () {
	memset(dist, -1, sizeof(dist));
	f0r (i, 0, 1 << 18) {
		f0r (k, 0, 18) {
			conn[i].pb(i ^ (1 << k));
		}
	}

	cin >> C >> N;

	V<ll> inps;
	queue<ll> q;
	f0r (i, 0, N) {
		string code; cin >> code;
		ll trans = 0;
		f0r (j, 0, C) {
			trans += (1 << j) * (code[j] == 'G');
		}
		inps.pb(trans);
		dist[trans] = 0;
		q.push(trans);
	}

	while (!q.empty()) {
		ll pos = q.front();
		q.pop();
		for (auto c : conn[pos]) {
			if (dist[c] == -1) {
				dist[c] = dist[pos] + 1;
				q.push(c);
			}
		}
	}
	
	for (auto i : inps) {
		cout << C - dist[(1 << C) - i - 1] << endl;
	}
}
