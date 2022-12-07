#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <cmath>
using namespace std;
long long N, T, a;
vector<long long> intervals;

bool test(long long n) {
    long long product = 0;
    for (auto i : intervals){
        product += (n / i);
    }
    return product >= T;
}

long long first_true(long long lo, long long hi) {
	hi++;
	while (lo < hi) {
		long long mid = lo + (hi - lo) / 2;
		if (test(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main() {
    cin >> N >> T;
    for (long long i = 0; i < N; i ++){
        cin >> a;
        intervals.push_back(a);
    }
    if(N == 1) cout << T * intervals[0] << endl;
    else if(test(10000) == 1) cout << first_true(1, 10000) << endl;
    else cout << first_true(1, 100000000000000000) << endl;
}