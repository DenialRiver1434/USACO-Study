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

vi revconn[100000];
int N, M, outdegree[100000], assignment[100000], reas[100000];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> N >> M;
	f0r (i, 0, M) {
		int a, b; cin >> a >> b;
		revconn[b - 1].pb(a - 1);
		outdegree[a - 1] ++;
	}
	priority_queue<int> pq;
	f0r (i, 0, N) {
		if(outdegree[i] == 0) {
			pq.push(i);
		}
	}
	int processing = N - 1;
	while (processing > 0) {
		int pos = pq.top();
		pq.pop();
		assignment[pos] = (processing --);
		for (auto r : revconn[pos]) {
			outdegree[r] --;
			if(outdegree[r] == 0) pq.push(r);
		}
	}
	f0r (i, 0, N) {
		reas[assignment[i]] = i + 1;
	}
	f0r (i, 0, N) {
		cout << reas[i] << " ";
	}
}
