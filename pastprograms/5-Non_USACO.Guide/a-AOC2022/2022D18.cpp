#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;
 
int N, a, b, c;
set<tuple<int, int, int>> blocks;
bool searched[25][25][25], found;

void ffill (int x, int y, int z) {
    if(x < 0 || y < 0 || z < 0 || x >= 25 || y >= 25 || z >= 25) {
        found = true;
        return;
    }
    if(blocks.find(mt(x, y, z)) != blocks.end() || searched[x][y][z]) return;
    searched[x][y][z] = true;
    ffill(x-1, y, z);
    ffill(x+1, y, z);
    ffill(x, y-1, z);
    ffill(x, y+1, z);
    ffill(x, y, z-1);
    ffill(x, y, z+1);
}
void fffill(int x, int y, int z) {
    if(x < 0 || y < 0 || z < 0 || x >= 25 || y >= 25 || z >= 25) {
        found = true;
        return;
    }
    if(blocks.find(mt(x, y, z)) != blocks.end()) return;
    blocks.is(mt(x, y, z));
    fffill(x-1, y, z);
    fffill(x+1, y, z);
    fffill(x, y-1, z);
    fffill(x, y+1, z);
    fffill(x, y, z-1);
    fffill(x, y, z+1);
}

int main () {
    ifstream fin; ofstream fout;
    fin.open("multimoo.in"); fout.open("multimoo.out");

    fin >> N;
    for (int i = 0; i < N; i ++) {
        fin >> a >> b >> c;
        a ++; b ++; c ++;
        blocks.is(mt(a, b, c));
    }

    for (int i = 0; i < 25; i ++) {
        for (int j = 0; j < 25; j ++) {
            for (int k = 0; k < 25; k ++) {
                if(!searched[i][j][k] && blocks.find(mt(i, j, k)) == blocks.end()) {
                    found = false;
                    ffill(i, j, k);
                    if(!found) {
                        fffill(i, j, k);
                    }
                }
            }
        }
    }

    int co = 0;
    for (auto bi : blocks) {
        a = get<0>(bi);
        b = get<1>(bi);
        c = get<2>(bi);
        co += (blocks.find(mt(a - 1, b, c)) == blocks.end());
        co += (blocks.find(mt(a + 1, b, c)) == blocks.end());
        co += (blocks.find(mt(a, b - 1, c)) == blocks.end());
        co += (blocks.find(mt(a, b + 1, c)) == blocks.end());
        co += (blocks.find(mt(a, b, c - 1)) == blocks.end());
        co += (blocks.find(mt(a, b, c + 1)) == blocks.end());
    }
    cout << co;
}