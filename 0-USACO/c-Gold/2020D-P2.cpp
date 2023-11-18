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
template<typename T> ostream& operator<<(ostream& out, pair<T, T>& a) {out << a.F << ", " << a.S << endl; return out;};
template<typename T> ostream& operator<<(ostream& out, tuple<T, T, T>& a) {out << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << endl; return out;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << endl; return out;};

const ll MAX_N = 1e5; // 1e5;
map<char, ll> dict = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
string s;
ll N, dp[MAX_N][4][4][4]; // latest start with, end with (not necessarily ended yet), need to end with

void exec (ll pos, ll newc) {
    f0r (pstart, 0, 4) {
        f0r (pend, 0, 4) {
            f0r (nend, 0, 4) {
                // Something happened
                if (pend == nend) {
                    dp[pos][newc][newc][pstart] += dp[pos - 1][pstart][pend][nend];
                    dp[pos][newc][newc][pstart] %= MOD;
                }
                // Nothing happens
                if (pend != newc) {
                    dp[pos][pstart][newc][nend] += dp[pos - 1][pstart][pend][nend];
                    dp[pos][pstart][newc][nend] %= MOD;
                }
            }
        }
    }
}

int main () {
    cin >> s;
    N = len(s);
    if (s[0] == '?') {
        f0r (i, 0, 4) {
            f0r (j, 0, 4) {
                dp[0][i][i][j] = 1;
            }
        }
    } else {
        f0r (j, 0, 4) {
            dp[0][dict[s[0]]][dict[s[0]]][j] = 1;
        }
    }

    f0r (i, 1, N) {
        if (s[i] == '?') {
            f0r (j, 0, 4) {
                exec(i, j);
            }
        }
        else {
            exec(i, dict[s[i]]);
        }
    }

    ll tot = 0;
    f0r (st, 0, 4) {
        f0r (en, 0, 4) {
            tot += dp[N - 1][st][en][en];
            tot %= MOD;
        }
    }
    cout << tot << endl;
}