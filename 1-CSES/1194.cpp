#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

int monsdist[1000][1000], adist[1000][1000], N, M;
bool wall[1000][1000];

void trace (int x, int y) {
	vector<char> op;
	while(adist[x][y] != 0) {
		if(x > 0) {
			if(adist[x - 1][y] < adist[x][y]) {
				op.pb('D');
				x --;
				continue;
			}
		}
		if(x < (N - 1)) {
			if(adist[x + 1][y] < adist[x][y]) {
				op.pb('U');
				x ++;
				continue;
			}
		}
		if(y > 0) {
			if(adist[x][y - 1] < adist[x][y]) {
				op.pb('R');
				y --;
				continue;
			}
		}
		if(y < (M - 1)) {
			if(adist[x][y + 1] < adist[x][y]) {
				op.pb('L');
				y ++;
				continue;
			}
		}
	}
	reverse(op.begin(), op.end());
	for (auto o : op) cout << o;
	cout << '\n';
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	// ifstream fin; ofstream fout;
	// fin.open("piggyback.in"); fout.open("piggyback.out");

	queue<pair<int, int>> ms, as;
	cin >> N >> M;
	f0r (i, 0, N) {
		f0r (j, 0, M) {
			char a; cin >> a;
			monsdist[i][j] = 10000000;
			adist[i][j] = 10000000;
			if(a == '#') wall[i][j] = 1;
			else {
				wall[i][j] = 0;
				if(a == 'A') {
					adist[i][j] = 0;
					as.push(mp(i, j));
				}
				if(a == 'M') {
					monsdist[i][j] = 0;
					ms.push(mp(i, j));
				}
			}
		}
	}

	while (!ms.empty()) {
		int x = ms.front().first, y = ms.front().second;
		ms.pop();

		if(x > 0) {
			if(!wall[x - 1][y] && monsdist[x - 1][y] == 10000000) {
				monsdist[x - 1][y] = monsdist[x][y] + 1;
				ms.push(mp(x - 1, y));
			}
		}
		if(y > 0) {
			if(!wall[x][y - 1] && monsdist[x][y - 1] == 10000000) {
				monsdist[x][y - 1] = monsdist[x][y] + 1;
				ms.push(mp(x, y - 1));
			}
		}
		if(x < (N - 1)) {
			if(!wall[x + 1][y] && monsdist[x + 1][y] == 10000000) {
				monsdist[x + 1][y] = monsdist[x][y] + 1;
				ms.push(mp(x + 1, y));
			}
		}
		if(y < (M - 1)) {
			if(!wall[x][y + 1] && monsdist[x][y + 1] == 10000000) {
				monsdist[x][y + 1] = monsdist[x][y] + 1;
				ms.push(mp(x, y + 1));
			}
		}
	}

	while (!as.empty()) {
		int x = as.front().first, y = as.front().second;
		as.pop();

		if(x > 0) {
			if(!wall[x - 1][y] && adist[x - 1][y] == 10000000) {
				adist[x - 1][y] = adist[x][y] + 1;
				as.push(mp(x - 1, y));
			}
		}
		if(y > 0) {
			if(!wall[x][y - 1] && adist[x][y - 1] == 10000000) {
				adist[x][y - 1] = adist[x][y] + 1;
				as.push(mp(x, y - 1));
			}
		}
		if(x < (N - 1)) {
			if(!wall[x + 1][y] && adist[x + 1][y] == 10000000) {
				adist[x + 1][y] = adist[x][y] + 1;
				as.push(mp(x + 1, y));
			}
		}
		if(y < (M - 1)) {
			if(!wall[x][y + 1] && adist[x][y + 1] == 10000000) {
				adist[x][y + 1] = adist[x][y] + 1;
				as.push(mp(x, y + 1));
			}
		}
	}

	f0r (i, 0, N) {
		if(adist[i][0] < monsdist[i][0]) {
			cout << "YES\n";
			cout << adist[i][0] << '\n';
			trace(i, 0);
			return 0;
		}
		if(adist[i][M - 1] < monsdist[i][M - 1]) {
			cout << "YES\n";
			cout << adist[i][M - 1] << '\n';
			trace(i, M - 1);
			return 0;
		}
	}

	f0r (i, 0, M) {
		if(adist[0][i] < monsdist[0][i]) {
			cout << "YES\n";
			cout << adist[0][i] << '\n';
			trace(0, i);
			return 0;
		}
		if(adist[N - 1][i] < monsdist[N - 1][i]) {
			cout << "YES\n";
			cout << adist[N - 1][i] << '\n';
			trace(N - 1, i);
			return 0;
		}
	}
	cout << "NO\n";
}