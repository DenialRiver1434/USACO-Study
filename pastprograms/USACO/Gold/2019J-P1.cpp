#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

const ll MOD = 1e9 + 7;
ll N, M, K;

ll powermod(ll base, ll exp) {
	base %= MOD;
	ll result = 1;
	while (exp > 0) {
		if (exp % 2 == 1) // if n is odd
			result = result * base % MOD;
		base = base * base % MOD;
		exp /= 2; // divide by two
	}
	return result;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	ifstream fin; ofstream fout; fin.open("poetry.in"); fout.open("poetry.out");

	fin >> N >> M >> K;
	ll count[K + 1], possible[N + 1]; // count result of DP, possible stores number of ways for each rhyme type
	map<ll, vector<ll>> rhymes;
	vector<ll> coins;
	set<int> sec;

	count[0] = 1;
	f0r (i, 1, K + 1) count[i] = 0;

	f0r (i, 0, N) {
		ll a, b; fin >> a >> b;
		rhymes[b].pb(a);
		coins.pb(a);
		sec.is(b);
	}
	f0r (i, 0, K + 1) {
		for (auto c : coins) {
			if ((i + c) <= K) {
				count[i + c] += count[i];
				count[i + c] %= MOD;
			}
		}
	}
	for (auto p : rhymes) {
		ll typ = p.first, total = 0;
		vector<ll> nums = p.second;
		for (auto n : nums) {
			total += count[K - n];
			total %= MOD;
		}
		possible[typ] = total;
	}

	map<char, ll> counts;
	f0r (i, 0, M) {
		char a; fin >> a;
		counts[a] ++;
	}
	ll c = 1;
	for (auto co : counts) {
		ll siz = co.second, tot = 0;
		for (auto s : sec) {
			tot += powermod(possible[s], siz);
			tot %= MOD;
		}
		if (tot > 0) {
			c *= tot;
			c %= MOD;
		}
	}
	fout << c << endl;
}