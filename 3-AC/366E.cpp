#include <bits/stdc++.h>
using namespace std;
#define pb push_back 
#define is insert
#define lb lower_bound
#define ll long long
#define V vector
#define MS multiset
#define PL pair<ll, ll>
#define F first
#define S second
#define PQ priority_queue
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define For(i, end, begin) for (ll i = end; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000009
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};
template<typename T> istream& operator>>(istream& in, pair<T, T>& a) {in >> a.F >> a.S; return in;};
template<typename T> ostream& operator<<(ostream& out, pair<T, T>& a) {out << a.F << ' ' << a.S << '\n'; return out;};

V<PL> points;
ll N, D; 

map<ll, ll> xs, ys;
V<tuple<ll, ll, ll>> xsegs;
// cost at LHS, slope, distance

int main () {
    cin >> N >> D;
    f0r (i, 0, N) {
        ll a, b; cin >> a >> b;
        xs[a] ++;
        ys[b] ++;
    }

    // cost at LHS, slope, distance
    ll xsmin = (*xs.begin()).F, cost = 0, slope = -N;
    for (auto x : xs) {
        cost += (x.F - xsmin) * x.S;
    }
    xsegs.pb({cost - inf * slope, slope, inf});

    for (auto itr = xs.begin(); itr != xs.end(); itr ++) {
        ll pos = (*itr).F, amt = (*itr).S;
        slope += amt * 2;
        if (next(itr) == xs.end()) {
            xsegs.pb({cost, slope, inf});
        } else {
            ll npos = (*next(itr)).F;
            xsegs.pb({cost, slope, npos - pos});
            cost += slope * (npos - pos);
        }
    }

    cost = 0, slope = -N;
    for (auto y : ys) {
        cost += abs(y.F + 2e6 + 5) * y.S;
    }

    V<ll> costpnt;
    f0r (i, -2e6 - 5, 2e6 + 5) {
        costpnt.pb(cost);
        if (ys.find(i) != ys.end()) {
            slope += 2 * ys[i];
        }
        cost += slope;
    }
    sort(all(costpnt), greater<ll>());
    
    // Lower, non-negative slope, distance
    V<tuple<ll, ll, ll>> xsegs1, xsegs2;
    bool switched = false;
    f0r (i, 0, len(xsegs)) {
        if (get<1>(xsegs[i]) < 0) {
            xsegs1.pb({get<0>(xsegs[i]) + get<1>(xsegs[i]) * get<2>(xsegs[i]), -get<1>(xsegs[i]), get<2>(xsegs[i])});
        } else {
            if (!switched) {
                xsegs2.pb({get<0>(xsegs[i]) + get<1>(xsegs[i]), get<1>(xsegs[i]), get<2>(xsegs[i]) - 1});
                switched = true;
            } else {
                xsegs2.pb(xsegs[i]);
            }
        }
    }
    reverse(all(xsegs1));

    ll ans = 0, passive = 0, ind = 0;

    // Limit gets looser and looser
    for (auto c : costpnt) {
        ll lim = D - c;
        if (lim < 0) continue;

        while (ind < len(xsegs1)) {
            ll lower = get<0>(xsegs1[ind]), slope = get<1>(xsegs1[ind]), duration = get<2>(xsegs1[ind]);
            ll higher = lower + slope * (duration - 1);
            if (lim > higher) {
                passive += duration;
                ind ++;
                continue;
            } else if (lim >= lower) {
                ll contr = 1 + (lim - lower) / slope;
                ans += contr;
            }
            break;
        }
        ans += passive;
    }

    passive = 0, ind = 0;
    for (auto c : costpnt) {
        ll lim = D - c;
        if (lim < 0) continue;

        while (ind < len(xsegs2)) {
            ll lower = get<0>(xsegs2[ind]), slope = get<1>(xsegs2[ind]), duration = get<2>(xsegs2[ind]);
            ll higher = lower + slope * (duration - 1);
            if (lim >= higher) {
                passive += duration;
                ind ++;
                continue;
            } else if (lim >= lower) {
                ll contr = 1 + (lim - lower) / slope;
                ans += contr;
            }
            break;
        }
        ans += passive;
    }
    cout << ans << endl;
}