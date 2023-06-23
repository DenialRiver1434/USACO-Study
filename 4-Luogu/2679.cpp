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

ll N, M, K, dp[2][201][201][2]; // 0 = not ended, 1 = ended 
const ll MOD = 1000000007;
string A, B;

int main() {
    cin >> N >> M >> K >> A >> B;
    A = 'a' + A; B = 'a' + B;

    dp[0][0][0][1] = 1; dp[1][0][0][1] = 1;
    for (int i = 1; i <= N; i ++) {
        f0r (j, 1, M + 1) {
            f0r (k, 1, K + 1) {
                if(A[i] == B[j]) { 
                    dp[i % 2][j][k][0] = (dp[(i + 1) % 2][j][k][0] + dp[(i + 1) % 2][j][k][1]) % MOD;
                    dp[i % 2][j][k][1] = (dp[(i + 1) % 2][j - 1][k][1] + dp[(i + 1) % 2][j - 1][k - 1][0] + dp[(i + 1) % 2][j - 1][k - 1][1]) % MOD;
                }
                else {
                    dp[i % 2][j][k][0] = (dp[(i + 1) % 2][j][k][0] + dp[(i + 1) % 2][j][k][1]) % MOD;
                    dp[i % 2][j][k][1] = 0;
                }
            }
        }
    }
    cout << (dp[N % 2][M][K][1] + dp[N % 2][M][K][0]) % MOD << endl;
}