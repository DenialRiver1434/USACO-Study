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

	map<ll, ll> best;
	best[0] = 0;

	for (auto c : cows) { // from best to worst
		ll weight = c.first, talent = c.second;
		vector<ll> tosearch;
		for (auto b : best) {
			if(b.first >= M) break;
			tosearch.pb(b.first);
		}
		f0r (i, 0, tosearch.size() / 2) {
			swap(tosearch[i], tosearch[tosearch.size() / 2 - 1 - i]);
		}

		for (auto curweight : tosearch) {
			ll curtalent = best[curweight];

			if(best.find(curweight + weight) == best.end()) {
				best[curweight + weight] = talent + curtalent;
			}
		}
	}

	ll opt = 0;
	for (auto b : best) {
		if(b.first >= M) {
			opt = max(opt, (1000 * b.second) / b.first);
		}
	}
	fout << opt << endl;
}