#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
vector<tuple<int, int>> coords;
vector<int> conn[100000];
int color[100000];
vector<int> rcolor[100001];

void fill(int pos, int col) {
	if(color[pos]) return;
	color[pos] = col;
	rcolor[col].pb(pos);
	for (auto c : conn[pos]) fill(c, col);
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("fenceplan.in");
	fout.open("fenceplan.out");

	fin >> N >> M;
	for (int i = 0; i < N; i ++) {
		fin >> a >> b;
		coords.pb(mt(a, b));
		color[i] = 0;
	}
	while (M --) {
		fin >> a >> b;
		conn[a - 1].pb(b - 1);
		conn[b - 1].pb(a - 1);
	}
	int col = 0;
	for (int i = 0; i < N; i ++) {
		if(color[i] == 0) {
			col ++;
			fill(i, col);
		}
	}
	int best = 1e9;
	for (int i = 1; i <= col; i ++) {
		int maxx = 0, maxy = 0, minx = 1e9, miny = 1e9;
		for (auto c : rcolor[i]) {
			int x = get<0>(coords[c]), y = get<1>(coords[c]);
			maxx = max(x, maxx);
			minx = min(x, minx);
			maxy = max(y, maxy);
			miny = min(y, miny);
		}
		best = min(best, (maxx - minx + maxy - miny) * 2);
	}
	fout << best;
}