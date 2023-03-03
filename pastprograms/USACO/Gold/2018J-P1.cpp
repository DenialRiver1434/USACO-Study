#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (int i = begin; i < end; i ++) 
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	ifstream fin; ofstream fout;
	fin.open("mootube.in"); fout.open("mootube.out");

	int N, M; fin >> N >> M;
	DSU D = DSU(N + 1);
	vector<tuple<int, int, int>> conn; // relevance, start, end
	f0r (i, 1, N) {
		int a, b, c; fin >> a >> b >> c;
		conn.pb(mt(-c, a, b));
	}
	sort(conn.begin(), conn.end());
	vector<pair<int, int>> questions, original; // min relevance, position 
	f0r (i, 0, M) {
		int a, b; fin >> a >> b;
		questions.pb(mp(-a, b));
		original.pb(mp(-a, b));
	}
	sort(questions.begin(), questions.end());
	
	map<pair<int, int>, int> ans;
	int cp = 0;
	for (auto q : questions) {
		while (cp < (N - 1)) {
			if(-get<0>(conn[cp]) >= -q.first) {
				D.unite(get<1>(conn[cp]), get<2>(conn[cp]));
				cp ++;
			}
			else {
				break;
			}
		}
		ans[q] = D.size(q.second);
	}
	for (auto o : original) {
		fout << ans[o] - 1 << endl;
	}
}
