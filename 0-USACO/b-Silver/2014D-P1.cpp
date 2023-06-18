#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

vector<int> conn[40000];
int dist0[40000], dist1[40000], distn[40000], B, E, P, N, M;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	ifstream fin; ofstream fout;
	fin.open("piggyback.in"); fout.open("piggyback.out");

	fin >> B >> E >> P >> N >> M;
	f0r (i, 0, M) {
		int a, b; fin >> a >> b;
		conn[a - 1].pb(b - 1);
		conn[b - 1].pb(a - 1);
	}
	f0r (i, 0, N) {
		dist0[i] = -1;
		dist1[i] = -1;
		distn[i] = -1;
	}
	dist0[0] = 0;
	dist1[1] = 0;
	distn[N - 1] = 0;
	
	queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int pos = q.front();
		q.pop();
		for (auto c : conn[pos]) {
			if(dist0[c] == -1) {
				q.push(c);
				dist0[c] = dist0[pos] + 1;
			}
		}
	}

	q.push(1);
	while(!q.empty()) {
		int pos = q.front();
		q.pop();
		for (auto c : conn[pos]) {
			if(dist1[c] == -1) {
				q.push(c);
				dist1[c] = dist1[pos] + 1;
			}
		}
	}

	q.push(N - 1);
	while(!q.empty()) {
		int pos = q.front();
		q.pop();
		for (auto c : conn[pos]) {
			if(distn[c] == -1) {
				q.push(c);
				distn[c] = distn[pos] + 1;
			}
		}
	}

	int best = 1e9;
	f0r (i, 0, N) {
		if(dist0[i] > 0 && dist1[i] > 0 && distn[i] > 0) {
			best = min(best, dist0[i] * B + dist1[i] * E + distn[i] * P);
		}
	}
	fout << best << endl;
}