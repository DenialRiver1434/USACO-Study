#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define lll long long
#define f0r(i, begin, n) for (int i = begin; i < n; i ++)
#define len(x) x.size()
#define vi vector<int>
#define vpi vector<pair<int, int>>
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
bool conn[21][21];
int N, cnt[2097152];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N;
	f0r (i, 0, N) {
		f0r (j, 0, N) cin >> conn[i][j];
	}
	cnt[0] = 1;
	f0r (i, 0, (1 << N) - 1) {
		if(cnt[i] == 0) continue;
		int process = 0;
		f0r (j, 0, N) process += (i & (1 << j)) > 0; 
		f0r (j, 0, N) {
			if(conn[process][j] && !(i & (1 << j))) {
				cnt[i + (1 << j)] += cnt[i];
				cnt[i + (1 << j)] %= MOD;
			}
		}
	}
	cout << cnt[(1 << N) - 1] << endl;
}