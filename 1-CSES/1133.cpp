#define pb push_back
#define mp make_pair
#define mt make_tuples
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll N, a, b, sumparent[200000], countparent[200000], sumchild[200000], countchild[200000];
vector<ll> conn[200000];

ll dfs (ll pos, ll prev) {
    ll children = 1;
    for (auto a : conn[pos]) {
        if (a != prev) children += (dfs(a, pos));
    }
    countchild[pos] = children;
    return children;
}

ll dfs1 (ll pos, ll prev) {
    ll children = 0;
    for (auto a : conn[pos]) {
        if (a != prev) children += (dfs1(a, pos) + countchild[a]);
    }
    sumchild[pos] = children;
    return children;
}

void dfs2 (ll pos, ll prev) { 
    ll count = sumchild[pos] + countchild[pos];
    if(prev != -1) {
        ll updated = (sumchild[prev] - count) + (countparent[pos]) + sumparent[prev];
        sumparent[pos] = updated;
    }
    for (auto a : conn[pos]) {
        if (a != prev) dfs2(a, pos);
    }
}

int main() {
    cin >> N;
    for (ll i = 1; i < N; i ++) {
        cin >> a >> b;
        conn[a - 1].pb(b - 1);
        conn[b - 1].pb(a - 1);
    }
    sumparent[0] = 0;
    dfs(0, -1);
    dfs1(0, -1);
    for (ll i = 0; i < N; i ++) {
        countparent[i] = N - countchild[i];
    }
    dfs2(0, -1);
    
    for (ll i = 0; i < N; i ++) {
        cout << sumparent[i] + sumchild[i] << " ";
    }
}