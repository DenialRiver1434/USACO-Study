#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define vl vector<ll>
#define sl set<ll>
#define msl multiset<ll>
#define pl pair<ll, ll>
#define vpl vector<pair<ll, ll>>
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.size()
#include "bits/stdc++.h"
using namespace std;

const int INF = 1e9;
int grid[800][800], N, M;
pair<int, int> arrives[800][800];
pl start, home;

bool process1 (int x, int y, int weight) {
    if((x < 0) || (x >= N) || (y < 0) || (y >= N)) {
        return false;
    }
    if (grid[x][y] != INF) {
        return false;
    }
    grid[x][y] = weight;
    return true;
}

bool process2 (int x, int y, pair<int, int> weight) {
    if((x < 0) || (x >= N) || (y < 0) || (y >= N)) {
        return false;
    }
    if (arrives[x][y].first != INF) {
        return false;
    }
    if (grid[x][y] <= weight.first) {
        return false;
    }
    arrives[x][y] = weight;
    return true;
}

bool test (int time) {
    f0r (i, 0, N) {
        f0r (j, 0, N) {
            arrives[i][j] = {INF, INF};
        }
    }
    arrives[start.first][start.second] = {time, 0};
    queue<pair<int, int>> q;
    q.push(start);
    while (!q.empty()) {
        int x, y; tie(x, y) = q.front();
        q.pop();
        auto llegar = arrives[x][y];
        if((++llegar.second) == M) {
            llegar.first ++;
            llegar.second = 0;
        }

        if (process2(x + 1, y, llegar)) {
            q.push({x + 1, y});
        }
        if (process2(x - 1, y, llegar)) {
            q.push({x - 1, y});
        }
        if (process2(x, y + 1, llegar)) {
            q.push({x, y + 1});
        }
        if (process2(x, y - 1, llegar)) {
            q.push({x, y - 1});
        }
    }

    
    //f0r (i, 0, N) {
    //    f0r (j, 0, N) {
    //        cout << i << " " << j << " : " << arrives[i][j].first << ", " << arrives[i][j].second << endl;
    //    }
    //}


    return arrives[home.first][home.second].first < INF;
}

ll last_true(ll lo, ll hi) {
	lo--;
	while (lo < hi) {
		ll mid = lo + (hi - lo + 1) / 2;
		if (test(mid)) lo = mid;
		else hi = mid - 1;
	}
	return lo;
}

int main () {
    cin >> N >> M;

    queue<pl> ffill;
    f0r (i, 0, N) {
        f0r (j, 0, N) {
            char a; cin >> a;
            if(a == 'T') grid[i][j] = -1;
            if(a == 'G') grid[i][j] = INF;
            if(a == 'H') {
                grid[i][j] = 0;
                ffill.push({i, j});
            }
            if(a == 'M') {
                grid[i][j] = INF;
                start = {i, j};
            }
            if(a == 'D') {
                grid[i][j] = 1e8;
                home = {i, j};
            }
        }
    }

    while (!ffill.empty()) {
        pl coords = ffill.front();
        ll x, y; tie(x, y) = coords;
        ffill.pop();

        if (process1(x + 1, y, grid[x][y] + 1)) {
            ffill.push({x + 1, y});
        }
        if (process1(x - 1, y, grid[x][y] + 1)) {
            ffill.push({x - 1, y});
        }
        if (process1(x, y + 1, grid[x][y] + 1)) {
            ffill.push({x, y + 1});
        }
        if (process1(x, y - 1, grid[x][y] + 1)) {
            ffill.push({x, y - 1});
        }
    }

    cout << last_true(0, grid[start.first][start.second] - 1) << endl;
    test(3);
}