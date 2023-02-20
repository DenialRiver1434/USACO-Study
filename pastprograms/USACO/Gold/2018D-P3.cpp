#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (int i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

int main () {
	ifstream fin; ofstream fout;
	fin.open("teamwork.in"); fout.open("teamwork.out");

	int N, M;
	fin >> N >> M;
	int best[N], cows[N];
	for_loop (i, 0, N) {
		fin >> cows[i];
		best[i] = 0;
		if(i == 0) {
			best[i] = cows[i];
			continue;
		}
		int top = 0;
		for (int j = i; j >= max(0, i - M + 1); j --) {
			top = max(top, cows[j]);
			if(j == 0) best[i] = max(best[i], top * (i - j + 1));
			else best[i] = max(best[i], best[j - 1] + top * (i - j + 1));
		}
	}
	fout << best[N - 1] << endl;
}