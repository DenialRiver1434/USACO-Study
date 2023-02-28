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

ll fact[1000001];

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

ll nCk(ll n, ll k) {
    if(k == 0 || (n == k)) return 1;
    ll c = fact[n];
    c = (c * powermod((fact[k] * fact[n - k]) % MOD, MOD - 2));
    return c % MOD;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);

	fact[0] = 1;
	f0r (i, 1, 1000001) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
	}

	ll prev, total = 1;
	cin >> N >> prev;
	f0r (i, 1, N) {
		ll cur; cin >> cur;
		if (prev < cur) {
			total *= nCk((cur - 1) / 2, (prev - 1) / 2);
			total %= MOD;
		}
		if (prev > cur) {
			total *= nCk((prev) / 2, (cur) / 2);
			total %= MOD;
		}
		prev = cur;
	}
	cout << total << endl;
}