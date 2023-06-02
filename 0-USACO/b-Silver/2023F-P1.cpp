#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define f0r(i, begin, n) for (ll i = begin; i < n; i ++)
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

ll N, tA, tB;
vector<tuple<ll, ll, ll>> friends;

bool test (ll num) {
	if(num >= (tA + tB - 2)) return true;
	ll mina = max(0LL, num - tB), minb = max(0LL, num - tA);
	for (auto f : friends) {
		ll A, B, wait;
		tie(A, B, wait) = f;
		ll missing = tA * A + tB * B - wait;
		if(missing <= 0) continue;

		if(A == B) {
			if(A * num < missing) return false;
			continue;
		}
		if (A < B) {
			ll numerator = B * num - missing;
			if(numerator < 0) return false;
			ll denominator = B - A;
			ll threshold = (numerator) / (denominator); // maximum A
			if(threshold < num - tB) return false;
			minb = max(minb, num - threshold);
		}
		else {
			ll numerator = A * num - missing;
			if(numerator < 0) return false;
			ll denominator = A - B;
			ll threshold = (numerator) / (denominator); // maximum B
			if(threshold < num - tA) return false;
			mina = max(mina, num - threshold);
		}
	}
	if(minb >= tB) return false;
	if(mina >= tA) return false;
	return (mina + minb) <= num;
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

void tc () {
	cin >> N >> tA >> tB;
	friends.clear();
	f0r (i, 0, N) {
		ll a, b, c;
		cin >> a >> b >> c;
		friends.pb(mt(a, b, c));
	}
	cout << first_true(0, tA + tB) << endl;
}

int main () {
	ll T; cin >> T;
	f0r (i, 0, T) {
		tc();
	}
}