#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (int i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

int N, M, C, possible[505][1000], worth[1000];
vector<pair<int, int>> roads;

int main () {
	ifstream fin; ofstream fout;
	fin.open("time.in"); fout.open("time.out");

    fin >> N >> M >> C;
	possible[0][0] = 0;
	fin >> worth[0];
	for_loop (i, 1, N) {
		possible[0][i] = -1e9;
		fin >> worth[i];
	}
	for_loop (i, 0, M) {
		int a, b; fin >> a >> b;
		roads.pb(mp(a - 1, b - 1));
	}
	for_loop (t, 1, 505) {
		for_loop (i, 0, N) {
			possible[t][i] = possible[t - 1][i] - (C * (2 * t - 1));
		}
		for (auto pa : roads) {
			int start = pa.first, end = pa.second;
			possible[t][end] = max(possible[t][end], possible[t - 1][start] + worth[end] - (C * (2 * t - 1)));
		}
	}
	int best = 0;
	for_loop (i, 0, 505) {
		best = max(best, possible[i][0]);
	}
	fout << best << endl;
}
