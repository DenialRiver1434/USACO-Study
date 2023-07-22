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
#include "bits/stdc++.h"
using namespace std;

vector<int> inps;
ll N, M;
msl down, up; // len(down) - 1 <= len(up) <= len(down)

ll cut () {
    return *down.rbegin();
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> N >> M;
    msl initial;
    f0r (i, 0, M) {
        int a; cin >> a;
        initial.is(a);
        inps.pb(a);
    }
    f0r (i, M, N) {
        int a; cin >> a;
        inps.pb(a);
    }

    int i = 0;
    for (auto ini : initial) {
        if(i < ((M + 1) / 2)) down.is(ini);
        else up.is(ini);
        i ++;
    }
    cout << cut() << " ";

    f0r (i, M, N) {
        int cu = cut();
        if(inps[i - M] <= cu) down.erase(down.find(inps[i - M]));
        else up.erase(up.find(inps[i - M]));
        if(inps[i] <= cu) down.is(inps[i]);
        else up.is(inps[i]);

        if(len(down) > (M + 1) / 2) {
            int temp = cut();
            down.erase(down.find(temp));
            up.is(temp);
        }
        if(len(down) < (M + 1) / 2) {
            int temp = *up.begin();
            up.erase(up.find(temp));
            down.is(temp);
        }
        cout << cut() << " ";
    }
}