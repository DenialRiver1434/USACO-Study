#include <bits/stdc++.h> 
using namespace std;
#define pb push_back 
#define is insert
#define lb lower_bound
#define ll long long
#define V vector
#define MS multiset
#define PL pair<int, int>
#define F first
#define S second
#define PQ priority_queue
#define f0r(i, begin, end) for (int i = begin; i < end; i ++) 
#define For(i, end, begin) for (int i = end - 1; i >= begin; i --) 
#define aint(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (int)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); fin.tie(nuintptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

int N, M;
vector<int> a, b, pref;
bool dp[1048576];
pair<int, int> reachval[20001], reachconfig[1048576];

int main () {
    cin >> N >> M;
    a = vector<int>(N); b = vector<int>(M);
    cin >> a >> b;
    pref.pb(0);
    f0r (i, 0, len(a)) {
        pref.pb(a[i] + pref[i]);

        f0r (j, pref[i], pref[i + 1]) {
            reachval[j] = {i, a[i] - (j - pref[i])};
        }
    }
    reachval[pref[len(a)]] = {N, -2};
    f0r (i, pref[len(a)] + 1, 20001) {
        reachval[i] = {-1, -1};
    }

    f0r (i, 0, (1 << M)) {
        int tot = 0;
        f0r (j, 0, M) {
            if((1 << j & i) > 0) {
                tot += b[j];
            }
        }
        reachconfig[i] = reachval[tot];
    }

    dp[0] = 1;
    f0r (i, 1, (1 << M)) {
        if(reachconfig[i].F == -1) continue;
        f0r (j, 0, M) {
            if((1 << j & i) > 0) {
                int alt = i - (1 << j);
                if (dp[alt] && (reachconfig[alt].S >= b[j])) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        if(dp[i] && (reachconfig[i].S == -2)) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}