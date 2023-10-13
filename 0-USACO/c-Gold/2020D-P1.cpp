#define pb push_back 
#define is insert
#define lb lower_bound
#define ll long long
#define vl vector<int>
#define sl set<int>
#define msl multiset<int>
#define pl pair<int, int>
#define vpl vector<pair<int, int>>
#define f0r(i, begin, end) for (int i = begin; i < end; i ++) 
#define For(i, end, begin) for (int i = end; i > begin; i --) 
#define INF 1000000000000000000
#define IINF 1000000000
#define MOD 1000000007
#define len(x) x.size()
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr);
#include <bits/stdc++.h> 
using namespace std;

bool grid[1000][1000]; // 1 = wall, 0 = free
vpl robotspawn;
int walldist[1000][1000], centerpos[1000][1000], N, D;
queue<pl> q1, q2;
priority_queue<tuple<int, int, int>> pq;

int power[1000][1000];

void process1 (int x, int y, int dist) {
    if ((x < 0) || (y < 0) || (x >= N) || (y >= N)) {
        return;
    }
    if (grid[x][y] || walldist[x][y] != IINF) return;
	walldist[x][y] = dist;
    q1.push({x, y});
}

bool process2 (int x, int y, int dist) {
    if ((x < 0) || (y < 0) || (x >= N) || (y >= N)) {
        return false;
    }
    if (grid[x][y] || centerpos[x][y] != IINF) return false;
    if (((dist - 1) / D) < walldist[x][y]) {
        centerpos[x][y] = dist;
    }
    return ((dist / D) < walldist[x][y]);
}

void process3 (int x, int y, int pow) {
    if ((x < 0) || (y < 0) || (x >= N) || (y >= N) || (pow < 0)) {
        return;
    }
    if(power[x][y] >= pow) {
        return;
    }
    pq.push({pow, x, y});
}

int main () {
    cin >> N >> D;
    f0r (i, 0, N) {
        f0r (j, 0, N) {
            char a; cin >> a;
            grid[i][j] = (a == '#');
            if(grid[i][j]) {
                q1.push({i, j});
            }
            else {
                walldist[i][j] = IINF;
            }
            if(a == 'S') {
                robotspawn.pb({i, j});
                q2.push({i, j});
                centerpos[i][j] = 0;
            }
            else {
                centerpos[i][j] = IINF;
            }
        }
    }
    while (!q1.empty()) {
        int x, y;
        tie(x, y) = q1.front();
        q1.pop();
        process1(x + 1, y, walldist[x][y] + 1);
        process1(x - 1, y, walldist[x][y] + 1);
        process1(x, y - 1, walldist[x][y] + 1);
        process1(x, y + 1, walldist[x][y] + 1);
    }
    while (!q2.empty()) {
        int x, y;
        tie(x, y) = q2.front();
        q2.pop();
        if(process2(x + 1, y, centerpos[x][y] + 1)) {
            q2.push({x + 1, y});
        }
        if(process2(x - 1, y, centerpos[x][y] + 1)) {
            q2.push({x - 1, y});
        }
        if(process2(x, y + 1, centerpos[x][y] + 1)) {
            q2.push({x, y + 1});
        }
        if(process2(x, y - 1, centerpos[x][y] + 1)) {
            q2.push({x, y - 1});
        }
    }
    
    f0r (i, 0, N) {
        f0r (j, 0, N) {
            power[i][j] = -1;
            if(centerpos[i][j] != IINF) {
                pq.push({walldist[i][j] - 1, i, j});
            }
        }
    }
    while (!pq.empty()) {
        int pow, x, y; tie(pow, x, y) = pq.top();
        pq.pop();
        if (power[x][y] >= pow) continue;
        power[x][y] = pow;
        process3 (x - 1, y, pow - 1);
        process3 (x + 1, y, pow - 1);
        process3 (x, y - 1, pow - 1);
        process3 (x, y + 1, pow - 1);
    }

    int tc = 0;
    f0r (i, 0, N) {
        f0r (j, 0, N) {
            tc += (power[i][j] >= 0);
        }
    }
    cout << tc << endl;
}