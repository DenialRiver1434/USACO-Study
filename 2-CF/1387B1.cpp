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
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

V<V<ll>> conn;
V<ll> val;
ll N, ans = 0;

void dfs (ll pos, ll pre) {
	for (auto c : conn[pos]) {
		if (c != pre) { dfs (c, pos); }
	}
	if (val[pos] == pos) {
		if (pre == -1) {
			ans += 2;
			swap(val[pos], val[conn[pos][0]]);
		}
		else {
			ans += 2;
			swap(val[pos], val[pre]);
		}
	}
}

int main () {
	cin >> N;
	conn = V<V<ll>>(N);
	val = V<ll>(N);
	f0r (i, 0, N - 1) {
		ll a, b;
		cin >> a >> b;
		conn[a - 1].pb(b - 1);
		conn[b - 1].pb(a - 1);
		val[i] = i;
	}
	val[N - 1] = N - 1;
	dfs (0, -1);
	
	cout << ans << endl;
	for (auto x : val) {
		cout << x + 1 << " ";
	}
}