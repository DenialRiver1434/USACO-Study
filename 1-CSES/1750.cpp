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
template<typename T> ostream& operator<<(ostream& out, pair<T, T>& a) {out << a.F << ' ' << a.S << endl; return out;};
 
const ll MAX_N = 2e5 + 5;
ll parent[MAX_N][30];
 
int main () {
    fastio;
    ll N, Q; cin >> N >> Q;
    f0r (i, 0, N) {
        cin >> parent[i][0];
        parent[i][0] --;
    }
 
    f0r (k, 1, 30) {
        f0r (i, 0, N) {
            ll pboss = parent[i][k - 1];
            parent[i][k] = parent[pboss][k - 1];
        }
    }
 
    f0r (i, 0, Q) {
        ll pos, d; cin >> pos >> d;
        pos --;
        f0r (k, 0, 30) {
            if ((1 << k & d) > 0) {
                pos = parent[pos][k];
            }
        }
        cout << pos + 1 << '\n';
    }
}