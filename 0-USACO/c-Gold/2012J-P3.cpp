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
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 1e5;
ll N, M, totnode, toted;
bool passed[MAX_N];
V<ll> conn[MAX_N];

void dfs (ll pos) {
    if (passed[pos]) return;
    passed[pos] = 1;
    totnode ++; toted += len(conn[pos]);

    for (auto c : conn[pos]) {
        dfs (c);
    }
}

int main () {
    cin >> N >> M;
    f0r (i, 0, M) {
        ll a, b; cin >> a >> b;
        conn[a - 1].pb(b - 1);
        conn[b - 1].pb(a - 1);
    }

    ll tot = 1;
    f0r (i, 0, N) {
        if (!passed[i]) {
            totnode = 0; toted = 0;
            dfs (i);
            toted /= 2;
            if (toted > totnode) {
                tot = 0;
                break;
            }
            else if (toted == totnode) {
                tot = (tot * 2) % MOD;
            }
            else {
                tot = (tot * totnode) % MOD;
            }
        }
    }
    cout << tot << endl;
}