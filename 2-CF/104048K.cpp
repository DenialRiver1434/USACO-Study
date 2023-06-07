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
vector<pair<ll, string>> unfil;
vector<string> Ses;
vl nums;

// THE FOLLOWING 3 FUNCTIONS ARE ALL PART OF HASHING

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

// FUNCTION FOR TESTING A CERTAIN PERMUTATION

void test () {
    ll cur = 0;
    f0r (i, 0, N - 1) {
        cur += saves[nums[i]][nums[i + 1]];
    }
    best = min(best, standard - cur);
}

int main () {
    // COLLECTING INPUT
    cin >> N;
    f0r (i, 0, N) {
        cin >> S;
        unfil.pb({len(S), S});
    }

    sort(unfil.begin(), unfil.end()); // SORT BY LENGTH
    f0r (i, 0, N) {
        hsh(unfil[i].second, i);
    }

    // SORTING OUT THE STRINGS THAT ARE SUBSTRINGS OF OTHER STRINGS
    // Otherwise, testcases such as
    // 4
    // abc
    // cde
    // efg
    // bcdef
    // will WA
    // The concept is quite easy, I wrote this very messily 
    f0r (i, 0, N) {
        bool gud = 1;
        f0r (j, i + 1, N) {
            string Si = unfil[i].second, Sj = unfil[j].second;
            ll li = len(Si), lj = len(Sj);
            f0r (spot, li, lj + 1) {
                if(hashrange(0, li, i) == hashrange(spot - li, spot, j)) {
                    gud = false;
                    break;
                }
            }
            if(!gud) break;
        }
        if(gud) {
            Ses.pb(unfil[i].second);
        }
    }

    // After we weeded out substrings, we need to redo the hashing
    N = len(Ses);
    f0r (i, 0, 10) {
        f0r (j, 0, 10005) {
            pref[i][j] = 0; powmod[i][j] = 0;
        }
    }
    f0r (i, 0, N) {
        hsh(Ses[i], i);
        nums.pb(i);
        standard += len(Ses[i]);
    }
    best = standard;
    
    // USING HASHING to find the maximum overlap when two spells are used consecutively
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

    // Bashing through all permutations
    test();
    while (next_permutation(nums.begin(), nums.end())) {
        test();
    }
    cout << best << endl;
}