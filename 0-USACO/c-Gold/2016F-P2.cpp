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

const ll MAX_N = 100;

ll N, K, dp[MAX_N][MAX_N][8], cnt[MAX_N];

int main () {
    fileread("cbarn2");

    f0r (i, 0, MAX_N) {
        f0r (j, 0, MAX_N) {
            f0r (k, 1, 8) dp[i][j][k] = INF;
        }
    }

    fin >> N >> K;
    f0r (i, 0, N) {
        fin >> cnt[i];
    }
     
    // k = 1
    f0r (st, 0, N) {
        ll tot = 0;
        f0r (i, 0, N) {
            ll en = (st + i) % N;
            tot += i * cnt[en];
            dp[st][(en + 1) % N][1] = tot;
        }
    }

    f0r (k, 2, K + 1) {
        f0r (st, 0, N) {
            f0r (i, 0, N) {
                ll en = (st + i + 1) % N;
                for (ll mid = (st + 1) % N; mid != en; mid = (mid + 1) % N) {
                    dp[st][en][k] = min(dp[st][en][k], dp[st][mid][k - 1] + dp[mid][en][1]);
                }
            }
        }
    }

    ll bst = INF;
    f0r (i, 0, N) {
        bst = min(bst, dp[i][i][K]);
    }
    fout << bst << endl;
}