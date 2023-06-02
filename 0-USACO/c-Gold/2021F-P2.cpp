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

const lll INF = 1e18;
lll best[300][301], N;
vector<lll> nums;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);

	cin >> N;
	f0r (i, 0, N) {
		lll a; cin >> a;
		nums.pb(a);
		best[i][i + 1] = 1;
	}

	f0r (diff, 2, N + 1) {
		f0r (start, 0, N - diff + 1) {
			lll end = start + diff;
			best[start][end] = INF;

			stack<int> lhs; 
			f0r (mid, start + 1, end) {
				best[start][end] = min(best[start][end], best[start][mid] + best[mid][end] - (nums[start] == nums[end - 1]));
			}
		}
	}
	cout << best[0][N] << endl;
}
