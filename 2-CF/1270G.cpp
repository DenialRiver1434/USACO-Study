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

const ll MAX_N = 1e6 + 5;
ll nxt[MAX_N];
ll vist[MAX_N];

int main () {
	fastio;

	ll T; cin >> T;
	while (T --) {
		ll N; cin >> N;
		f0r (i, 0, N) {
			ll a; cin >> a;
			nxt[i] = i - a;
			vist[i] = -1;
		}
		
		vist[0] = 0;
		ll pos = 0;
		while (true) {
			ll nval = vist[pos] + 1;
			pos = nxt[pos];
			if (vist[pos] != -1) {
				cout << nval - vist[pos] << '\n';
				break;
			}
			vist[pos] = nval;
		}

		ll npos = pos;
		while (true) {
			npos = nxt[npos];
			cout << npos + 1 << " ";
			if (npos == pos) {
				break;
			}
		}
		cout << '\n';
	}
}
