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

const lll MAX = 1e18;
lll best[500][500][2], arr[500], N;
bool pal[500][500];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N;
	f0r (i, 0, N) {
		cin >> arr[i];
		best[i][i][0] = best[i][i][1] = 1;
		pal[i][i] = 1;
	}

	for (lll i = N - 2; i >= 0; i --) {
		f0r (j, i + 1, N) {
			if((j - i) == 1) pal[i][j] = (arr[i] == arr[j]);
			else pal[i][j] = (arr[i] == arr[j]) && pal[i + 1][j - 1];

			best[i][j][0] = j - i + 1;
			best[i][j][1] = MAX;
			lll left = i, right = j, op;
			while (left <= right) {
				if(arr[left] == arr[right]) {
					if ((right - left) > 1) {
						best[i][j][0] = min(best[i][j][0], min(best[left + 1][right - 1][0] + 1, best[left + 1][right - 1][1]));
					}
					else {
						best[i][j][0] = min(best[i][j][0], 1LL);
					}
				}
				else break;
				left ++; right --;
			}
			f0r (k, i, j) {
				best[i][j][0] = min(best[i][j][0], best[i][k][0] + best[k + 1][j][0]);
				if(pal[i][k] || pal[k + 1][j]) best[i][j][1] = best[i][j][0];
			}
		}
	}
	cout << best[0][N - 1][0] << endl;
}