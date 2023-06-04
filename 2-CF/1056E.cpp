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
 
const ll A = 257274504162904133, B = 1720921529140328231;
ll pref[1000005], powmod[1000005], target0, target1, lT;
string S, T;
 
ll modmul (ll a, ll b) {
    __int128_t xa = a, xb = b;
    ll xm = (xa * xb) % B;
    if(xm < 0) xm += B;
    return xm;
}
 
void hsh (string X) {
    ll ls = len(X);
    pref[0] = X[0]; powmod[0] = 1;
    f0r (i, 1, ls) {
        pref[i] = (modmul(pref[i - 1], A) + X[i]) % B;
        powmod[i] = modmul(powmod[i - 1], A);
    }
}
 
ll hashrange (ll a, ll b) {
    if(a == 0) {
        return pref[b - 1];
    }
    ll hs = (pref[b - 1] - modmul(pref[a - 1], powmod[b - a])) % B;
    if(hs < 0) hs += B;
    return hs;
}

bool test (ll l0, ll l1) {
    ll left = 0, right = 0, target0 = -1, target1 = -1;
    for (auto ch : S) {
        if (ch == '0') {
            left = right; right += l0;
            ll cur = hashrange(left, right);
            if (target0 == -1) target0 = cur;
            else if (target0 != cur) return false;
        }
        else {
            left = right; right += l1;
            ll cur = hashrange(left, right);
            if (target1 == -1) target1 = cur;
            else if (target1 != cur) return false;
        }
    }
    return (target0 != target1);
}

int main() {
    cin >> S >> T;
    hsh(T); lT = len(T);

    ll count0 = 0, count1 = 0;
    for (auto ch : S) {
        if(ch == '0') count0 ++;
        else count1 ++;
    }

    ll tc = 0;
    f0r (l0, 1, lT) {
        if((l0 * count0) >= lT) break;
        if(((lT - (l0 * count0)) % count1) == 0) {
            ll l1 = (lT - (l0 * count0)) / count1;
            tc += test(l0, l1);
        }
    }
    cout << tc << endl;
}