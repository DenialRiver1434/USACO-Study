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

ll N, tot = 0;
ll sn (ll x) {
	ll ret = x * (x + 1) / 2;
	return ret % MOD;
}
ll mul (ll x, ll y) {
	return (x * y) % MOD;
}

int main () {
	cin >> N;
	V<ll> H(N), W(N);
	cin >> H >> W;

	stack<PL> s;
	ll width = 0;
	f0r (i, 0, N) {
		ll height = H[i], nwidth = width;
		while (!s.empty()) {
			ll pheight, pwidth;
			tie(pheight, pwidth) = s.top();
			if (pheight >= height) {
				s.pop();
				tot += mul(sn(nwidth - pwidth) + mul(nwidth - pwidth, width - nwidth), sn(pheight - height) + mul(pheight - height, height));
				tot %= MOD;
				nwidth = pwidth;
			}
			else break;
		}
		s.push({height, nwidth});
		width += W[i];
		width %= MOD;
	}
	ll nwidth = width;
	while (!s.empty()) {
		ll pheight, pwidth;
		tie(pheight, pwidth) = s.top();
		s.pop();
		tot += mul(sn(nwidth - pwidth) + mul(nwidth - pwidth, width - nwidth), sn(pheight));
		tot %= MOD;
		nwidth = pwidth;
	}
	if (tot < 0) tot += MOD;
	cout << tot << endl;
}