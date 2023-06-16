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
#include <bits/stdc++.h>
using namespace std;
string M, N;
ll lM, lN;
ll best[2005][2005]; // M x N
int main () {
    cin >> M >> N; lM = len(M), lN = len(N);
    f0r (i, 0, lM + 1) {
        best[i][0] = i;
    }
    f0r (i, 0, lN + 1) {
        best[0][i] = i;
    }
    f0r (i, 1, lM + 1) {
        f0r (j, 1, lN + 1) {
            best[i][j] = min(best[i - 1][j] + 1, min(best[i][j - 1] + 1, best[i - 1][j - 1] + (M[i - 1] != N[j - 1])));
        }
    }
    cout << best[lM][lN] << endl;
}
