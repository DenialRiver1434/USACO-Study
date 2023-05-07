#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

int N, M, arrival[200000], delay[200000];
set<tuple<int, int, int>> conn[200000];

void dfs (int pos, int time, bool spec) {
	if(!spec) {
		if(arrival[pos] < time) return;
		time += delay[pos];
	}

	auto nec = conn[pos];
	auto cut = nec.lower_bound(mt(time, 0, 0));
	while (cut != nec.end()) {
		if(arrival[get<1>(*cut)] > get<2>(*cut)) {
			arrival[get<1>(*cut)] = get<2>(*cut);
			dfs(get<1>(*cut), get<2>(*cut), 0);
		}
		cut ++;
		nec.erase(prev(cut));
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N >> M;
	f0r (i, 0, N) {
		arrival[i] = 1e9 + 5;
	}
	arrival[0] = 0;
	f0r (i, 0, M) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		conn[a - 1].is(mt(b, c - 1, d));
	}
	f0r (i, 0, N) cin >> delay[i];
	dfs(0, 0, 1);

	f0r (i, 0, N) {
		if(arrival[i] > 1e9) cout << -1 << endl;
		else cout << arrival[i] << endl;
	}
}