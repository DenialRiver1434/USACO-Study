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

const ll MAX_N = 300;
const ll MAX_D = 18;

ll N, ans[2][MAX_N][MAX_N]; 
ll dp[MAX_N + 1][MAX_D + 1][MAX_D + 1][3];
V<ll> digits;

void tc (ll x, bool typ) {
    if (x <= 0) return;

    V<ll> number;
    while (x > 0) {
        number.pb(x % 10);
        x /= 10;
    }
    reverse(all(number));

    ll ln = len(number);
    f0r (i, 0, N) {
        memset(dp, 0, sizeof(dp));
        
        f0r (dig, 0, ln) {
            if (digits[i] > number[dig]) {
                dp[i + 1][dig][dig][2] += 2;
                dp[i + 1][dig][dig][2] %= MOD;
            }
            else if (digits[i] == number[dig]) {
                dp[i + 1][dig][dig][1] += 2;
                dp[i + 1][dig][dig][1] %= MOD;
            }
            else {
                dp[i + 1][dig][dig][0] += 2;
                dp[i + 1][dig][dig][0] %= MOD;
            }
        }

        f0r (j, i + 1, N) {
            f0r (dig, 0, ln) {
                if (digits[j] > number[dig]) {
                    dp[j + 1][dig][dig][2] += 2;
                    dp[i + 1][dig][dig][2] %= MOD;
                }
                else if (digits[j] == number[dig]) {
                    dp[j + 1][dig][dig][1] += 2;
                    dp[i + 1][dig][dig][1] %= MOD;
                }
                else {
                    dp[j + 1][dig][dig][0] += 2;
                    dp[i + 1][dig][dig][0] %= MOD;
                }
            }

            f0r (l, 0, ln) {
                f0r (r, l, ln) {
                    // Add nothing
                    dp[j + 1][l][r][0] += dp[j][l][r][0];
                    dp[j + 1][l][r][1] += dp[j][l][r][1];
                    dp[j + 1][l][r][2] += dp[j][l][r][2];
                    dp[j + 1][l][r][0] %= MOD;
                    dp[j + 1][l][r][1] %= MOD;
                    dp[j + 1][l][r][2] %= MOD;

                    // Append right
                    ll nr = r + 1;
                    if (nr < ln) {
                        if (digits[j] > number[nr]) {
                            // (2 -> 2)
                            dp[j + 1][l][nr][2] += dp[j][l][r][2];
                            // (1 -> 2)
                            dp[j + 1][l][nr][2] += dp[j][l][r][1];
                            // (0 -> 0)
                            dp[j + 1][l][nr][0] += dp[j][l][r][0];
                        }
                        else if (digits[j] == number[nr]) {
                            // (2 -> 2)
                            dp[j + 1][l][nr][2] += dp[j][l][r][2];
                            // (1 -> 1)
                            dp[j + 1][l][nr][1] += dp[j][l][r][1];
                            // (0 -> 0)
                            dp[j + 1][l][nr][0] += dp[j][l][r][0];
                        }
                        else {
                            // (2 -> 2)
                            dp[j + 1][l][nr][2] += dp[j][l][r][2];
                            // (1 -> 0)
                            dp[j + 1][l][nr][0] += dp[j][l][r][1];
                            // (0 -> 0)
                            dp[j + 1][l][nr][0] += dp[j][l][r][0];
                        }
                        dp[j + 1][l][nr][0] %= MOD;
                        dp[j + 1][l][nr][1] %= MOD;
                        dp[j + 1][l][nr][2] %= MOD;
                    }

                    // Append left
                    ll nl = l - 1;
                    if (nl >= 0) {
                        if (digits[j] > number[nl]) {
                            // ALL -> 2
                            dp[j + 1][nl][r][2] += dp[j][l][r][0];
                            dp[j + 1][nl][r][2] += dp[j][l][r][1];
                            dp[j + 1][nl][r][2] += dp[j][l][r][2];
                        }
                        else if (digits[j] == number[nl]) {
                            // (2 -> 2)
                            dp[j + 1][nl][r][2] += dp[j][l][r][2];
                            // (1 -> 1)
                            dp[j + 1][nl][r][1] += dp[j][l][r][1];
                            // (0 -> 0)
                            dp[j + 1][nl][r][0] += dp[j][l][r][0];
                        }
                        else {
                            // ALL -> 0
                            dp[j + 1][nl][r][0] += dp[j][l][r][0];
                            dp[j + 1][nl][r][0] += dp[j][l][r][1];
                            dp[j + 1][nl][r][0] += dp[j][l][r][2];
                        }
                        dp[j + 1][nl][r][0] %= MOD;
                        dp[j + 1][nl][r][1] %= MOD;
                        dp[j + 1][nl][r][2] %= MOD;
                    }
                }
            }

            f0r (l, 0, ln) {
                if (l == 0) {
                    ans[typ][i][j - 1] += dp[j][l][ln - 1][0];
                    ans[typ][i][j - 1] += dp[j][l][ln - 1][1];
                }
                else {
                    ans[typ][i][j - 1] += dp[j][l][ln - 1][0];
                    ans[typ][i][j - 1] += dp[j][l][ln - 1][1];
                    ans[typ][i][j - 1] += dp[j][l][ln - 1][2];
                }
                ans[typ][i][j - 1] %= MOD;
            }
        }
        f0r (l, 0, ln) {
            if (l == 0) {
                ans[typ][i][N - 1] += dp[N][l][ln - 1][0];
                ans[typ][i][N - 1] += dp[N][l][ln - 1][1];
            }
            else {
                ans[typ][i][N - 1] += dp[N][l][ln - 1][0];
                ans[typ][i][N - 1] += dp[N][l][ln - 1][1];
                ans[typ][i][N - 1] += dp[N][l][ln - 1][2];
            }
            ans[typ][i][N - 1] %= MOD;
        }
    }
}

int main () {
    fastio;
    memset(ans, 0, sizeof(ans));
    
    ll A, B; cin >> N >> A >> B;
    digits = V<ll>(N);
    cin >> digits;
    tc (A - 1, 0); tc (B, 1);
 
    ll Q; cin >> Q;
    while (Q --) {
        ll a, b; cin >> a >> b;
        cout << (ans[1][a - 1][b - 1] - ans[0][a - 1][b - 1] + MOD) % MOD << '\n';
    }
}