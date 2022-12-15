#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, L, a, b, c, total = 0, T;
set<pair<int, int>> finishes; // time, dir
map<int, int> cowstodir;
vector<int> cows, lefts;
map<int, int> weights;

int main () {
	ifstream fin; ofstream fout;
	fin.open("meetings.in"); fout.open("meetings.out");

	fin >> N >> L;
	for (int i = 0; i < N; i ++) {
		fin >> a >> b >> c;
		cows.pb(b);
		weights[b] = a;
		total += a;
		if(c == 1) {
			finishes.is(mp(L - b, 1));
			cowstodir[b] = 1;
		}
		else {
			finishes.is(mp(b, -1));
			cowstodir[b] = -1;
			lefts.pb(b);
		}
	}
	sort(cows.begin(), cows.end());
	sort(lefts.begin(), lefts.end());

	int left = 0, right = N - 1, accum = 0;
	for (auto f : finishes) {
		if(f.second == 1) {
			accum += weights[cows[right --]];
		}
		else {
			accum += weights[cows[left ++]];
		}
		if((accum * 2) >= total) {
			T = f.first;
			break;
		}
	}
	
	int total = 0;
	for (auto c : cows) {
		if(cowstodir[c] == 1) {
			int pos = upper_bound(lefts.begin(), lefts.end(), (c + 2 * T)) - upper_bound(lefts.begin(), lefts.end(), c);
			total += (pos);
		}
	}
	fout << total;
}