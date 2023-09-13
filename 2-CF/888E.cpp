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

ll N, M, ans = 0;
V<ll> nums;

int main () {
	cin >> N >> M;
	nums = V<ll>(N);
	cin >> nums;
	ll N2 = N / 2;

	V<ll> lhs, rhs;
	f0r (i, 0, 1 << N2) {
		ll s = 0;
		f0r (j, 0, N2) {
			if ((1 << j & i) > 0) {
				s += nums[j];
				s %= M;
			}
		}
		lhs.pb(s);
	}

	N2 += (N % 2);
	f0r (i, 0, 1 << N2) {
		ll s = 0;
		f0r (j, 0, N2) {
			if ((1 << j & i) > 0) {
				s += nums[j + N2 - (N % 2)];
				s %= M;
			}
		}
		rhs.pb(s);
	}
	sort(all(lhs));
	
	for (auto r : rhs) {
		ll target = M - r;
		auto overpos = lower_bound(all(lhs), target);
		overpos = prev(overpos);
		ans = max(ans, r + *overpos);
	}
	cout << ans << endl;
}
