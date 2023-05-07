#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define f0r(i, begin, n) for (ll i = begin; i < n; i ++)
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

set<tuple<ll, ll, ll>> gardens;

int main () {
	ll N, G; cin >> N >> G;
	f0r (i, 0, N) {
		ll a, b, c; cin >> a >> b >> c;
		gardens.is(mt(c, a, b));
	}
	ll c = 0;
	f0r (i, 0, G) {
		ll x, y, time; cin >> x >> y >> time;
		if(gardens.find(mt(time, x, y)) != gardens.end()) continue;
		gardens.is(mt(time, x, y));
		auto pos = gardens.find(mt(time, x, y));

		bool f = 0;
		if(next(pos) != gardens.end()) {
			ll dt = get<0>(*next(pos)) - get<0>(*pos);
			ll dx = get<1>(*next(pos)) - get<1>(*pos);
			ll dy = get<2>(*next(pos)) - get<2>(*pos);
			if((dt * dt) < (dx * dx + dy * dy)) f = 1;
		}
		
		if(pos != gardens.begin()) {
			ll dt = get<0>(*prev(pos)) - get<0>(*pos);
			ll dx = get<1>(*prev(pos)) - get<1>(*pos);
			ll dy = get<2>(*prev(pos)) - get<2>(*pos);
			if((dt * dt) < (dx * dx + dy * dy)) f = 1;
		}
		gardens.erase(mt(time, x, y));
		c += f;
	}
	cout << c << endl;
}