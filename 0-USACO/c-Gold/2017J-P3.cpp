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

const V<PL> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const ll MAX_N = 20;

ll N, dist[MAX_N][MAX_N][MAX_N][MAX_N][4];
bool hay[MAX_N][MAX_N];

tuple<ll, ll, ll> push (ll x, ll y, ll dir) {
    if (x == N - 1 && y == N - 1) {
        return {x, y, dir};
    }
    x += moves[dir].F; y += moves[dir].S;
    if (x < 0 || x >= N || y < 0 || y >= N) {
        x -= moves[dir].F;
        y -= moves[dir].S;
    }
    else if (hay[x][y]) {
        x -= moves[dir].F;
        y -= moves[dir].S;
    }
    return {x, y, dir};
}

int main () {
    fileread("cownav");

    fin >> N;
    For (i, N - 1, -1) {
        f0r (j, 0, N) {
            char x; fin >> x;
            hay[i][j] = (x == 'H');
            f0r (k, 0, N) {
                f0r (l, 0, N) {
                    f0r (ilost, 0, 4) {
                        dist[i][j][k][l][ilost] = INF;
                    }
                }
            }
        }
    }

    queue<tuple<ll, ll, ll, ll, ll>> q;
    q.push({0, 0, 0, 0, 0});
    dist[0][0][0][0][0] = 0;
    while (!q.empty()) {
        ll x0, y0, x1, y1, dir0;
        tie (x0, y0, x1, y1, dir0) = q.front();
        ll dir1 = (dir0 + 1) % 4;
        ll di = dist[x0][y0][x1][y1][dir0];
        q.pop();

        if (x0 == N - 1 && y0 == N - 1 && x1 == N - 1 && y1 == N - 1) {
            fout << di << endl;
            return 0;
        }

        // Rot-right
        if (dist[x0][y0][x1][y1][(dir0 + 1) % 4] == INF) {
            dist[x0][y0][x1][y1][(dir0 + 1) % 4] = di + 1;
            q.push({x0, y0, x1, y1, (dir0 + 1) % 4});
        }

        // Rot-left
        if (dist[x0][y0][x1][y1][(dir0 + 3) % 4] == INF) {
            dist[x0][y0][x1][y1][(dir0 + 3) % 4] = di + 1;
            q.push({x0, y0, x1, y1, (dir0 + 3) % 4});
        }

        // Forward
        tie (x0, y0, dir0) = push(x0, y0, dir0);
        tie (x1, y1, dir1) = push(x1, y1, dir1);
        if (dist[x0][y0][x1][y1][dir0] == INF) {
            dist[x0][y0][x1][y1][dir0] = di + 1;
            q.push({x0, y0, x1, y1, dir0});
        }
    }
    fout << -1 << endl;
}