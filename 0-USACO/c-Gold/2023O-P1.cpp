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

int N, M, C[100000], F[100000], S[100000];
vi conn[100000], held1[100000], held2[100000];
bool visited1[100000], keyed1[100000], visited2[100000], keyed2[100000];

void solve () {
	cin >> N >> M;
	f0r (i, 0, N) {
		cin >> C[i]; C[i] --;
		conn[i].clear();
		held1[i].clear();
		held2[i].clear();
		visited1[i] = (i == 0);
		keyed1[i] = 0;
		visited2[i] = (i == 0);
		keyed2[i] = 0;
	}
	f0r (i, 0, N) {
		cin >> S[i];
		S[i] --;
	}
	f0r (i, 0, N) {
		cin >> F[i];
		F[i] --;
	}
	f0r (i, 0, M) {
		int a, b; cin >> a >> b;
		a --; b --;
		conn[a].pb(b);
		conn[b].pb(a);
	}

	// CAN GRAB ALL KEYS
	queue<int> q; q.push(0); visited1[0] = 1;
	while (!q.empty()) {
		int pos = q.front();
		q.pop();

		int ke = S[pos];
		if(!keyed1[ke]) {
			keyed1[ke] = 1;
			for (auto h : held1[ke]) {
				if(!visited1[h]) {
					q.push(h);
					visited1[h] = 1;
				}
			}
		}
		for (auto c : conn[pos]) {
			if(keyed1[C[c]]) {
				if(!visited1[c]) {
					q.push(c);
					visited1[c] = 1;
				}
			}
			else {
				held1[C[c]].pb(c);
			}
		}
	}
	f0r (i, 0, N) {
		if((!visited1[i]) && (S[i] != F[i])) {
			cout << "NO" << endl;
			return;
		} 
	}

	// CAN REVERSE ENGINEER
	q.push(0); visited2[0] = 1;
	while (!q.empty()) {
		int pos = q.front();
		q.pop();

		int ke = F[pos];
		if(!keyed2[ke]) {
			keyed2[ke] = 1;
			for (auto h : held2[ke]) {
				if(!visited2[h]) {
					q.push(h);
					visited2[h] = 1;
				}
			}
		}
		for (auto c : conn[pos]) {
			if(!visited1[c]) continue;
			if(keyed2[C[c]] || (C[c] == F[c])) {
				if((!visited2[c])) {
					q.push(c);
					visited2[c] = 1;
				}
			}
			else {
				held2[C[c]].pb(c);
			}
		}
	}
	f0r (i, 0, N) {
		if((!visited2[i]) && (S[i] != F[i])) {
			cout << "NO" << endl;
			return;
		} 
	}

	cout << "YES" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int T; cin >> T;
	while (T --) {
		solve ();
	}
}
