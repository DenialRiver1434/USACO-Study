#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll powermod (ll a, ll b, ll mod) { // 1000000007
    if (b == 0) return 1;
    else if ((b % 2) == 1) {
        ll pma = powermod (a, b / 2, mod);
        return (((pma * pma) % mod) * a) % mod;
    }
    else {
        ll pma = powermod (a, b / 2, mod);
        return (pma * pma) % mod;
    }
}

ll N, a, b;
ll factmod[1000001];

int main () {
    // Pre-processing
    ll c = 1; factmod[0] = 1;
    for (int i = 1; i <= 1000000; i ++) {
        c = (c * i) % 1000000007;
        factmod[i] = c;
    }

    cin >> N;
    while (N --) {
        cin >> a >> b;
        ll num = factmod[a];
        ll den1 = powermod(factmod[b], 1000000005, 1000000007);
        ll den2 = powermod(factmod[a - b], 1000000005, 1000000007);
        cout << (((num * den1) % 1000000007) * den2) % 1000000007 << endl;
    }
}
