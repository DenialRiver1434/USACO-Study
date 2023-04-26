#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define lll long long
#define f0r(i, begin, n) for (lll i = begin; i < n; i ++)
#define len(x) x.size()
#define vi vector<lll>
#define vpi vector<pair<lll, lll>>
#include <bits/stdc++.h>
using namespace std;

int main() {
    lll N, a, b; cin >> N >> a >> b;
	vi pref = {0};

	multiset<lll> important;
	lll tot = 0, maxi = -1e18;
    f0r (i, 1, N + 1) {
		lll c; cin >> c;
		tot += c;
		pref.pb(tot);
		if(i >= a) {
			important.is(pref[i - a]);
		}
		if(!important.empty()) maxi = max(maxi, tot - *important.begin());
		if(i >= b) {
			important.erase(important.find(pref[i - b]));
		}
	}
	cout << maxi << endl;
}