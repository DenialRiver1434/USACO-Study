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

map<lll, lll> cnt;
lll N, M, tot = 0;
vl past;
sl used;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    cin >> N >> M;
    lll j;
    for (j = 1; j <= N; j ++) {
        lll a; cin >> a;
        cnt[a] ++;
        used.is(a);
        past.pb(a);
        lll lu = len(used);
        tot += j;
        if(lu == M) break;
    }

    lll lhs = 0;
    f0r (i, j, N) {
        lll a; cin >> a;
        past.pb(a);
        cnt[a] ++;
        used.is(a);
        while (1) {
            lll lu = len(used);
            if(lu == M) break;
            if(--cnt[past[lhs]] == 0) {
                used.erase(past[lhs]);
            }
            lhs ++;
        }
        tot += (i - lhs + 1);
    }
    cout << tot << endl;
}
