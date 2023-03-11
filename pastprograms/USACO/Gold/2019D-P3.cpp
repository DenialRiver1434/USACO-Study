#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

int dist[26][26], region[26][100000]; // letter i, cost of K-region up to j
vector<int> inp;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	ifstream fin; ofstream fout;
	fin.open("cowmbat.in"); fout.open("cowmbat.out");

	int N, M, K; fin >> N >> M >> K;
	f0r (i, 0, N) {
		char a; fin >> a;
		inp.pb(int(a) - 97);
	}
	f0r (i, 0, M) {
		f0r (j, 0, M) fin >> dist[i][j];
	}

	// Floyd-Warshall
	f0r (k, 0, M) {
		f0r (i, 0, M) {
			f0r (j, 0, M) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	// Prefix sums pre-processing
	f0r (i, 0, M) {
		int c = 0;
		f0r (j, 0, N) {
			c += dist[inp[j]][i];
			region[i][j] = c;
		}
	}

	// DP
	int best[26][100000];
	f0r (i, 0, min(2 * K - 1, N)) {
		f0r (j, 0, M) {
			if(i == 0) {
				best[j][0] = dist[inp[0]][j];
			}
			else {
				best[j][i] = best[j][i - 1] + dist[inp[i]][j];
			}
		}
	}

	f0r (i, 2 * K - 1, N) {
		f0r (j, 0, M) {
			best[j][i] = best[j][i - 1] + dist[inp[i]][j];
			f0r (from, 0, M) {
				if(j == from) continue;
				best[j][i] = min(best[j][i], best[from][i - K] + region[j][i] - region[j][i - K]);
			}
		}
	}

	int b = 1e9;
	f0r (i, 0, M) {
		b = min(b, best[i][N - 1]);
	}
	fout << b << endl;
}