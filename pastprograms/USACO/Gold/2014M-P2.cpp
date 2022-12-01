#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, a;
vector<double> intervals;

bool test (double num) {
    double lowest = intervals[0] - num, total = intervals[0] - num, msum = intervals[1] - num;
    for (int i = 1; i < intervals.size() - 1; i ++) {
        double adjusted = intervals[i] - num;
        total += adjusted;
        msum = max(msum, total - lowest);
        lowest = min(lowest, total);
    }
    total += (intervals[N - 1] - num);
    return (msum >= total);
}

double first_true(double lo, double hi) {
	for (int i = 0; i < 50; i ++) {
		double mid = (hi + lo) / 2;
		if (test(mid)) hi = mid;
		else lo = mid;
	}
	return lo;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("sabotage.in");
    fout.open("sabotage.out");

    fin >> N;
    int rhs = 0;
    for (int i = 0; i < N; i ++){
        fin >> a;
        rhs = max(rhs, a);
        intervals.pb(a);
    }
    double num = first_true(0, rhs);
    fout << fixed << setprecision(3) << num << endl;
}