#define pb push_back
#define mp make_pair
#define mt make_tuples
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;
int N, pointto[200000], ans[200000], a;
bool visited[200000], incycle[200000], grouped[200000];
vector<int> conn[200000], rev[200000], starts;

void dfs (int pos) {
    if(grouped[pos]) return;
    grouped[pos] = true;
    for (auto a : conn[pos]) dfs(a);
}

void revsearch (int pos, int dist) {
    if(ans[pos]) return;
    ans[pos] = dist;
    for (auto a : rev[pos]) revsearch(a, dist + 1);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i ++) {
        cin >> a;
        pointto[i] = --a;
        rev[a].pb(i);
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
        int co = 0;
        vector<int> cycle;
        while (!incycle[pos]) {
            incycle[pos] = true;
            cycle.pb(pos);
            pos = pointto[pos];
            co ++;
        }
        for (auto c : cycle) ans[c] = co;
        for (auto c : cycle) {
            for (auto a : rev[c]) {
                revsearch(a, co + 1);
            }
        }
    }
    for (int i = 0; i < N; i ++) cout << ans[i] << " ";
}