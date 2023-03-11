#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define f0r(i, begin, n) for (ll i = begin; i < n; i ++)
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int, int>> flights; // start place, start time, end place, end time

int main () {
	int N, M; cin >> N >> M;
	int best[N], delaybest[N], delay[N];
	f0r (i, 0, M) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		flights.pb(mt(a - 1, b, c - 1, d));
	}
	f0r (i, 0, N) {
		cin >> delay[i];
		best[i] = 1e9;
		delaybest[i] = 1e9 + 1;
	}
	best[0] = 0; delaybest[0] = 0;

	f0r (i, 0, M + 1) { // Bellman-Ford
		for (auto f : flights) {
			int sp, st, ep, et;
			tie(sp, st, ep, et) = f;
			if(delaybest[sp] <= st) {
				best[ep] = min(best[ep], et);
				delaybest[ep] = min(delaybest[ep], et + delay[ep]);
			}
		}
	}
	f0r (i, 0, N) {
		if(best[i] == 1000000000) {
			cout << -1 << endl;
			continue;
		}
		cout << best[i] << endl;
	}
}