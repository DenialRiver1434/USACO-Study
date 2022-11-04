#include <bits/stdc++.h>
using namespace std;

bool reachable[501][501];
int order[501][501];
vector<int> paths[501];
int N, a;

void dfs(int origin, int loc) {
	if(reachable[origin][loc]) return;
	reachable[origin][loc] = true;
	vector<int> conn = paths[loc];
	for (auto c : conn) dfs(origin, c);
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i ++) {
		bool found = false;
		for (int j = 0; j < N; j ++) {
			cin >> a;
			order[i][j] = a;
			if(!found) paths[a].push_back(i);
			if(i == a) found = true;
		}
	}
	for (int i = 1; i <= N; i ++) {
		dfs(i, i);
	}
	for (int i = 1; i <= N; i ++) {
		for (int j = 0; j <= N; j ++){
			int pref = order[i][j];
			if(reachable[i][pref]) {
				cout << pref << endl;
				break;
			}
		}
	}
}