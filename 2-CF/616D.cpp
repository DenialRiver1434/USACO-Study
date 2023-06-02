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

vi hist;
map<lll, lll> active;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
    lll N, K, l = 0, best = 0;
	pair<lll, lll> ans;
    cin >> N >> K;
    f0r (i, 0, N) {
        int a; cin >> a;
        hist.pb(a);
		active[a] ++;
        while (len(active) > K) {
            if(--active[hist[l]] == 0) {
				active.erase(hist[l]);
			}
            l ++;
        }
		if((i - l) > best) {
			best = i - l;
			ans = {l, i};
		}
    }
    cout << ans.first + 1 << " " << ans.second + 1 << endl;
}
