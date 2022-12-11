#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, a, ans[200000];
vector<int> subordinates[200000];

int dfs (int pos) {
    int c = 0;
    for (auto a : subordinates[pos]) c += (dfs(a) + 1);
    ans[pos] = c;
    return c;
}

int main() {
    cin >> N;
    for (int i = 1; i < N; i ++) {
        cin >> a;
        subordinates[a - 1].pb(i);
    }
    dfs(0);
    for (int i = 0; i < N; i ++) cout << ans[i] << " ";
}