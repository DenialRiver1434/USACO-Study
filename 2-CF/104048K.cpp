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
ll pref[10][10005], powmod[10][10005], saves[10][10], N, best, standard;
string S;
vector<string> Ses;
vl nums;
 
ll modmul (ll a, ll b) {
    __int128_t xa = a, xb = b;
    ll xm = (xa * xb) % B;
    if(xm < 0) xm += B;
    return xm;
}
 
void hsh (string X, ll pos) {
    ll ls = len(X);
    pref[pos][0] = X[0]; powmod[pos][0] = 1;
    f0r (i, 1, ls) {
        pref[pos][i] = (modmul(pref[pos][i - 1], A) + X[i]) % B;
        powmod[pos][i] = modmul(powmod[pos][i - 1], A);
    }
}
 
ll hashrange (ll a, ll b, ll pos) {
    if(a == 0) {
        return pref[pos][b - 1];
    }
    ll hs = (pref[pos][b - 1] - modmul(pref[pos][a - 1], powmod[pos][b - a])) % B;
    if(hs < 0) hs += B;
    return hs;
}

void test () {
    ll cur = 0;
    f0r (i, 0, N - 1) {
        cur += saves[nums[i]][nums[i + 1]];
    }
    best = min(best, standard - cur);
}

int main () {
    cin >> N;
    f0r (i, 0, N) {
        cin >> S;
        hsh(S, i);
        Ses.pb(S);
        nums.pb(i);
        standard += len(S);
    }
    best = standard;

    // HASHING
    f0r (i, 0, N) {
        f0r (j, 0, N) {
            if(i == j) continue;
            string I = Ses[i], J = Ses[j];
            ll lI = len(I), lJ = len(J), best = 0;
            f0r (ovl, 0, min(lI, lJ) + 1) {
                if(hashrange(lI - ovl, lI, i) == hashrange(0, ovl, j)) best = ovl;
            }
            saves[i][j] = best;
        }
    }

    // BASHING
    test();
    while (next_permutation(nums.begin(), nums.end())) {
        test();
    }
    cout << best << endl;
}