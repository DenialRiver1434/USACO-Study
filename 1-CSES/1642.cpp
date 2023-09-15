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

ll N, X;
map<ll, PL> uno, dos;

int main () {
	cin >> N >> X;
	V<ll> nums(N); cin >> nums;
	f0r (i, 0, N) {
		f0r (j, i + 1, N) {
			ll s = nums[i] + nums[j];
			if (uno.find(s) == uno.end()) {
				uno[s] = {i, j};
			}
			else if (dos.find(s) == dos.end() && uno[s].S != j && uno[s].S != i && uno[s].F != j && uno[s].F != i) {
				dos[s] = {i, j};
			}

			if (uno.find(X - s) != uno.end()) {
				if (uno[X - s].F != i && uno[X - s].F != j && uno[X - s].S != i && uno[X - s].S != j) {
					cout << uno[X - s].F + 1 << " " << uno[X - s].S + 1 << " " << i + 1 << " " << j + 1 << endl;
					return 0;
				}
			}
			if (dos.find(X - s) != dos.end()) {
				if (dos[X - s].F != i && dos[X - s].F != j && dos[X - s].S != i && dos[X - s].S != j) {
					cout << dos[X - s].F + 1 << " " << dos[X - s].S + 1 << " " << i + 1 << " " << j + 1 << endl;
					return 0;
				}
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}