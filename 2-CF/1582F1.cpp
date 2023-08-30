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
#define MOD 998244353
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0LL); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

ll N, dp[512];

int main () {
	cin >> N;
	f0r (i, 0, 512) dp[i] = INF;

	dp[0] = 0;
	f0r (i, 0, N) {
		ll a; cin >> a;
		f0r (j, 0, 512) {
			if (dp[a ^ j] < a) {
				dp[j] = min(dp[j], a);
			}
		}
	}
	ll tot = 0;
	f0r (i, 0, 512) {
		if (dp[i] != INF) tot ++;
	}
	cout << tot << endl;
	f0r (i, 0, 512) {
		if (dp[i] != INF) cout << i << " ";
	}
}