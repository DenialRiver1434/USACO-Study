#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

// M = 1, O = 2

int N, grid[25][25], total = 0; bool searchgrid[25][25];
bool searched[626][3][3][3][3][3][3][3][3][3];
tuple<int, int, int> assignment[626];
set<int> current;
vector<int> conn[626];

char a, b, c;

bool good (int t1, int t2, int t3, int t4, int t5, int t6, int t7, int t8, int t9) {
	if(t1 == 1 && t2 == 2 && t3 == 2) return true;
	if(t4 == 1 && t5 == 2 && t6 == 2) return true;
	if(t7 == 1 && t8 == 2 && t9 == 2) return true;
	if(t1 == 2 && t2 == 2 && t3 == 1) return true;
	if(t4 == 2 && t5 == 2 && t6 == 1) return true;
	if(t7 == 2 && t8 == 2 && t9 == 1) return true;
	if(t1 == 2 && t4 == 2 && t7 == 1) return true;
	if(t2 == 2 && t5 == 2 && t8 == 1) return true;
	if(t3 == 2 && t6 == 2 && t9 == 1) return true;
	if(t1 == 1 && t4 == 2 && t7 == 2) return true;
	if(t2 == 1 && t5 == 2 && t8 == 2) return true;
	if(t3 == 1 && t6 == 2 && t9 == 2) return true;
	if(t1 == 1 && t5 == 2 && t9 == 2) return true;
	if(t1 == 2 && t5 == 2 && t9 == 1) return true;
	if(t3 == 1 && t5 == 2 && t7 == 2) return true;
	if(t3 == 2 && t5 == 2 && t7 == 1) return true;
	return false;
}

void dfs (int pos, int t1, int t2, int t3, int t4, int t5, int t6, int t7, int t8, int t9) {
	if(searched[pos][t1][t2][t3][t4][t5][t6][t7][t8][t9]) return;
	if(good(t1, t2, t3, t4, t5, t6, t7, t8, t9)) {
		bool found = true;
		for (int i = 0; i < 626; i ++ ) {
			if(searched[i][t1][t2][t3][t4][t5][t6][t7][t8][t9]) {
				found = false;
			}
		}
		searched[pos][t1][t2][t3][t4][t5][t6][t7][t8][t9] = true;
		if(found) {
			total += 1;
		}
		return;
	}
	searched[pos][t1][t2][t3][t4][t5][t6][t7][t8][t9] = true;
	int a = get<0>(assignment[pos]), b = get<1>(assignment[pos]), c = get<2>(assignment[pos]);
	if (a == 1) {
		if(b == 0 && c == 0 && t1 == 0) t1 = 1;
		if(b == 0 && c == 1 && t2 == 0) t2 = 1;
		if(b == 0 && c == 2 && t3 == 0) t3 = 1;
		if(b == 1 && c == 0 && t4 == 0) t4 = 1;
		if(b == 1 && c == 1 && t5 == 0) t5 = 1;
		if(b == 1 && c == 2 && t6 == 0) t6 = 1;
		if(b == 2 && c == 0 && t7 == 0) t7 = 1;
		if(b == 2 && c == 1 && t8 == 0) t8 = 1;
		if(b == 2 && c == 2 && t9 == 0) t9 = 1;
	}
	if (a == 2) {
		if(b == 0 && c == 0 && t1 == 0) t1 = 2;
		if(b == 0 && c == 1 && t2 == 0) t2 = 2;
		if(b == 0 && c == 2 && t3 == 0) t3 = 2;
		if(b == 1 && c == 0 && t4 == 0) t4 = 2;
		if(b == 1 && c == 1 && t5 == 0) t5 = 2;
		if(b == 1 && c == 2 && t6 == 0) t6 = 2;
		if(b == 2 && c == 0 && t7 == 0) t7 = 2;
		if(b == 2 && c == 1 && t8 == 0) t8 = 2;
		if(b == 2 && c == 2 && t9 == 0) t9 = 2;
	}
	for (auto c : conn[pos]) {
		dfs(c, t1, t2, t3, t4, t5, t6, t7, t8, t9);
	}
}

void fill (int x, int y, bool justin) {
	if(x < 0 || y < 0 || x >= N || y >= N) return;
	if(searchgrid[x][y]) return;
	if(grid[x][y] == -1) return;
	if(grid[x][y] > 0) {
		current.is(grid[x][y]);
		if(!justin) return;
	}
	searchgrid[x][y] = true;
	fill (x - 1, y, false);
	fill (x + 1, y, false);
	fill (x, y - 1, false);
	fill (x, y + 1, false);
}

int main () {
	cin >> N;
	int count = 1, startx, starty;
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			cin >> a;
			if(a == 'O') {
				cin >> b >> c;
				int bi = int(b) - int('1'), ci = int(c) - int('1');
				assignment[count] = mt(2, bi, ci);
				grid[i][j] = count ++;
			}
			else if(a == 'M') {
				cin >> b >> c;
				int bi = int(b) - int('1'), ci = int(c) - int('1');
				assignment[count] = mt(1, bi, ci);
				grid[i][j] = count ++;
			}
			else if(a == '#') {
				cin >> b >> c;
				grid[i][j] = -1;
			}
			else if(a == '.') {
				cin >> b >> c;
				grid[i][j] = 0;
			}
			else {
				cin >> b >> c;
				startx = i; starty = j;
			}
		}
	}

	fill(startx, starty, true);
	current.is(0);
	int l = current.size();
	for (auto i = current.begin(); i != current.end(); i ++) {
		for (auto j = next(i); j != current.end(); j ++) {
			conn[*i].pb(*j);
			conn[*j].pb(*i);
		}
	}
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			if(!searchgrid[i][j] && grid[i][j] != -1) {
				current.clear();
				fill(i, j, true);
				int l = current.size();
				for (auto i = current.begin(); i != current.end(); i ++) {
					for (auto j = next(i); j != current.end(); j ++) {
						conn[*i].pb(*j);
						conn[*j].pb(*i);
					}
				}
			}
		}
	}
	dfs(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	cout << total;
}