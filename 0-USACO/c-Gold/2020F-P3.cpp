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
#define INF 1000000000000000000LL
#define inf 1000000000
#define MOD 998244353
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 1e5;
ll N;
V<ll> siz[MAX_N], conn[MAX_N];
bool good[MAX_N];

ll dfs (ll pos, ll pre) {
    ll s = 0;
    for (auto c : conn[pos]) {
        if (c != pre) { 
            ll cs = dfs (c, pos) + 1; 
            s += cs;
            siz[pos].pb(cs);
        }
    }
    siz[pos].pb((N - 1) - s);
    return s;
}

int main () {
    fileread("deleg");

    V<ll> concern;

    fin >> N;
    f0r (i, 1, N) {
        if ((N - 1) % i == 0) {
            concern.pb(i);
            good[i] = 1;
        }
    }

    f0r (i, 0, N - 1) {
        ll a, b; fin >> a >> b;
        conn[a - 1].pb(b - 1);
        conn[b - 1].pb(a - 1);
    }
    dfs (0, -1);

    f0r (i, 0, N) {
        for (auto k : concern) {
            V<ll> ms;
            for (auto c : siz[i]) {
                if (c % k != 0) ms.pb(c % k);
            }
            sort(all(ms));
            ll l = 0;
            while (len(ms) - l > 1) {
                if ((ms[l] + ms[len(ms) - 1]) == k) {
                    ms.pop_back();
                    l ++;
                }
                else {
                    good[k] = 0;
                    break;
                }
            }
        }
    }

    f0r (i, 1, N) {
        fout << good[i];
    }
}