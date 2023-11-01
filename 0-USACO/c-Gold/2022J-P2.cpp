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

const ll MAX_N = 1e5;
bool active[MAX_N], searched[MAX_N];
ll ans[MAX_N], N, Q;

set<ll> roads[MAX_N];
V<tuple<char, ll, ll>> queries;

void dfs (ll pos) {
    if (searched[pos]) return;
    searched[pos] = 1;
    active[pos] = 1;
    ans[pos] = Q;
    for (auto r : roads[pos]) {
        dfs (r);
    }
}

void dfs2 (ll pos, ll layer) {
    if (active[pos]) return;
    active[pos] = 1; ans[pos] = layer;
    for (auto r : roads[pos]) {
        dfs2 (r, layer);
    }
}

int main () {
    memset(ans, 0, sizeof(ans));

    fastio;
    cin >> N >> Q;
    f0r (i, 0, N) {
        active[i] = 1;
    }

    V<PL> qroads;
    f0r (i, 0, Q) {
        char t; ll a, b;
        cin >> t;
        if (t == 'A') {
            cin >> a >> b;
            a --; b --;
            queries.pb({t, a, b});
            roads[a].is(b);
            roads[b].is(a);
            qroads.pb({a, b});
        }
        else if (t == 'D') {
            cin >> a; a --;
            active[a] = 0;
            queries.pb({t, a, -1});
        }
        else {
            cin >> a; a --;
            ll x, y; tie(x, y) = qroads[a];
            queries.pb({t, x, y});
            roads[x].erase(y);
            roads[y].erase(x);
        }
    }

    f0r (i, 0, N) {
        if (active[i]) {
            dfs (i);
        }
    }
    
    For (i, Q - 1, -1) {
        char typ; ll a, b;
        tie(typ, a, b) = queries[i];
        if (typ == 'D') {
            dfs2 (a, i);
        }
        else if (typ == 'A') {
            roads[a].erase(b);
            roads[b].erase(a);
        }
        else {
            if (active[a] || active[b]) {
                dfs2 (a, i);
                dfs2 (b, i);
            }
            roads[a].is(b);
            roads[b].is(a);
        }
    }
    
    f0r (i, 0, N) {
        cout << ans[i] << endl;
    }
}