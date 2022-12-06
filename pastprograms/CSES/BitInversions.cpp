#define pb push_back
#define mt make_tuple
#define is insert
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int N, M, a;
string inp;
set<int> starts;
multiset<int> substrings;

void change(int a) {
	if (a == 0 || a == inp.size()) return;
	auto itr = starts.find(a);
	if(itr == starts.end()) { // a not in set
		starts.is(a);
		itr = starts.find(a);
		int left = *prev(itr), right = *next(itr);
		substrings.erase(substrings.find(right - left));
		substrings.is(a - left); substrings.is(right - a);
	}
	else {
		int left = *prev(itr), right = *next(itr);
		substrings.erase(substrings.find(a - left)); substrings.erase(substrings.find(right - a));
		substrings.is(right - left);
		starts.erase(a);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> inp;
	N = inp.size();
	char prev = inp[0];
	starts.is(0);
	for (int i = 1; i < N; i ++) {
		if(inp[i] != prev) {
			prev = inp[i];
			substrings.is(i - *starts.rbegin());
			starts.is(i);
		}
	}
	substrings.is(N - *starts.rbegin());
	starts.is(N);

	cin >> M;
	while (M --) {
		cin >> a;
		change(a);
		change(a - 1);
		cout << *substrings.rbegin() << " ";
	}
}