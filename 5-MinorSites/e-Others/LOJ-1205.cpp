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

ll dp[18][3]; // 0 -> under, 1 -> line, 2 -> line over
ll calc[18];

ll tc (ll n) {
    if (n <= 0) return 0;

    V<ll> number;
    while (n > 0) {
        number.pb(n % 10);
        n /= 10;
    }
    reverse(all(number));
    memset(dp, 0, sizeof(dp));
    
    f0r (i, 1, 10) {
        if (i > number[0]) continue;
        else if (i == number[0] && i > number[len(number) - 1]) {
            dp[1][2] ++;
        }
        else if (i == number[0]) dp[1][1] ++;
        else dp[1][0] ++;
    }

    f0r (i, 1, (len(number) + 1) / 2) {
        f0r (newdigit, 0, 10) {
            if (newdigit > number[i]) {
                // 0 -> 0
                dp[i + 1][0] += dp[i][0];
            }
            else if (newdigit == number[i] && newdigit > number[len(number) - 1 - i]) {
                // 0 -> 0
                dp[i + 1][0] += dp[i][0];

                // 1 -> 2
                dp[i + 1][2] += dp[i][1];

                // 2 -> 2
                dp[i + 1][2] += dp[i][2];
            }
            else if (newdigit == number[i] && newdigit == number[len(number) - 1 - i]) {
                // 0 -> 0
                dp[i + 1][0] += dp[i][0];

                // 1 -> 1
                dp[i + 1][1] += dp[i][1];

                // 2 -> 2
                dp[i + 1][2] += dp[i][2];
            }
            else if (newdigit == number[i]) {
                // 0 -> 0
                dp[i + 1][0] += dp[i][0];

                // 1 -> 1
                dp[i + 1][1] += dp[i][1];

                // 2 -> 1
                dp[i + 1][1] += dp[i][2];
            }
            else {
                // 0 -> 0
                dp[i + 1][0] += dp[i][0];

                // 1 -> 0
                dp[i + 1][0] += dp[i][1];

                // 2 -> 0
                dp[i + 1][0] += dp[i][2];
            }
        }
    }

    ll tot = dp[(len(number) + 1) / 2][0] + dp[(len(number) + 1) / 2][1];
    f0r (length, 1, len(number)) {
        tot += calc[length];
    }
    return tot;
}

int main () {
    int T; cin >> T;
    ll val = 9;
    f0r (i, 0, 8) {
        calc[i * 2 + 1] = calc[i * 2 + 2] = val;
        val *= 10;
    }
    
    f0r (i, 0, T) {
        ll a, b; cin >> a >> b;
        if (a > b) swap (a, b);
        if (a == 0) {
            cout << "Case " << i + 1 << ": " << tc (b) + 1 << endl;
        }
        else if (a == 1) {
            cout << "Case " << i + 1 << ": " << tc (b) << endl;
        }
        else {
            cout << "Case " << i + 1 << ": " << tc (b) - tc (a - 1) << endl;
        }
    }
}