#include <bits/stdc++.h>
using namespace std;

int upTo[1001][1001];
int N, M, a, b, c, d;
string line;

void dfs(int origin, int loc) {
	
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i ++ ) {
		cin >> line;
		for (int j = 1; j <= N; j ++) {
			upTo[i][j] = upTo[i - 1][j] + upTo[i][j - 1] - upTo[i - 1][j - 1];
			if(line[j - 1] == '*') upTo[i][j] ++;
		}
	}
	for (int i = 0; i < M; i ++) {
		cin >> a >> b >> c >> d;
		cout << upTo[c][d] - upTo[a - 1][d] - upTo[c][b - 1] + upTo[a - 1][b - 1] << endl;
	}
}