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
#define all(X) x.begin(), x.end()
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
 
const ll MAX_N = 2e5 + 5;
ll parent[MAX_N][30];
PL distcycle[MAX_N];
bool searched[MAX_N];
ll cyclelen[MAX_N];

ll ancestor (ll pos, ll d) {
    f0r (k, 0, 30) {
        if ((1 << k & d) > 0) {
            pos = parent[pos][k];
        }
    }
    return pos;
}

void search (ll pos) {
    if (searched[pos]) {
        return;
    }
    V<ll> searchpast;
    ll apos = pos;
    while (!searched[apos]) {
        searched[apos] = 1;
        searchpast.pb(apos);
        apos = parent[apos][0];
    }
    if (distcycle[apos].F == -1) {
        distcycle[apos] = {0, 0};
        ll cd = 0;
        while (searchpast.back() != apos) {
            distcycle[searchpast.back()] = {0, ++cd};
            searchpast.pop_back();
        }
        ll bpos = apos;
        cyclelen[bpos] = cd + 1;
        f0r (i, 0, cd) {
            bpos = parent[bpos][0];
            cyclelen[bpos] = cd + 1;
        }

        ll nd = 0;
        while (!searchpast.empty()) {
            distcycle[searchpast.back()] = {(nd ++), 0};
            searchpast.pop_back();
        }
    } else {
        ll nd = distcycle[apos].F;
        while (!searchpast.empty()) {
            distcycle[searchpast.back()] = {(++ nd), 0};
            searchpast.pop_back();
        }
    }
}

int main () {
    fastio;
    ll N, Q; cin >> N >> Q;
    f0r (i, 0, N) {
        cin >> parent[i][0];
        parent[i][0] --;
        distcycle[i] = {-1, -1};
        searched[i] = false;
        cyclelen[i] = -1;
    }
 
    f0r (k, 1, 30) {
        f0r (i, 0, N) {
            ll pboss = parent[i][k - 1];
            parent[i][k] = parent[pboss][k - 1];
        }
    }
    
    f0r (i, 0, N) {
        if (!searched[i]) {
            search (i);
        }
    }

    f0r (i, 0, Q) {
        ll a, b; cin >> a >> b;
        a --; b --;
        if (a == b) {
            cout << 0 << endl;
            continue;
        }
        ll da = distcycle[a].F, db = distcycle[b].F;
        if (da == 0 && db == 0) {
            ll dfa = distcycle[a].S, dfb = distcycle[b].S;
            ll testlen = (dfa - dfb + cyclelen[a]) % cyclelen[a];
            if (ancestor(a, testlen) == b) {
                cout << testlen << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else if (da <= db) {
            cout << -1 << '\n';
        } else if (db == 0) {
            ll cycleent = ancestor(a, da);
            ll dfa = distcycle[cycleent].S, dfb = distcycle[b].S;
            ll testlen = (dfa - dfb + cyclelen[cycleent]) % cyclelen[cycleent];
            if (ancestor(a, testlen + da) == b) {
                cout << testlen + da << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else {
            ll testlen = da - db;
            if (ancestor(a, testlen) == b) {
                cout << testlen << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
}