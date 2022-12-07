#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, M, a;
vector<int> nums;

bool test (int num) { // everything is odd, so require (num/2 + 1) non-negative
	vector<int> ge0;
	ge0.pb(0);
	for (int i = 0; i < N; i ++) {
		int base = ge0[i];
		if(nums[i] >= num) base ++;
		else base --;
		ge0.pb(base);
	}
	set<int> evens, odds;
	bool found = false;
	for (int i = M; i <= N; i ++ ) {
		if((i % 2) == 0) {
			odds.is(ge0[i - M]);
			int om = *odds.begin();
			if((ge0[i] - om) >= 1) found = true;
		}
		else {
			evens.is(ge0[i - M]);
			int em = *evens.begin();
			if((ge0[i] - em) >= 1) found = true;
		}
	}
	return found;
}

int last_true(int lo, int hi) {
	lo--;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;
		if (test(mid)) lo = mid;
		else hi = mid - 1;
	}
	return lo;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i ++) {
		cin >> a;
		nums.pb(a);
	}
	if(N == M) {
		sort(nums.begin(), nums.end());
		cout << nums[floor((N + 1) / 2) - 1];
	}
	else {
		if((M % 2) == 0) M ++;
		cout << last_true(1, 200000);
	}
}