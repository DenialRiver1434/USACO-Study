#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, B, a, b;
map<int, int> ans;
map<int, vector<int>> snowtopos;
multiset<int> gaps, breakpos;

void dislink (int pos) {
	auto right = breakpos.lower_bound(pos);
	auto left = prev(right);
	breakpos.is(pos);
	gaps.erase(gaps.find(*right - *left));
	gaps.is(*right - pos); gaps.is(pos - *left);
}

int main() {
	ifstream fin; fin.open("snowboots.in");
	ofstream fout; fout.open("snowboots.out");

	fin >> N >> B;
	for (int i = 0; i < N; i ++) {
		fin >> a;
		if(snowtopos.find(a) != snowtopos.end()) snowtopos[a].pb(i);
		else snowtopos[a] = {i};
	}
	gaps.is(N - 1);
	breakpos.is(0); breakpos.is(N - 1);
	for (auto stp : snowtopos) {
		vector<int> free = stp.second;
		for (auto f : free) {
			if(f != 0 && f != (N - 1)) dislink(f);
		}
		ans[stp.first] = *gaps.rbegin();
	}
	for (int i = 0; i < B; i ++) {
		fin >> a >> b;
		auto pos = ans.lower_bound(a);
		if((*pos).first != a) pos --;
		fout << (b >= (*pos).second) << endl;
	}
}