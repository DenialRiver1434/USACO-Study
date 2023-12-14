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
template<typename T> ostream& operator<<(ostream& out, pair<T, T>& a) {out << a.F << ", " << a.S << endl; return out;};
template<typename T> ostream& operator<<(ostream& out, tuple<T, T, T>& a) {out << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << endl; return out;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 505;
const ll MAX_K = 12;
const ll MAX = 1 << MAX_K;

ll N, K, M, grid[MAX_N][MAX_N]; // . = 0; + = 1; # = 2
ll dist[MAX_K + 1][MAX_N][MAX_N]; // dist[K] is distance from (0, 0)
bool carryable[MAX + 1];
ll tiempo[MAX];
V<tuple<ll, ll, ll>> rocks; // coordx, coordy, weight

ll dp[MAX + 1];

bool check (ll pos, ll curx, ll cury) {
    if (curx < 0 || cury < 0 || curx >= N || cury >= N) return false;
    if (dist[pos][curx][cury] != -1) return false;
    if (grid[curx][cury] == 2) return false;
    return true;
}

void ffill (ll pos) {
    ll x, y;
    if (pos == K) {
        x = y = 0;
    }
    else {
        x = get<0>(rocks[pos]), y = get<1>(rocks[pos]);
    }

    deque<tuple<ll, ll, ll>> dq;
    dq.push_back({x, y, 0});
    dist[pos][x][y] = 0;

    while (!dq.empty()) {
        ll cx, cy, d;
        tie(cx, cy, d) = dq.front();
        dq.pop_front();

        if (check(pos, cx + 1, cy)) {
            dist[pos][cx + 1][cy] = d + grid[cx + 1][cy];
            if (grid[cx + 1][cy]) {
                dq.push_back({cx + 1, cy, d + 1});
            }
            else {
                dq.push_front({cx + 1, cy, d});
            }
        }
        if (check(pos, cx - 1, cy)) {
            dist[pos][cx - 1][cy] = d + grid[cx - 1][cy];
            if (grid[cx - 1][cy]) {
                dq.push_back({cx - 1, cy, d + 1});
            }
            else {
                dq.push_front({cx - 1, cy, d});
            }
        }
        if (check(pos, cx, cy + 1)) {
            dist[pos][cx][cy + 1] = d + grid[cx][cy + 1];
            if (grid[cx][cy + 1]) {
                dq.push_back({cx, cy + 1, d + 1});
            }
            else {
                dq.push_front({cx, cy + 1, d});
            }
        }
        if (check(pos, cx, cy - 1)) {
            dist[pos][cx][cy - 1] = d + grid[cx][cy - 1];
            if (grid[cx][cy - 1]) {
                dq.push_back({cx, cy - 1, d + 1});
            }
            else {
                dq.push_front({cx, cy - 1, d});
            }
        }
    }
}

ll gdist (ll pos1, ll pos2) {
    if (pos2 == K) {
        return dist[pos1][0][0];
    }
    return dist[pos1][get<0>(rocks[pos2])][get<1>(rocks[pos2])];
}

int main () {
    f0r (i, 0, MAX_K + 1) { 
        f0r (j, 0, MAX_N) {
            f0r (k, 0, MAX_N) {
                dist[i][j][k] = -1;
            }
        }
    }

    cin >> N >> K >> M;
    f0r (i, 0, N) {
        f0r (j, 0, N) {
            char x; cin >> x;
            if (x == '#') grid[i][j] = 2;
            else if (x == '+') grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }

    f0r (i, 0, K) {
        ll a, b, c; cin >> a >> b >> c;
        rocks.pb({a - 1, b - 1, c});
    }

    // Processing which can be carried
    f0r (i, 1, 1 << K) {
        ll t = 0;
        f0r (j, 0, K) {
            if ((1 << j & i) > 0) {
                t += get<2>(rocks[j]);
            }
        }
        carryable[i] = t <= M;
    }

    // Processing distances
    f0r (i, 0, K + 1) {
        ffill (i);
    }

    // Processing subsets
    ll tdp[MAX_K + 1][MAX];
    f0r (i, 0, MAX_K + 1) {
        f0r (j, 0, MAX) tdp[i][j] = INF;
    }

    tdp[K][0] = 0;
    f0r (i, 0, 1 << K) {
        f0r (ppos, 0, K + 1) {
            if (ppos != K && ((1 << ppos & i) == 0)) continue;
            f0r (npos, 0, K + 1) {
                if (npos != K && ((1 << npos & i) != 0)) continue; 
                if (npos == K) {
                    tdp[npos][i] = min(tdp[npos][i], tdp[ppos][i] + gdist(ppos, npos));
                }
                else {
                    tdp[npos][i + (1 << npos)] = min(tdp[npos][i + (1 << npos)], tdp[ppos][i] + gdist(ppos, npos));
                }
            }
        }
    }

    f0r (i, 0, 1 << K) {
        if (!carryable[i]) {
            tiempo[i] = INF;
        }
        else tiempo[i] = tdp[K][i];
        dp[i] = INF;
    }

    dp[0] = 0;
    f0r (i, 0, 1 << K) {
        f0r (nop, 0, 1 << K) {
            if ((nop & i) != 0) continue;
            dp[i + nop] = min(dp[i + nop], dp[i] + tiempo[nop]);
        }
    }
    cout << dp[(1 << K) - 1] << endl;
}