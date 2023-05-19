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

const lll MOD = 1e9 + 7;
sl conn[200000];
lll cnt[200000][3], N, K; // 0 = black, 1 = white
short color[200000];

void search(lll pos, lll prev) {
	lll mdiff = 0;
	cnt[pos][0] = 1, cnt[pos][1] = 1, cnt[pos][2] = 1;
	if(color[pos] == 1) {
		cnt[pos][1] = 0;
		cnt[pos][2] = 0;
	}
	if(color[pos] == 2) {
		cnt[pos][0] = 0;
		cnt[pos][2] = 0;
	}
	if(color[pos] == 3) {
		cnt[pos][0] = 0;
		cnt[pos][1] = 0;
	}

	for (auto c : conn[pos]) {
		if(c != prev) {
			search(c, pos);
			cnt[pos][0] *= (cnt[c][1] + cnt[c][2]); cnt[pos][0] %= MOD;
			cnt[pos][1] *= (cnt[c][0] + cnt[c][2]); cnt[pos][1] %= MOD;
			cnt[pos][2] *= (cnt[c][0] + cnt[c][1]); cnt[pos][2] %= MOD;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	ifstream fin; ofstream fout;
	fin.open("barnpainting.in"); fout.open("barnpainting.out");

	fin >> N >> K;
	f0r (i, 0, N - 1) {
		lll a, b; fin >> a >> b;
		conn[a - 1].is(b - 1);
		conn[b - 1].is(a - 1);
		color[a] = 0;
	}
	color[N - 1] = 0;
	f0r (i, 0, K) {
		lll a, b; fin >> a >> b;
		color[a - 1] = b;
	}
	search(0, -1);
	fout << (cnt[0][0] + cnt[0][1] + cnt[0][2]) % MOD << endl;
}
