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

ll N, M;

bool isla[50][50], shallow[50][50];
ll dist[15][15], islcount[50][50];
PL start[15];
ll dp[32768][15];

void ffill (ll x, ll y, ll col) {
    if (x < 0 || x >= N || y < 0 || y >= M) return;
    if (islcount[x][y] != col && isla[x][y]) {
        islcount[x][y] = col;
        ffill (x - 1, y, col);
        ffill (x + 1, y, col);
        ffill (x, y - 1, col);
        ffill (x, y + 1, col);
    }
}

int main () {
    fileread("island");

    fin >> N >> M;
    f0r (i, 0, N) {
        f0r (j, 0, M) {
            char x; fin >> x;
            isla[i][j] = (x == 'X');
            shallow[i][j] = (x == 'S');
            islcount[i][j] = -1;
        }
    }

    ll cnt = 0;
    f0r (i, 0, N) {
        f0r (j, 0, M) {
            if (isla[i][j] && islcount[i][j] == -1) {
                start[cnt] = {i, j};
                ffill (i, j, cnt ++);
            }
        }
    }

    f0r (i, 0, cnt) {
        f0r (j, 0, cnt) {
            dist[i][j] = INF;
        }
    }

    ll tdist[50][50];
    f0r (st, 0, cnt) {
        f0r (i, 0, 50) {
            f0r (j, 0, 50) {
                tdist[i][j] = INF;
            }
        }
        dist[st][st] = 0;

        deque<PL> pos;
        pos.push_back(start[st]);
        tdist[start[st].F][start[st].S] = 0;
        while (!pos.empty()) {
            ll x, y;
            tie(x, y) = pos.front();
            pos.pop_front();
            ll d = tdist[x][y];
            V<PL> newpos = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
            for (auto n : newpos) {
                ll nx = n.F, ny = n.S;
                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if (tdist[nx][ny] != INF) continue;
                if (!isla[nx][ny] && !shallow[nx][ny]) continue;
                if (isla[nx][ny]) {
                    tdist[nx][ny] = tdist[x][y];
                    dist[st][islcount[nx][ny]] = min(dist[st][islcount[nx][ny]], tdist[nx][ny]);
                    pos.push_front({nx, ny});
                }
                else {
                    tdist[nx][ny] = tdist[x][y] + 1;
                    pos.push_back({nx, ny});
                }
            }
        }
    }

    f0r (i, 0, 1 << cnt) {
        f0r (j, 0, cnt) {
            dp[i][j] = INF;
        }
    }
    f0r (i, 0, cnt) {
        dp[1 << i][i] = 0;
    }

    f0r (i, 1, 1 << cnt) {
        f0r (j, 0, cnt) {
            if ((1 << j & i) == 0) { continue; }
            f0r (pj, 0, cnt) {
                if ((1 << pj & i) == 0 || pj == j) { continue; }
                dp[i][j] = min(dp[i][j], dp[i - (1 << j)][pj] + dist[j][pj]);
            }
        }
    }
    ll best = INF;
    f0r (j, 0, cnt) {
        best = min(best, dp[(1 << cnt) - 1][j]);
    }
    fout << best << endl;
}