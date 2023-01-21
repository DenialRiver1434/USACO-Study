#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

pair<int, int> pasttrack[80001];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    pasttrack[0] = {-1, -1};

    int Q; cin >> Q;
    for_loop (i, 1, Q + 1) {
        char typ; cin >> typ;
        if (typ == 'a') {
            int c; cin >> c;
            pasttrack[i] = mp(i - 1, c);
        }
        else if (typ == 's') {
            int pot = pasttrack[i - 1].first;
            pasttrack[i] = pasttrack[pot];
        }
        else {
            int c; cin >> c;
            pasttrack[i] = pasttrack[c - 1];
        }
        cout << pasttrack[i].second << '\n';
    }
}