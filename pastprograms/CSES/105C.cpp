#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (int i = begin; i < end; i ++) 
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

int lowerbound(vector<int> arr, int x){
	reverse(arr.begin(), arr.end());
    int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
	return arr.size() - pos;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int N; cin >> N;
	if(N == 1) {
		cout << 1 << endl;
		return 0;
	}

	map<int, int> positions; vector<pair<int, int>> inps;
	f0r (i, 0, N) {
		int a, b;
		cin >> a >> b;
		inps.pb(mp(a, b));
	}
	sort(inps.begin(), inps.end());
	vector<int> nums;
	for (auto inp : inps) nums.pb(inp.second);

	vector<int> orders = {nums[0]};
	f0r (i, 1, N) {
		int n = nums[i];
		if(n < orders[orders.size() - 1]) orders.pb(n);
		else {
			int pos = lowerbound(orders, n);
			orders[pos] = n;
		}
	}
	cout << orders.size() << endl;
}
