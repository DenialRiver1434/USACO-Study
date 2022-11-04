#include <bits/stdc++.h>
using namespace std;

int N, M, a, best = 0;
int grid[800][800];
int upTo[801][801];
int search (int x, int y) {
	int a = max(0, x - M), b = max(0, y - M), c = min(2 * N - 1, x + M), d = min(2 * N - 1, y + M);
	return upTo[c + 1][d + 1] - upTo[a][d + 1] - upTo[c + 1][b] + upTo[a][b];
}

int main() {
    ifstream fin;
    fin.open("lazy.in");
    ofstream fout;
    fout.open("lazy.out");
	
	fin >> N >> M;
	int orow = 0, ocolumn = N - 1;
	for (int i = 0; i < N; i ++) {
		int cr = orow, cc = ocolumn;
		for (int j = 0; j < N; j ++) {
			fin >> a;
			grid[cr][cc] = a;
			cr ++; cc ++;
		}
		orow ++; ocolumn --;
	}
	
	for (int i = 1; i < N * 2 + 1; i ++ ) {
		for (int j = 1; j < N * 2 + 1; j ++) {
			upTo[i][j] = upTo[i - 1][j] + upTo[i][j - 1] - upTo[i - 1][j - 1];
			upTo[i][j] += grid[i - 1][j - 1];
		}
	}

	orow = 0, ocolumn = N - 1;
	for (int i = 0; i < N; i ++) {
		int cr = orow, cc = ocolumn;
		for (int j = 0; j < N; j ++) {
			best = max(best, search(cr, cc));
			cr ++; cc ++;
		}
		orow ++; ocolumn --;
	}
	fout << best;
}
