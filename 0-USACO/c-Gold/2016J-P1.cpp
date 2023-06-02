#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

double N;
double optimal, boptimal, a;
vector<double> loc;

bool test (double num, bool b) {
    double opt;
    if(b) opt = boptimal;
    else opt = optimal;
    double right = lower_bound(loc.begin(), loc.end(), opt) - loc.begin();
    double left = right - 1;
    if(b) right ++;
    if(right == N) return false;
    double prev = opt;
    bool found = true;
    for (double i = right; i < N - 0.1; i ++) {
        if((loc[i] - prev) > (num - i + right)) found = false;
        prev = loc[i];
    }
    prev = opt;
    for (double i = left; i >= -0.1; i --) {
        if((prev - loc[i]) > (num + i - left)) found = false;
        prev = loc[i];
    }
    return found;
}

double first_true(double lo, double hi) {
	for (double i = 0; i < 50; i ++) {
		double mid = (hi + lo) / 2;
		if (test(mid, true) || test(mid, false)) hi = mid;
		else lo = mid;
	}
	return lo;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("angry.in");
    fout.open("angry.out");

    fin >> N;
    for (double i = 0; i < N; i ++) {
        fin >> a;
        loc.pb(a);
    }
    sort(loc.begin(), loc.end());

    double greatest = 0;
    for (double i = 0; i < N - 1; i ++) {
        if((loc[i + 1] - loc[i]) > greatest) {
            greatest = loc[i + 1] - loc[i];
            optimal = loc[i] + (loc[i + 1] - loc[i]) / 2;
            boptimal = loc[i + 1];
        }
    }
    test(4.5, boptimal);
    double num = first_true(0, 1000000000);
    fout << fixed << setprecision(1) << num << endl;
}