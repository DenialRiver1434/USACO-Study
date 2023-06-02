#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (int i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	ifstream fin; ofstream fout;
	fin.open("cownav.in"); fout.open("cownav.out");

	int N;
	fin >> N;
	bool open[N][N];
	int best[N][N][4][N][N][4];

	f0r (i, 0, N) {
		f0r (j, 0, N) {
			char a; fin >> a;
			open[i][j] = (a == 'E');
			f0r (k, 0, N) {
				f0r (l, 0, N) {
					f0r (da, 0, 4) {
						f0r (db, 0, 4) {
							best[i][j][da][k][l][db] = INF;
						}
					}
				}
			}
		}
	}

	// +y = right = 0, down = +x = 1, -y = left = 2, -x = up = 3 
	best[N - 1][0][3][N - 1][0][0] = 0;
	queue<tuple<int, int, int, int, int, int>> q; // right x, y, dir -> down x, y, dir
	q.push(mt(N - 1, 0, 3, N - 1, 0, 0));
	while (!q.empty()) {
		int xr, yr, dr, xd, yd, dd;
		tie(xr, yr, dr, xd, yd, dd) = q.front();
		q.pop();
		int cur = best[xr][yr][dr][xd][yd][dd];
		// cout << xr << " " << yr << " " << dr << " " << xd << " " << yd << " " << dd << " : " << cur << endl;

		if((xr == 0) && (yr == (N - 1)) && (xd == 0) && (yd == (N - 1))) {
			fout << cur << endl;
			return 0;
		}
		
		// TURN RIGHT
		int potdr = (dr + 1) % 4;
		int potdd = (dd + 1) % 4;
		if((cur + 1) < best[xr][yr][potdr][xd][yd][potdd]) {
			best[xr][yr][potdr][xd][yd][potdd] = cur + 1;
			q.push(mt(xr, yr, potdr, xd, yd, potdd));
		}

		// TURN LEFT
		potdr = (dr - 1);
		if(potdr < 0) potdr += 4;
		potdd = (dd - 1);
		if(potdd < 0) potdd += 4;
		if((cur + 1) < best[xr][yr][potdr][xd][yd][potdd]) {
			best[xr][yr][potdr][xd][yd][potdd] = cur + 1;
			q.push(mt(xr, yr, potdr, xd, yd, potdd));
		}

		// FOWARD
		if((xr != 0) || (yr != (N - 1))) {
			if(dr == 0 && yr != (N - 1)) {
				if(open[xr][yr + 1]) yr ++;
			}
			if(dr == 1 && xr != (N - 1)) {
				if(open[xr + 1][yr]) xr ++;
			}
			if(dr == 2 && yr != 0) {
				if(open[xr][yr - 1]) yr --;
			}
			if (dr == 3 && xr != 0) {
				if(open[xr - 1][yr]) xr --;
			}
		}

		if((xd != 0) || (yd != (N - 1))) {
			if(dd == 0 && yd != (N - 1)) {
				if(open[xd][yd + 1]) yd ++;
			}
			if(dd == 1 && xd != (N - 1)) {
				if(open[xd + 1][yd]) xd ++;
			}
			if(dd == 2 && yd != 0) {
				if(open[xd][yd - 1]) yd --;
			}
			if (dd == 3 && xd != 0) {
				if(open[xd - 1][yd]) xd --;
			}
		}

		if((cur + 1) < best[xr][yr][dr][xd][yd][dd]) {
			best[xr][yr][dr][xd][yd][dd] = cur + 1;
			q.push(mt(xr, yr, dr, xd, yd, dd));
		}
	}
	fout << -1 << endl;
}
