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
template<typename T> ostream& operator<<(ostream& out, pair<T, T>& a) {out << a.F << ", " << a.S << endl; return out;};
template<typename T> ostream& operator<<(ostream& out, tuple<T, T, T>& a) {out << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << endl; return out;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

bool reachable[2][10001];

void tc () {
    memset(reachable, 0, sizeof(reachable));
    ll N; cin >> N;
    if (N == 1) {
        cin >> N;
        cin >> N;
        cout << 0 << endl;
        return;
    }

    V<ll> inps;
    ll tot = 0, s = 0;
    f0r (i, 0, N) {
        ll a; cin >> a;
        tot += (N - 2) * (a) * (a);
        s += a;
        inps.pb(a);
    }

    reachable[1][0] = 1;
    f0r (i, 0, N) {
        ll a; cin >> a;
        tot += (N - 2) * (a) * (a);
        s += a;
        
        memset(reachable[i % 2], 0, sizeof(reachable[i % 2]));
        f0r (j, 0, 10001) {
            if (j >= a) {
                reachable[i % 2][j] |= reachable[(i + 1) % 2][j - a];
            }
            if (j >= inps[i]) {
                reachable[i % 2][j] |= reachable[(i + 1) % 2][j - inps[i]];
            }
        }
    }

    ll s2 = INF;
    f0r (j, 0, 10001) {
        if (reachable[(N + 1) % 2][j]) {
            s2 = min(s2, (j * j) + (s - j) * (s - j));
        }
    }
    cout << tot + s2 << endl;
}

int main () {
    ll T; cin >> T;
    while (T --) {
        tc ();
    }
}