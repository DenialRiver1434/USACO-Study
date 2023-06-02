#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

int dist (int x1, int y1, int x2, int y2) {
	return ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	ifstream fin; ofstream fout;
	fin.open("radio.in"); fout.open("radio.out");

	int N, M; fin >> N >> M;
	int best[N + 1][M + 1];

	f0r (i, 0, N + 1) {
		f0r (j, 0, M + 1) best[i][j] = 1e9;
	}

	int a, b, c, d; fin >> a >> b >> c >> d;
	vector<pair<int, int>> farmer = {{a, b}};
	vector<pair<int, int>> bessie = {{c, d}};
	best[0][0] = 0;

	char inp; 
	f0r (i, 0, N) {
		fin >> inp;
		if(inp == 'N') {
			farmer.pb(mp(a, ++b));
		}
		if(inp == 'S') {
			farmer.pb(mp(a, --b));
		}
		if(inp == 'E') {
			farmer.pb(mp(++a, b));
		}
		if(inp == 'W') {
			farmer.pb(mp(--a, b));
		}
	}
	f0r (i, 0, M) {
		fin >> inp;
		if(inp == 'N') {
			bessie.pb(mp(c, ++d));
		}
		if(inp == 'S') {
			bessie.pb(mp(c, --d));
		}
		if(inp == 'E') {
			bessie.pb(mp(++c, d));
		}
		if(inp == 'W') {
			bessie.pb(mp(--c, d));
		}
	}
	
	f0r (i, 0, N + 1) {
		f0r (j, 0, M + 1) {
			if(i == 0 && j == 0) continue;
			if (i > 0) {
				best[i][j] = min(best[i][j], best[i - 1][j]);
			}
			if (j > 0) {
				best[i][j] = min(best[i][j], best[i][j - 1]);
			}
			if ((i > 0) && (j > 0)) {
				best[i][j] = min(best[i][j], best[i - 1][j - 1]);
			}
			best[i][j] += dist(farmer[i].first, farmer[i].second, bessie[j].first, bessie[j].second);
		}
	}
	fout << best[N][M] << endl;
}