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
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};
 
ll N;
V<ll> conn[200000];
PL bdist[200000], sdist[200000];
 
void dp (ll pos, ll pre) {
    bdist[pos] = sdist[pos] = {0LL, pos};
    for (auto c : conn[pos]) {
        if (c != pre) {
            dp(c, pos);
            if (bdist[pos].F < bdist[c].F + 1) {
                sdist[pos] = bdist[pos];
                bdist[pos] = {bdist[c].F + 1, c};
            }
            else if (sdist[pos].F < bdist[c].F + 1) {
                sdist[pos] = {bdist[c].F + 1, c};
            }
        }
    }
}
 
void dp2 (ll pos, ll pre) {
    if (pre != -1) {
        if (bdist[pre].S == pos) {
            if (bdist[pos].F < sdist[pre].F + 1) {
                sdist[pos] = bdist[pos];
                bdist[pos] = {sdist[pre].F + 1, pre};
            }
            else if (sdist[pos].F < sdist[pre].F + 1) {
                sdist[pos] = {sdist[pre].F + 1, pre};
            }
        }
        else {
            if (bdist[pos].F < bdist[pre].F + 1) {
                sdist[pos] = bdist[pos];
                bdist[pos] = {bdist[pre].F + 1, pre};
            }
            else if (sdist[pos].F < bdist[pre].F + 1) {
                sdist[pos] = {bdist[pre].F + 1, pre};
            }
        }
    }
    for (auto c : conn[pos]) {
        if (c != pre) {
            dp2 (c, pos);
        }
    }
}
 
int main () {
	cin >> N;
    f0r (i, 0, N - 1) {
        ll a, b; cin >> a >> b;
        conn[a - 1].pb(b - 1);
        conn[b - 1].pb(a - 1);
    }
    dp (0, -1);
    dp2 (0, -1);
 
    f0r (i, 0, N) {
        cout << bdist[i].F << " ";
    }
}