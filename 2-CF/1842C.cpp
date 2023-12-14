
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
#define inf 1000000000LL
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 2e5 + 5;
ll lastappear[MAX_N], dp[2][MAX_N];

void tc () {
    memset(lastappear, -1, sizeof(lastappear));
    memset(dp, 0, sizeof(dp));
    ll N; cin >> N;
    f0r (i, 0, N) {
        ll a; cin >> a;
        if (i > 0) { 
            dp[1][i] = dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]); 
        }
        if (lastappear[a] > -1) {
            dp[1][i] = max(dp[1][i], dp[1][lastappear[a]] + (i - lastappear[a]));
            dp[1][i] = max(dp[1][i], dp[0][lastappear[a]] + (i - lastappear[a] + 1));
        }
        lastappear[a] = i;
    }
    cout << max(dp[0][N - 1], dp[1][N - 1]) << endl;
}

int main () {
    ll T; cin >> T;
    while (T --) {
        tc ();
    }
}
