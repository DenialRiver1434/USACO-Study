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

const V<char> req = {'b', 'e', 's', 's', 'i', 'e'};
const ll MAX_N = 2e5;

ll cost[MAX_N], maxto[MAX_N], N, best = INF;
ll dp[MAX_N][6];

int main () {
	string s; cin >> s;
    N = len(s);
    f0r (i, 0, N) {
        cin >> cost[i];
        f0r (j, 0, 6) {
            dp[i][j] = INF;
        }
    }

    ll tc = 0, xtyp = 0;
    f0r (i, 0, N) {
        xtyp += (s[i] == req[xtyp]);
        if (xtyp == 6) {
            tc ++;
            xtyp = 0;
        }
        maxto[i] = tc;
    }
    cout << tc << endl;

    dp[0][0] = 0;
    if (s[0] == 'b') {
        dp[0][1] = 0;
    }
    f0r (i, 1, N) {
        ll fin = maxto[i];
        For (j, 5, 0) {
            dp[fin][j] += cost[i];
            if (req[j - 1] == s[i]) {
                dp[fin][j] = min(dp[fin][j], dp[fin][j - 1]);
            }
        }
        if (fin > 0 && s[i] == 'e') {
            dp[fin][0] = min(dp[fin][0], dp[fin - 1][5]);
        }

        fin --;
        if (fin >= 0) {
            For (j, 5, 0) {
                dp[fin][j] += cost[i];
                if (req[j - 1] == s[i]) {
                    dp[fin][j] = min(dp[fin][j], dp[fin][j - 1]);
                }
            }
            if (fin > 0) {
                dp[fin][0] += cost[i];
                if (s[i] == 'e') {
                    dp[fin][0] = min(dp[fin][0], dp[fin - 1][5]);
                }
            }
        }
        best = min(best, dp[tc][0]);
    }
    cout << best << endl;
}