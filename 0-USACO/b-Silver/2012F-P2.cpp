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

ll N, K, fact[10000];

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

ll nCk (ll n, ll k) {
    if (n < k) return 0;
    if (k == 0 || (n == k)) return 1;
    ll c = fact[n];
    c = (c * powermod(fact[k], MOD - 2)) % MOD;
    c = (c * powermod(fact[n - k], MOD - 2)) % MOD;
    return c;
}

int main () {
    fact[0] = 1;
    f0r (i, 1, 10000) {
        fact[i] = (i * fact[i - 1]) % MOD;
    }

    cin >> N >> K;
    if (K == 1) {
        cout << 1;
        f0r (i, 1, N) {
            cout << 0;
        }
        return 0;
    }
    
    ll ma = 0;
    f0r (i, K, 10000) {
        if (nCk (i, K) > N) break;
        ma = i;
    }

    string ans = "";
    For (dig, ma + 1, 0) {
        if (N > nCk (dig - 1, K)) {
            ans += '1';
            N -= nCk (dig - 1, K);
            K --;
        }
        else {
            ans += '0';
        }
    }
    reverse(all(ans));
    while (ans.back() == '0') ans.pop_back();
    reverse(all(ans));
    cout << ans << endl;
}