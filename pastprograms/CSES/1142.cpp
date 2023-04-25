#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define lll long long
#define f0r(i, begin, n) for (lll i = begin; i < n; i ++)
#define len(x) x.size()
#define vi vector<lll>
#define vpi vector<pair<lll, lll>>
#include <bits/stdc++.h>
using namespace std;

stack<pair<lll, lll>> s;
vector<lll> nums, lhs, rhs;

int main() {
    lll N; cin >> N;
	f0r (i, 0, N) {
		lll x; cin >> x;
		nums.pb(x);
	}

    s.push({0, 0});
    f0r (i, 1, N + 1) {
		lll a = nums[i - 1];
        while(s.top().second >= a) s.pop();
        lhs.pb(s.top().first);
        s.push({i, a});
    }

	while(!s.empty()) s.pop();
	s.push({N, 0});
    for (lll i = N - 1; i >= 0; i --) {
		lll a = nums[i];
        while(s.top().second >= a) s.pop();
        rhs.pb(s.top().first);
        s.push({i, a});
    }
	
	reverse(rhs.begin(), rhs.end());
	lll b = 0;
	f0r (i, 0, N) {
		b = max(b, nums[i] * (rhs[i] - lhs[i]));
	}
	cout << b << endl;
}