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
 
ll T, N, X;
 
void tc () {
    cin >> N >> X;
 
    V<PL> a;
    V<ll> b(N);
    f0r (i, 0, N) {
        ll x; cin >> x;
        a.pb({x, i});
    }
    sort(all(a));
    cin >> b;
    sort(all(b));
    V<ll> compb;
 
    ll tot = 0;
    f0r (i, 0, N - X) {
        compb.pb(b[i + X]);
    }
    f0r (i, 0, X) {
        compb.pb(b[i]);
    }
    
    f0r (i, 0, N) {
        if (compb[i] < a[i].F) {
            tot ++;
        }
    }
    if (tot != X) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        V<ll> ans(N);
        f0r (i, 0, N) {
            ans[a[i].S] = compb[i];
        }
        cout << ans << endl;
    }
}
 
int main () {
    cin >> T;
    while (T --) {
        tc ();
    }
}
