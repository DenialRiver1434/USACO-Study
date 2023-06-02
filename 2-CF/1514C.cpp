#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int main () {
    ll N;
    cin >> N;

    set<ll> works = {1};
    ll modulo = 1;
    for (ll i = 2; i < N; i ++) {
        if(gcd(i, N) == 1) {
            works.is(i);
            modulo = (modulo * i) % N;
        }
    }
    if(modulo != 1) { 
        for (int i = modulo; i > 1; i --) {
            if(works.find(i) != works.end() && (modulo % i) == 0) {
                works.erase(i);
                modulo /= i;
            }
        }
    }

    cout << works.size() << endl;
    for (auto w : works) {
        cout << w << " ";
    }
}