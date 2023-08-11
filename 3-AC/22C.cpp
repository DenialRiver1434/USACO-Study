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
#define For(i, end, begin) for (ll i = end - 1; i >= begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); fin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

ll N;
V<ll> a, b;
set<ll> secure, temp;
bool searched[51];

void dfs (int pos) {
    for (auto s : secure) {
        if (!searched[pos % s]) {
            searched[pos % s] = 1;
            dfs (pos % s);
        }
    }
    for (auto s : temp) {
        if (!searched[pos % s]) {
            searched[pos % s] = 1;
            dfs (pos % s);
        }
    }
}

bool works () {
    f0r (i, 0, N) {
        f0r (i, 0, 51) searched[i] = 0;
        searched[a[i]] = 1;
        dfs(a[i]);
        if(!searched[b[i]]) return 0;
    }
    return 1;
}

int main () {
    cin >> N;
    a = b = V<ll>(N);
    cin >> a >> b;

    f0r (i, 1, 51) temp.is(i);
    if (!works()) {
        cout << -1 << endl;
        return 0;
    }
    For (i, 51, 1) {
        temp.erase(temp.find(i));
        if(!works()) secure.is(i);
    }
    ll tot = 0;
    for (auto s : secure) {
        tot += (1LL << s);
    }
    cout << tot << endl;
}