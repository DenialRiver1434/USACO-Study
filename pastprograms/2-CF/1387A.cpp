
// Work in progress

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

double N, M, value[100000], final[100000]; 
bool searched[100000], dfsed[100000];
int pos, a, b, c;
vector<int> connred[100000], connblack[100000], processing;

double test(double num) {
	for (auto p : processing) {
		searched[p] = false;
		value[p] = -1;
	}

	double s = 0;
	return 1;
}

double first_true(double lo, double hi) {
	for (int i = 0; i < 50; i ++) {
		double mid = (hi + lo) / 2;
		if (test(mid) < test(mid + 0.000000001)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	return lo;
}

void dfs (int pos) {
	if(dfsed[pos]) return;
	dfsed[pos] = true;
	processing.pb(pos);
	for (auto cr : connred[pos]) dfs(cr);
	for (auto cr : connblack[pos]) dfs(cr);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < (M - 0.01); i ++) {
		cin >> a >> b >> c;
		a --; b --;
		if(c == 1) {
			connblack[a].pb(b);
			connblack[b].pb(a);
		}
		else {
			connred[a].pb(b);
			connred[b].pb(a);
		}
	}
	for (int i = 0; i < N; i ++) {
		if(!dfsed[i]) {
			processing.clear();
			dfs(i);
			for (auto p : processing) cout << p << " ";
			double a = first_true(-1e6, 1e6);
			cout << setprecision(20) << a << endl;
		}
	}

}