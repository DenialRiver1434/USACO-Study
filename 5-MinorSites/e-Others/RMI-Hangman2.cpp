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

const ll A = 257274504162904133, B = 1720921529140328231;
ll pref[1000005], powmod[1000005];
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
	ll N, M; cin >> N >> M;
	V<string> words(N);
	cin >> words;
	bitset<30000> ans;

	if (N < M) {
		f0r (i, 0, N) {
			f0r (j, 0, N) {
				if (i != j) {
					ll diff = 0;
					f0r (k, 0, M) {
						diff += words[i][k] != words[j][k];
					}
					if (diff <= 2) {
						ans[i] = 1;
						break;
					}
				}
			}
			cout << ans[i];
		}
	}
	else {
		V<PL> a;
		f0r (i, 0, N) {
			hsh(words[i]);
			f0r (j1, 0, M) {
				f0r (j2, j1 + 1, M) {
					if (j1 == 1 && j2 == 3) {
						cout << "";
					}
					ll hval = 0;
					hval += modmul(hashrange(0, j1), powmod[M - j1]);
					hval += modmul(hashrange(j1 + 1, j2), powmod[M - j2]);
					hval += hashrange(j2 + 1, M);
					hval %= B;
					if (hval < 0) hval += B;

					a.pb({hval, i});
				}
			}
		}
		sort(all(a));
		ll la = len(a);

		f0r (i, 1, la) {
			if (a[i - 1].F == a[i].F) {
				ans[a[i - 1].S] = ans[a[i].S] = 1;
			}
		}
		f0r (i, 0, N) {
			cout << ans[i];
		}
	}
	cout << '\n';
}

int main () {
	fastio;
	ll T; cin >> T;
	while (T --) {
		tc ();
	}
}