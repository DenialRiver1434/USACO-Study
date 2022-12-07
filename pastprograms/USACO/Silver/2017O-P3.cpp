#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N;
int grid[20][20];
bool searched[20][20];
int lb, rb, bb, ub;
vector<int> counts;
char a;
vector<tuple<int, int, int, int>> found;

void dfs (int x, int y, int color) {
	if(x < lb || x > rb || y < bb || y > ub || searched[x][y]) return;
	if(grid[x][y] != color) return;
	searched[x][y] = true;
	dfs(x - 1, y, color);
	dfs(x + 1, y, color);
	dfs(x, y - 1, color);
	dfs(x, y + 1, color);
}

bool check () {
	for (int i = 0; i < 26; i ++) counts[i] = 0;

	for (int i = lb; i < rb + 1; i ++) {
		for (int j = bb; j < ub + 1; j ++) {
			searched[i][j] = false;
		}
	}
	for (int i = lb; i < rb + 1; i ++) {
		for (int j = bb; j < ub + 1; j ++) {
			if(!searched[i][j]) {
				dfs(i, j, grid[i][j]);
				counts[grid[i][j]] ++;
			}
		}
	}
	sort(counts.begin(), counts.end(), greater<int>());
	if(counts[0] > 1 && counts[1] == 1 && counts[2] == 0) return true;
	return false;
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("where.in");
	fout.open("where.out");

	fin >> N;
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			fin >> a;
			grid[i][j] = int(a) - int('A');
		}
	}
	for (int i = 0; i < 26; i ++) counts.pb(0);
	for (lb = 0; lb < N; lb ++) {
		for (rb = lb; rb < N; rb ++) {
			for (bb = 0; bb < N; bb ++) {
				for (ub = bb; ub < N; ub ++) {
					if(check()) {
						found.pb(mt(lb, rb, bb, ub));
					}
				}
			}
		}
	}

	int count = 0, M = found.size();
	for (int i = 0; i < M; i ++) {
		bool good = true;
		for (int j = 0; j < M; j ++) {
			if(i == j) continue;
			auto pending = found[i], checker = found[j];
			if((get<0>(checker) <= get<0>(pending)) && (get<2>(checker) <= get<2>(pending)) && (get<1>(checker) >= get<1>(pending)) && (get<3>(checker) >= get<3>(pending))) good = false;
		}
		if(good) {
			count ++;
		}
	}
	fout << count;
}