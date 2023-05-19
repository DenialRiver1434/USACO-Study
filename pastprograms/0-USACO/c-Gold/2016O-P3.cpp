#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define lll long long
#define f0r(i, begin, n) for (lll i = begin; i < n; i ++)
#define len(x) x.size()
#define vl vector<lll>
#define sl set<lll>
#define msl multiset<lll>
#define pl pair<lll, lll>
#define vpl vector<pair<lll, lll>>
#include <bits/stdc++.h>
using namespace std;

lll best[248][249], ans = 0, N;
const lll lim = -1e18;

int main() {
	ifstream fin; ofstream fout;
	fin.open("248.in"); fout.open("248.out");
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	
	fin >> N;
	f0r (i, 0, 248) {
		f0r (j, 0, 249) {
			best[i][j] = lim;
		}
	}

	f0r (i, 0, N) {
		lll a; fin >> a;
		best[i][i + 1] = a;
		ans = max(ans, a);
	}

	f0r (diff, 2, N + 1) {
		f0r (i, 0, N - diff + 1) {
			f0r (j, i + 1, i + diff) {
				if(best[i][j] == best[j][i + diff]) {
					best[i][i + diff] = max(best[i][i + diff], best[i][j] + 1);
					ans = max(ans, best[i][i + diff]);
				}
			}
		}
	}
	fout << ans << endl; 
}
