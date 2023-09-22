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

ll T, A, S, B;
ll cnt[4001][201], tot = 0;
V<ll> groups;

int main () {
	cin >> T >> A >> S >> B;
	V<ll> ants(A);
	cin >> ants;

	sort(all(ants));
	f0r (i, 0, 201) {
		groups.pb(upper_bound(all(ants), i) - lower_bound(all(ants), i));
	}

	cnt[0][0] = 1;
	f0r (j, 1, 201) {
		f0r (k, 0, groups[j] + 1) {
			f0r (i, k, A) {
				cnt[i][j] += cnt[i - k][j - 1];
				cnt[i][j] %= 1000000;
			}
		}
	}
	f0r (i, S, B + 1) {
		tot += cnt[i][200];
		tot %= 1000000;
	}
	cout << tot << endl;
}
