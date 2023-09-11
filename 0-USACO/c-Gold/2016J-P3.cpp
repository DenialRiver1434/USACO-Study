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

// HASHING STUFF
const ll A = 257274504162904133, B = 1720921529140328231;
ll powmod[1000005];
string S;
ll modmul (ll a, ll b) {
    __int128_t xa = a, xb = b;
    ll xm = (xa * xb) % B;
    if(xm < 0) xm += B;
    return xm;
}
ll hsh (string s) {
    ll tot = s[0];
    f0r (i, 1, len(s)) {
        tot = (modmul(tot, A) + s[i]) % B;
    }
	return tot;
}
// END HASHING STUFF

// 1 = up, 2 = right ->, 3 = down, 4 = left <-
PL typ (PL a, PL b) {
	if (a.F == b.F) {
		if (a.S < b.S) {
			return {b.S - a.S, 1};
		}
		return {a.S - b.S, 3};
	}
	else {
		if (a.F < b.F) {
			return {b.F - a.F, 2};
		}
		return {a.F - b.F, 4};
	}
}

ll mindist[200], N, ans = 0;
char turntyp[201];
V<PL> coords;
V<string> corners;
map<ll, ll> seen;

int main () {	
	fileread("lightsout");
	
	powmod[0] = 1;
	f0r (i, 0, 1000005) {
		powmod[i] = modmul(powmod[i - 1], A);
	}

	fin >> N;
	f0r (i, 0, N) {
		ll a, b; fin >> a >> b;
		coords.pb({a, b});
	}
	coords.pb(coords[0]);

	// Calculating mindist
	f0r (i, 1, N) {
		ll a = 0, b = 0;
		For (j, i, 0) {
			a += typ(coords[j], coords[j - 1]).F;
		}
		f0r (j, i, N) {
			b += typ(coords[j], coords[j + 1]).F;
		}
		mindist[i] = min(a, b);
	}

	// Calculating the corners
	turntyp[0] = turntyp[N] = 'e';
	f0r (i, 1, N) {
		ll typa = typ(coords[i - 1], coords[i]).S;
		ll typb = typ(coords[i], coords[i + 1]).S;
		if (typa == 1) {
			if (typb == 2) {
				turntyp[i] = 'n';
			}
			else {
				turntyp[i] = 't';
			}
		}
		if (typa == 2) {
			if (typb == 1) {
				turntyp[i] = 't';
			}
			else {
				turntyp[i] = 'n';
			}
		}
		if (typa == 3) {
			if (typb == 2) {
				turntyp[i] = 't';
			}
			else {
				turntyp[i] = 'n';
			}
		}
		if (typa == 4) {
			if (typb == 1) {
				turntyp[i] = 'n';
			}
			else {
				turntyp[i] = 't';
			}
		}
	}

	seen[hsh("e")] = 1;
	f0r (i, 1, N) {
		string s;
		s += turntyp[i];
		seen[hsh(s)] ++;
		f0r (j, i, N) {
			s += to_string(typ(coords[j], coords[j + 1]).F);
			s += turntyp[j + 1];
			seen[hsh(s)] ++;
		}
	}
	
	
	f0r (i, 1, N) {
		string s;
		s += turntyp[i];
		if (seen[hsh(s)] == 1) {
			continue; // No difference
		}
		ll edist = 0;
		f0r (j, i, N) {
			s += to_string(typ(coords[j], coords[j + 1]).F);
			s += turntyp[j + 1];
			edist += typ(coords[j], coords[j + 1]).F;
			if (seen[hsh(s)] == 1) {
				edist += mindist[j + 1];
				break;
			}
 		}
		ans = max(ans, edist - mindist[i]);
	}
	fout << ans << endl;
}
