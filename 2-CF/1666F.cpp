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

const ll MAX_N = 5e3; // 5e3

ll N, nCk[MAX_N][MAX_N];

void tc () {
	ll N; cin >> N;
	V<ll> heights(N);
	cin >> heights;
	reverse(all(heights));

	V<PL> nums;
	for (auto h : heights) {
		if (nums.empty()) nums.pb({h, 1});
		else if (nums.back().F != h) nums.pb({h, 1});
		else nums.back().S ++;
	}

	V<V<ll>> dp(N + 1, vector<ll>(N + 1, 0ll));
	ll passed = 0;
	dp[0][0] = 1;
	f0r (i, 0, len(nums)) {
		f0r (j, 0, passed + 1) {
			ll open = max(j - 1, 0LL) + (j == N / 2) - (passed - j);
			if (j <= N / 2) {
				dp[passed + nums[i].S][j] += nCk[max(0LL, open)][nums[i].S] * dp[passed][j];
				dp[passed + nums[i].S][j] %= MOD;
			}
			if ((j + 1) <= N / 2) {
				dp[passed + nums[i].S][j + 1] += nCk[max(0LL, open)][nums[i].S - 1] * dp[passed][j];
				dp[passed + nums[i].S][j + 1] %= MOD;
			}
		}
		passed += nums[i].S;
	}
	cout << dp[N][N / 2] << endl;
}

int main () {
	ll T; cin >> T;
	nCk[0][0] = 1;
	f0r (i, 1, MAX_N) {
		nCk[i][0] = nCk[i][i] = 1;
		f0r (j, 1, MAX_N) {
			nCk[i][j] = (nCk[i - 1][j - 1] + nCk[i - 1][j]) % MOD;
		}
	}
	while (T --) {
		tc ();
	}
}