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
#define For(i, end, begin) for (ll i = end - 1; i >= begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 998244353
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); fin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;}; 

ll N, mod, dp[2][10001], P;
vector<ll> primes;

void SieveOfEratosthenes(ll n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (ll p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    f0r (i, 2, n + 1) {
        if(prime[i]) primes.push_back(i);
    }
}

int main () {
    fileread("exercise");
    fin >> N >> mod;
    SieveOfEratosthenes(N);
    P = len(primes);
    
    f0r (i, 0, N + 1) {
        dp[1][i] = 1;
    }
    f0r (i, 0, P) {
        f0r (j, 0, N + 1) {
            dp[i % 2][j] = dp[(i + 1) % 2][j];
            ll p = primes[i];
            while (p <= j) {
                dp[i % 2][j] += (dp[(i + 1) % 2][j - p] * p);
                dp[i % 2][j] %= mod;
                p *= primes[i];
            }
        }
    }

    fout << dp[(P - 1) % 2][N] << endl;
}