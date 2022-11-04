#include <vector>
#include <string>
#include <iostream>
using namespace std;
long long xb, yb, xe, ye, n, dx = 0, dy = 0;
string s;

bool test(long long n) {
    long long tx = dx * (n / s.size()) + xb, ty = dy * (n / s.size()) + yb;
    for (long long i = 0; i < (n % s.size()); i ++){
        char dir = s[i];
        if(dir == 'U') ty ++;
        else if(dir == 'D') ty--;
        else if(dir == 'R') tx++;
        else tx--;
    }
    long long md = abs(tx - xe) + abs(ty - ye);
    return md <= n;
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
    cin >> xb >> yb >> xe >> ye >> n >> s;
    for (long long i = 0; i < s.size(); i ++){
        char dir = s[i];
        if(dir == 'U') dy ++;
        else if(dir == 'D') dy--;
        else if(dir == 'R') dx++;
        else dx--;
    }

    if(test(9223372036854775806)) cout << first_true(1, 9223372036854775806);
    else cout << -1;
}