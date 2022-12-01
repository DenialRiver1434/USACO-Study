#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, a;
set<int> lasts;
map<int, vector<int>> record;
map<int, int> backtofront;
vector<int> order;

int main() {
	cin >> N;
	for (int i = 0; i < N; i ++) {
		cin >> a;
		if(!lasts.empty()) {
			if(*lasts.begin() > a) {
				vector<int> starter = {a};
				record[a] = starter;
				lasts.is(a);
				backtofront[a] = a;
			}
			else {
				auto pos =  *(--lasts.lower_bound(a));
				int leader = backtofront[pos];
				backtofront[a] = leader;
				record[leader].pb(a);
				lasts.erase(pos);
				lasts.is(a);
			}
		}
		else {
			vector<int> starter = {a};
			record[a] = starter;
			lasts.is(a);
			backtofront[a] = a;
		}
		order.pb(a);
	}

	for (auto i : order) {
		if(record.find(i) != record.end()) {
			auto found = record[i];
			for (auto c : found) {
				cout << c << " ";
			}
			cout << endl;
		}
	}
}