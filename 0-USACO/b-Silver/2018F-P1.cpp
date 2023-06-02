#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

ll L, N, fs, bs, space, a, b;
map<ll, ll> stops;
vector<ll> maximums;

int main() {
	ifstream fin; fin.open("reststops.in");
	ofstream fout; fout.open("reststops.out");
	fin >> L >> N >> fs >> bs;
	space = fs - bs;
	for (ll i = 0; i < N; i ++) {
		fin >> a >> b;
		stops[a] = b;
	}
	ll best = 0;
	auto i = stops.end();
	i --;
	while (true) {
		if((*i).second > best) {
			maximums.pb((*i).first);
			best = (*i).second;
		}
		if(i == stops.begin()) break;
		i --;
	}
	reverse(maximums.begin(), maximums.end());
	ll M = maximums.size();
	ll prev = 0, total = 0;
	for (auto m : maximums) {
		total += (m - prev) * stops[m];
		prev = m;
	}
	fout << total * space;
}