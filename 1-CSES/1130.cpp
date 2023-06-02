#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define lll long long
#define f0r(i, begin, n) for (lll i = begin; i < n; i ++)
#define len(x) x.size()
#define vl vector<lll>
#define sl set<lll>
#define msl multiset<lll>
#define pl pair<lll, lll>
#define vpl vector<pair<lll, lll>>
#include <bits/stdc++.h>
using namespace std;

sl conn[200000];
lll best[200000][2], N; // 0 = unav, 1 = av

void search(lll pos, lll prev) {
	lll mdiff = 0;
	best[pos][0] = 1, best[pos][1] = 0;
	for (auto c : conn[pos]) {
		if(c != prev) {
			search(c, pos);
			best[pos][0] += best[c][1];
			best[pos][1] += best[c][1];
			mdiff = max(mdiff, best[c][0] - best[c][1]);
		}
	}
	best[pos][1] += mdiff;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);

	cin >> N;
	if(N < 2) {
		cout << 0 << endl;
		return 0;
	}

	f0r (i, 0, N - 1) {
		lll a, b; cin >> a >> b;
		conn[a - 1].is(b - 1);
		conn[b - 1].is(a - 1);
	}
	lll start;
	f0r (i, 0, N) {
		lll sz = len(conn[i]);
		if(sz == 1) {
			start = i;
			break;
		}
	}
	search(start, -1);
	cout << best[start][1] << endl;
}
