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
	ios_base::sync_with_stdio(0); cin.tie(nullptr);/*
	ifstream fin; ofstream fout;
	fin.open("nocross.in"); fout.open("nocross.out");*/

	int N, M; cin >> N >> M;
	int depth[N], source[N];
	vector<int> conn[N];

	f0r (i, 0, M) {
		int a, b; cin >> a >> b;
		conn[a - 1].pb(b - 1);
		conn[b - 1].pb(a - 1);
	}

	f0r (i, 1, N) depth[i] = 1e6;
	queue<int> visits;
	depth[0] = 0;
	visits.push(0);
	while (!visits.empty()) {
		int pos = visits.front();
		if(pos == (N - 1)) {
			cout << depth[pos] + 1 << endl;
			break;
		}
		visits.pop();
		for (auto c : conn[pos]) {
			if (depth[c] > (depth[pos] + 1)) {
				depth[c] = depth[pos] + 1;
				source[c] = pos;
				visits.push(c);
			}
		}
	}
	
	if(depth[N - 1] == 1e6) cout << "IMPOSSIBLE" << endl;
	else {
		int loc = N - 1;
		vector<int> route = {loc};
		while (loc != 0) {
			loc = source[loc];
			route.pb(loc);
		}
		for (int i = depth[N - 1]; i >= 0; i --) {
			cout << route[i] + 1 << " ";
		}
	}
}