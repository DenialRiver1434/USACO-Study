#define pb push_back
#define mp make_pair
#define mt make_tuples
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;
int N, pointto[100000], a, c = 0;
bool visited[100000], incycle[100000], grouped[100000];
vector<int> conn[100000], starts;

void dfs (int pos) {
    if(grouped[pos]) return;
    grouped[pos] = true;
    for (auto a : conn[pos]) dfs(a);
}

int main() {
    ifstream fin; ofstream fout;
    fin.open("shuffle.in"); fout.open("shuffle.out");
    fin >> N;
    for (int i = 0; i < N; i ++) {
        fin >> a;
        pointto[i] = --a;
        conn[i].pb(a);
        conn[a].pb(i);
    }
    for (int i = 0; i < N; i ++) {
        if(!grouped[i]) {
            dfs(i);
            starts.pb(i);
        }
    }

    for (auto s : starts) {
        int pos = s;
        while (!visited[pos]) {
            visited[pos] = true;
            pos = pointto[pos];
        }
        while (!incycle[pos]) {
            incycle[pos] = true;
            pos = pointto[pos];
            c ++;
        }
    }
    fout << c;
}