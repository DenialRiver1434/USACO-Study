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

int main () {
	ll N, M, ans = 0;
	cin >> N >> M;
	V<ll> nums(N);
	cin >> nums;
	
	V<ll> dp[2];
	dp[0] = dp[1] = V<ll>(N + 1, INF);
	for (ll i : nums) {
		ll pos = lower_bound(dp[0].begin(), dp[0].end(), i) - dp[0].begin();
		dp[0][pos] = i;
		ans = max(ans, pos);

		ll pos2 = lower_bound(dp[1].begin(), dp[1].end(), i) - dp[1].begin();
		dp[1][pos2] = i;
		ans = max(ans, pos2);

		dp[1][pos] = min(dp[1][pos], i - M);
	}
	cout << ans + 1 << endl;
}