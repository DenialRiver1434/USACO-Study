#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> xs, ys; // xs means all the x's on a certain y
map<tuple<int, int, int>, int> best; // x, y, dir (0 = +x, 1 = +y, 2 = -x, 3 = -y)
set<tuple<int, int, int>> searched;

const int INF = 1e9;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	ifstream fin; ofstream fout;
	fin.open("lasers.in"); fout.open("lasers.out");

	int N, xl, yl, xb, yb;
	fin >> N >> xl >> yl >> xb >> yb;

	xs[yb].is(xb);
	ys[xb].is(yb);
	deque<tuple<int, int, int>> q;
	f0r (i, 0, 4) {
		best[mt(xl, yl, i)] = 0;
		best[mt(xb, yb, i)] = INF;
		q.push_back(mt(xl, yl, i));
	}
	
	f0r (i, 0, N) {
		int a, b; fin >> a >> b;
		f0r (j, 0, 4) best[mt(a, b, i)] = INF;
		xs[b].is(a);
		ys[a].is(b);
	}

	while (!q.empty()) {
		int x, y, dir;
		tie(x, y, dir) = q.front();
		
		int us = best[mt(x, y, dir)];
		q.pop_front();

		if(dir == 0) {
			auto start = xs[y].lower_bound(x);
			while (start != xs[y].end()) {
				f0r (j, 0, 4) {
					if(searched.find(mt(*start, y, j)) != searched.end()) continue;
					searched.is(mt(*start, y, j));
					best[mt(*start, y, j)] = us + (j != dir);
					if(j == dir) q.push_front(mt(*start, y, j));
					else q.push_back(mt(*start, y, j));
				}
				start = next(start);
				xs[y].erase(prev(start));
			}
		}
		else if(dir == 1) {
			auto start = ys[x].lower_bound(y);
			while (start != ys[x].end()) {
				f0r (j, 0, 4) {
					if(searched.find(mt(x, *start, j)) != searched.end()) continue;
					searched.is(mt(x, *start, j));
					best[mt(x, *start, j)] = us + (j != dir);
					if(j == dir) q.push_front(mt(x, *start, j));
					else q.push_back(mt(x, *start, j));
				}
				start = next(start);
				ys[x].erase(prev(start));
			}
		}
		else if(dir == 2) {
			auto start = xs[y].upper_bound(x);
			bool spec = true;
			while (start != xs[y].begin()) {
				start = prev(start);
				if(!spec) xs[y].erase(next(start));
				else spec = false;
				f0r (j, 0, 4) {
					if(searched.find(mt(*start, y, j)) != searched.end()) continue;
					searched.is(mt(*start, y, j));
					best[mt(*start, y, j)] = us + (j != dir);
					if(j == dir) q.push_front(mt(*start, y, j));
					else q.push_back(mt(*start, y, j));
				}
			}
		}
		else {
			auto start = ys[x].upper_bound(y);
			bool spec = true;
			while (start != ys[x].begin()) {
				start = prev(start);
				if(!spec) ys[x].erase(next(start));
				else spec = false;
				f0r (j, 0, 4) {
					if(searched.find(mt(x, *start, j)) != searched.end()) continue;
					searched.is(mt(x, *start, j));
					best[mt(x, *start, j)] = us + (j != dir);
					if(j == dir) q.push_front(mt(x, *start, j));
					else q.push_back(mt(x, *start, j));
				}
			}
		}
	}

	int b = INF;
	f0r (i, 0, 4) {
		b = min(b, best[mt(xb, yb, i)]);
	}

	if(b == INF) fout << -1 << endl;
	else fout << b << endl;
}