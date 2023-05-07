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

ll simply (ll num, ll den) {
    return (num * powermod(den, 998244351, 998244353)) % 998244353;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    map<ll, ll> worth, count;
    
    ll N; cin >> N;
    for_loop(i, 0, N) {
        ll M; cin >> M;
        for_loop(j, 0, M) {
            ll a; cin >> a;
            worth[a] = (worth[a] + simply(1, N * M)) % 998244353;
            count[a] ++;
        }
    }
    ll total = 0;
    for (auto c : count) {
        total = (total + (worth[c.first] * (simply(count[c.first], N)))) % 998244353;
    }
    cout << total;
}