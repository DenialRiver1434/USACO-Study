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
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

ll N, K, dp[302][302]; 
V<ll> horses;

int main () {
	cin >> N >> K; K += 2;
	horses = V<ll>(K - 2);
	cin >> horses;
	horses.pb(0); horses.pb(N + 1);
	sort(all(horses));

	f0r (i, 0, 302) {
		f0r (j, 0, 302) dp[i][j] = INF;
	}
	f0r (i, 0, K) dp[i][i] = 0;
	f0r (i, 0, K - 1) {
		dp[i][i + 1] = horses[i + 1] - horses[i] - 1;
	}
	f0r (i, 0, K - 2) {
		dp[i][i + 2] = horses[i + 2] - horses[i] - 1;
	}
	f0r (diff, 3, K) {
		f0r (start, 0, K - diff) {
			ll end = start + diff;
			dp[start][end] = min(dp[start][end], dp[start][start + 1] + dp[start + 1][end] + horses[end] - horses[start + 1]);
			dp[start][end] = min(dp[start][end], dp[end - 1][end] + dp[start][end - 1] + horses[end - 1] - horses[start]);
			f0r (mid, start + 2, end - 1) {
				dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid][end] + (horses[end] - horses[start] - 1));
			}
		}
	}
	cout << dp[0][K - 1] << endl;
}