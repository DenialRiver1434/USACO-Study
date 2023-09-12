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
ll rowpref[200][200], verpref[200][200];

bool is_frame (ll ax, ll ay, ll bx, ll by) {
	if (ax > bx) swap(ax, bx);
	if (ay > by) swap(ay, by);
	ll hori = rowpref[ax][by] + rowpref[bx][by];
	if (ay > 0) {
		hori -= (rowpref[ax][ay - 1] + rowpref[bx][ay - 1]);
	}
	ll vert = verpref[bx][ay] + verpref[bx][by];
	if (ax > 0) {
		vert -= (verpref[ax - 1][ay] + verpref[ax - 1][by]);
	}
	return hori + vert == 0;
}

int main () {
	fileread("fortmoo");

	fin >> N >> M;
	f0r (i, 0, N) {
		f0r (j, 0, M) {
			char x; fin >> x;
			rowpref[i][j] = verpref[i][j] = (x == 'X');
			if (j > 0) rowpref[i][j] += rowpref[i][j - 1];
			if (i > 0) verpref[i][j] += verpref[i - 1][j];
		}
	}

	f0r (row1, 0, N) {
		f0r (row2, row1 + 1, N) {
			V<ll> good;
			f0r (j, 0, M) {
				if (is_frame(row1, j, row2, j)) {
					good.pb(j);
				}
			}
			ll G = len(good);

			ll rhs = 0;
			f0r (lhs, 0, G) {
				while (rhs < G - 1) {
					rhs ++;
					if (!is_frame(row1, good[lhs], row2, good[rhs])) {
						rhs --;
						break;
					}
				}
				ans = max(ans, (good[rhs] - good[lhs] + 1) * (row2 - row1 + 1));
			}
		}
	}
	fout << ans << endl;
}