#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

ll nums[500], best[500];
vector<tuple<ll, ll, ll>> potential;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);

	ll N; cin >> N;
	f0r (i, 0, N) {
		cin >> nums[i];
		ll sum = 0;
		for (ll j = i; j >= 0; j --) {
			sum += nums[j];
			potential.pb(mt(sum, j, i));
		}
		best[i] = 1e16;
	}

	sort(potential.begin(), potential.end());
	ll L = len(potential);
	f0r (i, 1, L) {
		ll X = abs(get<0>(potential[i]) - get<0>(potential[i - 1]));
		ll s0 = get<1>(potential[i - 1]), e0 = get<2>(potential[i - 1]);
		ll s1 = get<1>(potential[i]), e1 = get<2>(potential[i]); // INCLUSIVE
		f0r (j, min(s0, s1), max(e0, e1) + 1) {
			short c = 0;
			if((j >= s0) && (j <= e0)) c ++;
			if((j >= s1) && (j <= e1)) c ++;
			if(c == 1) best[j] = min(best[j], X);
		}
	}

	f0r (i, 0, N) cout << best[i] << endl;
}
