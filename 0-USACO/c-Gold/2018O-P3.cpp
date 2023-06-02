#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

ll N, M;

bool comp (pair<ll, ll> a, pair<ll, ll> b) {
	if(a.first == 0 && a.second == 0) return false;
	if(b.first == 0 && b.second == 0) return true;
	return (a.second * b.first) > (b.second * a.first); // If a is better than b
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	ifstream fin; ofstream fout; fin.open("talent.in"); fout.open("talent.out");

	fin >> N >> M;
	vector<pair<ll, ll>> cows;
	f0r (i, 0, N) {
		ll a, b; fin >> a >> b;
		cows.pb(mp(a, b));
	}
	sort(cows.begin(), cows.end(), comp);

	map<ll, ll> past;
	ll best[M];
	f0r (i, 0, M) best[i] = -1;
	best[0] = 0;

	f0r (i, 0, N) {
		ll movement = cows[i].first;
		for (ll j = M - 1; j >= movement; j --) {
			if(best[j - movement] > -1) best[j] = max(best[j], best[j - movement] + cows[i].second);
		}
		f0r (j, i + 1, N) {
			ll curmove = cows[j].first;
			f0r (k, max(0LL, M - curmove), M) {
				if(best[k] > -1) {
					if(past.find(k + curmove) != past.end()) {
						past[k + curmove] = max(past[k + curmove], cows[j].second + best[k]);
					}
					else {
						past[k + curmove] = cows[j].second + best[k];
					}
				}
			}
		}
	}

	ll opt = 0;
	for (auto b : past) {
		if(b.first >= M) {
			opt = max(opt, (1000 * b.second) / b.first);
		}
	}
	fout << opt << endl;
}
