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
#define inf 1000000000LL
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

V<ll> Bpoints;

ll mdist (ll x) {
	ll bpos = lower_bound(all(Bpoints), x) - Bpoints.begin();
	ll bval = Bpoints[bpos];
	return bval - x + (len(Bpoints) - bpos - 1);
}

void tc () {
	Bpoints.clear();
	ll A, B, basec = 0; cin >> A >> B;
	while (A > B) {
		if (A % 2 == 0) {
			A /= 2;
		}
		else {
			A ++;
		}
		basec ++;
	}

	while (B > 0) {
		Bpoints.pb(B);
		if (B % 2 == 0) {
			B /= 2;
		}
		else {
			B --;
		}
	}
	reverse(all(Bpoints));

	ll ans = INF;
	ans = min(ans, basec + mdist(A));
	while (true) {
		if (A % 2 == 0) {
			A /= 2;
		}
		else {
			A ++;
		}
		basec ++;
		ans = min(ans, basec + mdist(A));
		if (A == 1) break; 
	}
	cout << ans << endl;
}

int main () {
	ll T; cin >> T;
	while (T --) {
		tc ();
	}
}
