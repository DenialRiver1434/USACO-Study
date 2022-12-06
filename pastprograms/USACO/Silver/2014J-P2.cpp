#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, M, a, num;
int grid[500][500];
bool found[500][500];
vector<tuple<int, int>> waypoints;

void fill (int x, int y, int prev) {
	if (x < 0 || y < 0 || x >= N || y >= M) return;
	if (found[x][y] || abs(grid[x][y] - prev) > num) return;

	found[x][y] = true;
	fill(x - 1, y, grid[x][y]);
	fill(x + 1, y, grid[x][y]);
	fill(x, y - 1, grid[x][y]);
	fill(x, y + 1, grid[x][y]);
}

bool test () {
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < M; j ++) {
			found[i][j] = false;
		}
	}
	fill (get<0>(waypoints[0]), get<1>(waypoints[0]), grid[get<0>(waypoints[0])][get<1>(waypoints[0])]);
	bool f = true;
	for (auto w : waypoints) {
		if(!found[get<0>(w)][get<1>(w)]) f = false;
	}
	return f;
}

int first_true(int lo, int hi) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		num = mid;
		if (test()) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("ccski.in");
	fout.open("ccski.out");

	ios_base::sync_with_stdio(0); fin.tie(nullptr);
	fin >> N >> M;
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < M; j ++) {
			fin >> a;
			grid[i][j] = a;
		}
	}
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < M; j ++) {
			fin >> a;
			if (a) {
				waypoints.pb(mt(i, j));
			}
		}
	}
	if(waypoints.size() < 2) {
		fout << 0;
		return 0;
	}
	fout << first_true(0, 1e9);
}