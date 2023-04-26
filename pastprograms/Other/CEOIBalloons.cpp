#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define lll long long
#define f0r(i, begin, n) for (lll i = begin; i < n; i ++)
#define len(x) x.size()
#define vi vector<int>
#define vpi vector<pair<int, int>>
#include <bits/stdc++.h>
using namespace std;

set<string> names;
stack<pair<long double, long double>> hist;

long double sizd (long double a, long double pra, long double prb) {
    return ((a - pra) * (a - pra)) / (4 * prb);
}

int main() {
    lll N; cin >> N;
    f0r (i, 0, N) {
        long double a, b; cin >> a >> b;
        while(!hist.empty()) {
            pair<long double, long double> pld = hist.top();
			b = min(b, sizd(a, pld.first, pld.second));
			if(pld.second <= b) hist.pop();
			else break;
        }

        hist.push({a, b});
        cout << fixed << setprecision(3) << b << endl;
    }
}