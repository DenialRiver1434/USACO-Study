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
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 1e5 + 10;
bool role[MAX_N];

void tc () {
	ll N; cin >> N;
	
	bool firstans, secans;
	role[0] = 1; 
	f0r (i, 1, N) {
		cout << "? " << i << " " << i + 1 << endl;
		bool x; cin >> x;

		if (i == 1) firstans = x;
		if (i == 2) secans = x;

		if (x) role[i] = role[i - 1];
		else role[i] = !role[i - 1];
	}
	// n - 1 moves

	// Check if imposter in first position
	cout << "? 2 1" << endl;
	bool x; cin >> x;
	if (x != firstans) {
		// Either Imp \in 1, 2

		cout << "? 3 2" << endl;
		bool x; cin >> x;

		if (x != secans) {
			cout << "! 2" << endl;
			return;
		} else {
			cout << "! 1" << endl;
			return;
		}
	}

	// Binsearch for imposter
	ll lo = 0, hi = N - 1;
	while (lo < hi) {
		ll mid = lo + (hi - lo + 1) / 2;

		cout << "? 1 " << mid + 1 << endl;
		bool x; cin >> x;
		x = !x; // Whether we got that mid, 0 are on diff teams
		bool defx = role[mid] ^ role[0]; // Whether we reported mid, 0 are on diff team

		if (defx == x) lo = mid;
		else hi = mid - 1;
	}
	cout << "! " << lo + 1 << endl;
}

int main () {
    ll T; cin >> T;
    while (T --) {
		tc ();
    }
}
