#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define f0r(i, begin, n) for (ll i = begin; i < n; i ++)
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

int grid[1001][1001], dc[1001][1001];
int adjusted[1001][1001], simplified[1001][1001];

int main () {
    ifstream fin; ofstream fout;
    fin.open("paintbarn.in"); fout.open("paintbarn.out");

	int N, K; 
	fin >> N >> K;
    f0r (i, 0, N) {
        int a, b, c, d; fin >> a >> b >> c >> d;
        dc[a][b] ++; dc[c][b] --; dc[a][d] --; dc[c][d] ++;
    }
    int lay = 0, cK = 0;
    f0r (i, 0, 1001) {
        int bonus = 0;
        f0r (j, 0, 1001) {
            bonus += dc[i][j];
            if(i == 0) dc[i][j] = bonus;
            else dc[i][j] = dc[i - 1][j] + bonus;
            if(dc[i][j] == K) {
                cK ++;
                simplified[i][j] = -1;
            }
            if(dc[i][j] == (K - 1)) {
                simplified[i][j] = 1;
            }
        }
    }
    fout << cK << endl;
}
