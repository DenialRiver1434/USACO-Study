#define pb push_back
#define mt make_tuple
#define is insert
#include <bits/stdc++.h>
using namespace std;

int N, M, a;
multiset<int> sdist, locs;

int main() {
    cin >> N >> M;
    cin >> a;
    locs.is(a);
    sdist.is(a);
    sdist.is(N - a);
    cout << *sdist.rbegin() << endl;
    for (int i = 1; i < M; i ++ ) {
        cin >> a;
        locs.is(a);
        auto victim = locs.lower_bound(a);
        int ldist, rdist;
        if(victim == locs.begin())  {
            ldist = a;
        }
        else {
            ldist = a - *(--victim);
            victim ++;
        }
        if(*victim == *locs.rbegin()) {
            rdist = N - a;
        }
        else {
            rdist = *(++ victim) - a;
            victim --;
        }
        sdist.erase(sdist.find(ldist + rdist));
        sdist.is(ldist);
        sdist.is(rdist);
        cout << *sdist.rbegin() << endl;
    }
}