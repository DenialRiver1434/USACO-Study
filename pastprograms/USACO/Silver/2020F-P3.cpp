#define pb push_back
#define mp make_pair
#define mt make_tuples
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, a, b, acount = 0, bcount = 0, atotal = 0, btotal = 0, missing[200000];
vector<int> conn[200000];

void dfs (int pos, int prev, bool isa) {
    if (isa) {
        acount ++;
        atotal += missing[pos];
    }
    else {
        bcount ++;
        btotal += missing[pos];
    }
    for (auto a : conn[pos]) {
        if (a != prev) dfs(a, pos, !isa);
    }
}

int main() {
    ifstream fin; fin.open("clocktree.in");
    ofstream fout; fout.open("clocktree.out");
    fin >> N;
    for (int i = 0; i < N; i ++) {
        fin >> a;
        missing[i] = 12 - a;
    }
    for (int i = 1; i < N; i ++) {
        fin >> a >> b;
        conn[a - 1].pb(b - 1);
        conn[b - 1].pb(a - 1);
    }
    dfs(0, -1, 1);
    atotal = atotal % 12; btotal = btotal % 12;
    if (atotal == btotal) fout << acount + bcount;
    else if (atotal == (btotal + 1)) fout << bcount;
    else if ((atotal + 1) == btotal) fout << acount;
    else fout << 0;
}