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
ll pref[1000005], powmod[1000005], N, target, lT, lR;
string S, T;
 
ll modmul (ll a, ll b) {
    __int128_t xa = a, xb = b;
    ll xm = (xa * xb) % B;
    if(xm < 0) xm += B;
    return xm;
}
 
void hsh (string S) {
    ll ls = len(S);
    pref[0] = S[0];
    f0r (i, 1, ls) {
        pref[i] = (modmul(pref[i - 1], A) + S[i]) % B;
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

int main() {
    ifstream fin; ofstream fout;
    fin.open("censor.in"); fout.open("censor.out");
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
	
    fin >> S >> T;
    lT = len(T);
    hsh(T); target = pref[lT - 1];

    vector<char> R;
    powmod[0] = 1; pref[0] = 0;
    f0r (i, 1, 1000005) {
        pref[i] = 0;
        powmod[i] = modmul(powmod[i - 1], A);
    }

    for (auto ch : S) {
        R.pb(ch);
        lR = len(R);
        if(lR == 1) {
            pref[0] = ch;
        }
        else {
            pref[lR - 1] = (modmul(pref[lR - 2], A) + ch) % B;
        }
        
        if(hashrange(lR - lT, lR) == target) {
            f0r (i, 0, lT) {
                R.pop_back();
            }
        }
    }
    for (auto ch : R) fout << ch;
} 