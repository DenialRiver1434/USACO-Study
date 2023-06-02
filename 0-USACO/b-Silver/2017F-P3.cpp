#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, K, R, a, b, c, d;
bool searched[100][100];
int colors[100][100];
bool toright[100][100], toleft[100][100], toup[100][100], todown[100][100];
vector<pair<int, int>> inps;

void dfs (int x, int y, int color) {
	if(x < 0 || x >= N || y < 0 || y >= N || colors[x][y]) return;
	colors[x][y] = color;
	if(!todown[x][y]) dfs(x - 1, y, color);
	if(!toup[x][y]) dfs(x + 1, y, color);
	if(!toleft[x][y]) dfs(x, y - 1, color);
	if(!toright[x][y]) dfs(x, y + 1, color);
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("countcross.in");
	fout.open("countcross.out");

	fin >> N >> K >> R;
	for (int i = 0; i < R; i ++) { // down = -, up = +
		fin >> a >> b >> c >> d;
		a --; b --; c --; d --;
		if(a < c) {
			toup[a][b] = true;
			todown[c][d] = true;
		}
		else if(a > c) {
			todown[a][b] = true;
			toup[c][d] = true;
		}
		else if(b < d) {
			toright[a][b] = true;
			toleft[c][d] = true;
		}
		else {
			toleft[a][b] = true;
			toright[c][d] = true;
		}
	}
	int color = 1;
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			if(!colors[i][j]) dfs(i, j, color ++);
		}
	}
	for (int i = 0; i < K; i ++) {
		fin >> a >> b;
		a --; b --;
		inps.pb(mp(a, b));
	}
	int co = 0;
	for (int i = 0; i < K; i ++) {
		for (int j = i + 1; j < K; j ++) {
			auto a = inps[i], b = inps[j];
			if(colors[a.first][a.second] != colors[b.first][b.second]) co ++;
		}
	}
	fout << co;
}