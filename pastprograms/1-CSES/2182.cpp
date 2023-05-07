#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

ll MOD = 1000000007;

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

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    vector<pair<ll, ll>> expo;
    ll total = 1, num = 1, sumd = 1, alt = 1;
    ll N; cin >> N;

    for_loop (i, 0, N) {
        ll a, b; cin >> a >> b;
        expo.pb(mp(a, b));
        total = (total * powermod(a, b)) % MOD;
        num = (num * (b + 1)) % MOD;
        alt = (alt * (b + 1)) % (MOD - 1);

        // *= (a^(b+1) - 1) / (a-1)
        ll num = (powermod(a, b + 1) - 1) % MOD;
        ll denon = powermod(a - 1, MOD - 2);
        ll tot = (num * denon) % MOD;
        sumd = (sumd * tot) % MOD;
    }

    vector<ll> ltr, rtl; ll l = 1, r = 1;
    for_loop (i, 0, N) {
        ltr.pb(l);
        rtl.pb(r);
        l = (l * (1 + expo[i].second)) % (MOD - 1);
        r = (r * (1 + expo[N - i - 1].second)) % (MOD - 1);
    }


    ll c = 1;
    for_loop (i, 0, N) {
        ll a = expo[i].first, b = expo[i].second;
        ll inner = ((b * (b + 1)) / 2) % (MOD - 1);
        ll second = (ltr[i] * rtl[N - i - 1]) % (MOD - 1);
        ll comb = (inner * second) % (MOD - 1);
        c = (c * powermod(a, comb)) % (MOD);
    }

    cout << num << " " << sumd << " " << c;
}