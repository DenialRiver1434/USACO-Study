#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

ll powermod(ll base, ll exp, ll MOD) {
	base %= MOD;
	ll result = 1;
	while (exp > 0) {
		if (exp % 2 == 1) // if n is odd
			result = result * base % MOD;
		base = base * base % MOD;
		exp /= 2; // divide by two
	}
	return result;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    queue<pair<ll, ll>> past;

    ll ca = 1, cb = 0;
    ll Q; cin >> Q;
    for_loop (i, 0, Q) {
        int typ; cin >> typ;
        if(typ == 0) {
            ll a, b; cin >> a >> b;
            ca = (ca * a) % 998244353;
            cb = (cb * a + b) % 998244353;
            past.push(mp(a, b));
        }
        else if(typ == 1) {
            pair<ll, ll> p = past.front();
            past.pop();
            ll pra = p.first, prb = p.second;
            ca = (ca * powermod(pra, 998244351, 998244353)) % 998244353;
            cb = (cb - ca * prb) % 998244353;
        }
        else {
            ll b; cin >> b;
            cout << (ca * b + cb) % 998244353 << endl;
        }
    }
}