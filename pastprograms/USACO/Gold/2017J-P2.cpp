#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

int main () {
	ifstream fin; ofstream fout;
	fin.open("hps.in"); fout.open("hps.out");

	int N, M; 
	fin >> N >> M;
	int H[21][100001], P[21][100001], S[21][100001];
	for_loop (i, 0, 22) {
		H[i][0] = 0;
	}
	for_loop (i, 1, N + 1) {
		char a; fin >> a;
		H[0][i] = H[0][i - 1] + (a == 'H');
		P[0][i] = P[0][i - 1] + (a == 'P');
		S[0][i] = S[0][i - 1] + (a == 'S');
	for_loop (j, 1, M + 1) {
			H[j][i] = max({H[j - 1][i - 1], P[j - 1][i - 1], S[j - 1][i - 1]}) + (a == 'H');
			P[j][i] = max({H[j - 1][i - 1], P[j - 1][i - 1], S[j - 1][i - 1]}) + (a == 'P');
			S[j][i] = max({H[j - 1][i - 1], P[j - 1][i - 1], S[j - 1][i - 1]}) + (a == 'S');
			H[j][i] = max(H[j][i], H[j][i - 1] + (a == 'H'));
			P[j][i] = max(P[j][i], P[j][i - 1] + (a == 'P'));
			S[j][i] = max(S[j][i], S[j][i - 1] + (a == 'S'));
		}
	}
	int best = 0;
	for_loop (i, 0, M + 1) {
		best = max({best, H[i][N], P[i][N], S[i][N]});
	}
	fout << best << endl;
}