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

ll N, K;

int main () {
    cin >> N >> K;
    ll a, b, c, d, e, f; 
    cout << "and 1 2" << endl;
    cin >> a;
    cout << "or 1 2" << endl;
    cin >> b;
    cout << "and 2 3" << endl;
    cin >> c;
    cout << "or 2 3" << endl;
    cin >> d;
    cout << "and 3 1" << endl;
    cin >> e;
    cout << "or 3 1" << endl;
    cin >> f;
    ll s1 = a + b, s2 = c + d, s3 = e + f, s = (a + b + c + d + e + f) / 2;
    V<ll> arr = {s - s2, s - s3, s - s1};
    
    f0r (i, 3, N) {
        cout << "and " << i << " " << i + 1 << endl;
        cin >> a;
        cout << "or " << i << " " << i + 1 << endl;
        cin >> b;
        arr.pb((a + b) - arr[i - 1]);
    }
    sort(all(arr));
    cout << "finish " << arr[K - 1] << endl;
}