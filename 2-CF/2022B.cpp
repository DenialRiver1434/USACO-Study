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
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

vector<ll> cars;

void tc () {
    ll N, X; cin >> N >> X;

    ll maxcnt = 0, tot = 0;

    cars.clear();
    f0r (i, 0, N) {
        ll a; cin >> a;
        cars.pb(a);
        tot += a;
        maxcnt = max(maxcnt, a);
    }

    bool bon = ((tot % X) != 0);
    tot /= X;
    tot += bon;
    cout << max(maxcnt, tot) << endl;
}

int main () {
    ll T; cin >> T;
    while (T --) {
        tc ();
    }
}
