#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, c;
int cows[100000], color[100000];
vector<int> conn[100000];
bool grouped[100000];
vector<vector<int>> groups;
vector<tuple<int, int, int>> portals;

void fill(int pos, int col) {
	if(color[pos]) return;
	color[pos] = col;
	for (auto p : conn[pos]) fill(p, col);
}

bool test(int num) {
	for (int i = 0; i < N; i ++) {
		color[i] = 0;
		conn[i].clear();
	}

	for (int i = num; i < M; i ++) {
		int left = get<1>(portals[i]), right = get<2>(portals[i]);
		conn[left].pb(right);
		conn[right].pb(left);
	}

	int col = 1;
	for (int i = 0; i < N; i ++) {
		if(!color[i]) {
			fill(i, col);
			col ++;
		}
	}

	int found = true;
	for (auto g : groups) {
		int standard = color[g[0]];
		for (auto ch : g) {
			if(color[ch] != standard) found = false;
		}
	}
	return found;
}

int last_true(int lo, int hi) {
	lo--;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;
		if (test(mid)) lo = mid;
		else hi = mid - 1;
	}
	return lo;
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("wormsort.in");
	fout.open("wormsort.out");
	
	fin >> N >> M;
	for (int i = 0; i < N; i ++) {
		fin >> a;
		cows[i] = a - 1;
	}
	for (int i = 0; i < N; i ++) {
		if(!grouped[i]) {
			vector<int> forming;
			int pos = cows[i];
			grouped[i] = true;
			forming.pb(i);
			while(pos != i) {
				grouped[pos] = true;
				forming.pb(pos);
				pos = cows[pos];
			}
			groups.pb(forming);
		}
	}
	if(groups.size() == N) {
		fout << -1;
		return 0;
	}
	for (int i = 0; i < M; i ++) {
		fin >> a >> b >> c;
		portals.pb(mt(c, a - 1, b - 1));
	}
	sort(portals.begin(), portals.end());
	int needed = last_true(0, M - 1);
	fout << get<0>(portals[needed]);
}