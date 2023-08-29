#include <bits/stdc++.h> 
using namespace std;
#define pb push_back 
#define is insert
#define ll long long
#define V vector
#define MS multiset
#define PL pair<ll, ll>
#define F first
#define S second
#define PQ priority_queue
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define For(i, end, begin) for (ll i = end; i > begin; i --) 
#define all(x) x.begin(), x.end()
#define INF 1000000000000000000
#define inf 1000000000
#define MOD 1000000007
#define len(x) (ll)x.size()
#define fileread(file) ifstream fin; fin.open((string)file + ".in"); ofstream fout; fout.open((string)file + ".out")
#define fastio ios_base::sync_with_stdio(0LL); cin.tie(nullptr)
template<typename T> istream& operator>>(istream& in, V<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, V<T>& a) {for(auto &x : a) out << x << ' '; return out;};

ll N, M, heights[1000], best = 0;

int main () {
	cin >> N >> M;
	f0r (i, 0, M) heights[i] = 0;

	f0r (oloop, 0, N) {
		string s; cin >> s;
		f0r (i, 0, M) {
			if (s[i] == '*') heights[i] = 0;
			else heights[i] ++;
		}

		stack<PL> past;
		f0r (i, 0, M) {
			ll h = heights[i], bpos = i;
			while (len(past)) {
				ll ppos, pheight; 
				tie(ppos, pheight) = past.top();
				if (pheight >= h) {
					best = max(best, (i - ppos) * pheight);
					bpos = min(bpos, ppos);
					past.pop();
				}
				else break;
			}
			past.push({bpos, h});
		}
		while (len(past)) {
			ll ppos, pheight; 
			tie(ppos, pheight) = past.top();
			best = max(best, (M - ppos) * pheight);
			past.pop();
		}
	}
	cout << best << endl;
}