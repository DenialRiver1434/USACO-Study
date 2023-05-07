#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int N, M; cin >> N >> M;
	if(N == 1) {
		cout << 1 << endl;
		return 0;
	}
	vector<int> best = {M};
	f0r (i, 0, N) {
		int a; cin >> a;
		if(a > best[best.size() - 1]) {
			best.pb(a);
		}
		else {
			int pos = lower_bound(best.begin(), best.end(), a) - best.begin();
			best[pos] = a;
		}
	}
	cout << best.size();
}
