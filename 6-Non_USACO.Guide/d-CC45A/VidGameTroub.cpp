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
#define INF 1000000000000000000LL
#define inf 1000000000
#define MOD 998244353
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_B = 1e5;
ll N, B, dp[2][MAX_B + 1], bes = -INF;

int main () {
    f0r (i, 0, MAX_B + 1) {
        dp[0][i] = dp[1][i] = -INF;
    }
    dp[0][0] = 0;

    cin >> N >> B;
    f0r (i, 0, N) {
        ll base, K;
        cin >> base >> K;

        f0r (j, 0, K) {
            ll cost, val;
            cin >> cost >> val;

            // Ya lo tienes
            For (k, B, cost - 1) {
                dp[1][k] = max(dp[1][k], dp[1][k - cost] + val);
            }
            // Haven't buyed console
            For (k, B, cost + base - 1) {
                if (k - cost - base == 0) {
                    cout << "";
                }
                dp[1][k] = max(dp[1][k], dp[0][k - cost - base] + val);
            }
        }

        f0r (j, 0, B + 1) {
            dp[0][j] = max(dp[0][j], dp[1][j]);
            dp[1][j] = -INF;
            bes = max(bes, dp[0][j]);
        }
    }

    cout << bes << endl;