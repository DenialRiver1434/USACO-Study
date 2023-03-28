#define pb push_back
#define mt make_tuple
#define mp make_pair
#define is insert
#define ll long long
#define f0r(i, begin, end) for (ll i = begin; i < end; i ++) 
#define len(x) x.size()
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int add (int a, int b) {
	if(a == INF) return INF;
	return a + b;
}

string S;
int val[200000], best[200000][6];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> S;
	f0r (i, 0, 200000) {
		f0r (j, 0, 6) {
			best[i][j] = INF;
		}
	}
	int top = 0, ls = len(S);
	for (auto ch : S) {
		int wort; cin >> wort;
		f0r (i, max(0, top - 3), min(top + 2, ls)) {
			if(ch == 'b') {
				if(i == 0) best[i][0] = 0;
				else {
					if(best[i - 1][5] != INF) {
						best[i][0] = best[i - 1][5];
						top = i;
					}
				}
				best[i][1] = add(best[i][1], wort);
				best[i][2] = add(best[i][2], wort);
				best[i][3] = add(best[i][3], wort);
				best[i][4] = add(best[i][4], wort);
			}
			else if(ch == 'e') {
				best[i][5] = min(best[i][5], best[i][4]);
				best[i][1] = min(add(best[i][1], wort), best[i][0]);
				best[i][0] = add(best[i][0], wort);
				best[i][2] = add(best[i][2], wort);
				best[i][3] = add(best[i][3], wort);
				best[i][4] = add(best[i][4], wort);
			}
			else if(ch == 's') {
				best[i][3] = min(add(best[i][3], wort), best[i][2]);
				best[i][2] = min(add(best[i][2], wort), best[i][1]);
				best[i][0] = add(best[i][0], wort);
				best[i][1] = add(best[i][1], wort);
				best[i][4] = add(best[i][4], wort);
			}
			else if(ch == 'i') {
				best[i][4] = min(add(best[i][4], wort), best[i][3]);
				best[i][0] = add(best[i][0], wort);
				best[i][1] = add(best[i][1], wort);
				best[i][2] = add(best[i][2], wort);
				best[i][3] = add(best[i][3], wort);
			}
			else {
				best[i][0] = add(best[i][0], wort);
				best[i][1] = add(best[i][1], wort);
				best[i][2] = add(best[i][2], wort);
				best[i][3] = add(best[i][3], wort);
				best[i][4] = add(best[i][4], wort);
			}
		}
	}
	int maxd = 0, maxc = 0;
	for (int i = 199999; i >= 0; i --) {
		if(best[i][5] != INF) {
			cout << i + 1 << endl << best[i][5] << endl;
			return 0;
		}
	}
	cout << 0 << endl << 0 << endl;
}