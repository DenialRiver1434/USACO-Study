#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
vector<int> conn[100000], rconn[100000];
bool searched[100000], rsearched[100000];

void dfs(int pos) {
	if(searched[pos]) return;
	searched[pos] = true;
	for (auto c : conn[pos]) dfs(c);
}
void rdfs(int pos) {
	if(rsearched[pos]) return;
	rsearched[pos] = true;
	for (auto c : rconn[pos]) rdfs(c);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i ++) {
		cin >> a >> b;
		a --; b --;
		conn[a].pb(b);
		rconn[b].pb(a);
	}
	dfs(0);
	for (int i = 0; i < N; i ++) {
		if(!searched[i]) {
			cout << "NO" << endl;
			cout << 1 << " " << i + 1;
			return 0;
		}
	}
	rdfs(0);
	for (int i = 0; i < N; i ++) {
		if(!rsearched[i]) {
			cout << "NO" << endl;
			cout << i + 1 << " " << 1;
			return 0;
		}
	}
	cout << "YES";
}