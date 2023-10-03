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
ll N, M, dp1[MAX_N], dp2[MAX_N];
V<ll> pref[MAX_N], suf[MAX_N];
V<ll> conn[MAX_N];

void dfs1 (ll pos, ll pre) {
    ll tot = 1;
    
    V<ll> facts;
    for (auto c : conn[pos]) {
        if (c != pre) {
            dfs1 (c, pos);
            tot *= (dp1[c] + 1);
            tot %= M;
            facts.pb(dp1[c] + 1);
        }
    }

    if (!facts.empty()) {
        ll lf = len(facts);
        pref[pos] = suf[pos] = V<ll>(lf);
        pref[pos][0] = suf[pos][lf - 1] = 1;

        f0r (i, 1, lf) {
            pref[pos][i] = pref[pos][i - 1] * facts[i - 1];
            pref[pos][i] %= M;
        }
        For (i, lf - 1, 0) {
            suf[pos][i - 1] = suf[pos][i] * facts[i];
            suf[pos][i - 1] %= M;
        }
    }

    dp1[pos] = tot;
}

void dfs2 (ll pos, ll pre, ll abovefact) {
    ll i = 0;
    dp2[pos] = (dp1[pos] * abovefact) % M;
    for (auto c : conn[pos]) {
        if (c != pre) {
            ll above = abovefact * pref[pos][i];
            above %= M;
            above *= suf[pos][i];
            above %= M;
            dfs2 (c, pos, above + 1);
            i ++;
        }
    }
}

int main () {
    cin >> N >> M;
    f0r (i, 0, N - 1) {
        ll a, b; cin >> a >> b;
        conn[a - 1].pb(b - 1);
        conn[b - 1].pb(a - 1);
    }
    dfs1 (0, -1);
    dfs2 (0, -1, 1);

    f0r (i, 0, N) {
        cout << (dp2[i] + M) % M << endl;
    }
}