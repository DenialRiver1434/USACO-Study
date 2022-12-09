#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, a, b, best = -1, bestname = -1;
vector<int> conn[200000];

void dfs (int pos, int prev, int depth) {
    if(depth > best) {
        bestname = pos;
        best = depth;
    }
    for (auto c : conn[pos]) {
        if(c != prev) dfs(c, pos, depth + 1);
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i ++) {
        cin >> a >> b;
        conn[a - 1].pb(b - 1);
        conn[b - 1].pb(a - 1);
    }
    dfs(0, -1, 0);
    int temp = bestname;
    bestname = -1;
    best = 0;
    dfs(temp, -1, 0);
    cout << best << endl;
}
