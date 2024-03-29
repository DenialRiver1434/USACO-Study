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
#define all(X) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000009
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

void tc () {
	ll N, K; cin >> N >> K;
	bool grid[N][N];
	memset(grid, 0, sizeof(grid));

	if (K % 2) {
		cout << "No" << endl;
		return;
	}

	if (N == 2) {
		if (K == 0) {
			cout << "Yes\n0 0\n0 0" << endl;
		}
		else if (K == 2) {
			cout << "Yes\n1 0\n0 1" << endl;
		}
		else {
			cout << "Yes\n1 1\n1 1" << endl;
		}
		return;
	}

	bool flop = (2 * K) > (N * N);
	if (flop) {
		K = N * N - K;
	}

	if (K == 2) {
		cout << "No" << endl;
		return;
	}

	if (K % 4 == 2) {
		K -= 6;
		grid[N - 3][N - 2] = grid[N - 3][N - 1] = grid[N - 2][N - 1] = grid[N - 2][N - 3] = grid[N - 1][N - 3] = grid[N - 1][N - 2] = 1;
	}
	f0r (i, 0, N / 2) {
		f0r (j, 0, N / 2) {
			if (K == 0) break;
			grid[2 * i][2 * j] = grid[2 * i + 1][2 * j] = grid[2 * i][2 * j + 1] = grid[2 * i + 1][2 * j + 1] = 1;
			K -= 4;
		}
		if (K == 0) break;
	}

	cout << "Yes" << endl;
	f0r (i, 0, N) {
		f0r (j, 0, N) {
			cout << (grid[i][j] ^ flop) << " ";
		}
		cout << endl;
	}
}

int main () {
	ll T; cin >> T;
	while (T --) {
		tc ();
	}
}