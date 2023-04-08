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

int N, M;
vector<vi> inps;

priority_queue<int, vector<int>, greater<int> > q;
int indegree[100000];
vi conn[100000];
vector<int> sorted;

void ts () {
	sorted.clear();
	f0r (i, 0, N) {
		if(indegree[i] == 0) q.push(i);
	}
	while(!q.empty()) {
		int pos = q.top();
		q.pop();
		sorted.pb(pos);
		for (auto c : conn[pos]) {
			if((--indegree[c]) == 0) q.push(c);
		}
	}
}

bool test (int upto) {
	f0r (i, 0, upto) {
		int lencur = len(inps[i]);
		f0r (j, 1, lencur) {
			indegree[inps[i][j]] ++;
			conn[inps[i][j - 1]].pb(inps[i][j]);
		}
	}
	ts();
	bool ret = (len(sorted) == N);
	sorted.clear();
	f0r (i, 0, N) {
		indegree[i] = 0;
		conn[i].clear();
	}
	return ret;
}

int last_true(int lo, int hi) {
	lo--;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;
		if (test(mid)) lo = mid;
		else hi = mid - 1;
	}
	return lo;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	ifstream fin; ofstream fout;
	fin.open("milkorder.in"); fout.open("milkorder.out");

	cin >> N >> M;
	f0r (i, 0, M) {
		int mi; cin >> mi;
		vi temp;
		f0r (j, 0, mi) {
			int a; cin >> a;
			temp.pb(a - 1);
		}
		inps.pb(temp);
	}
	int upto = last_true(0, M);
	f0r (i, 0, upto) {
		int lencur = len(inps[i]);
		f0r (j, 1, lencur) {
			indegree[inps[i][j]] ++;
			conn[inps[i][j - 1]].pb(inps[i][j]);
		}
	}
	ts();
	for (auto s : sorted) {
		if(s != sorted[0]) cout << " "; 
		cout << s + 1;
	}
	out << endl;
}
