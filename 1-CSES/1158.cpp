#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define for_loop(i, begin, n) for (int i = begin; i < n; i ++)
#include <bits/stdc++.h>
using namespace std;

int main () {
	int N, X; cin >> N >> X;
	int best[X + 1], prices[N];
	for_loop (i, 0, X + 1) best[i] = -1e9;
	best[0] = 0;

	for_loop (i, 0, N) cin >> prices[i];
	for_loop (i, 0, N) {
		int pages; cin >> pages;
		int price = prices[i];
		for (int j = X - price; j >= 0; j --) {
			best[j + price] = max(best[j + price], best[j] + pages);
		}
	}

	int optimal = 0;
	for_loop (i, 0, X + 1) optimal = max(optimal, best[i]);
	cout << optimal;
}