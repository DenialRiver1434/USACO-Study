#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;
 
ll MOD = 1e9 + 7;
 
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
 
ll factmod(ll n) {
    ll c = 1;
    for (int i = 1; i <= n; i ++) {
        c = (c * i) % MOD;
    }
    return c;
}
 
map<char, ll> counts;
 
int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    ll a, b; cin >> a >> b;
    int c = factmod(a + b - 1);
    c = (c * powermod(factmod(a - 1), MOD - 2)) % MOD;
    c = (c * powermod(factmod(b), MOD - 2)) % MOD;
    cout << c;
}