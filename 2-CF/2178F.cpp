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
#define For(i, end, begin) for (ll i = end; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 998244353
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 2e5 + 5;

map<ll, V<ll>> adj;
bool color[MAX_N];
ll subsize[MAX_N];
V<ll> component;

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

ll process (ll cur, ll pre) {
    ll tots = 1, rem = 0;
    for (auto a : adj[cur]) {
        if (a != pre) {
            rem += process (a, cur);
            tots += subsize[a];
        }
    }

    subsize[cur] = tots;
    color[cur] = tots % 2;
    if (color[cur] == 0 && cur != 0) {
        component.pb(tots - rem);
        return tots;
    } else {
        return rem;
    }
}

void tc () {
    adj.clear();
    component.clear();

    ll N; cin >> N;
    f0r (i, 0, N - 1) {
        ll a, b; cin >> a >> b;
        a --; b --;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    subsize[0] = N;
    color[0] = (N % 2);

    process (0, -1);

    if (len(component) == 0) {
        cout << 1 << endl;
        return;
    }

    ll ts = N;
    for (auto c : component) {
        ts -= c;
    }
    
    // |M|
    ll ans = ts;
    // |G_1|^2 ... |G_k|^2
    for (auto c : component) {
        ans *= c;
        ans %= MOD;
        ans *= c;
        ans %= MOD;
    }
    // (k-1)!
    f0r (i, 1, len(component)) {
        ans *= i;
        ans %= MOD;
    }

    // (1/|G_1| + ...)
    ll ff = 0;
    for (auto c : component) {
        ff += powermod (c, MOD - 2);
        ff %= MOD;
    }
    ans *= ff;
    ans %= MOD;

    cout << ans << endl;
}

int main () {
    int T; cin >> T;
    while (T --) {
        tc ();
    }
}