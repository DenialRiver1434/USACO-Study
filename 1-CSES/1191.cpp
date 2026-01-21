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
#define all(X) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000009
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};
template<typename T> istream& operator>>(istream& in, pair<T, T>& a) {in >> a.F >> a.S; return in;};
template<typename T> ostream& operator<<(ostream& out, pair<T, T>& a) {out << a.F << ' ' << a.S << '\n'; return out;};

const ll MAX_N = 2e5 + 5;
ll N, M, arr[MAX_N], pref[MAX_N], mend[MAX_N][30], passes[MAX_N][30];

ll sumrange (ll lhs, ll siz) {
    return pref[lhs + siz] - pref[lhs];
}

ll dist (ll pos, ll jumps) {
    ll rounds = 0;
    ll npos = pos;
    f0r (i, 0, 30) {
        if ((1 << i & jumps) > 0) {
            rounds += passes[npos][i];
            npos = mend[npos][i];
        }
    }
    return (npos - pos) + N * rounds;
}

int main () {
    fastio;
    cin >> N >> M;
    f0r (i, 0, N) {
        cin >> arr[i];
        pref[i + 1] = pref[i] + arr[i];
    }
    f0r (i, N, 2 * N) {
        pref[i + 1] = pref[i] + arr[i - N];
    }
    
    if (pref[N] <= M) {
        cout << 1 << endl;
        return 0;
    }

    f0r (i, 0, N) {
        ll lo = 0, hi = N;
        while (lo < hi) {
            ll mid = lo + (hi - lo + 1) / 2;
            if (sumrange(i, mid) <= M) lo = mid;
            else hi = mid - 1;
        }
        mend[i][0] = (i + lo) % N;
        passes[i][0] = (i + lo) >= N;
    }

    f0r (j, 1, 30) {
        f0r (i, 0, N) {
            ll dest = mend[i][j - 1];
            mend[i][j] = mend[dest][j - 1];
            passes[i][j] = passes[i][j - 1] + passes[dest][j - 1];
        }
    }
    
    ll ans = N;
    f0r (i, 0, N) {
        ll lo = 0, hi = N;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            if (dist(i, mid) >= N) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        ans = min(ans, lo);
    }
    cout << ans << endl;
}