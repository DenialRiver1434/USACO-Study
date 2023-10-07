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
#define INF 1000000000000000000LL
#define inf 1000000000
#define MOD 998244353
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 1e6;

ll fact[MAX_N + 1];

ll powermod (ll base, ll exp) {
	base %= MOD;
	ll result = 1;
	while (exp > 0) {
		if (exp % 2 == 1) // if n is odd
			result = result * base % MOD;
		base = base * base % MOD;
		exp /= 2; // divide by two
	}
	return result;
}

void tc (ll n) {
    f0r (k, 1, n + 1) {
        ll tot = 1;
        if (n - 2*k + 3 < 0) {
            cout << 0 << " ";
            continue;
        }
        tot *= fact[n - 2*k + 3];
        tot %= MOD;

        tot *= fact[2 * k - 2];
        tot %= MOD;

        if (k - 2 < 0) {
            cout << 0 << " ";
            continue;
        }
        if (n - k - 1 < k - 2) {
            cout << 0 << " ";
            continue;
        }
        tot *= fact[n - k - 1];
        tot %= MOD;
        tot *= powermod(fact[k - 2], MOD - 2);
        tot %= MOD;
        tot *= powermod(fact[(n - k - 1) - (k - 2)], MOD - 2);
        tot %= MOD;
        cout << tot << " ";
    }
}

int main () {
    fact[0] = 1;
    f0r (i, 1, MAX_N + 1) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    ll T; cin >> T;
    while (T --) {
        ll x; cin >> x;
        tc (x);
        cout << endl;
    }
}