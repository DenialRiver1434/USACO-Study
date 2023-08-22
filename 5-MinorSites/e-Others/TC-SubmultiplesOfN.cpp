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

ll lB, dp[5000][1000], N;
ll arr[5000], first_next[5000][10], ans = 0;

int main () {
	string B; cin >> B >> N;
	lB = len(B);

	f0r (i, 0, 5000) {
		f0r (j, 0, 1000) {
			dp[i][j] = 0;
		}
	}
	f0r (i, 0, lB) {
		f0r (j, 0, 10) first_next[i][j] = INF;
	}
	f0r (i, 0, lB) {
		ll num = int(B[i]) - int('0');
		arr[i] = num;
		f0r (j, 0, i) {
			if (first_next[j][num] == INF) first_next[j][num] = i;
		}
	}
	
	bool visited[10];
	f0r (i, 0, 10) visited[i] = 0;
	f0r (i, 0, lB) {
		if (visited[arr[i]]) continue;
		visited[arr[i]] = 1;
		if(arr[i] != 0) {
			dp[i][arr[i] % N] = 1;
		}
	}
	
	f0r (i, 0, lB) {
		if (visited[arr[i]]) continue;
		visited[arr[i]] = 1;
		dp[i][arr[i] % N] = 1;
	}
	f0r (i, 0, lB) {
		f0r (j, 0, N) {
			f0r (k, 0, 10) {
				if (first_next[i][k] != INF) {
					ll newpos = first_next[i][k];
					dp[newpos][(10 * j + k) % N] += dp[i][j];
					dp[newpos][(10 * j + k) % N] %= MOD;
				}
			}
		}
		ans += dp[i][0];
		ans %= MOD;
	}
	cout << ans << endl;
}