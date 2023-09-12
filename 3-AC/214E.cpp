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

void tc () {
	ll N; cin >> N;
	V<PL> queries;
	set<PL> ranges;
	f0r (i, 0, N) {
		ll a, b; cin >> a >> b;
		queries.pb({b + 1, a});
	}
	sort(all(queries));

	for (auto a : queries) {
		ll start, finish;
		tie(finish, start) = a;
		if (ranges.empty()) {
			ranges.is({start, start + 1});
			continue;
		}
		
		auto pos = ranges.lower_bound({start, INF});
		if (pos != ranges.begin()) {
			pos = prev(pos);
			start = max(start, (*pos).S);
		}
		if (start >= finish) {
			cout << "NO" << endl;
			return;
		}

		finish = start + 1;
		ranges.is({start, finish});
		pos = ranges.lower_bound({start, finish});
		if (next(pos) != ranges.end()) {
			if ((*next(pos)).F == finish) {
				ll nxt = (*next(pos)).S;
				ranges.erase(next(pos));
				ranges.erase(pos);
				ranges.is({start, nxt});
				finish = nxt;
			}
		}
		pos = ranges.lower_bound({start, finish});

		if (pos != ranges.begin()) {
			if ((*prev(pos)).S == start) {
				ll lo = (*prev(pos)).F;
				ranges.erase(prev(pos));
				ranges.erase(pos);
				ranges.is({lo, finish});
			}
		}
	}
	cout << "YES" << endl;
}

int main () {
    ll T; cin >> T;
	while (T --) {
		tc ();
	}
}
