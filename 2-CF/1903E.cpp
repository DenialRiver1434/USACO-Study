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
 
ll T, N, a, b;
set<ll> eend, oend;
 
void rem () {
    ll x; cin >> x;
    x --;
    if (eend.find(x) != eend.end()) {
        eend.erase(eend.find(x));
    }
    else {
        oend.erase(oend.find(x));
    }
}
 
void tc () {
    eend.clear(); oend.clear();
 
    cin >> N >> a >> b;
    ll oddend = 0, evenend = 0;
 
    f0r (i, 0, N) {
        ll c, d; cin >> c >> d;
        bool dist = (c - a + b - d) % 2;
        if (dist % 2 == 0) {
            evenend ++;
            eend.is(i);
        }
        else {
            oddend ++;
            oend.is(i);
        }
    }
    
    f0r (i, 0, N - 1) {
        if (i % 2 == 0) {
            if (oddend > 0) {
                oddend --;
            }
            else {
                evenend --;
            }
        }
        else {
            if (evenend > 0) {
                evenend --;
            }
            else {
                oddend --;
            }
        }
    }
 
    
    if (oddend == 1) {
        cout << "Second" << endl;
        rem();
        while (!eend.empty() || !oend.empty()) {
            if (!eend.empty()) {
                ll pos = *eend.begin();
                eend.erase(eend.begin());
                cout << pos + 1 << endl;
            } else {
                ll pos = *oend.begin();
                oend.erase(oend.begin());
                cout << pos + 1 << endl;
            }
            if (!eend.empty() || !oend.empty()) {
                rem();
            }
        }
    }
    else {
        cout << "First" << endl;
        while (!eend.empty() || !oend.empty()) {
            if (!oend.empty()) {
                ll pos = *oend.begin();
                oend.erase(oend.begin());
                cout << pos + 1 << endl;
            } else {
                ll pos = *eend.begin();
                eend.erase(eend.begin());
                cout << pos + 1 << endl;
            }
            if (!eend.empty() || !oend.empty()) {
                rem();
            }
        }
    }
}
 
int main () {
    cin >> T;
    while (T --) {
        tc ();
    }
}
