#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int grid[50][50];
bool visited[50][50];
char a;
vector<tuple<int, int>> required;

void wall (int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M) return;
	grid[x][y] = -2;
}

void fill (int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M) return;
	if (visited[x][y] || grid[x][y] != -1) return;
	visited[x][y] = true;
	fill(x - 1, y);
	fill(x + 1, y);
	fill(x, y - 1);
	fill(x, y + 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> T;
	while (T --) {
		cin >> N >> M;
		required.clear();
		for (int i = 0; i < N; i ++) {
			for (int j = 0; j < M; j ++) {
				grid[i][j] = 0; // Done here to prevent stuff from overwriting (see line 37)
				visited[i][j] = false; 
			}
		}

		for (int i = 0; i < N; i ++) {
			for (int j = 0; j < M; j ++) {
				cin >> a;
				if (a == 'B') {
					wall(i - 1, j);
					wall(i + 1, j);
					wall(i, j - 1);
					wall(i, j + 1);
				}
				if (a == 'G') {
					required.pb(mt(i, j));
				}
				if (! grid[i][j]) {
					if (a == '#') grid[i][j] = -2;
					else grid[i][j] = -1;
				}
			}
		}
		
		fill (N - 1, M - 1);
		bool found = true;
		for (auto pair : required) {
			if(!visited[get<0>(pair)][get<1>(pair)]) {
				found = false;
				break;
			}
		}
		if (found) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}