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

ll get_tot (ll l, ll r) {
    if (r <= l) {
        return 0;
    }
    cout << "? " << l + 1 << " " << r << endl;
    ll a; cin >> a;
    return a;
}

void search (ll L, ll R) {
    if (R == L) throw;
    ll ts = get_tot(L, R);

    if (R - L == 1) {
        cout << "! " << ts << endl;
    } else {
        ll lo = L, hi = R;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            if (get_tot(L, mid) >= (ts / 2)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        // [L, lo) or [lo, R)
        if ((lo - L) < (R - lo)) {
            search (L, lo);
        } else {
            search (lo, R);
        }
    }
}

void tc () {
    ll N; cin >> N;
    search (0, N);
}

int main () {
    int T; cin >> T;
    while (T --) {
        tc ();
    }
}