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

const lll A = 972638213777, B = 2305843009213693951;
lll h[200000], p[200000], cnth[26], cntn[26];
set<lll> hashed;

lll modmul (lll a, lll b) {
    __int128 xa = a, xb = b;
    lll xm = (xa * xb) % B;
    if(xm < 0) xm += B;
    return xm;
}

void hsh (string s) {
    lll ls = len(s);
    h[0] = s[0];
    p[0] = 1;
    f0r (i, 1, ls) {
        h[i] = (modmul(h[i - 1], A) + s[i]) % B;
        p[i] = modmul(p[i - 1], A);
    }
}

bool check() {
    f0r (i, 0, 26) {
        if(cnth[i] != cntn[i]) return false;
    }
    return true;
}

int main() {
    string N, H; cin >> N >> H;
    lll lN = len(N), lH(len(H));
    if(lN > lH) {
        cout << 0 << endl;
        return 0;
    }
    hsh(H);
    
    f0r (i, 0, lN) {
        cnth[H[i] - 'a'] ++;
    }
    for (auto n : N) {
        cntn[n - 'a'] ++;
    }
    if(check()) {
        hashed.is(h[lN - 1]);
    }
    f0r (i, 1, lH - lN + 1) {
        cnth[H[i - 1] - 'a'] --;
        cnth[H[i + lN - 1] - 'a'] ++;
        if(check()) {
            lll hs = (h[i + lN - 1] - modmul(h[i - 1], p[lN])) % B;
            if(hs < 0) hs += B;
            hashed.is(hs);
        }
    }

    cout << len(hashed) << endl;
} 