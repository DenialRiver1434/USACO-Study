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

ll N, M, K, grid[20][20], tot = 0;
V<ll> arrivals[20]; // (i, N - i - 1)

int main () {
	cin >> N >> M >> K;
	f0r (i, 0, N) {
		f0r (j, 0, M) {
			cin >> grid[i][j];
		}
	}

	f0r (i, 0, 1 << (N - 1)) {
		ll posx = N - 1, posy = M - 1, s = grid[N - 1][M - 1];
		bool good = 1;
		f0r (j, 0, N - 1) {
			if ((1 << j & i) > 0) {
				posx --;
			}
			else {
				posy --;
			}
			if (posx < 0 || posy < 0) {
				good = 0;
				break;
			}
			s ^= grid[posx][posy];
		}
		if (!good) continue;
		arrivals[posx].pb(s);
	}

	f0r (i, 0, N) {
		sort(all(arrivals[i]));
	}

	f0r (i, 0, 1 << (M - 1)) {
		ll posx = 0, posy = 0, s = 0;
		bool good = 1;
		f0r (j, 0, M - 1) {
			s ^= grid[posx][posy];
			if ((1 << j & i) > 0) {
				posx ++;
			}
			else {
				posy ++;
			}
			if (posx >= N || posy >= M) {
				good = 0;
				break;
			}
		}
		if (!good) continue;

		ll target = K ^ s;
		tot += upper_bound(all(arrivals[posx]), target) - lower_bound(all(arrivals[posx]), target);
	}
	cout << tot << endl;
}