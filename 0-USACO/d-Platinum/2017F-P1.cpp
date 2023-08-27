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
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define For(i, end, begin) for (ll i = end; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0LL); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

Tree<ll> above, below;

ll N;
stack<ll> nums;
ll pos[100005], baseline = 0, best = INF;

int main () {
	fileread("mincross");

	fin >> N;
	V<int> a = V<int>(N), b = V<int>(N);
	fin >> b >> a;
	f0r (i, 0, N) {
		pos[b[i]] = i;
	}
	f0r (i, 0, N) {
		ll x = a[i];
		nums.push(pos[x]);
		above.is(-pos[x]);
		below.is(pos[x]);
		baseline += above.order_of_key(-pos[x]);
	}
	best = baseline;

	f0r (i, 0, N) {
		ll t = nums.top();
		nums.pop();
		baseline -= above.order_of_key(-t);
		baseline += below.order_of_key(t);
		best = min(best, baseline);
	}

	swap (a, b);
	above.clear(); below.clear();
	baseline = 0;
	f0r (i, 0, N) {
		pos[b[i]] = i;
	}
	f0r (i, 0, N) {
		ll x = a[i];
		nums.push(pos[x]);
		above.is(-pos[x]);
		below.is(pos[x]);
		baseline += above.order_of_key(-pos[x]);
	}

	f0r (i, 0, N) {
		ll t = nums.top();
		nums.pop();
		baseline -= above.order_of_key(-t);
		baseline += below.order_of_key(t);
		best = min(best, baseline);
	}
	fout << best << endl;
}