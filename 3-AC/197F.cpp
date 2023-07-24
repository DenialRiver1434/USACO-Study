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
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.size()
#include "bits/stdc++.h"
using namespace std;

int best[1000][1000], N, M, ans = 1e9;
vector<pair<int, char>> conn[1000];

int main () {
    cin >> N >> M;
    f0r (i, 0, M) {
        int a, b; char c;
        cin >> a >> b >> c;
        a --; b --;
        conn[a].pb(mp(b, c));
        conn[b].pb(mp(a, c));
    }
    f0r (i, 0, 1000) {
        f0r (j, 0, 1000) {
            best[i][j] = 1e9;
        }
    }
    best[0][N - 1] = 0;

    queue<tuple<int, int, int>> q;
    q.push({0, N - 1, 0});
    while (!q.empty()) {
        int start, end, dist;
        tie(start, end, dist) = q.front();
        q.pop();
        if(start == end) {
            ans = min(ans, 2 * dist);
            break;
        }
        if ((2 * dist) >= ans) {
            break;
        }

        for (auto cstart : conn[start]) {
            if(cstart.first == end) {
                ans = min(ans, 2 * dist + 1);
                break;
            }
            for (auto cend : conn[end]) {
                if(cstart.second == cend.second) {
                    int nstart = cstart.first, nend = cend.first;
                    if(best[nstart][nend] > (dist + 1)) {
                        best[nstart][nend] = dist + 1;
                        q.push({nstart, nend, dist + 1});
                    }
                }
            }
        }
    }
    if (ans == 1000000000) {
        cout << -1 << endl;
    }
    else cout << ans << endl;
}