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
#define INF 1000000000000000000LL
#define inf 1000000000LL
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 500;
ll N, distles[MAX_N][MAX_N], dist100[MAX_N][MAX_N], grid[MAX_N][MAX_N], tc = 0;

int main () {
	cin >> N;
	f0r (i, 0, N) {
		f0r (j, 0, N) {
			cin >> grid[i][j];
			if (grid[i][j] == 100) {
				dist100[i][j] = 0;
			}
			else if (j == 0) {
				dist100[i][j] = INF;
			}
			else {
				dist100[i][j] = min(INF, dist100[i][j - 1] + 1LL);
			}

			if (grid[i][j] < 100) {
				distles[i][j] = 0;
			}
			else if (j == 0) {
				distles[i][j] = INF;
			}
			else {
				distles[i][j] = min(INF, distles[i][j - 1] + 1LL);
			}
		}
	}

	f0r (i, 0, N) {
		f0r (j, 0, N) {
			ll d100 = dist100[i][j], dles = min(j + 1, distles[i][j]), c = 0;
			c += max(0LL, dles - d100);

			For (k, i - 1, -1) {
				d100 = min(dist100[k][j], d100);
				dles = min(distles[k][j], dles);
				c += max(0LL, dles - d100);
			}
			tc += c;
		}
	}
	cout << tc << endl;
}
