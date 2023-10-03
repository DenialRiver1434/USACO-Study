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

const ll MAX_N = 1e5;
ll N, length[MAX_N], totfile = 0;
V<ll> conn[MAX_N];
bool isfile[MAX_N];

PL dp1[MAX_N];

void dfs1 (ll pos) {
	ll tot = 0, subsize = isfile[pos];
	for (auto c : conn[pos]) {
		dfs1 (c);
		subsize += dp1[c].S;
		tot += dp1[c].F;
		if (isfile[c]) {
			tot += dp1[c].S * length[c];
		}
		else {
			tot += dp1[c].S * (length[c] + 1);
		}
	}
	dp1[pos] = {tot, subsize};
}

void dfs2 (ll pos, ll down) {
	down += 3 * (totfile - dp1[pos].S);
	down += dp1[pos].F;
	dp1[pos].F += (down - dp1[pos].F);
	for (auto c : conn[pos]) {
		ll t = dp1[c].F;
		if (isfile[c]) {
			t += dp1[c].S * length[c];
		}
		else {
			t += dp1[c].S * (length[c] + 1);
		}
		dfs2 (c, down - t);
	}
}

int main () {
	fileread("dirtraverse");

	fin >> N;
	f0r (i, 0, N) {
		string x; fin >> x;
		length[i] = len(x);
		ll M; fin >> M;
		isfile[i] = (M == 0);
		f0r (j, 0, M) {
			ll a; fin >> a;
			conn[i].pb(a - 1);
		}
		totfile += isfile[i];
	}
	dfs1 (0);
	dfs2 (0, 0);

	ll best = INF;
	f0r (i, 0, N) {
		if (!isfile[i]) {
			best = min(best, dp1[i].F);
		}
	}
	fout << best << endl;
}