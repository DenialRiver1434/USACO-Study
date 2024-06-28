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
#define MOD 998244353
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

void tc () {
	ll N, M, k; cin >> N >> M >> k;
	V<V<ll>> arr(N), cnt(N), cntdp(N);
	f0r (i, 0, N) {
		f0r (j, 0, M) {
			ll a; cin >> a;
			arr[i].pb(a);
			cnt[i].pb(0);
			cntdp[i].pb(0);
		}
	}

	ll difftot = 0;

	f0r (i, 0, N) {
		f0r (j, 0, M) {
			char a; cin >> a;
			if (a == '1') {
				cnt[i][j] = 1;
				difftot += arr[i][j];
			}
			else {
				cnt[i][j] = -1;
				difftot -= arr[i][j];
			}
		}
	}

	f0r (i, 0, N) {
		f0r (j, 0, M) {
			cntdp[i][j] = cnt[i][j];

			if (i > 0) cntdp[i][j] += cntdp[i - 1][j];
			if (j > 0) cntdp[i][j] += cntdp[i][j - 1];
			if (i > 0 && j > 0) cntdp[i][j] -= cntdp[i - 1][j - 1];
		}
	}

	ll tgcd = -1;
	f0r (i, 0, N - k + 1) {
		f0r (j, 0, M - k + 1) {
			ll cnttot = cntdp[i + k - 1][j + k - 1];
			if (i > 0) cnttot -= cntdp[i - 1][j + k - 1];
			if (j > 0) cnttot -= cntdp[i + k - 1][j - 1];
			if (i > 0 && j > 0) cnttot += cntdp[i - 1][j - 1];

			if (cnttot == 0) continue;
			else if (tgcd == -1) {
				tgcd = abs(cnttot);
			}
			else {
				tgcd = gcd(tgcd, abs(cnttot));
			}
		}
	}

	if (difftot == 0) {
		cout << "YES" << endl;
	}
	else if (tgcd == -1) {
		cout << "NO" << endl;
	}
	else if (difftot % tgcd == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main () {
	ll T; cin >> T;
	while (T --) {
		tc ();
	}
}