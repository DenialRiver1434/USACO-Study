#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

double N, a;
vector<double> speeds, dists;

bool test (double num) {
	double lhs = 0, rhs = 1e9;
    for (double i = 0; i < N; i ++) {
		double left = dists[i] - (speeds[i] * num), right = dists[i] + (speeds[i] * num);
		lhs = max(lhs, left);
		rhs = min(rhs, right);
	}
	return (lhs < rhs);
}

double first_true(double lo, double hi) {
	for (double i = 0; i < 100; i ++) {
		double mid = (hi + lo) / 2;
		if (test(mid)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	return lo;
}

int main() {
    cin >> N;
	for (double i = 0; i < N; i ++) {
		cin >> a;
		dists.pb(a);
	}
	for (double i = 0; i < N; i ++) {
		cin >> a;
		speeds.pb(a);
	}
    cout << fixed << setprecision(7) << first_true(0, 1e9) << endl;
}