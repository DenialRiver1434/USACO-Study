
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

const ll MAX = 1 << 20;
ll N, B;
ll dp[MAX], worth[20][20];
V<PL> bonus[20];

int main () {
    fileread("dec");

    fin >> N >> B;
    f0r (i, 0, B) {
        ll a, b, c; fin >> a >> b >> c;
        bonus[a - 1].pb({b, c});
    }

    f0r (i, 0, N) {
        f0r (j, 0, N) {
            fin >> worth[i][j];
        }
    }
    f0r (i, 0, N) {
        sort(all(bonus[i]));
    }

    // First event
    f0r (cow, 0, N) {
        ll val = worth[cow][0];
        for (auto b : bonus[0]) {
            if (b.F <= val) {
                val += b.S;
            }
        }
        dp[1 << cow] = val;
    }

    f0r (pbset, 0, 1 << N) {
        f0r (newcow, 0, N) {
            if ((1 << newcow & pbset) > 0) {
                continue;
            }
            ll eve = __builtin_popcount(pbset);
            ll val = dp[pbset] + worth[newcow][eve];
            for (auto b : bonus[eve]) {
                if (b.F <= val) {
                    val += b.S;
                }
            }

            ll bset = pbset + (1 << newcow);
            dp[bset] = max(dp[bset], val);
        }
    }
    fout << dp[(1 << N) - 1] << endl;
}
