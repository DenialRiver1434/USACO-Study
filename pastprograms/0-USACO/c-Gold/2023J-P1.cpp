#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.length()
#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);

	ll L, R, N; 
	cin >> L >> R >> N;
	pair<ll, vector<ll>> instructions[N];
	ll power[26][N + 1]; // character, layer

	f0r (i, 0, N) {
		char a; cin >> a;
		string b; cin >> b;
		vector<ll> nums;

		for (char ch : b) {
			nums.pb(int(ch) - 97);
		}
		instructions[i] = mp(int(a) - 97, nums);
		f0r (j, 0, 26) {
			power[j][i] = 0;
		}
	}
	f0r (j, 0, 26) power[j][N] = 1;

	for (ll i = N - 1; i >= 0; i --) {
		ll typ = instructions[i].first; vector<ll> op = instructions[i].second;
		f0r (j, 0, 26) {
			if (j == typ) {
				for (auto o : op) {
					power[j][i] += power[o][i + 1];
					power[j][i] = min(power[j][i], R + 5);
				}
			}
			else power[j][i] = power[j][i + 1];
		}
	}

	vector<ll> current = {0}; // {2, 3, 5, 1, 2, 4, 5}
	f0r (i, 0, N) { // O(N * (R - L)) 
		ll moved = 0, debt = 0;
		vector<ll> newer;
		for (auto c : current) {
			moved += power[c][i];
			if (moved < L) {
				debt += power[c][i];
			}
			else {
				newer.pb(c);
			}
			if (moved >= R) break;
		}
		current.clear();
		for (auto n : newer) {
			if (n == (instructions[i].first)) {
				for (auto o : instructions[i].second) {
					current.pb(o);
				}
			}
			else current.pb(n);
		}
		L -= debt; R -= debt;
	}
	for (ll i = L - 1; i < R; i ++) {
		cout << char(current[i] + 97);
	}
	cout << endl;
}