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

ll N, P, Q;
V<tuple<ll, ll, ll>> cakes;
ll best = INF;
map<ll, ll> mincost;

int main () {
	cin >> N >> P >> Q;
	f0r (i, 0, N) {
		ll a, b, c; cin >> a >> b >> c;
		cakes.emplace_back(a, b, c);
	}

	ll N1 = N / 2;
	f0r (i, 1, 1 << N1) {
		ll offset = 0, cost = 0;
		f0r (j, 0, N1) {
			if ((1 << j & i) > 0) {
				offset -= get<0>(cakes[j]) * Q - get<1>(cakes[j]) * P;
				cost += get<2>(cakes[j]);
			}
		}
		if (mincost.find(offset) != mincost.end()) 
			mincost[offset] = min(mincost[offset], cost);
		else
			mincost[offset] = cost;
		
		if (offset == 0) {
			best = min(best, cost);
		}
	}

	ll N2 = N1 + N % 2;
	f0r (i, 1, 1 << N2) {
		ll offset = 0, cost = 0;
		f0r (j, 0, N2) {
			if ((1 << j & i) > 0) {
				offset += get<0>(cakes[j + N1]) * Q - get<1>(cakes[j + N1]) * P;
				cost += get<2>(cakes[j + N1]);
			}
		}
		if (mincost.find(offset) != mincost.end())
			best = min(best, mincost[offset] + cost);
		if (offset == 0) {
			best = min(best, cost);
		}
	}

	if (best == INF) {
		cout << -1 << endl;
	}
	else cout << best << endl;
}