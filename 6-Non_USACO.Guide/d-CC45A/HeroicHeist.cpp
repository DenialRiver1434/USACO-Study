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

const ll MAX_N = 2e3;
ll N;
V<PL> starships;
ll dp[MAX_N][MAX_N], ans = 0;

int main () {
	cin >> N;
    f0r (i, 0, N) {
        ll a, b; cin >> a >> b;
        starships.pb({a, b});
    }
    sort(all(starships));

    dp[0][0] = starships[0].S;
    f0r (i, 1, N) {
        For (j, i, -1) {
            ll ppos = starships[i].F - 2 * (starships[i].F - starships[j].F);
            ll apos = lower_bound(all(starships), make_pair(ppos, -1LL)) - starships.begin();
            dp[i][j] = dp[j][apos] + starships[i].S;
            
            if (j != i) {
                dp[i][j] = max(dp[i][j], dp[i][j + 1]);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    
    f0r (i, 0, N) {
        starships[i].F *= -1;
        f0r (j, 0, N) {
            dp[i][j] = 0;
        }
    }
    reverse(all(starships));

    dp[0][0] = starships[0].S;
    f0r (i, 1, N) {
        For (j, i, -1) {
            ll ppos = starships[i].F - 2 * (starships[i].F - starships[j].F);
            ll apos = lower_bound(all(starships), make_pair(ppos, -1LL)) - starships.begin();
            dp[i][j] = dp[j][apos] + starships[i].S;
            
            if (j != i) {
                dp[i][j] = max(dp[i][j], dp[i][j + 1]);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}