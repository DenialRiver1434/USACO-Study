#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
	long long n; cin >> n;
	vector<long long> arr(2 * n);
	for (int i = 0; i < 2 * n; i++)cin >> arr[i];
	sort(arr.begin(), arr.end(), greater<long long>());

	//cout << endl;
	//for (int i = 0; i < 2 * n; i++)cout << arr[i] << " ";
	//cout << endl;
	set<long long> nums;
	long long sum = 0;
	for (long long i = 0; i < 2 * n; i += 2) {
		long long x = (arr[i] - sum) / (2 * n - i);
		if (arr[i] != arr[i + 1] || (arr[i] - sum) % (2 * n - i) != 0 || nums.count(x) || x < 1) {
			cout << "NO" << endl;
			return;
		}
		nums.insert(x);
		sum += 2 * x;
		//cout << x << " ";
		//cout << sum << endl;
	}
	cout << "YES" << endl;
}

int main() {
	int q; cin >> q;
	while (q--) {
		solve();
	}
}