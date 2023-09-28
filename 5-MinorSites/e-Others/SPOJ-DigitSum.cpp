#include <bits/stdc++.h> 
using namespace std;
#define pb push_back 
#define is insert
#define ll unsigned long long int
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

ll tc (ll n) {
    if (n == 0) return 0;

    ll tot = 0, dp[17][150][2];

    V<ll> number;
    while (n > 0) {
        number.pb(n % 10);
        n /= 10;
    }
    reverse(all(number));
    memset(dp, 0, sizeof(dp));
    
    f0r (i, 0, 10) {
        if (i > number[0]) continue;
        bool under = i < number[0];
        dp[1][i][under] ++;
    }

    f0r (i, 1, len(number)) {
        f0r (n1, 0, 150) {
            f0r (newdigit, 0, 10) {
                if (newdigit > number[i]) {
                    // isunder (1 -> 1)
                    dp[i + 1][n1 + newdigit][1] += dp[i][n1][1];
                }
                else if (newdigit == number[i]) {
                    // isunder (1 -> 1)
                    dp[i + 1][n1 + newdigit][1] += dp[i][n1][1];

                    // isunder (0 -> 0)
                    dp[i + 1][n1 + newdigit][0] += dp[i][n1][0];
                }
                else {
                    // isunder (1 -> 1)
                    dp[i + 1][n1 + newdigit][1] += dp[i][n1][1];

                    // isunder (0 -> 1)
                    dp[i + 1][n1 + newdigit][1] += dp[i][n1][0];
                }
            }
        }
    }

    f0r (n1, 0, 150) {
        tot += dp[len(number)][n1][0] * n1;
        tot += dp[len(number)][n1][1] * n1;
    }
    return tot;
}

int main () {
    ll T; cin >> T;
    while (T --) {
        ll a, b; cin >> a >> b;
        if (a == 0) {
            cout << tc(b) << endl;
        }
        else cout << tc(b) - tc(a - 1) << endl;
    }
}