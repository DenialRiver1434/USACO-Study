#include <bits/stdc++.h> 
using namespace std;
#define pb push_back 
#define is insert
#define ll long long
#define V vector
#define MS multiset
#define PL pair<ll, ll>
#define F first
#define S second
#define PQ priority_queue
#define f0r(i, begin, finish) for (ll i = begin; i < finish; i ++) 
#define For(i, finish, begin) for (ll i = finish; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

ll N, curpos = 0, fall = 1;

struct Hill {
    ll x1, y1, x2, y2, id;

    double getY (ll x) const {
        return y1 + (double(x - x1) / double(x2 - x1)) * (y2 - y1);
    }

    bool operator<(const Hill& o) const {
        return getY(curpos) < o.getY(curpos);
    }
};

set<Hill> hills;
map<ll, V<Hill>> start, finish;
set<ll> crit;

int main () {
    fileread("hillwalk");

    fin >> N;
    Hill curhill;

    f0r (i, 0, N) {
        ll a, b, c, d; fin >> a >> b >> c >> d;
        if (a == 0 && b == 0) {
            curhill = {a, b, c, d, i};
        }
        start[a].pb({a, b, c, d, i});
        finish[c].pb({a, b, c, d, i});
        crit.is(a);
        crit.is(c);
    }

    for (auto c : crit) {
        curpos = c;

        // Take out the finishes
        for (auto h : finish[curpos]) {
            hills.erase(h);
        }

        // Add in the starts
        for (auto h : start[curpos]) {
            hills.is(h);
        }

        // Fall?
        if (curpos == curhill.x2) {
            auto pos = hills.lower_bound(curhill);
            if (pos == hills.begin()) {
                break;
            }
            Hill nhill = *prev(pos);
            fall ++;
            curhill = nhill;
        }
    }
    
    fout << fall << endl;
}