#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define lll long long
#define vi vector<lll>
#define vpi vector<pair<lll, lll>>
#define f0r(i, begin, end) for (lll i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

lll N, grid[2000][2000], dist[2000];
vector<pair<lll, lll>> conn[2000];
vector<tuple<lll, lll, lll>> topdists;
bool searched[2000];

struct DSU {
	vector<int> e;

	DSU(int N) : e(N, -1) {}

	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool connected(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) { return false; }
		if (e[x] > e[y]) { swap(x, y); }
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

void dfs (lll pos) {
	for (auto p : conn[pos]) {
		lll dis = p.first, pot = p.second;
		if(!searched[pot]) {
			dist[pot] = dist[pos] + dis;
			searched[pot] = 1;
			dfs(pot);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);

	cin >> N;
	f0r (i, 0, N) {
		f0r (j, 0, N) {
			cin >> grid[i][j];
			if((i == j) && (grid[i][j] > 0)) {
				cout << "NO" << endl;
				return 0;
			} 
			if((i != j) && (grid[i][j] == 0)) {
				cout << "NO" << endl;
				return 0;
			}
			if((i > j) && (grid[i][j] != grid[j][i])) {
				cout << "NO" << endl;
				return 0;
			}
			if(i < j) {
				topdists.pb(mt(grid[i][j], i, j));
			}
		}
	}
	if(N == 1) {
		cout << "YES" << endl;
		return 0;
	}
	
	sort(topdists.begin(), topdists.end());
	lll added = 0;
	DSU D = DSU(N);
	for (auto ti : topdists) {
		lll dist, st, en;
		tie(dist, st, en) = ti;
		if(!D.connected(st, en)) {
			conn[st].pb(mp(dist, en));
			conn[en].pb(mp(dist, st));
			D.unite(st, en);
			added ++;
			if(added == (N - 1)) break;
		}
	}

	f0r (i, 0, N) {
		f0r (j, 0, N) {
			searched[j] = 0;
		}
		dist[i] = 0;
		searched[i] = 1;
		dfs(i);
		f0r (j, 0, N) {
			if(dist[j] != grid[i][j]) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
}
