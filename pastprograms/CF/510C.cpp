#define pb push_back
#define mp make_pair
#define mt make_tuple
#define is insert
#define lll long long
#define f0r(i, begin, n) for (int i = begin; i < n; i ++)
#define len(x) x.size()
#define vi vector<int>
#define vpi vector<pair<int, int>>
#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int N, indegree[26];
vector<int> conn[26];
vector<int> sorted;
bool alert = false;

void cmp (string a, string b) {
	int ub = min(len(a), len(b));
	f0r (i, 0, ub) {
		if(a[i] != b[i]) {
			indegree[int(b[i]) - 97] ++;
			conn[int(a[i]) - 97].pb(int(b[i]) - 97);
			return;
		}
	}
	if(len(a) > len(b)) alert = true;
}

void ts () {
	f0r (i, 0, 26) {
		if(indegree[i] == 0) q.push(i);
	}
	while(!q.empty()) {
		int pos = q.front();
		q.pop();
		sorted.pb(pos);
		for (auto c : conn[pos]) {
			if((--indegree[c]) == 0) q.push(c);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	string cur, prev;
	cin >> N >> prev;

	f0r (i, 1, N) {
		cin >> cur;
		cmp(prev, cur);
		if(alert) {
			cout << "Impossible" << endl;
			return 0;
		}
		prev = cur;
	}
	ts();
	if(len(sorted) < 26) cout << "Impossible" << endl;
	else {
		for (auto s : sorted) {
			cout << char(s + 97);
		}
	}
}