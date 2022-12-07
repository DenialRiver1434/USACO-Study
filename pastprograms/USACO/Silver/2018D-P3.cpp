#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, K, ccc = 0;
char a;
vector<int> board[10];
bool searched[10][100];

void dfs (int x, int y, int color) {
	if(x < 0 || x > 9 || y < 0 || y >= board[x].size()) return;
	if(searched[x][y] || board[x][y] != color) return;
	searched[x][y] = true;
	ccc ++;
	dfs(x - 1, y, color);
	dfs(x + 1, y, color);
	dfs(x, y - 1, color);
	dfs(x, y + 1, color);
}
void floodfill (int x, int y, int color) {
	if(x < 0 || x > 9 || y < 0 || y >= board[x].size()) return;
	if(board[x][y] != color) return;
	board[x][y] = 0;
	floodfill(x - 1, y, color);
	floodfill(x + 1, y, color);
	floodfill(x, y - 1, color);
	floodfill(x, y + 1, color);
}

void gravity () {
	for (int i = 0; i < 10; i ++) {
		vector<int> add;
		for (auto b : board[i]) {
			if(b) add.pb(b);
		}
		board[i].clear();
		for (auto a : add) board[i].pb(a);
	}
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("mooyomooyo.in");
	fout.open("mooyomooyo.out");

	fin >> N >> K;
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < 10; j ++) {
			fin >> a;
			board[j].pb(int(a) - 48);
		}
	}
	for (int i = 0; i < 10; i ++) reverse(board[i].begin(), board[i].end());
	gravity();
	while(true) {
		bool changed = false;
		for (int i = 0; i < 10; i ++) {
			for (int j = 0; j < board[i].size(); j ++) {
				searched[i][j] = false;
			}
		}

		for (int i = 0; i < 10; i ++) {
			for (int j = 0; j < board[i].size(); j ++) {
				if(!searched[i][j] && board[i][j] != 0) {
					ccc = 0;
					dfs (i, j, board[i][j]);
					if(ccc >= K) {
						changed = true;
						floodfill (i, j, board[i][j]);
					}
				}
			}
		}
		if(changed) gravity();
		else break;
	}
	for (int i = N - 1; i >= 0; i --) {
		for (int j = 0; j < 10; j ++) {
			if(i >= board[j].size()) fout << 0;
			else fout << board[j][i];
		}
		fout << endl;
	}
}