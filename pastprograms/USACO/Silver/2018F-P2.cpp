#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
bool visited[250][250];
int snow[250];
pair<int, int> shoes[250];

void dfs (int pos, int boot) {
    if(pos >= (N - 1)) {
        visited[N - 1][boot] = true;
        return;
    }
    if(visited[pos][boot] || shoes[boot].first < snow[pos]) return;
    visited[pos][boot] = true;
    for (int i = boot + 1; i < M; i ++) {
        dfs(pos, i);
    }
    for (int i = pos + 1; i < (pos + shoes[boot].second + 1); i ++) {
        dfs(i, boot);
    }
}

int main() {
    ifstream fin; ofstream fout;
    fin.open("snowboots.in"); fout.open("snowboots.out");

    fin >> N >> M;
    for (int i = 0; i < N; i ++) fin >> snow[i];
    for (int i = 0; i < M; i ++) {
        fin >> a >> b;
        shoes[i] = mp(a, b);
    }
    dfs(0, 0);
    for (int i = 0; i <= M; i ++) {
        if(visited[N - 1][i]) {
            fout << i;
            return 0;
        }
    }
}