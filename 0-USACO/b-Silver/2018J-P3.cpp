#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, c, cou = 0;
set<pair<int, int>> blocked[5000];

void dfs (int pos, int prev) {
    cou ++;
    for (auto pair : blocked[pos]) {
        if(pair.second == prev || pair.first < a) continue;
        dfs(pair.second, pos);
    }
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("mootube.in");
    fout.open("mootube.out");
    fin >> N >> M;
    for (int i = 0; i < (N - 1); i ++) {
        fin >> a >> b >> c;
        a --; b --;
        blocked[a].is(mp(c, b));
        blocked[b].is(mp(c, a));
    }
    for (int i = 0; i < M; i ++) {
        fin >> a >> b;
        b --;
        cou = 0;
        dfs(b, -1);
        fout << cou - 1 << endl;
    }
}
