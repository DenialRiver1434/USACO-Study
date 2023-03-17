#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

int N, M, grid[4000][4000];

void ffill (int x, int y, int col, int org) {
	if(x < 0 || x >= N || y < 0 || y >= M) return;
	if(grid[x][y] == org) {
		grid[x][y] = col;
		ffill(x - 1, y, col, org);
		ffill(x + 1, y, col, org);
		ffill(x, y - 1, col, org);
		ffill(x, y + 1, col, org);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N >> M;
	f0r (i, 0, N) {
		f0r (j, 0, M) {
			char a; cin >> a;
			if(a == '.') grid[i][j] = -3;
			else if(a == 'F') grid[i][j] = -2;
			else grid[i][j] = -1;
		}
	}
	int col = 0;
	f0r (i, 0, N) {
		f0r (j, 0, M) {
			if(grid[i][j] == -1 || grid[i][j] == -2) {
				ffill(i, j, col ++, grid[i][j]);
			}
		}
	}
	
	set<int> conn[col];
	f0r (i, 0, N) {
		f0r (j, 0, M) {
			if(i > 0) {
				if(grid[i][j] >= 0 && grid[i - 1][j] >= 0 && grid[i][j] != grid[i - 1][j]) {
					conn[grid[i][j]].is(grid[i - 1][j]);
					conn[grid[i - 1][j]].is(grid[i][j]);
				}
			}
			if(j > 0) {
				if(grid[i][j] >= 0 && grid[i][j - 1] >= 0 && grid[i][j] != grid[i][j - 1]) {
					conn[grid[i][j]].is(grid[i][j - 1]);
					conn[grid[i][j - 1]].is(grid[i][j]);
				}
			}
		}
	}

	int dist[col];
	f0r (i, 0, col) dist[i] = -1;
	dist[grid[0][0]] = 0;

	int m = 0;
	queue<int> q;
	q.push(grid[0][0]);
	
	while(!q.empty()) {
		int pos = q.front();
		q.pop();
		for (auto c : conn[pos]) {
			if(dist[c] == -1) {
				q.push(c);
				dist[c] = dist[pos] + 1;
				m = max(m, dist[c]);
			}
		}
	}

	cout << m + 1 << endl;
}