#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (int i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

int main () {
	// ios_base::sync_with_stdio(0); cin.tie(nullptr);
	ifstream fin; ofstream fout;
	fin.open("snakes.in"); fout.open("snakes.out");

	int N, K; fin >> N >> K; 
	int snakes[N], best[N][N]; // best is inclusive
	for_loop (i, 0, N) {
		fin >> snakes[i];
	}

	for_loop (i, 0, N) {
		multiset<int> nums;
		for_loop (j, i, N) {
			nums.is(snakes[j]);

			int base = *nums.rbegin();
			best[i][j] = 0;
			for (auto n : nums) {
				best[i][j] += (base - n);
			}
		}
	}
	
	int possible[K + 1][N];
	for_loop (i, 0, K + 1) {
		for_loop (j, 0, N) {
			possible[i][j] = 1e9;
		}
	}
	
	for_loop (i, 0, N) {
		possible[0][i] = best[0][i];
		for_loop (j, 0, i) {
			for_loop (k, 0, K) {
				possible[k + 1][i] = min(possible[k + 1][i], possible[k][j] + best[j + 1][i]);
			}
		}
	}

	int res = 1e9;
	for_loop (i, 0, K + 1) {
		res = min(res, possible[i][N - 1]);
	}
	fout << res << endl;
}