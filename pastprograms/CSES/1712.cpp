#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

ll powermod (ll a, ll b, ll mod) { // 1000000007
    if (b == 0) return 1;
    else if ((b % 2) == 1) return (((powermod (a, b / 2, mod) * powermod (a, b / 2, mod)) % mod) * a) % mod;
    else return (powermod (a, b / 2, mod) * powermod (a, b / 2, mod)) % mod;
}

int main () {
    int T; cin >> T;  
    while (T --) {
        ll c, a, b;
        cin >> c >> a >> b;
        ll pow = powermod(a % (1000000006), b, 1000000006);
        cout << powermod(c % 1000000007, pow, 1000000007) << endl;
    }
}