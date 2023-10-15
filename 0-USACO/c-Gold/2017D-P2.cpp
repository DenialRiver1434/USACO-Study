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

const ll MAX_N = 1e5;
ll dp[MAX_N][3], col[MAX_N];
V<ll> conn[MAX_N];

void dfs (ll pos, ll pre) {
    for (auto c : conn[pos]) {
        if (c != pre) {
            dfs (c, pos);
        }
    }
    f0r (i, 0, 3) {
        if (col[pos] == -1) { dp[pos][i] = 1; }
        else { dp[pos][i] = (i == col[pos]); }

        for (auto c : conn[pos]) {
            if (c != pre) {
                ll opt = 0;
                f0r (j, 0, 3) {
                    if (i != j) {
                        opt += dp[c][j];
                        opt %= MOD;
                    }
                }
                dp[pos][i] *= opt;
                dp[pos][i] %= MOD;
            }
        }
    }
}

int main () {
	fileread("barnpainting");

    ll N, K; fin >> N >> K;
    col[0] = -1;
    f0r (i, 1, N) {
        col[i] = -1;
        ll a, b; fin >> a >> b;
        conn[a - 1].pb(b - 1);
        conn[b - 1].pb(a - 1);
    }
    f0r (i, 0, K) {
        ll a, b; fin >> a >> b;
        col[a - 1] = b - 1;
    }

    dfs (0, -1);
    fout << (dp[0][0] + dp[0][1] + dp[0][2] + MOD) % MOD << endl;
}