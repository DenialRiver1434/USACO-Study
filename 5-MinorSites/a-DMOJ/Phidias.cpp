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
#define MOD 1000000009
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_L = 605;

ll dp[MAX_L][MAX_L], W, H, N;
V<PL> sizes;

int main () {
	cin >> W >> H >> N;
    f0r (i, 0, N) {
        ll a, b; cin >> a >> b;
        sizes.pb({a, b});
    }

	f0r (i, 0, MAX_L) {
		f0r (j, 0, MAX_L) dp[i][j] = i * j;
	}
	f0r (tot, 0, 2 * MAX_L) {
		f0r (i, 0, min(MAX_L, tot + 1)) {
			ll j = tot - i;
			if (j >= MAX_L) continue;

            f0r (k, 0, N) {
                ll x = sizes[k].F, y = sizes[k].S;
                if (x <= i && y <= j) {
                    // Hori cut
                    dp[i][j] = min(dp[i][j], dp[i - x][y] + dp[i][j - y]);

                    // Vert cut
                    dp[i][j] = min(dp[i][j], dp[x][j - y] + dp[i - x][j]);
                }
            }
		}
	}
	
	cout << dp[W][H];
}