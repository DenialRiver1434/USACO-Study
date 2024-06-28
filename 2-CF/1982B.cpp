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

void tc () {
	ll x, y, k;
	cin >> x >> y >> k;
	
	while (x != 1) {
		ll dy = y - (x % y);
		if (k < dy) {
			cout << x + k << endl;
			return;
		}
		k -= dy;
		x += dy;
		
		while (x % y == 0) {
			x /= y;
		}

		if (k == 0) {
			cout << x << endl;
			return;
		}
	}

	ll pans = ((x + k - 1) % (y - 1)) + 1;
	cout << pans << endl;
}

int main () {
	ll T; cin >> T;
	while (T --) {
		tc ();
	}
}