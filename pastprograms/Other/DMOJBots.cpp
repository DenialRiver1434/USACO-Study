#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

ll MOD = 1e9+7;

ll powermod(ll base, ll exp) {
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

ll nPk(ll n, ll k) {
    ll c = 1;
    if(k == 0) return 1;
    for (int i = (n - k + 1); i <= n; i ++) {
        c = (c * i) % MOD;
    }
    return c;
}

int main () {
    int N; cin >> N;
    ll m = powermod(nPk(N, N), MOD - 2), c = nPk(N + 1, N), num = nPk(N + 1, N);
    for (int i = (N + 2); i <= (2 * N + 1); i ++) {
        num = (num * powermod(i - N, MOD - 2)) % MOD;
        num = (num * i) % MOD;
        c = (c + num) % MOD;
    }
    cout << (c * m) % MOD;
}