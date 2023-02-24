#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

const ll MOD = 1e9 + 7;
ll N;

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

ll nCk(ll n, ll k) {
    if(k == 0 || (n == k)) return 1;
    ll c = nPk(n, k);
    c = (c * powermod(nPk(k, k), MOD - 2));
    return c % MOD;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N;
	if (N == 1) {
		cout << 1 << endl;
	}
	else {
		ll a, b; cin >> a >> b;
		if (a == b) {
			cout << 1 << endl;
		}
		else if (a < b) {
			a--; b--; // first move must go to right
			ll far = a / 2, close = (b - a) / 2;
			cout << nCk (far + close, far) << endl;
		}
		else {
			ll close = (a - b) / 2, far = b / 2; 
			cout << nCk (far + close, far) << endl;
		}
	}
}