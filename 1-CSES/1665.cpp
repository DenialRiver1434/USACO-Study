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
#define pq priority_queue
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define For(i, end, begin) for (ll i = end; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); fin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

ll dp[2][52][10001], N, X;
V<ll> arr;

int main () {
    cin >> N >> X;
    arr = V<ll>(N);
    cin >> arr;
    sort(all(arr));

    dp[1][0][5000] = 1;
    f0r (i, 0, N) {
        // Reset
        f0r (j, 0, 51) {
            f0r (k, 0, 5001 + X) {
                dp[i % 2][j][k] = 0;
            }
        }
        f0r (j, 0, 51) {
            f0r (k, 0, 5001 + X) {
                if((i == 1) && (j == 0) && (k == 5001)) {
                    cout << "";
                }

                bool curi = i % 2;
                // i goes into its own new complete 
                dp[curi][j][k] = dp[!curi][j][k];
                
                // i joins old incomplete
                dp[curi][j][k] += j * dp[!curi][j][k];

                // i joins old and completes
                if((j < 51) && ((k - arr[i]) > 0)) {
                    dp[curi][j][k] += (j + 1) * dp[!curi][j + 1][k - arr[i]];
                }

                // i starts new incomplete
                if((j > 0) && ((k + arr[i]) < (5001 + X))) {
                    dp[curi][j][k] += dp[!curi][j - 1][k + arr[i]];
                }

                dp[curi][j][k] %= MOD;
            }
        }
    }

    ll tot = 0;
    f0r (k, 5000, 5001 + X) {
        tot += dp[(N - 1) % 2][0][k];
        tot %= MOD;
    }
    cout << tot << endl;
}