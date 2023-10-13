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
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_D = 19;
ll dp[MAX_D][MAX_D + 1][MAX_D + 1][2]; // Position, how many digits, how many focus1 digits, is_under

void reset () {
    f0r (i, 0, MAX_D) {
        f0r (j, 0, MAX_D + 1) {
            f0r (k, 0, MAX_D + 1) {
                f0r (l, 0, 2) {
                    dp[i][j][k][l] = 0;
                }
            }
        }
    }
}

ll cnt (ll n) {
    ll N = n;
    ll ans = 0, ansdup = 0;
    V<ll> number; 
    while (n > 0) {
        number.pb(n % 10);
        n /= 10;
    }
    reverse(all(number));
    
    f0r (focus1, 0, 10) {
        reset ();
        // First round

        dp[0][0][0][1] = 1;
        f0r (nd, 1, number[0]) {
            dp[0][1][nd == focus1][1] ++;
        }
        dp[0][1][number[0] == focus1][0] = 1;

        f0r (i, 0, len(number) - 1) {
            f0r (tot, 0, i + 2) {
                f0r (targ, 0, tot + 1) {
                    f0r (newdigit, 0, 10) {
                        if (tot == 0 && newdigit == 0) {
                            dp[i + 1][tot][targ][1] = 1;
                        }
                        else if (newdigit > number[i + 1]) {
                            dp[i + 1][tot + 1][targ + (newdigit == focus1)][1] += dp[i][tot][targ][1];
                        }
                        else if (newdigit == number[i + 1]) {
                            dp[i + 1][tot + 1][targ + (newdigit == focus1)][1] += dp[i][tot][targ][1];
                            dp[i + 1][tot + 1][targ + (newdigit == focus1)][0] += dp[i][tot][targ][0];
                        }
                        else if (newdigit < number[i + 1]) {
                            dp[i + 1][tot + 1][targ + (newdigit == focus1)][1] += dp[i][tot][targ][1];
                            dp[i + 1][tot + 1][targ + (newdigit == focus1)][1] += dp[i][tot][targ][0];
                        }
                    }
                }
            }
        }
        ll x = 0; // debug x
        f0r (tot, 1, len(number) + 1) {
            f0r (targ, 0, tot + 1) {
                if (2 * targ >= tot) {
                    x += dp[len(number) - 1][tot][targ][0];
                    x += dp[len(number) - 1][tot][targ][1];
                }
            }
        }
        ans += x;

        // Duplicates
        f0r (focus2, focus1 + 1, 10) {
            for (ll leng = 2; leng <= len(number); leng += 2) {
                f0r (mask, 0, 1 << leng) {
                    if (__builtin_popcount(mask) * 2 != leng) continue;
                    if (focus1 == 0 && mask % 2) continue;
                    ll t = 0;
                    f0r (i, 0, leng) {
                        t *= 10;
                        if ((1 << i & mask) > 0) { // if odd
                            t += focus1;
                        }
                        else {
                            t += focus2;
                        }
                    }
                    if (t <= N) {
                        ansdup ++;
                    }
                }
            }
        }
    }
    return ans - ansdup;
}

int main () {
    ll X, Y; 
	fileread("odometer");
    fin >> X >> Y;
    fout << cnt (Y) - cnt (X - 1) << endl;
}