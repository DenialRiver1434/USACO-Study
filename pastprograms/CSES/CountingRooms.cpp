#include <bits/stdc++.h>
using namespace std;
int N, M;
char a;
int grid[1000][1000];
 
void floodfill (int x, int y, int color) {
	if(x < 0 || y < 0 || x >= N || y >= M) return;
	if(grid[x][y] != -1) return;
	grid[x][y] = color;
	floodfill(x - 1, y, color);
	floodfill(x, y - 1, color);
	floodfill(x + 1, y, color);
	floodfill(x, y + 1, color);
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < M; j ++) {
			cin >> a;
			if(a == '.') grid[i][j] = -1;
			else grid[i][j] = -2;
		}
	}
	int fills = 0;
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < M; j ++) {
			if(grid[i][j] == -1) {
				fills ++;
				floodfill(i, j, fills);
			}
		}
	}
	cout << fills;
}