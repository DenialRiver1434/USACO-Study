#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (ll i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

ll MOD = 1e9 + 7;

ll fact[200001];

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
    if(n < k) return 0;
    if(k == 0 || (n == k)) return 1;
    ll c = nPk(n, k);
    c = (c * powermod(fact[k], MOD - 2)) % MOD;
    return c;
}

void solve () {
    ll N, M, K; cin >> N >> M >> K;
    vector<ll> nums;
    for_loop (i, 0, N) {
        ll a; cin >> a;
        nums.pb(a);
    }
    sort(nums.begin(), nums.end());
    ll left = 0, right = 0, pl = 0, pr = 0, prev = -1, tc = 0;
    while (right < N) {
        while (left < N) {
            if(nums[left] != prev) {
                prev = nums[left];
                break;
            }
            left ++;
        }
        while (right < N) {
            if((nums[right] - nums[left]) <= K) {
                right ++;
            }
            else break;
        }
        tc = (tc + nCk((right - left), M) - nCk((pr - left), M)) % MOD;
        pl = left, pr = right;
    }
    cout << ((tc + MOD) % MOD) << endl;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    ll c = 1; fact[0] = 1;
    for (int i = 1; i < 200002; i ++) {
        c = (c * i) % MOD;
        fact[i] = c;
    }

    ll T; cin >> T;
    while (T --) {
        solve();
    }
}