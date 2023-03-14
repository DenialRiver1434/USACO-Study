#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (int i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

int N, M;
const int INF = 1e9;

int assign[50000], best[50000];
set<int> revas[50], conn[50];
bool typmatch[50][50];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N >> M;

	f0r (i, 0, N) {
		cin >> assign[i];
		best[i] = INF;
		revas[--assign[i]].is(i);
	}
	f0r (i, 0, M) {
		f0r (j, 0, M) {
			char a; cin >> a;
			typmatch[i][j] = (a == '1');
		}
	}

	int temp = assign[0];
	revas[temp].erase(0);
	f0r (i, 0, M) {
		f0r (j, 0, M) {
			if(typmatch[i][j]) {
				for (auto r : revas[j]) {
					conn[i].is(r);
				}
			}
		}
	}
	revas[temp].is(0);

	priority_queue<pair<int, int>> q; // leftdist, pos
	q.push(mp(0, 0));
	best[0] = 0;

	while(!q.empty()) {
		int ovlp = -q.top().first; int pos = q.top().second;
		q.pop();
		int col = assign[pos];

		if(best[pos] != ovlp) continue;
		f0r (j, 0, M) {
			if(typmatch[j][col]) {
				conn[j].erase(pos);
			}
		}

		best[pos] = ovlp;

		for (auto c : conn[col]) {
			if(c == (N - 1)) {
				cout << ovlp * 2 + N - 1 << endl;
				return 0;
			}
			if(c < pos) {
				if(best[c] > (ovlp + pos - c)) {
					best[c] = ovlp + pos - c;
					q.push(mp(-best[c], c));
				}
			}
			else {
				if(best[c] > ovlp) {
					best[c] = ovlp;
					q.push(mp(-best[c], c));
				}
			}
		}
	}
	cout << -1 << endl;
}
