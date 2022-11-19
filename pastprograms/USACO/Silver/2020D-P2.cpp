#define pb push_back
#define mt make_tuple
#include <bits/stdc++.h>

using namespace std;

typedef vector<tuple<int, int>> vti;
vti given, coords;
vector<int> xs, ys;
int N, a, b;

int occupied[2500][2500];
int numcows (int x1, int y1, int x2, int y2) { // Less to more, inclusive
	int num = occupied[x2][y2];
	if(x1 > 0) num -= occupied[x1 - 1][y2];
	if(y1 > 0) num -= occupied[x2][y1 - 1];
	if(x1 > 0 && y1 > 0) num += occupied[x1 - 1][y1 - 1];
	return num;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i ++) {
		cin >> a >> b;
		xs.pb(a);
		ys.pb(b);
		given.pb(mt(a, b));
	}
	sort(xs.begin(), xs.end()); sort(ys.begin(), ys.end());
	for (auto pair : given) {
		int a = get<0>(pair), b = get<1>(pair);
		coords.pb(mt(lower_bound(xs.begin(), xs.end(), a) - xs.begin(), lower_bound(ys.begin(), ys.end(), b) - ys.begin()));
	}
	for (int i = 0; i < N; i ++) {
		int a = get<0>(coords[i]), b = get<1>(coords[i]);
		occupied[a][b] += 1;
	}
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			if(i > 0) occupied[i][j] += occupied[i - 1][j];
			if(j > 0) occupied[i][j] += occupied[i][j - 1];
			if(i > 0 && j > 0) occupied[i][j] -= occupied[i - 1][j - 1];
		}
	}
	long long ans = 0;
	for (int i = 0; i < N; i ++) {
		for (int j = i + 1; j < N; j ++) {
			int xi = get<0>(coords[i]), yi = get<1>(coords[i]), xj = get<0>(coords[j]), yj = get<1>(coords[j]);
			int ya = min(yi, yj), yb = max(yi, yj);
			int c = numcows(0, ya, min(xi, xj), yb);
			int d = numcows(max(xi, xj), ya, N - 1, yb);
			ans += c * d;
		}
	}
	ans += (N + 1);
	cout << ans;
}