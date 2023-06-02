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
ll pref[1000005], powmod[1000005], N;
string s;
 
ll modmul (ll a, ll b) {
    __int128_t xa = a, xb = b;
    ll xm = (xa * xb) % B;
    if(xm < 0) xm += B;
    return xm;
}
 
void hsh (string s) {
    ll ls = len(s);
    pref[0] = s[0];
    powmod[0] = 1;
    f0r (i, 1, ls) {
        pref[i] = (modmul(pref[i - 1], A) + s[i]) % B;
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

void tc () {
    cin >> s;

    f0r (i, 0, 1000005) {
        pref[i] = 0;
        powmod[i] = 0;
    }
    
    hsh(s);
    N = len(s);
    ll tc = 0, left = 0, right = N;
    
    while (true) {
        if((right - left) == 1) {
            tc ++;
            break;
        }
        if((right - left) < 1) break;

        bool found = false;
        f0r (dist, 1, (right - left) / 2 + 1) {
            if(hashrange(left, left + dist) == hashrange(right - dist, right)) {
                tc += 2;
                left += dist; right -= dist;
                found = true;
                break;
            }
        }
        if(!found) {
            tc ++;
            break;
        }
    }
    cout << tc << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
	ll T; cin >> T;
    while (T --) {
        tc ();
    }
} 