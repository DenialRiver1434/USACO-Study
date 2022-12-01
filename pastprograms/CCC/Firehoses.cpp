#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int H, K, a;
vector<int> positions, locations;

bool test (int num) {
	int prev = -2e6, count = 0;
	for (auto l : locations) {
		if(abs(l - prev) > num) {
			count ++;
			prev = l + num;
		}
	}
	return (count <= K);
}

int first_true(int lo, int hi) { 
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (test(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main() {
	cin >> H;
	if(H == 1) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < H; i ++) {
		cin >> a;
		positions.pb(a);
	}
	cin >> K;
	sort(positions.begin(), positions.end());
	int md = 0, mp = 0, prev = 0, start = -1;
	for (auto p : positions) {
		if(start == -1) start = p;
		else if((p - prev) > md) {
			md = p - prev;
			mp = p;
			prev = p;
		}
	}
	int dist = 1e6 - positions[H - 1] + start;
	if(dist > md) mp = positions[0];
	for (auto p : positions) {
		if ((p - mp) >= 0) locations.pb(p - mp);
		else locations.pb(1e6 + p - mp);
	}
	sort(locations.begin(), locations.end());
	cout << first_true(0, 1e6);
}