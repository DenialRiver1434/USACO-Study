#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

ll N, K;

int dist (int a, int b) {
	if (a < b) return b - a;
	else return b - a + N;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	ifstream fin; ofstream fout;
	fin.open("cbarn2.in"); fout.open("cbarn2.out");

	fin >> N >> K;
	ll arr[N];
	f0r (i, 0, N) fin >> arr[i];

	ll best[N][N][K + 1]; // best[a][b][c] -> best outcome for the range [a, b) with at least a door at a, and c doors total. If a >= b (3, 0, 2)
	f0r (i, 0, N) {
		f0r (j, 0, N) {
			f0r (k, 0, K + 1) {
				best[i][j][k] = 0;
			}
		}
	}

	// k = 1
	f0r (i, 0, N) {
		f0r (j, 0, N) {
			ll walked = 0;
			for (ll k = i; (k != j) || (walked == 0); k = (k + 1) % N) {
				best[i][j][1] += walked * arr[k];
				walked ++;
			}
		}
	}

	f0r (c, 2, K + 1) {
		f0r (a, 0, N) {
			f0r (b, 0, N) {
				ll optimal = 1e18;
				if(dist(a, b) <= c) {
					continue;
				}

				for (ll k = (a + 1) % N; k != b; k = (k + 1) % N) {
					optimal = min(optimal, best[a][k][1] + best[k][b][c - 1]);
				}
				best[a][b][c] = optimal;
			}
		}
	}
	
	ll ans = 1e18;
	f0r (i, 0, N) {
		ans = min(ans, best[i][i][K]);
	}
	fout << ans << endl;
}