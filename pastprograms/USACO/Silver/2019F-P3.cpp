#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define f0r(i, begin, n) for (ll i = begin; i < n; i ++)
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

const int INF = -1e9;
int grid[205][205], dc[205][205];
int simplified[205][205], psimp[205][205];
int rowbestdiff[205][205][205], columnbestdiff[205][205][205];

int main () {
    ifstream fin; ofstream fout;
    fin.open("paintbarn.in"); fout.open("paintbarn.out");

	int N, K; 
	fin >> N >> K;
    f0r (i, 0, N) {
        int a, b, c, d; fin >> a >> b >> c >> d;
		a += 2; b += 2; c += 2; d += 2;
        dc[a][b] ++; dc[c][b] --; dc[a][d] --; dc[c][d] ++;
    }
    int lay = 0, baseline = 0;
    f0r (i, 0, 205) {
        int bonus = 0;
        f0r (j, 0, 205) {
            bonus += dc[i][j];
            if(i == 0) dc[i][j] = bonus;
            else dc[i][j] = dc[i - 1][j] + bonus;
            if(dc[i][j] == K) {
                simplified[i][j] = -1;
				baseline ++;
            }
            if(dc[i][j] == (K - 1)) {
                simplified[i][j] = 1;
            }
			
			psimp[i][j] = simplified[i][j];
			if(i > 0) psimp[i][j] += psimp[i - 1][j];
			if(j > 0) psimp[i][j] += psimp[i][j - 1];
			if((i > 0) && (j > 0)) psimp[i][j] -= psimp[i - 1][j - 1];
        }
    }

	f0r (i, 0, 205) {
		f0r (j, i, 205) {
			rowbestdiff[i][j][0] = 0;
			columnbestdiff[i][j][0] = 0;
			f0r (k, 1, 205) {
				rowbestdiff[i][j][k] = max(rowbestdiff[i][j][k - 1], psimp[i][k] - psimp[j][k]);
				columnbestdiff[i][j][k] = max(columnbestdiff[i][j][k - 1], psimp[k][i] - psimp[k][j]);
			}
		}
	}

	int optimal = 0;
	int ba = 0;
	f0r (i, 1, 205) {
		int bb = 0;
		f0r (j, 1, i + 1) {
			f0r (k, 1, 205) {
				ba = max(ba, rowbestdiff[j][i][k] + psimp[i][k] - psimp[j][k]);
			}
		}
		f0r (j, i + 1, 205) {
			f0r (k, 1, 205) {
				bb = max(bb, rowbestdiff[i][j][k] + psimp[j][k] - psimp[i][k]);
			}
		}
		optimal = max(optimal, ba + bb);
	}
	ba = 0;
	f0r (i, 1, 205) {
		int bb = 0;
		f0r (j, 1, i + 1) {
			f0r (k, 1, 205) {
				ba = max(ba, columnbestdiff[j][i][k] + psimp[k][i] - psimp[k][j]);
			}
		}
		f0r (j, i + 1, 205) {
			f0r (k, 1, 205) {
				bb = max(bb, columnbestdiff[i][j][k] + psimp[k][j] - psimp[k][i]);
			}
		}
		optimal = max(optimal, ba + bb);
	}

	fout << min(40000, optimal + baseline) << endl;
}
