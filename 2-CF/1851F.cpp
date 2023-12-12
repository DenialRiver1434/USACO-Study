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

void tc () {
    ll N, M; cin >> N >> M;

    V<PL> arr(N);
    f0r (i, 0, N) {
        cin >> arr[i].F;
        arr[i].S = i;
    }
    sort(all(arr));

    PL bpair = {-1, -1};
    ll apos = -1;
    ll bpval = -INF;
    f0r (i, 0, N - 1) {
        ll val = ((1 << M) - arr[i].F - 1) ^ arr[i + 1].F;
        if (val > bpval) {
            bpval = val;
            bpair = {arr[i].S, arr[i + 1].S};
            apos = i;
        }
    }

    ll comp = 0;
    f0r (i, 0, M) {
        bool n1 = ((1 << i) & arr[apos].F) > 0;
        bool n2 = ((1 << i) & arr[apos + 1].F) > 0;
        if (!n1 && !n2) {
            comp += (1 << i);
        }
    }

    cout << bpair.F + 1 << " " << bpair.S + 1 << " " << comp << endl;
}

int main () {
    ll T; cin >> T;
    while (T --) {
        tc ();
    }
}