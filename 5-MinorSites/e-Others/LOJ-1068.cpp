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

int tot, dp[2][100][100][2];

int tc (int n, int k) {
    if (n == 0) return 0;
    if (k >= 100) return 0;

    tot = 0;

    V<int> number;
    while (n > 0) {
        number.pb(n % 10);
        n /= 10;
    }
    reverse(all(number));
    memset(dp, 0, sizeof(dp));
    
    f0r (i, 0, 10) {
        if (i > number[0]) continue;
        bool under = i < number[0];
        dp[1][i][i % k][under] ++;
    }

    f0r (i, 1, len(number)) {
        memset(dp[(i + 1) % 2], 0, sizeof(dp[(i + 1) % 2]));
        f0r (n1, 0, 90) {
            f0r (m, 0, k) {
                f0r (newdigit, 0, 10) {
                    if (newdigit > number[i]) {
                        // isunder (1 -> 1)
                        dp[(i + 1) % 2][n1 + newdigit][(m * 10 + newdigit) % k][1] += dp[i % 2][n1][m][1];
                    }
                    else if (newdigit == number[i]) {
                        // isunder (1 -> 1)
                        dp[(i + 1) % 2][n1 + newdigit][(m * 10 + newdigit) % k][1] += dp[i % 2][n1][m][1];

                        // isunder (0 -> 0)
                        dp[(i + 1) % 2][n1 + newdigit][(m * 10 + newdigit) % k][0] += dp[i % 2][n1][m][0];
                    }
                    else {
                        // isunder (1 -> 1)
                        dp[(i + 1) % 2][n1 + newdigit][(m * 10 + newdigit) % k][1] += dp[i % 2][n1][m][1];

                        // isunder (0 -> 1)
                        dp[(i + 1) % 2][n1 + newdigit][(m * 10 + newdigit) % k][1] += dp[i % 2][n1][m][0];
                    }
                }
            }
        }
    }
    
    for (int n1 = k; n1 < 100; n1 += k) {
        tot += dp[len(number) % 2][n1][0][0];
        tot += dp[len(number) % 2][n1][0][1];
    }
    return tot;
}

int main () {
    int T; cin >> T;
    f0r (i, 0, T) {
        int a, b, k; cin >> a >> b >> k;
        cout << "Case " << i + 1 << ": " << tc(b, k) - tc(a - 1, k) << endl;
    }
}