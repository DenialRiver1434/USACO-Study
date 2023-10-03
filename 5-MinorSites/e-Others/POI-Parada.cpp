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

const ll MAX_N = 2e5;
ll N, adj[MAX_N], best = -INF;
V<ll> conn[MAX_N];
ll dp[3][MAX_N]; // 0 = tail, 1 = bend, 2 = singular

void dfs (ll pos, ll pre) {
    V<ll> options;
    for (auto c : conn[pos]) {
        if (c != pre) {
            dfs (c, pos);
            options.pb(max(dp[0][c], dp[2][c]));
        }
    }
    sort(all(options));
    reverse(all(options));

    dp[2][pos] = adj[pos];
    if (len(options) == 1) {
        dp[0][pos] = dp[1][pos] = options[0] + adj[pos];
    }
    else if (len(options) >= 2) {
        dp[0][pos] = adj[pos] + options[0];
        dp[1][pos] = max(dp[0][pos], adj[pos] + options[0] + options[1]);
    }
}

int main () {
    cin >> N >> K;
}