#define pb push_back
#define mt make_tuple
#include <bits/stdc++.h>

using namespace std;

map<tuple<char, int, int>, vector<tuple<char, int, int>>> kills;
map<tuple<char, int, int>, int> killcount;
vector<tuple<char, int, int>> order;
int N, a, b;
set<tuple<int, int>> east, north;
char dir;

bool ycomp(tuple<int, int> p, tuple<int, int> q) { return get<1>(p) < get<1>(q); }

int killdfs(tuple<char, int, int> n) {
	if(killcount.find(n) != killcount.end()) return killcount[n];
	else {
		int c = kills[n].size();
		for (auto k : kills[n]) c += killdfs(k);
		return c;
	}
}

int intersect(int xn, int yn, int xe, int ye) { // East crashes North = 2, No crash = 1, North crashes East = 0
	if(xn < xe || yn > ye) return 1;
	int ndist = xe - xn, edist = yn - ye;
	if(ndist > edist) return 0;
	else if(edist > ndist) return 2;
	return 1;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i ++) {
		cin >> dir >> a >> b;
		order.pb(mt(dir, a, b));
		kills[mt(dir, a, b)] = {};
		if (dir == 'E') east.insert(mt(b, a)); // For sorting purposes
		else north.insert(mt(a, b));
	}

	for (auto ntup : north) {
		int xn = get<0>(ntup), yn = get<1>(ntup);
		for (auto itr = east.begin(); itr != east.end();) {
			auto etup = *itr;
			int xe = get<1>(etup), ye = get<0>(etup);
			int res = intersect(xn, yn, xe, ye);
			if(res == 2) {
				kills[mt('N', xn, yn)].pb(mt('E', xe, ye));
				east.erase(itr++);
			}
			else if(res == 0) {
				kills[mt('E', xe, ye)].pb(mt('N', xn, yn));
				break;
			}
			else ++itr;
		}
	}
	for (auto o : order) {
		cout << killdfs(o) << endl;
	}
}