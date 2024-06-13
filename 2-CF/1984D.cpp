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

const ll A = 257274504162904133, B = 1720921529140328231;
ll pref[200005], powmod[200005], N;
ll nna[200005];
string S;
 
ll modmul (ll a, ll b) {
    __int128_t xa = a, xb = b;
    ll xm = (xa * xb) % B;
    if(xm < 0) xm += B;
    return xm;
}

void hsh (string s) {
    ll ls = len(s);
    pref[0] = s[0];
    powmod[0] = 1;
    f0r (i, 1, ls) {
        pref[i] = (modmul(pref[i - 1], A) + s[i]) % B;
        powmod[i] = modmul(powmod[i - 1], A);
    }
}

ll hashrange (ll a, ll b) {
    if(a == 0) {
        return pref[b - 1];
    }
    ll hs = (pref[b - 1] - modmul(pref[a - 1], powmod[b - a])) % B;
    if(hs < 0) hs += B;
    return hs;
}

void tc () {
	string S; cin >> S;
	hsh(S);
	N = len(S);
	
	nna[N] = 0;
	For (i, N - 1, -1) {
		if (S[i] != 'a') nna[i] = 0;
		else nna[i] = nna[i + 1] + 1;
	}

	if (nna[0] == N) {
		cout << N - 1 << endl;
		return;
	}
	
	// Don't safety if at last

	ll ans = 0;
	f0r (siz, 1, N - nna[0] + 1) { // Size of block
		ll safety = nna[0];
		ll pos = nna[0], hashval = hashrange(pos, pos + siz);
		pos += siz;

		bool fail = 0;
		while (true) {
			ll cx = nna[pos];
			pos += cx;
			if (pos >= N) break;
			safety = min(safety, cx);

			if ((pos + siz) > N) {
				fail = 1;
				break;
			}
			if (hashrange(pos, pos + siz) != hashval) {
				fail = 1;
				break;
			}

			pos += siz;
		}
		if (!fail) {
			ans += (1 + safety);
		}
	}
	cout << ans << endl;
}

int main () {
	ll T; cin >> T;
	while (T --) {
		tc ();
	}
}