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

const ll MAX_N = 105;
ll N, dp[MAX_N][MAX_N + 1], arr[MAX_N], tot[MAX_N][MAX_N + 1];

int main () {
    cin >> N;
    f0r (i, 0, N) {
        cin >> arr[i];
    }

    f0r (l, 0, N) {
        f0r (r, l, N + 1) {
            ll d = 0;
            f0r (k, l, r) {
                d += arr[k];
            }
            tot[l][r] = d;
            dp[l][r] = -INF;
        }
    }

    f0r (lr, 0, N + 1) dp[lr][lr] = 0;

    f0r (diff, 1, N + 1) {
        f0r (l, 0, N - diff + 1) {
            ll r = l + diff;
            dp[l][r] = max(arr[l] + tot[l + 1][r] - dp[l + 1][r], arr[r - 1] + tot[l][r - 1] - dp[l][r - 1]);
        }
    }
    cout << dp[0][N] << " " << tot[0][N] - dp[0][N] << endl;
}