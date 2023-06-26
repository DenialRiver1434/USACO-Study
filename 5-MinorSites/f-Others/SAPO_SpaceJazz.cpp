#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (int i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

string inp;
int best[500][500];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> inp;
	int leng = inp.size();

	f0r (i, 0, leng) {
		f0r (j, 0, leng) {
			if(j >= i) best[i][j] = 1000000000;
			else best[i][j] = 0;
		}
	}

	f0r (pos, 0, leng) best[pos][pos] = 1;
	f0r (dist, 1, leng) {
		f0r (start, 0, leng - dist) {
			int end = start + dist;
			if(inp[start] == inp[end]) best[start][end] = min(best[start][end], best[start + 1][end - 1]);
			f0r (inter, start, end) best[start][end] = min(best[start][end], best[start][inter] + best[inter + 1][end]);
		}
	}
	cout << best[0][leng - 1] << endl; 
}
