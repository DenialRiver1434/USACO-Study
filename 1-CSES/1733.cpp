#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#define f0r(i, begin, n) for (ll i = begin; i < n; i ++)
#define len(x) x.size()
#define vl vector<ll>
#define sl set<ll>
#define msl multiset<ll>
#define pl pair<ll, ll>
#define vpl vector<pair<ll, ll>>
#include <bits/stdc++.h>
using namespace std;
 
const ll A = 972638213777, B = 2305843009213693951;
ll h[1000005], p[1000005];
 
ll modmul (ll a, ll b) {
    __int128_t xa = a, xb = b;
    ll xm = (xa * xb) % B;
    if(xm < 0) xm += B;
    return xm;
}
 
void hsh (string s) {
    ll ls = len(s);
    h[0] = s[0];
    p[0] = 1;
    f0r (i, 1, ls) {
        h[i] = (modmul(h[i - 1], A) + s[i]) % B;
        p[i] = modmul(p[i - 1], A);
    }
}
 
ll hashrange (ll a, ll b) {
    if(a == 0) {
        return h[b - 1];
    }
    ll hs = (h[b - 1] - modmul(h[a - 1], p[b - a])) % B;
    if(hs < 0) hs += B;
    return hs;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    
    string n; cin >> n;
    hsh(n);
    ll N = len(n);
 
    f0r (leng, 1, N) {
        bool ok = 1;
 
        ll deber = hashrange(0, leng);
        f0r (i, 1, N / leng) {
            if(hashrange(i * leng, i * leng + leng) != deber) {
                ok = 0;
            }
        }
        ll cutoff = N % leng;
        if(hashrange(N - cutoff, N) != hashrange(0, cutoff)) {
            ok = 0;
        }
 
        if(ok) {
            cout << leng << " ";
        }
    }
    cout << N << '\n';
} 