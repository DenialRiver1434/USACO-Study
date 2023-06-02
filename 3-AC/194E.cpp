#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define lll long long
#define f0r(i, begin, n) for (lll i = begin; i < n; i ++)
#define len(x) x.size()
#define vl vector<lll>
#define sl set<lll>
#define msl multiset<lll>
#define pl pair<lll, lll>
#define vpl vector<pair<lll, lll>>
#include <bits/stdc++.h>
using namespace std;

lll cnt[1500000], N, M, best = 1e18;
vl past;
sl unav;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    cin >> N >> M;
    f0r (i, 0, M + 1) unav.is(i);
    f0r (i, 0, M) {
        lll a; cin >> a;
        cnt[a] ++;
        if(unav.find(a) != unav.end()) unav.erase(a);
        past.pb(a);
    }

    best = min(best, *unav.begin());
    f0r (i, M, N) {
        lll a; cin >> a;
        cnt[a] ++;
        if(unav.find(a) != unav.end()) {
            unav.erase(a);
        }
        if(--cnt[past[i - M]] == 0) {
            unav.is(past[i - M]);
        }
        best = min(best, *unav.begin());
        past.pb(a);
    }
    cout << best << endl;
}
