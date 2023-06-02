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
lll N, cnt[501][501], fact[501], choose[501][501];
string s;

lll powermod(lll base, lll exp) {
	base %= MOD;
	lll result = 1;
	while (exp > 0) {
		if (exp % 2 == 1) // if n is odd
			result = result * base % MOD;
		base = base * base % MOD;
		exp /= 2; // divide by two
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);

	cin >> s;
	N = len(s);
	if ((N % 2) == 1) {
		cout << 0 << endl;
		return 0;
	}

	fact[0] = 1;
	f0r (i, 1, 501) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
		f0r (j, 0, i + 1) {
			choose[i][j] = fact[i] * powermod(fact[j], MOD - 2);
			choose[i][j] %= MOD;
			choose[i][j] *= powermod(fact[i - j], MOD - 2);
			choose[i][j] %= MOD;
		}
	}

	f0r (i, 0, N + 1) {
		cnt[i][i] = 1;
	}
	for (lll diff = 2; diff <= N; diff += 2) {
		f0r (i, 0, N - diff + 1) {
			for (lll k = i + 2; k <= (i + diff); k += 2) {
				if(s[i] == s[k - 1]) {
					lll add = cnt[i + 1][k - 1] * cnt[k][i + diff];
					add %= MOD;
					add *= choose[diff / 2][(k - i) / 2];
					add %= MOD;

					cnt[i][i + diff] += add;
					cnt[i][i + diff] %= MOD;
				}
			}
		}
	}
	cout << cnt[0][N] << endl;
}