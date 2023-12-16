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
 
ll T, N;
 
void tc () {
    cin >> N;
    V<ll> arr(N);
    cin >> arr;
    
    if (len(arr) % 2 == 1) {
        cout << 4 << endl;
        cout << 1 << " " << len(arr) << endl;
        cout << 2 << " " << len(arr) << endl;
        cout << 1 << " " << 2 << endl;
        cout << 1 << " " << 2 << endl;
    }
    else {
        cout << 2 << endl;
        cout << 1 << " " << len(arr) << endl;
        cout << 1 << " " << len(arr) << endl;
    }
    return;
}
 
int main () {
    cin >> T;
    while (T --) {
        tc ();
    }
}
