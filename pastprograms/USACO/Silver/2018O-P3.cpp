#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, grid[250][250], original[250][250], actual[62501], sized[62501];
set<int> conn[62501];
bool searched[250][250], searched2[250][250];

void ffill (int x, int y, int color, int origin) {
    if(x < 0 || y < 0 || x >= N || y >= N) return;
    if(searched[x][y]) return;
    if(grid[x][y] != origin) return;
    grid[x][y] = color;
    searched[x][y] = true;
    sized[color] ++;
    ffill(x - 1, y, color, origin);
    ffill(x, y - 1, color, origin);
    ffill(x, y + 1, color, origin);
    ffill(x + 1, y, color, origin);
}

void fill2 (int x, int y, int color) {
    if(x < 0 || y < 0 || x >= N || y >= N) return;
    if(grid[x][y] != color) {
        conn[color].is(grid[x][y]);
        conn[grid[x][y]].is(color);
        return;
    }
    if(searched2[x][y]) return;
    searched2[x][y] = true;
    fill2(x - 1, y, color);
    fill2(x, y - 1, color);
    fill2(x, y + 1, color);
    fill2(x + 1, y, color);
}

int main() {
    ifstream fin; ofstream fout;
    fin.open("multimoo.in"); fout.open("multimoo.out");

    fin >> N;
    int color = 0, best = 0;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            int a;
            fin >> a;
            grid[i][j] = a; original[i][j] = a;
        }
    }
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if(!searched[i][j]) {
                actual[color] = original[i][j];
                ffill(i, j, color, original[i][j]);
                best = max(best, sized[color ++]);
            }
        }
    }
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if(!searched2[i][j]) {
                fill2(i, j, grid[i][j]);
            }
        }
    }
    for (int i = 0; i < 10; i ++) {
        for (auto c : conn[i]) cout << c << " ";
        cout << endl;
    }
}