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

const ll MAX = 2e5 + 5;

V<ll> filter[MAX];
ll nextnum[MAX], arr[MAX], dest[MAX][30];
 
ll dist (ll pos, ll jumps) {
    ll npos = pos;
    f0r (i, 0, 30) {
        if ((1 << i & jumps) > 0) {
            npos = dest[npos][i];
        }
    }
    return npos;
}

ll opt[MAX];

int main () {
    ll N, M, Q;
    cin >> N >> M >> Q;

    ll fs; cin >> fs;
    ll p = fs;
    f0r (i, 1, N) {
        ll a; cin >> a;
        nextnum[p] = a;
        p = a;
    }
    nextnum[p] = fs;

    f0r (i, 0, M) {
        cin >> arr[i];
        filter[arr[i]].pb(i);
    }
    f0r (i, 0, M) {
        ll target = nextnum[arr[i]];
        auto x = lower_bound(all(filter[target]), i);
        if (x == filter[target].end()) {
            dest[i][0] = M;
        } else {
            dest[i][0] = *lower_bound(all(filter[target]), i);
        }
    }
    dest[M][0] = M;

    f0r (j, 1, 30) {
        f0r (i, 0, M + 1) {
            ll med = dest[i][j - 1];
            dest[i][j] = dest[med][j - 1];
        }
    }

    f0r (i, 0, M) {
        opt[i] = dist(i, N - 1);
    }
    For (i, M - 2, -1) {
        opt[i] = min(opt[i], opt[i + 1]);
    }
    
    f0r (i, 0, Q) {
        ll a, b; cin >> a >> b;
        a --; b --;
        if (opt[a] <= b) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
}