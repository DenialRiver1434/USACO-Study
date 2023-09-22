#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MAX = 1e18;

ll N, K;
vector<ll> odds, evens;

// The numbers possible using only prime divisors from A and B, respectively
vector<ll> onums, enums;

bool test (ll x) {
	ll tot = 0;

	// Two pointers
	ll opoint = lower_bound(onums.begin(), onums.end(), x) - onums.begin();
	if (opoint == onums.size()) opoint --;

	for (auto e : enums) {
		if (e > x) break;
		while (onums[opoint] > x / e) { // Written to prevent overflow
			opoint --;
		}
		tot += opoint + 1;
	}
	return tot >= K;
}

ll first_true (ll lo, ll hi) {
	hi++;
	while (lo < hi) {
		ll mid = lo + (hi - lo) / 2;
		if (test(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

// Run DFS to generate all possible products

void dfsa (ll x, ll pos) {
	onums.push_back(x);
	for (int i = pos; i < odds.size(); i ++) {
		if (MAX / x < odds[i]) break; // prevent overflow
		dfsa (x * odds[i], i);
	}
}

void dfsb (ll x, ll pos) {
	enums.push_back(x);
	for (int i = pos; i < evens.size(); i ++) {
		if (MAX / x < evens[i]) break; // prevent overflow
		dfsb (x * evens[i], i);
	}
}

int main () {
	cin >> N;
	for (int i = 0; i < N; i ++) {
		ll x; cin >> x;
		if (i % 2 == 0) odds.push_back(x);
		else evens.push_back(x);
	}
	cin >> K;

	// Pre-generate everything
	dfsa(1, 0);
	dfsb(1, 0);
	sort(onums.begin(), onums.end());
	sort(enums.begin(), enums.end());

	test (9);
	cout << first_true(1, MAX) << endl;
}