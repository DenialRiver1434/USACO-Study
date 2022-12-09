#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
char cha;
bool cows[100000];
vector<int> conn[100000];
int assignment[100000];

void ev (int a, int prev, int color) {
    assignment[a] = color;
    for (auto c : conn[a]) {
        if (c != prev && cows[c] == cows[a]) ev(c, a, color);
    }
}

int main() { // H = true, G = false
    ifstream fin; ofstream fout;
    fin.open("milkvisits.in"); fout.open("milkvisits.out");
    fin >> N >> M;
    for (int i = 0; i < N; i ++) {
        fin >> cha;
        cows[i] = (cha == 'H');
    }
    for (int i = 1; i < N; i ++) {
        fin >> a >> b;
        conn[--a].pb(--b);
        conn[b].pb(a);
    }

    int group = 1;
    for (int i = 0; i < N; i ++) {
        if(!assignment[i]) {
            ev(i, -1, group);
            group ++;
        }
    }

    for (int i = 0; i < M; i ++) {
        fin >> a >> b >> cha;
        a--; b--;
        bool typ = (cha == 'H');
        if((assignment[a] != assignment[b]) || cows[a] == typ) fout << 1;
        else fout << 0;
    }
}