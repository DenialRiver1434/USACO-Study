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

const ll MAX_N = 1005;
ll N, E, dp[MAX_N], val[MAX_N], dist[MAX_N][MAX_N], ans = 0;
V<ll> conn[MAX_N];
V<PL> pos;

int main () {
    fileread("buffet");

    f0r (i, 0, MAX_N) {
        f0r (j, 0, MAX_N) {
            dist[i][j] = inf;
        }
    }

    fin >> N >> E;
    f0r (i, 0, N) {
        ll Q, D; fin >> Q >> D;
        pos.pb({Q, i});
        val[i] = Q; dp[i] = Q;
        f0r (j, 0, D) {
            ll a; fin >> a;
            conn[i].pb(a - 1);
        }
    }

    queue<ll> vs;
    f0r (i, 0, N) {
        dist[i][i] = 0;
        vs.push(i);
        while (!vs.empty()) {
            ll pos = vs.front();
            vs.pop();
            for (auto c : conn[pos]) {
                if (dist[i][c] != inf) continue;
                dist[i][c] = dist[i][pos] + 1;
                vs.push(c);
            }
        }
    }

    sort(all(pos));
    f0r (i, 0, N) {
        ll curpos = pos[i].S; 
        f0r (j, 0, i) {
            ll ppos = pos[j].S;
            dp[curpos] = max(dp[curpos], dp[ppos] - E * dist[curpos][ppos] + pos[i].F);
            ans = max(ans, dp[curpos]);
        }
    }
    
    fout << ans << endl;
}