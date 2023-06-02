#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

short N, grid[1002][1002];
char a;

void floodfill (short x, short y, short color) {
	if(x < 0 || y < 0 || x >= 1002 || y >= 1002) return;
	if(grid[x][y] != 0) return;
	grid[x][y] = color;
	floodfill(x - 1, y, color);
	floodfill(x, y - 1, color);
	floodfill(x + 1, y, color);
	floodfill(x, y + 1, color);
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("gates.in");
	fout.open("gates.out");

	ios_base::sync_with_stdio(0); fin.tie(nullptr);
	fin >> N;
	short x = 501, y = 501;
	grid[x][y] = -1;
	short color = 1;
	for (short i = 0; i < N; i ++) {
		fin >> a;
		if (a == 'N') {
			if((x + 2) >= 1002) {
				cout << 1;
				return 0;
			}
			x ++;
			grid[x][y] = -1;
			x ++;
			grid[x][y] = -1;
		}
		else if (a == 'E') {
			if((y + 2) >= 1002) {
				cout << 1;
				return 0;
			}
			y ++;
			grid[x][y] = -1;
			y ++;
			grid[x][y] = -1;
		}
		else if (a == 'S') {
			if((x - 2) < 0) {
				cout << 1;
				return 0;
			}
			x --;
			grid[x][y] = -1;
			x --;
			grid[x][y] = -1;
		}
		else {
			if((y - 2) < 0) {
				cout << 1;
				return 0;
			}
			y --;
			grid[x][y] = -1;
			y --;
			grid[x][y] = -1;
		}
	}
	for (short i = 0; i < 1002; i ++) {
		for (short j = 0; j < 1002; j ++) {
			if(grid[i][j] == 0) {
				floodfill(i, j, color);
				color ++;
			}
		}
	}
	fout << color - 2;
}