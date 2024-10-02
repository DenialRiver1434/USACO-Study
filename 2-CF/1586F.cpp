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
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

const ll MAX_N = 1000;
ll assign[MAX_N][MAX_N];
ll N, M;

ll color (ll left, ll right) {
	ll retcol;
	if (right - left > M) { // Split
		V<PL> groups;
		ll subleng = (right - left) / M;
		if ((right - left) % M > 0) subleng ++;
		ll lhs = left;
		while (lhs < right) {
			groups.pb({lhs, min(lhs + subleng, right)});
			lhs = min(lhs + subleng, right);
		}

		ll lg = len(groups);
		For (i, lg - 1, -1) {
			retcol = color(groups[i].F, groups[i].S) + 1;
		}
		f0r (i, 0, lg) {
			f0r (j, i + 1, lg) {
				ll l1 = groups[i].F, r1 = groups[i].S;
				ll l2 = groups[j].F, r2 = groups[j].S;
				f0r (x, l1, r1) {
					f0r (y, l2, r2) {
						assign[x][y] = retcol;
					}
				}
			}
		}
	}
	else {
		retcol = 1;
		f0r (i, left, right) {
			f0r (j, i + 1, right) {
				assign[i][j] = retcol;
			}
		}
	}
	return retcol;
}

int main () {
	cin >> N >> M;

	cout << color(0, N) << endl;

	f0r (i, 0, N) {
		f0r (j, i + 1, N) {
			cout << assign[i][j] << " ";
		}
	}
}