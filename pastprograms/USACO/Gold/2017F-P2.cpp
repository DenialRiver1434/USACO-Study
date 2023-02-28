#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	ifstream fin; ofstream fout;
	fin.open("nocross.in"); fout.open("nocross.out");

	int N;
	fin >> N;
	int best[N][N], left[N], right[N]; // best case with cross walk from i to j
	f0r (i, 0, N) fin >> left[i];
	f0r (i, 0, N) fin >> right[i];

	f0r (i, 0, N) {
		f0r (j, 0, N) {
			best[i][j] = abs(left[i] - right[j]) <= 4;
			if (i > 0 && j > 0) best[i][j] += best[i - 1][j - 1];
			if (i > 0) best[i][j] = max(best[i][j], best[i - 1][j]);
			if (j > 0) best[i][j] = max(best[i][j], best[i][j - 1]);
		}
	}
	fout << best[N - 1][N - 1] << endl;
}