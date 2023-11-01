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

const ll MAX_N = 5e3;

ll N, R, dp[3][MAX_N], ans[100000];
V<tuple<ll, ll, ll>> queries[MAX_N];

short pref[MAX_N][MAX_N + 1], comp[5000001];
V<ll> nums, decomp;

int main () {
    fileread("threesum");
    memset(comp, -1, sizeof(comp));

    fin >> N >> R;
    f0r (i, 0, N) {
        ll a; fin >> a;
        nums.pb(a);
        decomp.pb(a);
    }
    sort(all(decomp));

    f0r (i, 0, N) {
        ll n = decomp[i];
        comp[n + 2000000] = i;
        pref[i][0] = 0;
        f0r (j, 0, N) {
            pref[i][j + 1] = pref[i][j] + (n == nums[j]);
        }
    }

    f0r (i, 0, R) {
        ll a, b; fin >> a >> b;
        queries[b - a].pb({a - 1, b - 1, i});
    }

    f0r (diff, 2, N) {
        f0r (i, 0, N) {
            dp[2][i] = dp[1][i];
            dp[1][i] = dp[0][i];
            dp[0][i] = 0;
        }
        f0r (i, 0, N - diff) {
            ll rhs = i + diff;
            ll lx = nums[i], rx = nums[rhs];
            if (comp[2000000 - lx - rx] != -1) {
                dp[0][i] = pref[comp[2000000 - lx - rx]][rhs] - pref[comp[2000000 - lx - rx]][i + 1];
            } else {
                dp[0][i] = 0;
            }
            dp[0][i] += dp[1][i + 1];
            dp[0][i] += dp[1][i];
            dp[0][i] -= dp[2][i + 1];
        }
        for (auto q : queries[diff]) {
            ans[get<2>(q)] = dp[0][get<0>(q)];
        }
    }

    f0r (i, 0, R) {
        fout << ans[i] << endl;
    }
}