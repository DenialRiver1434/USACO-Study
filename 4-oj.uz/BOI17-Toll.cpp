#include <bits/stdc++.h>
using namespace std;
#define pb push_back 
#define is insert
#define lb lower_bound
#define ll long long
#define V vector
#define MS multiset
#define PL pair<ll, ll>
#define F first
#define S second
#define PQ priority_queue
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define For(i, end, begin) for (ll i = end; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000009
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};
template<typename T> istream& operator>>(istream& in, pair<T, T>& a) {in >> a.F >> a.S; return in;};
template<typename T> ostream& operator<<(ostream& out, pair<T, T>& a) {out << a.F << ' ' << a.S << '\n'; return out;};

const ll MAX = 2e5 + 5;
V<PL> roads[MAX];
ll costplay[MAX][20][5];

ll dp[MAX];
set<ll> dpclear;

int main () {
    ll K, N, M, O;
    cin >> K >> N >> M >> O;

    f0r (i, 0, N + 5) {
        f0r (j, 0, 20) {
            f0r (k, 0, 5) {
                costplay[i][j][k] = INF;
            }
        }
        dp[i] = INF;
    }
    
    f0r (i, 0, M) {
        ll a, b, t; cin >> a >> b >> t;
        costplay[a][0][b % K] = min(t, costplay[a][0][b % K]);
    }

    f0r (j, 1, 20) {
        f0r (i, 0, N) {
            f0r (destk, 0, K) {
                f0r (midk, 0, K) {
                    ll gmid = i / K + (1 << (j - 1));
                    ll midind = midk + gmid * K;
                    if (midind < N) {
                        costplay[i][j][destk] = min(costplay[i][j][destk], costplay[i][j - 1][midk] + costplay[midind][j - 1][destk]);
                    }
                }
            }
        }
    }

    f0r (i, 0, O) {
        for (auto d : dpclear) {
            dp[d] = INF;
        }
        dpclear.clear();

        ll a, b; cin >> a >> b;
        ll ga = a / K, gb = b / K;
        ll jumpnec = gb - ga, curgroup = ga;
        dp[a] = 0;
        dpclear.is(a);

        f0r (j, 0, 20) {
            if ((jumpnec & 1 << j) > 0) {
                ll newgroup = curgroup + (1 << j);
                f0r (startk, 0, K) {
                    f0r (endk, 0, K) {
                        dp[newgroup * K + endk] = min(dp[newgroup * K + endk], dp[curgroup * K + startk] + costplay[curgroup * K + startk][j][endk]);
                        dpclear.is(newgroup * K + endk);
                    }
                }
                curgroup = newgroup;
            }
        }
        if (dp[b] >= INF) {
            cout << -1 << endl;
        }
        else {
            cout << dp[b] << endl;
        }
    }
}