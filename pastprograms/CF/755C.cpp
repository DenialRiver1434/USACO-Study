#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, a;
vector<int> conn[10000];
bool searched[10000];

void dfs (int pos) {
    if(searched[pos]) return;
    searched[pos] = true;
    for (auto a : conn[pos]) dfs(a);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i ++) {
        cin >> a;
        conn[i].pb(--a);
        conn[a].pb(i);
    }
    int c = 0;
    for (int i = 0; i < N; i ++) {
        if(!searched[i]) {
            c ++;
            dfs(i);
        }
    }
    cout << c;
}