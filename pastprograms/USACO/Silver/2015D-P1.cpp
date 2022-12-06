#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, c, d, onc = 1;

vector<pair<int, int>> switches[100][100];
bool on[100][100], searched[100][100], accessible[100][100];

void flood (int x, int y) {
	if(x < 0 || y < 0 || x >= N || y >= N) return;
	if(!searched[x][y]) {
		accessible[x][y] = true;
		if(on[x][y]) {
			searched[x][y] = true;
			for (auto p : switches[x][y]) {
				if(!on[p.first][p.second]) {
					on[p.first][p.second] = true;
					onc ++;
					if(accessible[p.first][p.second]) flood(p.first, p.second);
				}
			}
			flood(x - 1, y);
			flood(x + 1, y);
			flood(x, y - 1);
			flood(x, y + 1);
		}
	}
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("lightson.in");
	fout.open("lightson.out");

	ios_base::sync_with_stdio(0); fin.tie(nullptr);
	fin >> N >> M;
	for (int i = 0; i < M; i ++) {
		fin >> a >> b >> c >> d;
		a --; b --; c --; d --;
		switches[a][b].pb(mp(c, d));
	}
	on[0][0] = true;
	flood(0, 0);
	fout << onc;
}