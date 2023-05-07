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
set<lll> proc;

int main() {
    lll N, l = 0, best = 0;
    cin >> N;
    f0r (i, 0, N) {
        int a; cin >> a;
        hist.pb(a);
        while (proc.find(a) != proc.end()) {
            proc.erase(hist[l]);
            l ++;
        }
        proc.is(a);
        lll lp = len(proc);
        best = max(best, lp);
    }
    cout << best << endl;
}
