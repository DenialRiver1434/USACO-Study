#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll a;
bool test(ll connected) {
	ll bridges = a - connected;
	return bridges >= ((connected * (connected - 1)) / 2);
} 

ll last_true(ll lo, ll hi) {
	lo--;
	while (lo < hi) {
		ll mid = lo + (hi - lo + 1) / 2;
		if (test(mid)) lo = mid;
		else hi = mid - 1;
	}
	return lo;
}

void solve (ll a) {
	ll count = a - 1;
	if(3 <= a && test(3))	{
		ll pos = last_true(3, a);
		count = max(count, (a - pos) + ((pos * (pos - 1)) / 2));
		pos ++;
		count = max(count, (a - pos) * 2);
	}
	cout << count << endl;
}

int main () {
	ll Q;
	cin >> Q;
	while (Q --) {
		cin >> a;
		solve(a);
	}
}