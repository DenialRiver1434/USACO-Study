#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	string a, b;
	cin >> a >> b;
	int N = len(a), M = len(b);
	int least[N + 1][M + 1]; 
	f0r (i, 0, N + 1) {
		f0r (j, 0, M + 1) {
			least[i][j] = 1e8;
		}
	}

	least[0][0] = 0;

	f0r (i, 0, N + 1) {
		f0r (j, 0, M + 1) {
			if (i > 0) {
				least[i][j] = min(least[i][j], least[i - 1][j] + 1); // Add
			}
			if (j > 0) {
				least[i][j] = min(least[i][j], least[i][j - 1] + 1); // Remove
			}
			if (i > 0 && j > 0) {
				least[i][j] = min(least[i][j], least[i - 1][j - 1] + (a[i - 1] != b[j - 1])); // Edit
			}
		}
	}

	cout << least[N][M] << endl;
}