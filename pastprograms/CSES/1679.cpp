#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (int i = begin; i < end; i ++) 
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M;
bool searched[100000];
vector<int> conn[100000];
vector<int> sorted;
set<int> searching;
bool flag = false;

void dfs (int i) {
	if(flag) return;
	if(searched[i]) return;
	searched[i] = true;
	searching.is(i);
	for (auto c : conn[i]) {
		if(searching.find(c) != searching.end()) {
			cout << "IMPOSSIBLE" << endl;
			flag = true;
			return;
		}
		dfs(c);
	}
	searching.erase(i);
	sorted.pb(i);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N >> M;
	f0r (i, 0, M) {
		int a, b; cin >> a >> b;
		conn[a - 1].pb(b - 1);
	}
	f0r (i, 0, N) {
		dfs(i);
		if(flag) return 0;
	}
	reverse(sorted.begin(), sorted.end());
	for (auto s : sorted) {
		cout << s + 1 << " ";
	}
}
