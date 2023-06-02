#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll N, T, a, x, b, y, k, z;
multiset<ll> tnums;

bool test (ll num) {
	multiset<ll> nums;
	for (auto t : tnums) nums.is(t);
	ll count = 0;
	for (ll i = z - 1; i < num; i += z) {
		ll top = *(nums.rbegin());
		count += (a + b) * top;
		nums.erase(nums.find(top));
	}
	for (ll i = x - 1; i < num; i += x) {
		if(((i + 1) % z) == 0) continue;
		ll top = *(nums.rbegin());
		count += (a) * top;
		nums.erase(nums.find(top));
	}
	for (ll i = y - 1; i < num; i += y) {
		if(((i + 1) % z) == 0) continue;
		ll top = *(nums.rbegin());
		count += (b) * top;
		nums.erase(nums.find(top));
	}
	return (count >= k);
}

ll first_true(ll lo, ll hi) {
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

int main() {
	cin >> T;
	while (T --) {
		tnums.clear();
		cin >> N;
		for (int i = 0; i < N; i ++) {
			cin >> a;
			tnums.is(a / 100);
		}
		cin >> a >> x;
		cin >> b >> y;
		cin >> k;
		z = (x * y) / (gcd(x, y));
		if(b > a) {
			swap(a, b); // a is best, b is secondary
			swap(x, y);
		}
		if(!test(N)) {
			cout << -1 << endl;
		}
		else {
			cout << first_true(1, N) << endl;
		}
	}
}