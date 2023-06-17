#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define vl vector<int>
#define sl set<int>
#define msl multiset<int>
#define pl pair<int, int>
#define vpl vector<pair<int, int>>
#define f0r(i, begin, end) for (int i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

int N, M, squares[355], moves[5], best[41][41][41][41];

int main () {
	cin >> N >> M;
	f0r (i, 0, N) {
		cin >> squares[i];
	}
	f0r (i, 0, M) {
		int a; cin >> a;
		moves[a] ++;
	}
	f0r (m1, 0, moves[1] + 1) {
		f0r (m2, 0, moves[2] + 1) {
			f0r (m3, 0, moves[3] + 1) {
				f0r (m4, 0, moves[4] + 1) {
					int pos = m1 + m2 * 2 + m3 * 3 + m4 * 4;
					if (m1 > 0) {
						best[m1][m2][m3][m4] = max(best[m1][m2][m3][m4], best[m1 - 1][m2][m3][m4]);
					}
					if (m2 > 0) {
						best[m1][m2][m3][m4] = max(best[m1][m2][m3][m4], best[m1][m2 - 1][m3][m4]);
					}
					if (m3 > 0) {
						best[m1][m2][m3][m4] = max(best[m1][m2][m3][m4], best[m1][m2][m3 - 1][m4]);
					}
					if (m4 > 0) {
						best[m1][m2][m3][m4] = max(best[m1][m2][m3][m4], best[m1][m2][m3][m4 - 1]);
					}
					best[m1][m2][m3][m4] += squares[pos];
				}
			}
		}
	}
	cout << best[moves[1]][moves[2]][moves[3]][moves[4]] << endl;
}