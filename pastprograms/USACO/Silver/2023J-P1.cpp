#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

ll T;
map<ll, vector<ll>> paired;
set<ll> polled; 
ll dest[123]; vector<ll> source[123]; bool searched[123];
bool isloop, stub; set<ll> processing;

void search (ll pos) {
    if(source[pos].size() > 1) isloop = false;
    if(processing.find(pos) != processing.end()) {
        if(dest[pos] == pos) stub = true;
        return;
    }
    if(searched[pos]) {
        isloop = false; // ran llo another already-searched loop
        return;
    }
    searched[pos] = true;
    processing.is(pos);
    search(dest[pos]);
}

void solve () {
    string inp, oup;
    cin >> inp; cin >> oup;

    polled.clear();
    paired.clear();
    for (ll i = 0; i < 123; i ++) {
        dest[i] = 0;
        searched[i] = 0;
        source[i].clear();
    }

    if(inp == oup) {
        cout << 0 << '\n';
        return;
    }

    for (ll i = 0; i < inp.length(); i ++) {
        paired[inp[i]].pb(i);
    }
    
    for (auto p : paired) {
        vector<ll> pends = p.second;
        dest[p.first] = oup[pends[0]];
        source[oup[pends[0]]].pb(p.first);
        polled.is(dest[p.first]);
        for (auto pe : pends) {
            if(oup[pe] != dest[p.first]) {
                cout << -1 << '\n'; // Check if it's a function
                return;
            }
        }
    }

    if(polled.size() == 52 && inp.length() > 50) {
        cout << -1 << '\n'; // No space to move
        return;
    }

    ll c = 0;
    for (ll i = 65; i < 123; i ++) {
        if(i == 91) i = 97;
        if(!searched[i] && dest[i]) {
            isloop = true; stub = false;
            processing.clear();

            search(i);

            if(isloop && !stub) c ++;
            if(stub) c --;
            c += processing.size();
        }
    }
    cout << c << '\n';
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> T;
    while (T --) {
        solve();
    }
}