#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

int grid[100][100], best[100][100], N, M, possible = INT_MAX;
priority_queue<tuple<int, int, int>> pq;

void pa (int x, int y, int dist) {
    if(x < 0 || y < 0 || x >= N || y >= N) return;
    dist += grid[x][y];
    if(x == 2 && y == 2) {
        cout << "";
    }
    if(best[x][y] > dist) {
        best[x][y] = dist;
        pq.push(mt(-dist, x, y));
    }
}

int main () {
    ifstream fin; ofstream fout;
    fin.open("visitfj.in");
    fout.open("visitfj.out");

    fin >> N >> M;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            fin >> grid[i][j];
            best[i][j] = INT_MAX;
        }
    }
    best[0][0] = 0;
    pq.push(mt(0, 0, 0));
    while(pq.size()) {
        int dist = -get<0>(pq.top()), x = get<1>(pq.top()), y = get<2>(pq.top());
        pq.pop();
        if(dist != best[x][y]) continue;
        if((abs((N - 1) - x) + abs((N - 1) - y)) < 3) {
            possible = min(possible, dist + M * (abs((N - 1) - x) + abs((N - 1) - y)));
            continue;
        }
        dist += (3 * M);
        pa(x + 1, y, dist);
        pa(x - 1, y, dist);
        pa(x, y + 1, dist);
        pa(x, y - 1, dist);
        pa(x + 3, y, dist);
        pa(x - 3, y, dist);
        pa(x, y + 3, dist);
        pa(x, y - 3, dist);
        pa(x + 2, y + 1, dist);
        pa(x + 2, y - 1, dist);
        pa(x + 1, y + 2, dist);
        pa(x + 1, y - 2, dist);
        pa(x - 2, y + 1, dist);
        pa(x - 2, y - 1, dist);
        pa(x - 1, y + 2, dist);
        pa(x - 1, y - 2, dist);
    }
    fout << possible << endl;
}