#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define vl vector<ll>
#define sl set<ll>
#define msl multiset<ll>
#define pl pair<ll, ll>
#define vpl vector<pair<ll, ll>>
#define f0r(i, begin, end) for (int i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

int dp[1048576]; // 1048576
int ans = 21, N, L;
vector<pair<int, set<int>>> movies;

int main () {
    ifstream fin; ofstream fout;
    fin.open("movie.in"); fout.open("movie.out");
    fin >> N >> L;

    f0r (i, 0, N) {
        int a, b; fin >> a >> b;
        set<int> times;
        f0r (j, 0, b) {
            int c; fin >> c;
            times.is(c);
        }
        movies.pb(mp(a, times));
    }

    dp[0] = 0;
    f0r (i, 1, (1 << N)) {
        dp[i] = -1;

        f0r (j, 0, N) {
            if(((1 << j) & i) == 0) continue;
            if(dp[i - (1 << j)] < *movies[j].second.begin()) continue;
            
            auto pos = movies[j].second.lower_bound(dp[i - (1 << j)]);
            if(*pos > dp[i - (1 << j)]) pos = prev(pos);
            dp[i] = max(dp[i], *pos + movies[j].first);
        }

        if(dp[i] >= L) {
            ans = min(ans, __builtin_popcount(i));
        }
        // cout << i << " " << dp[i] << endl;
    }

    if(ans == 21) {
        fout << -1 << endl;
    }
    else {
        fout << ans << endl;
    }
}