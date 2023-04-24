#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define lll long long
#define vi vector<int>
#define si set<int>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define f0r(i, begin, end) for (int i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

const int lim = 1e9;
int N, best[2][1000][1000];
vi nums;

int main() {
	ifstream fin; ofstream fout;
	fin.open("cowrun.in"); fout.open("cowrun.out");

	fin >> N;
	if(N == 1) {
		int a; fin >> a;
		fout << abs(a) << endl;
		return 0;
	}
	int l = 0;
	f0r (i, 0, N) {
		int a; fin >> a;
		l += (a < 0);
		nums.pb(a);
	}
	f0r (i, 0, N) {
		f0r (j, 0, N) {
			best[0][i][j] = lim;
			best[1][i][j] = lim;
		}
	}
	sort(nums.begin(), nums.end());
	//best[0][l - 1][l] = nums[l] * N + (nums[l] - nums[l - 1]) * (N - 1);
	//best[1][l - 1][l] = -nums[l - 1] * N - (nums[l - 1] - nums[l]) * (N - 1);

	int s = 0, prev = 0;
	for (int left = l - 1; left >= 0; left --) {
		s += (prev - nums[left]) * (N - ((l - 1) - left));
		prev = nums[left];
		best[0][left][l - 1] = s;
	}
	s = 0, prev = 0;
	f0r (right, l, N) {
		s += (nums[right] - prev) * (N - right + l);
		prev = nums[right];
		best[1][l][right] = s;
	}

	for (int left = l - 1; left >= 0; left --) {
		f0r (right, l, N) {
			//if((left != (l - 1)) || (right != l)) {
				int remains = N - (right - left);
				best[0][left][right] = min(best[0][left + 1][right] + (nums[left + 1] - nums[left]) * remains, best[1][left + 1][right] + (nums[right] - nums[left]) * remains);
				best[1][left][right] = min(best[1][left][right - 1] + (nums[right] - nums[right - 1]) * remains, best[0][left][right - 1] + (nums[right] - nums[left]) * remains);
				best[0][left][right] = min(best[0][left][right], best[1][left][right] + (nums[right] - nums[left]) * remains);
				best[1][left][right] = min(best[1][left][right], best[0][left][right] + (nums[right] - nums[left]) * remains);
			//}
		}
	}
	fout << min(best[0][0][N - 1], best[1][0][N - 1]) << endl;
}