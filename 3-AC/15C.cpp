#define pb push_back 
#define is insert
#define lb lower_bound
#define ll long long
#define vl vector<ll>
#define sl set<ll>
#define msl multiset<ll>
#define pl pair<ll, ll>
#define vpl vector<pair<ll, ll>>
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define For(i, end, begin) for (ll i = end; i > begin; i --) 
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) x.size()
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr);
#include <bits/stdc++.h> 
using namespace std;

bool grid[2001][2001];
int pref[2001][2001], horpref[2001][2001], verpref[2001][2001], N, M, Q;

int main () {
    fastio
    cin >> N >> M >> Q;
    f0r (i, 1, N + 1) {
        f0r (j, 1, M + 1) {
            char a; cin >> a;
            grid[i][j] = (a == '1');
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            horpref[i][j] = horpref[i][j - 1];
            verpref[i][j] = verpref[i - 1][j];
            if(grid[i][j]) {
                if((!grid[i - 1][j]) && (!grid[i][j - 1])) {
                    pref[i][j] ++;
                }
                if((grid[i - 1][j]) && (grid[i][j - 1])) {
                    pref[i][j] --;
                }
                horpref[i][j] += (!grid[i][j - 1]);
                verpref[i][j] += (!grid[i - 1][j]);
            }
        }
    }
    f0r (i, 0, Q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int base = pref[c][d] - pref[a][d] - pref[c][b] + pref[a][b];
        base += (horpref[a][d] - horpref[a][b] + verpref[c][b] - verpref[a][b]);
        base += grid[a][b];
        cout << base << endl;
    }
}