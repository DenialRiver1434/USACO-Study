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

MS<ll> nums;

int main () {
	ll N, a, b; cin >> N >> a >> b;
	nums.is(max(a, b));
	f0r (i, 1, N / 2) {
		ll a, b; cin >> a >> b;
		if (min(a, b) > *nums.begin()) {
			nums.erase(nums.begin());
			nums.is(a); nums.is(b);
		}
		else {
			nums.is(max(a, b));
		}
	}

	ll ans = 0;
	for (auto n : nums) ans += n;
	cout << ans << endl;
}