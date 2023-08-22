/*
ID: shurong1
LANG: C++
TASK: castle
*/

#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, M, original[50][50], color[50][50], area[2501];

void fill (int x, int y, int col) {
    if(x < 0 || y < 0 || x >= N || y >= M) return;
    if(color[x][y]) return;
    color[x][y] = col;
    area[col] ++;
    int num = original[x][y];
    if(num < 8) {
        fill (x + 1, y, col);
    }
    else num -= 8;
    if(num < 4) {
        fill (x, y + 1, col);
    }
    else num -= 4;
    if(num < 2) {
        fill (x - 1, y, col);
    }
    else num -= 2;
    if(num < 1) {
        fill (x, y - 1, col);
    }
}

int main () {
    ifstream fin; fin.open("castle.in");
    ofstream fout; fout.open("castle.out");
    fin >> M >> N;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            fin >> original[i][j];
        }
    }
    int col = 1, ma = 0;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            if(!color[i][j]) fill(i, j, col ++);
            ma = max(ma, area[col - 1]);
        }
    }
    fout << col - 1 << endl;
    fout << ma << endl;
    int best = 0; 
    tuple<int, int, char> op;
    
    for (int j = 0; j < M; j ++) {
        for (int i = N - 1; i >= 0; i --) {
            if(i > 0) {
                if(color[i - 1][j] != color[i][j]) {
                    int pos = area[color[i - 1][j]] + area[color[i][j]];
                    if(pos > best) {
                        best = pos;
                        op = mt(i + 1, j + 1, 'N');
                    }
                }
            }
            if(j < (M - 1)) { 
                if(color[i][j + 1] != color[i][j]) {
                    int pos = area[color[i][j + 1]] + area[color[i][j]];
                    if(pos > best) {
                        best = pos;
                        op = mt(i + 1, j + 1, 'E');
                    }
                }
            }
        }
	}
    fout << best << endl;
    fout << get<0>(op) << " " << get<1>(op) << " " << get<2>(op) << endl;
}
