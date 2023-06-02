#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define f0r(i, begin, n) for (ll i = begin; i < n; i ++)
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

int find_lis(vector<int> a) {
	vector<int> dp;
	for (int i : a) {
		int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
		if (pos == dp.size()) {
			// we can have a new, longer increasing subsequence!
			dp.push_back(i);
		} else {
			// oh ok, at least we can make the ending element smaller
			dp[pos] = i;
		}
	}
	return dp.size();
}

int main () {
	int N; // number of vertices
	cin >> N;
    map<int, int> pos;
    vector<int> lis;
    f0r (i, 0, N) {
		int a; cin >> a;
		pos[a] = i;
	}
    f0r (i, 0, N) {
		int a; cin >> a;
		lis.pb(pos[a]);
	}
	cout << find_lis(lis) << endl;
}