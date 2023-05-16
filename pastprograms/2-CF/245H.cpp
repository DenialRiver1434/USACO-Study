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
 
bool works[5000][5001];
lll cnt[5000][5001], N, Q;
string inp;
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
 
	cin >> inp;
	N = len(inp);
	f0r (i, 0, N) {
		cnt[i][i + 1] = 1;
		works[i][i + 1] = 1;
		works[i][i] = 1;
	}
 
	f0r (diff, 2, N + 1) {
		f0r (start, 0, N - diff + 1) {
			lll end = start + diff;
			works[start][end] = works[start + 1][end - 1] && (inp[start] == inp[end - 1]);
		}
	}
 
	f0r (diff, 2, N + 1) {
		f0r (start, 0, N - diff + 1) {
			lll end = start + diff;
			cnt[start][end] = works[start][end] + cnt[start][end - 1] + cnt[start + 1][end] - cnt[start + 1][end - 1];
		}
	}
 
	cin >> Q;
	f0r (i, 0, Q) {
		lll a, b; cin >> a >> b;
		cout << cnt[a - 1][b] << '\n';
	}
}
