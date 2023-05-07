#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

vector<ll> conn[100000];
set<ll> found, start, cinish;
vector<set<ll>> middles;
bool searched[100000];
ll T, N, M, a, b;

ll optimizedist(ll num) {
	num = abs(num);
	if((num % 2) == 1) {
		ll less = num / 2;
		return (less * less) + ((less + 1) * (less + 1));
	}
	else {
		ll less = num / 2;
		return (less * less) * 2;
	}
}

void dfs(ll pos) {
	if(!searched[pos]) {
		searched[pos] = true;
		found.is(pos);
		for (auto c : conn[pos]) dfs(c);
	}
}

int main() {
	cin >> T;
	while(T --) {
		cin >> N >> M;
		for (ll i = 0; i < N; i ++) {
			conn[i].clear();
			searched[i] = false;
		}
		middles.clear(); start.clear(); cinish.clear();
		for (ll i = 0; i < M; i ++) {
			cin >> a >> b;
			conn[a - 1].pb(b - 1);
			conn[b - 1].pb(a - 1);
		}

		found.clear();
		dfs(0);
		if(searched[N - 1]) {
			cout << 0 << endl;
			continue;
		}
		for (auto f : found) start.is(f);

		found.clear();
		dfs(N - 1);
		for (auto f : found) cinish.is(f);

		for (ll i = 0; i < N; i ++) {
			if(!searched[i]) {
				found.clear();
				dfs(i);
				set<ll> adds;
				for (auto f : found) adds.is(f);
				middles.pb(adds);
			}
		}
		ll best = 1e12;
		for (auto s : start) {
			auto pos = cinish.lower_bound(s);
			best = min(best, optimizedist(*pos - s));
			if(pos != cinish.begin()) {
				pos --;
				best = min(best, optimizedist(*pos - s));
			}
		}
			
		for (auto mid : middles) {
			ll bestleft = 1e12, besright = 1e12;
			for (auto m : mid) {
				auto pos = cinish.lower_bound(m);
				besright = min(besright, (*pos - m) * (*pos - m));
				if(pos != cinish.begin()) {
					pos --;
					besright = min(besright, (*pos - m) * (*pos - m));
				}

				if(m > *start.rbegin()) {
					auto pos = start.lower_bound(m);
					pos --;
					bestleft = min(bestleft, (*pos - m) * (*pos - m));
				}
				else {
					auto pos = start.lower_bound(m);
					bestleft = min(bestleft, (*pos - m) * (*pos - m));
					pos --;
					bestleft = min(bestleft, (*pos - m) * (*pos - m));
				}
			}
			best = min(best, bestleft + besright);
		}
		cout << best << endl;
	}
}