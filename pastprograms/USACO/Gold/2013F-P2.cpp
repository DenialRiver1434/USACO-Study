#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (int i = begin; i < end; i ++) 
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	ifstream fin; ofstream fout;
	fin.open("tractor.in"); fout.open("tractor.out");

	int N; fin >> N;
	if(N == 1) {
		cout << 0 << endl;
		return 0;
	}
	int target = (N*N) / 2 + (N % 2);
	int grid[N][N];
	DSU D = DSU(N * N);
	vector<tuple<int, int, int>> paths; // diff, start, end
	f0r (i, 0, N) {
		f0r (j, 0, N) {
			int val = i * N + j;
			fin >> grid[i][j];
			if(i > 0) {
				paths.pb(mt(abs(grid[i][j] - grid[i - 1][j]), val, val - N));
			}
			if(j > 0) {
				paths.pb(mt(abs(grid[i][j] - grid[i][j - 1]), val, val - 1));
			}
		}
	}
	sort(paths.begin(), paths.end());
	for (auto p : paths) {
		D.unite(get<1>(p), get<2>(p));
		if(D.size(get<1>(p)) >= target) {
			fout << get<0>(p) << endl;
			return 0;
		}
	}
}
