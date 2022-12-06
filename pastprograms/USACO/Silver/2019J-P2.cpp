#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, area, perimeter, color = 0;
int perimeters[1000000];
int grid[1000][1000];
char a;


void flood(int x, int y) {
	if(x < 0 || y < 0 || x == N || y == N) {
		perimeter ++;
		return;
	}
	if(grid[x][y] == -2) {
		perimeter ++;
		return;
	}
	if(grid[x][y] == -1) {
		grid[x][y] = color;
		area ++;
		flood(x - 1, y);
		flood(x + 1, y);
		flood(x, y - 1);
		flood(x, y + 1);
	}
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("perimeter.in");
	fout.open("perimeter.out");

	ios_base::sync_with_stdio(0); fin.tie(nullptr);
	fin >> N;
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			fin >> a;
			if(a == '#') grid[i][j] = -1;
			if(a == '.') grid[i][j] = -2;
		}
	}
	int bestarea = -1, bestcolor = -1;
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			if(grid[i][j] == -1) {
				area = 0; perimeter = 0;
				flood(i, j);
				perimeters[color] = perimeter;
				if((area == bestarea && perimeters[bestcolor] > perimeter) || (area > bestarea)) {
					bestarea = area; bestcolor = color;
				}
				color ++;
			}
		}
	}
	fout << bestarea << " " << perimeters[bestcolor];
}