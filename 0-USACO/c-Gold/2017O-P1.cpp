#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define vl vector<ll>
#define sl set<ll>
#define msl multiset<ll>
#define pl pair<ll, ll>
#define vpl vector<pair<ll, ll>>
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

ll N, M;
const ll A = 257274504162904133, B = 1720921529140328231;
ll pref[1000][505], powmod[505];
string S[1000];
 
ll modmul (ll a, ll b) {
    __int128_t xa = a, xb = b;
    ll xm = (xa * xb) % B;
    if(xm < 0) xm += B;
    return xm;
}
 
void hsh (string s, ll pos) {
    ll ls = len(s);
    pref[pos][0] = s[0];
    powmod[0] = 1;
    f0r (i, 1, ls) {
        pref[pos][i] = (modmul(pref[pos][i - 1], A) + s[i]) % B;
        powmod[i] = modmul(powmod[i - 1], A);
    }
}
 
ll hashrange (ll a, ll b, ll pos) {
    if(a == 0) {
        return pref[pos][b - 1];
    }
    ll hs = (pref[pos][b - 1] - modmul(pref[pos][a - 1], powmod[b - a])) % B;
    if(hs < 0) hs += B;
    return hs;
}

bool testrange (ll a, ll b) {
    set<ll> spots;
    f0r (i, 0, N) {
        spots.is(hashrange(a, b, i));
    }
    f0r (i, N, 2 * N) {
        ll x = (hashrange(a, b, i));
        if(spots.find(x) != spots.end()) return false;
    }

    return true;
}

bool test (ll leng) {
    bool found = false;
    f0r (i, 0, M - leng + 1) {
        if(testrange(i, i + leng)) {
            found = true;
            break;
        }
    }
    return found;
}

ll first_true(ll lo, ll hi) {
	hi++;
	while (lo < hi) {
		ll mid = lo + (hi - lo) / 2;
		if (test(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main () {
    ifstream fin; ofstream fout;
    fin.open("cownomics.in"); fout.open("cownomics.out");

    fin >> N >> M;
    f0r (i, 0, 2 * N) {
        fin >> S[i];
        hsh(S[i], i);
    }
    fout << first_true(1, M) << endl;
}