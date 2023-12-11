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

ll N, M, Q, sset[4096], cnt[4096];
V<ll> arr;
ll dp[4096][101];

ll translated (string x) {
    ll tot = 0;
    f0r (j, 0, N) {
        if (x[j] == '1') {
            tot += 1 << (N - j - 1);
        }
    }
    return tot;
}

int main () {
    fastio;
    cin >> N >> M >> Q;
    f0r (i, 0, N) {
        ll a; cin >> a;
        arr.pb(a);
    }

    f0r (i, 0, 1 << N) {
        ll tc = 0;
        f0r (j, 0, N) {
            if (((1 << j) & i) > 0) {
                tc += arr[N - j - 1];
            }
        }
        sset[i] = tc;
    }

    f0r (i, 0, M) {
        string x; cin >> x;
        cnt[translated(x)] ++;
    }

    f0r (i, 0, 1 << N) {
        f0r (j, 0, 1 << N) {
            ll tot = sset[((1 << N) - j - 1) ^ i];
            if (tot > 100) continue;
            dp[i][tot] += cnt[j];
        }
        f0r (k, 1, 101) {
            dp[i][k] += dp[i][k - 1];
        }
    }
    
    f0r (i, 0, Q) {
        string a; ll b; cin >> a >> b;
        ll sp = translated(a);
        cout << dp[sp][b] << '\n';
    }
}