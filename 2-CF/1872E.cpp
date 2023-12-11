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

ll T;

void tc () {
    V<ll> pref = {0}, arr;
    ll N, xor0 = 0, xor1 = 0; cin >> N;
    f0r (i, 0, N) {
        ll a; cin >> a;
        pref.pb(pref[i] ^ a);
        arr.pb(a);
    }
    f0r (i, 0, N) {
        char a; cin >> a;
        if (a == '0') xor0 ^= arr[i];
        else xor1 ^= arr[i];
    }

    ll Q; cin >> Q;
    f0r (i, 0, Q) {
        ll typ, a, b; cin >> typ;
        if (typ == 2) {
            cin >> a;
            if (a == 0) {
                cout << xor0 << " ";
            }
            else {
                cout << xor1 << " ";
            }
        }
        else {
            cin >> a >> b;
            ll x = pref[a - 1] ^ pref[b];
            xor0 ^= x;
            xor1 ^= x;
        }
    }
    cout << endl;
}

int main () {
    cin >> T;
    while (T --) {
        tc ();
    }
}