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

const V<PL> mover = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
const ll MAX_N = 1e3;
ll N, M, grid[MAX_N][MAX_N], dist[MAX_N][MAX_N][4][2];

bool ok (ll x, ll y, bool smelly) {
    if (x < 0 || x >= N || y < 0 || y >= M) return false;
    if (grid[x][y] == 0) return false;
    if (grid[x][y] == 3 && !smelly) return false;
    return true;
}

int main () {
    fileread("dream");

    fin >> N >> M;
    f0r (i, 0, N) {
        f0r (j, 0, M) {
            fin >> grid[i][j];
            f0r (k, 0, 4) {
                dist[i][j][k][0] = dist[i][j][k][1] = INF;
            }
        }
    }

    deque<tuple<ll, ll, ll, bool>> dq;
    dist[0][0][0][0] = 0;
    dq.push_back({0, 0, 0, 0});

    while (!dq.empty()) {
        ll x, y, dir, smelly;
        tie(x, y, dir, smelly) = dq.front();
        dq.pop_front();
        ll d = dist[x][y][dir][smelly];
        
        if (x == N - 1 && y == M - 1) {
            fout << d << endl;
            return 0;
        }

        if (grid[x][y] != 4) {
            // Rotate around
            f0r (k, 0, 4) {
                if (dist[x][y][k][smelly] > d) {
                    dist[x][y][k][smelly] = d;
                    dq.push_front({x, y, k, smelly});
                }
            }

            x += mover[dir].F; y += mover[dir].S;
            if (ok(x, y, smelly)) {
                if (grid[x][y] == 4) smelly = 0;
                if (grid[x][y] == 2) smelly = 1;
                if (dist[x][y][dir][smelly] > (d + 1)) {
                    dist[x][y][dir][smelly] = d + 1;
                    dq.push_back({x, y, dir, smelly});
                }
            }
        }
        else if (ok(x + mover[dir].F, y + mover[dir].S, smelly)) {
            x += mover[dir].F; y += mover[dir].S;
            if (grid[x][y] == 4) smelly = 0;
            if (grid[x][y] == 2) smelly = 1;
            if (dist[x][y][dir][smelly] > (d + 1)) {
                dist[x][y][dir][smelly] = d + 1;
                dq.push_back({x, y, dir, smelly});
            }
        }
        else {
            f0r (k, 0, 4) {
                if (dist[x][y][k][smelly] > d) {
                    dist[x][y][k][smelly] = d;
                    dq.push_front({x, y, k, smelly});
                }
            }
        }
    }
    fout << -1 << endl;
}