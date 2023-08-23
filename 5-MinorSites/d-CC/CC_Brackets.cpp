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

int N, K, dp[700][701];
vector<int> value, brackets; 

int main () {
	cin >> N >> K;
	brackets = value = vector<int>(N);
	cin >> value >> brackets;

	dp[0][1] = 0;
	f0r (i, 0, N - 1) {
		dp[i + 1][i + 2] = 0;
		if (brackets[i] + K == brackets[i + 1]) {
			dp[i][i + 2] = value[i] + value[i + 1];
		}
	}
	
	f0r (diff, 3, N + 1) {
		f0r (start, 0, N - diff + 1) {
			int end = start + diff;
			if (brackets[start] + K == brackets[end - 1]) {
				dp[start][end] = max(dp[start][end], dp[start + 1][end - 1] + value[start] + value[end - 1]);
			}
			f0r (mid, start + 1, end) {
				dp[start][end] = max(dp[start][end], dp[start][mid] + dp[mid][end]);
			}
		}
	}
	cout << dp[0][N] << endl;
}