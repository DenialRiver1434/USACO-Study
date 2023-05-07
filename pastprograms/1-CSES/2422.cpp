#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll N;

bool test (ll num) {
    ll count = 0;
    for (ll i = 1; i <= N; i ++) {
        count += min(N, num / i);
    }
    return ((count * 2) > N * N);
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
    cin >> N;
    cout << first_true(1, N * N) << endl;
}