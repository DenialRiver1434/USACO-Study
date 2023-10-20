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
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_RC = 250;
ll R, C, K, grid[MAX_RC][MAX_RC], rowtot[MAX_RC][MAX_RC];
map<ll, ll> rowdp[MAX_RC][MAX_RC];

int main () {
    fileread ("hopscotch");

	fin >> R >> C >> K;

    f0r (i, 0, R) {
        f0r (j, 0, C) {
            fin >> grid[i][j];
        }
    }

    f0r (i, 0, C) {
        rowtot[0][i] = 1;
        rowdp[0][i][grid[0][0]] = 1;
    }

    f0r (i, 1, R - 1) {
        f0r (j, 1, C - 1) {
            ll c = grid[i][j];
            
            rowtot[i][j] = rowtot[i][j - 1];
            for (auto r : rowdp[i][j - 1]) {
                rowdp[i][j][r.F] = r.S;
            }

            ll tot = 0;
            f0r (r, 0, i) {
                tot += rowtot[r][j - 1];
                if (rowdp[r][j - 1].find(c) != rowdp[r][j - 1].end()) {
                    tot -= rowdp[r][j - 1][c];
                }
                tot += MOD;
                tot %= MOD;
            }
            rowtot[i][j] += tot;
            rowtot[i][j] %= MOD;
            rowdp[i][j][c] += tot;
            rowdp[i][j][c] %= MOD;
        }
    }
    ll c = grid[R - 1][C - 1];
    ll tot = 0;
    f0r (r, 0, R - 1) {
        tot += rowtot[r][C - 2];
        tot -= rowdp[r][C - 2][c];
        tot += MOD;
        tot %= MOD;
    }
    fout << tot << endl;
}
