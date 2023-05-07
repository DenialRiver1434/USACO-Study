#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (int i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

int N, M; 
vector<int> conn[100000];
set<int> exits;
int adj[100000], bdist[100000], edist[100000];

const int INF = 1e9;

int dfs (int pos, int pre) {
	if(bdist[pos] >= edist[pos]) return 1;
	int c = 0;
	for (auto co : conn[pos]) {
		if(co != pre) c += dfs(co, pos);
	}
	return c;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	ifstream fin; ofstream fout;
	fin.open("atlarge.in"); fout.open("atlarge.out");

	fin >> N >> M; M --;
	f0r (i, 1, N) {
		int a, b; fin >> a >> b;
		conn[a - 1].pb(b - 1);
		conn[b - 1].pb(a - 1);
		adj[a - 1] ++; adj[b - 1] ++;
	}

	queue<int> q;
	f0r (i, 0, N) {
		if(adj[i] == 1) {
			exits.is(i);
			q.push(i);
			edist[i] = 0;
		}
		else edist[i] = INF;
		bdist[i] = INF;
	}
	bdist[M] = 0;
	
	while(!q.empty()) {
		int pos = q.front();
		q.pop();
		for (auto c : conn[pos]) {
			if(edist[c] == INF) {
				edist[c] = edist[pos] + 1;
				q.push(c);
			}
		}
	}
	q.push(M);
	while(!q.empty()) {
		int pos = q.front();
		q.pop();
		for (auto c : conn[pos]) {
			if(bdist[c] == INF) {
				bdist[c] = bdist[pos] + 1;
				q.push(c);
			}
		}
	}
	
	fout << dfs(M, -1) << endl; 
}
