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
template<typename T> ostream& operator<<(ostream& out, pair<T, T>& a) {out << a.F << ", " << a.S << endl; return out;};
template<typename T> ostream& operator<<(ostream& out, tuple<T, T, T>& a) {out << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << endl; return out;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << endl; return out;};

const ll MAX = 1e6 + 5;
ll N, M, K, dp[MAX], distto[MAX], tot = 0;

ll powermod (ll base, ll exp, ll mod = MOD) {
	base %= mod;
	ll result = 1;
	while (exp > 0) {
		if (exp % 2 == 1) // if n is odd
			result = result * base % mod;
		base = base * base % mod;
		exp /= 2; // divide by two
	}
	return result;
}

int main () {
    fileread("spainting");
    fin >> N >> M >> K;
    
    dp[0] = M - 1;
    distto[0] = M - 1;
    ll rollsum = M - 1;
    f0r (pos, 1, MAX) {
        dp[pos] = (distto[pos - 1] * (M - 1)) % MOD;
        distto[pos] = (distto[pos - 1] * (M - 1) + rollsum) % MOD;
        rollsum += dp[pos];
        if (pos - K + 2 >= 0) {
            rollsum -= dp[pos - K + 2];
        }
    }

    f0r (sp, 0, N - K + 1) {
        ll extra = N - sp - K;
        ll cur = powermod(M, extra + 1);
        if (sp > 0) {
            cur *= distto[sp - 1];
            cur %= MOD;
        }
        tot += cur;
        tot %= MOD;
    }
    fout << tot << endl;
}