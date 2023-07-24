#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define vl vector<ll>
#define sl set<ll>
#define msl multiset<ll>
#define pl pair<ll, ll>
#define vpl vector<pair<ll, ll>>
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.size()
#include "bits/stdc++.h"
using namespace std;

ll MOD = 1e9 + 7, fact[2000005];
ll K, lS; string S;

ll powermod (ll base, ll exp) {
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

ll cpos (ll n) {
    ll tot = fact[n];
    tot = (tot * powermod(fact[n - lS + 1], MOD - 2)) % MOD;
    tot = (tot * powermod(fact[lS - 1], MOD - 2)) % MOD;
    return tot;
}

int main () {
    cin >> K >> S; lS = len(S);
    fact[0] = 1;
    f0r (i, 1, 2000005) {
        fact[i] = (i * fact[i - 1]) % MOD;
    }
    
    ll tot = 0;
    f0r (i, 0, K + 1) {
        ll ad = (powermod(26, i) * cpos(K + lS - i - 1)) % MOD;
        ad *= powermod(25, K - i);
        ad %= MOD;
        tot += ad;
        tot %= MOD;
    }
    cout << tot << endl;
}