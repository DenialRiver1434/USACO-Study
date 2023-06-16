#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, c, d;
bool connections[20][20];
set<int> used;
bool found;

void dfs(int pos, int target, set<int> record) {
	if(record.find(pos) != record.end() || found) {
		if(pos == target) found = true;
	}
	else {
		record.is(pos);
		for (int i = 0; i < N; i ++) {
			if(connections[pos][i]) dfs(i, target, record);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i ++) {
		cin >> a >> b >> c >> d;
		if(c > d) connections[a - 1][b - 1] = true;
		else connections[b - 1][a - 1] = true;
	}
	int c = 0;
	for (int i = 0; i < N; i ++) {
		found = false;
		dfs(i, i, {});
		if(found) c ++;
	}
	cout << c;
}