#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;
 
ll N, a, b, missparent[200001], misschild[200001], target = 0, bales[200001], original[200001];
multiset<ll> conn[200001];
map<ll, ll> neighbors[200001];
set<pair<ll, ll>> possible;
vector<tuple<ll, ll, ll>> outputs;

void dfs (ll pos, ll prev) {
    ll c = 0;
    for (auto co : conn[pos]) {
        if(co != prev) {
            dfs (co, pos);
            c += misschild[co] + target - bales[co];
            neighbors[pos][co] = (misschild[co] + target - bales[co]);
        }
    }
    misschild[pos] = c;
}

void dfs2 (ll pos, ll prev) {
    if(prev != -1) {
        ll us = misschild[pos] + target - bales[pos];
        missparent[pos] = (missparent[prev] + misschild[prev]) - us + target - bales[prev];
        neighbors[pos][prev] = (missparent[pos]);
    }
    for (auto co : conn[pos]) {
        if(co != prev) {
            dfs2 (co, pos);
        }
    }
}

void dfs3 (ll pos, ll prev, ll moved) {
    bales[pos] += moved;
    bales[prev] -= moved;
    outputs.pb(mt(prev, pos, moved));
    moved = bales[pos] - target;
    if(moved <= 0) return;
    possible.erase(mp(original[pos], pos));

    for (auto n : neighbors[pos]) {
        if(n.first == prev) continue;
        if(n.second > 0 && (possible.find(mp(original[n.first], n.first)) != possible.end())) {
            dfs3(n.first, pos, n.second);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> N;
    for (ll i = 1; i <= N; i ++) {
        cin >> a;
        bales[i] = a;
        original[i] = a;
        possible.is(mp(a, i));
        target += a;
    }
    target /= N;
    for (ll i = 1; i < N; i ++) {
        cin >> a >> b;
        conn[a].is(b);
        conn[b].is(a);
    }
    dfs (1, -1);
    dfs2 (1, -1);
    
    while(possible.size()) {
        pair<ll, ll> current = *possible.rbegin();
        possible.erase(current);
        int spare = current.first - target;
        for (auto n : neighbors[current.second]) {
            if(n.second > 0 && (possible.find(mp(original[n.first], n.first)) != possible.end())) {
                dfs3(n.first, current.second, n.second);
            }
        }
    }
    cout << outputs.size() << endl;
    for (auto tup : outputs) {
        cout << get<0>(tup) << " " << get<1>(tup) << " " << get<2>(tup) << endl;
    }