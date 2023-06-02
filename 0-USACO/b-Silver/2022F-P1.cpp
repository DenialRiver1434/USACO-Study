#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

bool possible[500][500], reachable[500][500];
int grid[500][500];
int N, a;

void dfs (int pos, int start) {
	if(reachable[start][pos]) return;
	reachable[start][pos] = true;
	for (int i = 0; i < N; i ++) {
		if(possible[pos][i]) dfs(i, start);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i ++) {
		bool pos = true;
		for (int j = 0; j < N; j ++) {
			cin >> a;
			grid[i][j] = a;
			if(pos) possible[i][a - 1] = true;
			if((a - 1) == i) pos = false;
		}
	}
	
	for (int i = 0; i < N; i ++) {
		dfs(i, i);
	}
	
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			int target = grid[i][j] - 1;
			if(reachable[target][i]) {
				cout << target + 1 << endl;
				break;
			}
		}
	}
}