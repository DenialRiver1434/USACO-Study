#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (int i = begin; i < end; i ++) 
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

int best[2][500][500];
char inp[500][500];
const int MOD = 1e9 + 7;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	ifstream fin; ofstream fout;
	fin.open("palpath.in"); fout.open("palpath.out");

	int N; fin >> N;
	f0r (i, 0, 2) {
		f0r (j, 0, N) {
			f0r (k, 0, N) best[i][j][k] = (i == 0) && (j == k);
		}
	}
	f0r (i, 0, N) {
		f0r (j, 0, N) fin >> inp[i][j];
	}

	f0r (a, 0, N - 1) {
		f0r (x1, 0, N) {
			f0r (x2, x1, N) best[(a + 1) % 2][x1][x2] = 0;
		}

		for (int x1 = N - 1; x1 >= 0; x1 --) {
			f0r (x2, x1, N) {
				int total = 2 * a;
				int vert = x2 - x1;
				int hori = total - vert;
				if((hori < 0) || (hori >= N)) continue;

				double expx = (x2 + x1) / 2;
				if(((x2 + x1) % 2) == 1) expx += 0.5;
				double expy = N - 1 - expx;
				double y1 = expy - hori / 2;
				if((hori % 2) == 1) y1 -= 0.5;
				int defy1 = round(y1);
				int defy2 = defy1 + hori;

				if((defy1 < 0) || (defy2 >= N)) continue;

				int cur = best[a % 2][x1][x2];
				if((x1 > 0) && (x2 < (N - 1))) {
					if (inp[x1 - 1][defy1] == inp[x2 + 1][defy2]) {
						best[(a + 1) % 2][x1 - 1][x2 + 1] += cur;
						best[(a + 1) % 2][x1 - 1][x2 + 1] %= MOD;
					}
				}
				if((x1 > 0) && (defy2 < (N - 1))) {
					if (inp[x1 - 1][defy1] == inp[x2][defy2 + 1]) {
						best[(a + 1) % 2][x1 - 1][x2] += cur;
						best[(a + 1) % 2][x1 - 1][x2] %= MOD;
					}
				}
				if((defy1 > 0) && (x2 < (N - 1))) {
					if (inp[x1][defy1 - 1] == inp[x2 + 1][defy2]) {
						best[(a + 1) % 2][x1][x2 + 1] += cur;
						best[(a + 1) % 2][x1][x2 + 1] %= MOD;
					}
				}
				if((defy1 > 0) && (defy2 < (N - 1))) {
					if (inp[x1][defy1 - 1] == inp[x2][defy2 + 1]) {
						best[(a + 1) % 2][x1][x2] += cur;
						best[(a + 1) % 2][x1][x2] %= MOD;
					}
				}
			}
		}
	}

	fout << best[(N - 1) % 2][0][N - 1] << endl;
}
