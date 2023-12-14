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
#define MOD 998244353
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, pair<T, T>& a) {out << a.F << ", " << a.S << endl; return out;};
template<typename T> ostream& operator<<(ostream& out, tuple<T, T, T>& a) {out << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << endl; return out;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 300;
const ll MID = MAX_N * MAX_N + 2;
ll dp[2][2 * MAX_N * MAX_N + 4]; // Number of arrays

int main () {
    ll N, tot = 0; cin >> N;
    V<ll> arr(N);
    cin >> arr;

    dp[1][MID + arr[1]] = 1;
    f0r (pos, 2, N) {
        memset(dp[pos % 2], 0, sizeof(dp[pos % 2]));
        f0r (pval, 0, 2 * MID) {
            if (pval == MID) {
                dp[pos % 2][MID + arr[pos]] += dp[(pos + 1) % 2][pval];
                dp[pos % 2][MID + arr[pos]] %= MOD;
            }
            else {
                ll nval1 = (arr[pos] + MID) + (pval - MID);
                ll nval2 = (arr[pos] + MID) - (pval - MID);
                dp[pos % 2][nval1] += dp[(pos + 1) % 2][pval];
                dp[pos % 2][nval1] %= MOD;
                dp[pos % 2][nval2] += dp[(pos + 1) % 2][pval];
                dp[pos % 2][nval2] %= MOD;
            }
        }

        if (pos == (N - 1)) {
            f0r (n, 0, 2 * MID) {
                tot += dp[pos % 2][n];
                tot %= MOD;
            }
        }
    }
    cout << tot << endl;
}