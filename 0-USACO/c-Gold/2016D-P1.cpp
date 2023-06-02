#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
bool connect[1001][1001];
bool visited[1001];
vector<tuple<int,int>> positions;
int dists[1001][1001];

void dfs (int pos) {
	if(visited[pos]) return;
	visited[pos] = true;
	for (int i = 0; i < N; i ++) {
		if(connect[i][pos]) dfs(i);
	}
}

int test (int num) {
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			int x1 = get<0>(positions[i]), y1 = get<1>(positions[i]);
			int x2 = get<0>(positions[j]), y2 = get<1>(positions[j]);
			if (((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) <= num) {
				connect[i][j] = true;
			}
			else connect[i][j] = false;
		}
	}
	for (int i = 0; i < N; i ++) visited[i] = false;
	dfs(0);
	bool found = true;
	for (int i = 0; i < N; i ++) {
		if (!visited[i]) found = false;
	}
	return found;
}

int first_true(int lo, int hi) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (test(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("moocast.in");
	fout.open("moocast.out");

	fin >> N;
	for (int i = 0; i < N; i ++) {
		fin >> a >> b;
		positions.pb(mt(a, b));
	}
	fout << first_true(1, 2e9);
}