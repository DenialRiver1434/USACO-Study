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

ll N;
PL dest;
V<PL> nums;

int main () {
	cin >> N >> dest.F >> dest.S;

	V<ll> ans(N + 1, 0);
	f0r (i, 0, N) {
		ll a, b; cin >> a >> b;
		nums.pb({a, b});
	}
	
	ll N1 = N / 2;
	ll N2 = N1 + (N % 2);

	V<V<PL>> lhs(N1 + 1), rhs(N2 + 1);
	f0r (i, 0, 1 << N1) {
		PL s = {0, 0};
		ll bits = __builtin_popcountll(i);
		f0r (j, 0, N1) {
			if ((1 << j & i) > 0) {
				s.F += nums[j].F;
				s.S += nums[j].S;
			}
		}
		lhs[bits].pb(s);
	}
	f0r (i, 0, N1 + 1) {
		sort(all(lhs[i]));
	}

	f0r (i, 0, 1 << N2) {
		PL s = {0, 0};
		ll bits = __builtin_popcountll(i);
		f0r (j, 0, N2) {
			if ((1 << j & i) > 0) {
				s.F += nums[j + N1].F;
				s.S += nums[j + N1].S;
			}
		}
		PL miss = {dest.F - s.F, dest.S - s.S};
		rhs[bits].pb(miss);
	}
	f0r (i, 0, N2 + 1) {
		sort(all(rhs[i]));
	}

	f0r (i, 0, N1 + 1) {
		f0r (j, 0, N2 + 1) {
			ll li = len(lhs[i]), ri = len(rhs[i]), pos = 0;
			PL pre = {-2e9, -2e9};
			ll precost = 0;
			for (auto r : rhs[j]) {
				if (r == pre) {
					ans[i + j] += precost;
					continue;
				}
				pre = r;
				precost = 0;
				while (pos < li) {
					if (lhs[i][pos] > r) break;
					if (lhs[i][pos] == r) {
						precost ++;
					}
					pos ++;
				}
				ans[i + j] += precost;
			}
		}
	}

	f0r (i, 1, N + 1) {
		cout << ans[i] << endl;
	}
}
