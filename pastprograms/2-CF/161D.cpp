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

sl conn[50002];
lll cnt[50002][501], N, K, TC = 0; 

void search(lll pos, lll prev) {
	lll tot[501];
	f0r (i, 0, 501) tot[i] = 0;
	for (auto c : conn[pos]) {
		if(c != prev) {
			search(c, pos);
			f0r (i, 0, 501) {
				tot[i] += cnt[c][i];
			}
		}
	}
	cnt[pos][0] = 1;
	f0r (i, 1, 501) {
		for (auto c : conn[pos]) {
			if(c != prev) {
				cnt[pos][i] += cnt[c][i - 1];
			}
		}
	}
	TC += cnt[pos][K];

	lll k = 1, ad = 0;
	for (auto c : conn[pos]) {
		if(c != prev) {
			f0r (i, 0, K - 1) {
				ad += cnt[c][i] * (tot[K - i - 2] - cnt[c][K - i - 2]);
			}
			k ++;
		}
	}
	ad /= 2;
	TC += ad;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);

	cin >> N >> K;
	f0r (i, 0, N - 1) {
		lll a, b; cin >> a >> b;
		conn[a - 1].is(b - 1);
		conn[b - 1].is(a - 1);
	}
	search(0, -1);
	cout << TC << endl;
}