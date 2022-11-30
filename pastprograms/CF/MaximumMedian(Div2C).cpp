#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll N, M, a;
vector<ll> nums;

bool test (ll num) {
    ll diff = 0;
    for (ll i = N / 2; i < N; i ++) {
        diff += max(0ll, num - nums[i]);
    }
    return (diff <= M);
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

int main() {
    cin >> N >> M;
    ll mini = 1000000000, maxi = 0;
    for (ll i = 0; i < N; i ++) {
        cin >> a;
        mini = min(mini, a);
        maxi = max(maxi, a);
        nums.pb(a);
    }
    sort(nums.begin(), nums.end());
    cout << last_true(mini, maxi + M);
}